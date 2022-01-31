#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x70035c2e, "module_layout" },
	{ 0x26c3aaa4, "gpiod_unexport" },
	{ 0x5a118e47, "gpiod_export" },
	{ 0x9f10e4e4, "gpiod_direction_output_raw" },
	{ 0xfe990052, "gpio_free" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xcb369c55, "cdev_del" },
	{ 0x7d9b3fc1, "class_destroy" },
	{ 0xe162751b, "device_destroy" },
	{ 0x74488b62, "device_create" },
	{ 0x831e1955, "__class_create" },
	{ 0x824de4cd, "cdev_add" },
	{ 0x403dda38, "cdev_init" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x507a1370, "gpiod_get_raw_value" },
	{ 0x86332725, "__stack_chk_fail" },
	{ 0x5f754e5a, "memset" },
	{ 0x2cfde9a2, "warn_slowpath_fmt" },
	{ 0x6b591756, "gpiod_set_raw_value" },
	{ 0x42079654, "gpio_to_desc" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "48F7BA8ADA7799C5726FBA8");
