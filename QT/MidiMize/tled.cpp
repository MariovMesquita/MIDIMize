#include "tled.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>


TLed::TLed(CProtectedBuffer<ledCommand_t>* led_cmds, void*(*job) (void*))
{
    this->cmdBuffer = led_cmds;
    this->job = job;
}


int TLed::create()
{
    if( pthread_create(&this->threadId, NULL, this->job, this->cmdBuffer) )
    {
        printf("ERROR pthread_create()\n");
        std::exit(-1);
    }

    return 0;
}

void* tLed_job(void* opaque)
{
    CProtectedBuffer<ledCommand_t>* my_buffer = (CProtectedBuffer<ledCommand_t>*)opaque;

    int osc1, osc2, pwr;
    int32_t on=1;
    int32_t off=0;

    system("insmod /etc/MIDImize/device_drivers/osc2_led_rpi4.ko");
    system("insmod /etc/MIDImize/device_drivers/osc1_led_rpi4.ko");
    system("insmod /etc/MIDImize/device_drivers/pwr_led_rpi4.ko");

    osc1 = open("/dev/osc1_led", O_WRONLY); // Open oscillator 1 LED device file
    osc2 = open("/dev/osc2_led", O_WRONLY); // Open oscillator 2 LED device file
    pwr = open("/dev/pwr_led", O_WRONLY);   // Open power LED device file

    while(1)
    {
        ledCommand_t cmd;
        my_buffer->popBuffer(cmd);
        switch(cmd.led_cmd)
        {
            /* OSCILLATOR 1 LED */
            case OSC_1_ON:
                ioctl(osc1, PWR, (int32_t*) &on);
                break;

            case OSC_1_OFF:
                ioctl(osc1, PWR, (int32_t*) &off);
                break;

            case OSC_1_BLK:
                ioctl(osc1, BLK, (int32_t*) &cmd.note);
                break;

            /* OSCILLATOR 2 LED */
            case OSC_2_ON:
                ioctl(osc2, PWR, (int32_t*) &on);
                break;

            case OSC_2_OFF:
                ioctl(osc2, PWR, (int32_t*) &off);
                break;

            case OSC_2_BLK:
                ioctl(osc2, BLK, (int32_t*) &cmd.note);
                break;

            /* POWER LED */
            case PWR_ON:
                ioctl(pwr, PWR, (int32_t*) &on);
                break;

            case PWR_OFF:
                ioctl(pwr, PWR, (int32_t*) &off);
                break;

            case PWR_BLK:
                ioctl(pwr, BLK, (int32_t*) &cmd.note);
                break;

            default:
                break;
        }
    }
}

float note_to_freq(int note)
{
    return noteFreqs[note];
}
