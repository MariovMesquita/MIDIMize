obj-m := pwr_led_rpi4.o
KERNEL_DIR ?= ~/buildroot/buildroot-2021.02.5/output/build/linux-custom
ARCH ?= arm
CROSS_COMPILE ?= ~/buildroot/buildroot-2021.02.5/output/host/bin/arm-buildroot-linux-gnueabihf-

export ARCH CROSS_COMPILE

KBUILD_TARGETS	:= clean help modules modules_install

.PHONY: all clean deploy $(KBUILD_TARGETS)

all: modules
$(KBUILD_TARGETS):
	$(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) $@
	#make -C $(KERNEL_DIR) \
	#ARCH=arm CROSS_COMPILE=~/buildroot/buildroot-2021.02.5/output/host/bin/arm-buildroot-linux-gnueabihf- \
	#M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) clean
	#make -C $(KERNEL_DIR) \
	#ARCH=arm CROSS_COMPILE=~/buildroot/buildroot-2021.02.5/output/host/bin/arm-buildroot-linux-gnueabihf- \
	#M=$(PWD) clean

deploy:
	scp *.ko root@$(address):/etc/MIDImize/device_drivers