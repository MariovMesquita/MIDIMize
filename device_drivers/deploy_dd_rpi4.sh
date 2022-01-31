./pwr_led/make
./osc_leds/osc1/make
./osc_leds/osc2/make
scp userApp ./pwr_led/pwr_led_rpi4.ko ./osc_leds/osc1/osc1_led_rpi4.ko ./osc_leds/osc2/osc2_led_rpi4.ko root@10.42.0.37:/etc/MIDImize/device_drivers/