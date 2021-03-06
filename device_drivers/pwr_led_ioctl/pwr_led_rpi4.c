#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h> //file operations (file system)
#include <linux/kdev_t.h> // udev - device manager
#include <linux/device.h> // udev - device manager
#include <linux/cdev.h> // character devices
#include <linux/gpio.h> // kernel GPIO subsystem
#include <linux/uaccess.h> //copy to/from user
#include <linux/timer.h> // kernel timers
#include <linux/ioctl.h>

#define GPIO_PWR_LED 25

#define BLK _IOW('a', 'b', int32_t*)
#define PWR _IOW('a', 'p', int32_t*)


int32_t freq = 0;
int32_t ctrl = 0;

static struct timer_list pwr_timer;
bool blink = 0;

dev_t dev = 0; // holds major and minor numbers
static struct class *dev_class; // holds device class
static struct cdev pwr_led_cdev; // kernel internal structure to represent character device drivers

static int __init pwr_led_init (void);
static void __exit pwr_led_exit (void);
static int pwr_led_open (struct inode* inode, struct file* file);
static int pwr_led_release (struct inode* inode, struct file* file);
static ssize_t pwr_led_read (struct file* file, char __user* buf, size_t len, loff_t* off);
static ssize_t pwr_led_write (struct file* file, const char* buf, size_t len, loff_t* off);
static long pwr_led_ioctl(struct file* file, unsigned int cmd, unsigned long arg);

static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .read = pwr_led_read,
    .write = pwr_led_write,
    .open = pwr_led_open,
    .release = pwr_led_release,
    .unlocked_ioctl = pwr_led_ioctl,
};

void timer_callback(struct timer_list* data)
{
    if(gpio_get_value(GPIO_PWR_LED))
    {
        gpio_set_value(GPIO_PWR_LED, 0);
    }
    else if(!gpio_get_value(GPIO_PWR_LED))
    {
        gpio_set_value(GPIO_PWR_LED, 1);
    }
    mod_timer(&pwr_timer, jiffies + msecs_to_jiffies(freq));
}

static long pwr_led_ioctl(struct file* file, unsigned int cmd, unsigned long arg)
{
    switch(cmd)
    {
        case BLK:
            if(copy_from_user(&freq, (int32_t*) arg, sizeof(freq)))
            {
                pr_err("ERROR writing data\n");
            }
            blink = 1;
            mod_timer(&pwr_timer, jiffies + msecs_to_jiffies(freq));
            pr_info("Blinking led - %d ms\n", freq);
            break;
        
        case PWR:
            if(copy_from_user(&ctrl, (int32_t*) arg, sizeof(ctrl)))
            {
                pr_err("ERROR writing data\n");
            }   
            if(ctrl == 1)
            {
                if (blink == 1)
                {
                    del_timer(&pwr_timer);
                    blink=0;
                }
                gpio_set_value(GPIO_PWR_LED, 1);
                pr_info("pwr_led ON\n");
            }
            else if(ctrl == 0)
            {
                if (blink == 1)
                {
                    del_timer(&pwr_timer);
                    blink=0;
                }
                gpio_set_value(GPIO_PWR_LED, 0);        
                pr_info("pwr_led OFF\n");    
            }
            else
            {
                pr_info("Unknown PWR command\n");
            }
            break;

        default:
            pr_info("Default ioctl command\n");
            break;
    }
    return 0;
}


static int pwr_led_open(struct inode* inode, struct file* file)
{
    pr_info("pwr_led driver open\n");
    return 0;
}

static int pwr_led_release(struct inode* inode, struct file* file)
{
    pr_info("pwr_led driver release\n");
    return 0;
}

static ssize_t pwr_led_read(struct file* file, char __user* buf, size_t len, loff_t* off)
{
    uint8_t gpio_state = 0;
    gpio_state = gpio_get_value(GPIO_PWR_LED);

    len = 1;
    if (copy_to_user(buf, &gpio_state, len) > 0)
    {
        pr_err("A problem occured copying to user.\n");
    }
    if(gpio_state == 0)
    {
        pr_info("pwr_led is OFF\n");
    }
    else
    {
        pr_info("pwr_led is ON\n");
    }
    
    return 0;
}

static ssize_t pwr_led_write(struct file* file, const char __user* buf, size_t len, loff_t* off)
{
    pr_info("Write function\n");
    return len;
}

static int __init pwr_led_init(void)
 {
    /* Allocate major and minor numbers */
    if((alloc_chrdev_region(&dev, 0, 1, "pwr_led")) <0)
    {
       pr_err("Unable to allocate major number for device: pwr_led\n");
       unregister_chrdev_region(dev, 1); 
       
       return -1;
    }
    pr_info("Device: pwr_led  Major = %d  Minor = %d  \n", MAJOR(dev), MINOR(dev));

    /* Add device to character device subsystem */
    cdev_init(&pwr_led_cdev,&fops);

    if((cdev_add(&pwr_led_cdev, dev, 1)) < 0)
    {
        pr_err("Unable to add pwr_led\n");
        cdev_del(&pwr_led_cdev);
        unregister_chrdev_region(dev,1);
         
        return -1;
    }

    /* Create device class struct */
    if((dev_class = class_create(THIS_MODULE, "pwr_led")) == NULL)
    {
        pr_err("Unable to create pwr_led device class struct\n");
        class_destroy(dev_class);
        cdev_del(&pwr_led_cdev);
        unregister_chrdev_region(dev,1);
         
        return -1;
    }

    /* Create device */
    if((device_create(dev_class, NULL, dev, NULL, "pwr_led")) == NULL)
    {
        pr_err("Unable to create pwr_led device\n");
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&pwr_led_cdev);
        unregister_chrdev_region(dev,1);

        return -1;
    }

    /* Check if GPIO is valid*/
    if(gpio_is_valid(GPIO_PWR_LED) == false)
    {
        pr_err("GPIO: %d is not valid\n", GPIO_PWR_LED);
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&pwr_led_cdev);
        unregister_chrdev_region(dev,1);

        return -1;
    }

    /* Request GPIO */   
    if(gpio_request(GPIO_PWR_LED, "GPIO_25") < 0)
    {
        pr_err("ERROR requesting GPIO %d\n", GPIO_PWR_LED);
        gpio_free(GPIO_PWR_LED);
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&pwr_led_cdev);
        unregister_chrdev_region(dev, 1);

        return -1;
    }

    timer_setup(&pwr_timer, timer_callback, 0);
    pwr_timer.expires = jiffies + HZ;
    //DEFINE_TIMER(pwrtimer, timer_callback, jiffies + HZ, 0);

    gpio_direction_output(GPIO_PWR_LED, 0);
    gpio_export(GPIO_PWR_LED, false); // direction_may_change = false -> user space is not allowed to change GPIO direction
    
    pr_info("Device pwr_led created. Kernel module inserted. \n");
     
    return 0;
 }

 static void __exit pwr_led_exit(void)
 {
    del_timer(&pwr_timer);
    gpio_set_value(GPIO_PWR_LED, 0);
    gpio_unexport(GPIO_PWR_LED);
    gpio_free(GPIO_PWR_LED);
    device_destroy(dev_class, dev);
    class_destroy(dev_class);
    cdev_del(&pwr_led_cdev);
    unregister_chrdev_region(dev,1);
    pr_info("pwr_led module removed. \n");
 }

 module_init(pwr_led_init);
 module_exit(pwr_led_exit);

 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("Mario Mesquita");
 MODULE_DESCRIPTION("null");
 MODULE_VERSION("null");