#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kdev_t.h> // udev - device manager
#include <linux/device.h> // udev - device manager

dev_t dev = 0; // holds major and minor numbers
static struct class *dev_class; // holds device class

static int __init hello_world_init(void)
 {
     /* Allocate major and minor numbers */
     if((alloc_chrdev_region(&dev, 0, 1, "osc1_led")) <0)
     {
         pr_err("Unable to allocate major number for device: osc1_led\n");
         return -1;
     }
     pr_info("Device: osc1_led  Major = %d  Minor = %d  \n", MAJOR(dev), MINOR(dev));

     /* Create device class struct */
     if((dev_class = class_create(THIS_MODULE, "gpio_led")) == NULL)
     {
         pr_err("Unable to create gpio_led device class struct\n");
         unregister_chrdev_region(dev,1);
         
         return -1;
     }

     /* Create device */
     if((device_create(dev_class, NULL, dev, NULL, "osc1_led")) == NULL)
     {
         pr_err("Unable to create osc1_led device\n");
         class_destroy(dev_class);
     }

     pr_info("Device osc1_led created. Kernel module inserted. \n");
     
     return 0;
 }

 static void __exit hello_world_exit(void)
 {
     device_destroy(dev_class, dev);
     class_destroy(dev_class);
     unregister_chrdev_region(dev,1);
     pr_info("osc1_led module removed. \n");
 }

 module_init(hello_world_init);
 module_exit(hello_world_exit);

 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("Mario Mesquita");
 MODULE_DESCRIPTION("null");
 MODULE_VERSION("null");