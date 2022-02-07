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

#define GPIO_OSC1_LED 24

#define BLK _IOW('a', 'b', int32_t*)
#define PWR _IOW('a', 'p', int32_t*)


int32_t freq = 0;
int32_t ctrl = 0;

static struct timer_list osc1_timer;
bool blink = false;

dev_t dev = 0; // holds major and minor numbers
static struct class *dev_class; // holds device class
static struct cdev osc1_led_cdev; // kernel internal structure to represent character device drivers

static int __init osc1_led_init (void);
static void __exit osc1_led_exit (void);
static int osc1_led_open (struct inode* inode, struct file* file);
static int osc1_release (struct inode* inode, struct file* file);
static ssize_t osc1_led_read (struct file* file, char __user* buf, size_t len, loff_t* off);
static ssize_t osc1_led_write (struct file* file, const char* buf, size_t len, loff_t* off);
static long osc1_led_ioctl(struct file* file, unsigned int cmd, unsigned long arg);

static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .read = osc1_led_read,
    .write = osc1_led_write,
    .open = osc1_led_open,
    .release = osc1_release,
    .unlocked_ioctl = osc1_led_ioctl,
};

void timer_callback(struct timer_list* data)
{
    if(gpio_get_value(GPIO_OSC1_LED))
    {
        gpio_set_value(GPIO_OSC1_LED, 0);
    }
    else if(!gpio_get_value(GPIO_OSC1_LED))
    {
        gpio_set_value(GPIO_OSC1_LED, 1);
    }
    mod_timer(&osc1_timer, jiffies + msecs_to_jiffies(freq)); // timer will expire after freq miliseconds
}

static long osc1_led_ioctl(struct file* file, unsigned int cmd, unsigned long arg)
{
    switch(cmd)
    {
        /* BLINK IOCTL FUNCTION */
        case BLK:
            if(copy_from_user(&freq, (int32_t*) arg, sizeof(freq)))
            {
                pr_err("ERROR writing data\n");
            }
            blink = 1;
            mod_timer(&osc1_timer, jiffies + msecs_to_jiffies(freq)); // timer will expire after freq miliseconds
            pr_info("Blinking led - %d ms\n", freq);
            break;
        
        /* POWER IOCTL FUNCTION */
        case PWR:
            if(copy_from_user(&ctrl, (int32_t*) arg, sizeof(ctrl)))
            {
                pr_err("ERROR writing data\n");
            }   
            if(ctrl == 1)
            {
                if (blink)
                {
                    del_timer(&osc1_timer);
                    blink=false;
                }
                gpio_set_value(GPIO_OSC1_LED, 1);
                pr_info("osc_1_led ON\n");
            }
            else if(ctrl == false)
            {
                if (blink )
                {
                    del_timer(&osc1_timer);
                    blink=false;
                }
                gpio_set_value(GPIO_OSC1_LED, 0);        
                pr_info("osc_1_led OFF\n");    
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


static int osc1_led_open(struct inode* inode, struct file* file)
{
    pr_info("osc1_led driver open\n");
    return 0;
}

static int osc1_release(struct inode* inode, struct file* file)
{
    pr_info("osc1_led driver release\n");
    return 0;
}

static ssize_t osc1_led_read(struct file* file, char __user* buf, size_t len, loff_t* off)
{
    uint8_t gpio_state = 0;
    gpio_state = gpio_get_value(GPIO_OSC1_LED);

    len = 1;
    if (copy_to_user(buf, &gpio_state, len) > 0)
    {
        pr_err("A problem occured copying to user.\n");
    }
    if(gpio_state == 0)
    {
        pr_info("osc_1_led is OFF\n");
    }
    else
    {
        pr_info("osc_1_led is ON\n");
    }
    
    return 0;
}

static ssize_t osc1_led_write(struct file* file, const char __user* buf, size_t len, loff_t* off)
{
    pr_info("Write function\n");
    return len;
}

static int __init osc1_led_init(void)
 {
    /* Allocate major and minor numbers */
    if((alloc_chrdev_region(&dev, 0, 1, "osc1_led")) <0)
    {
       pr_err("Unable to allocate major number for device: osc1_led\n");
       unregister_chrdev_region(dev, 1); 
       
       return -1;
    }
    pr_info("Device: osc1_led  Major = %d  Minor = %d  \n", MAJOR(dev), MINOR(dev));

    /* Add device to character device subsystem */
    cdev_init(&osc1_led_cdev,&fops);

    if((cdev_add(&osc1_led_cdev, dev, 1)) < 0)
    {
        pr_err("Unable to add osc1_led\n");
        cdev_del(&osc1_led_cdev);
        unregister_chrdev_region(dev,1);
         
        return -1;
    }

    /* Create device class struct */
    if((dev_class = class_create(THIS_MODULE, "osc1_led")) == NULL)
    {
        pr_err("Unable to create osc1_led device class struct\n");
        class_destroy(dev_class);
        cdev_del(&osc1_led_cdev);
        unregister_chrdev_region(dev,1);
         
        return -1;
    }

    /* Create device */
    if((device_create(dev_class, NULL, dev, NULL, "osc1_led")) == NULL)
    {
        pr_err("Unable to create osc1_led device\n");
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&osc1_led_cdev);
        unregister_chrdev_region(dev,1);

        return -1;
    }

    /* Check if GPIO is valid*/
    if(gpio_is_valid(GPIO_OSC1_LED) == false)
    {
        pr_err("GPIO: %d is not valid\n", GPIO_OSC1_LED);
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&osc1_led_cdev);
        unregister_chrdev_region(dev,1);

        return -1;
    }

    /* Request GPIO */   
    if(gpio_request(GPIO_OSC1_LED, "GPIO_24") < 0)
    {
        pr_err("ERROR requesting GPIO %d\n", GPIO_OSC1_LED);
        gpio_free(GPIO_OSC1_LED);
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&osc1_led_cdev);
        unregister_chrdev_region(dev, 1);

        return -1;
    }

    timer_setup(&osc1_timer, timer_callback, 0); // kernel timer setup
    osc1_timer.expires = jiffies + HZ; // kernel timer timeout // HZ = 100hz frequency of the system timer (tick rate)
    

    gpio_direction_output(GPIO_OSC1_LED, 0); // Sets GPIO 24 as an output 
    gpio_export(GPIO_OSC1_LED, false);  // direction_may_change = false -> user space is not allowed to change GPIO direction
    
    pr_info("Device osc1_led created. Kernel module inserted. \n");
     
    return 0;
 }

 static void __exit osc1_led_exit(void)
 {
    del_timer(&osc1_timer);
    gpio_set_value(GPIO_OSC1_LED, 0);
    gpio_unexport(GPIO_OSC1_LED);
    gpio_free(GPIO_OSC1_LED);
    device_destroy(dev_class, dev);
    class_destroy(dev_class);
    cdev_del(&osc1_led_cdev);
    unregister_chrdev_region(dev,1);
    pr_info("osc1_led module removed. \n");
 }

 module_init(osc1_led_init);
 module_exit(osc1_led_exit);

 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("Mario Mesquita");
 MODULE_DESCRIPTION("null");
 MODULE_VERSION("null");