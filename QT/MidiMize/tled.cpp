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
    //CProtectedBuffer<ledCommand_t>& commands = *((CProtectedBuffer<ledCommand_t> *)cmdBuffer);

    int osc1, osc2, pwr;

    system("insmod ./device_drivers/osc2_led_rpi4.ko");
    system("insmod ./device_drivers/osc1_led_rpi4.ko");
    system("insmod ./device_drivers/pwr_led_rpi4.ko");

    osc1 = open("/dev/osc1_led", O_WRONLY);
    osc2 = open("/dev/osc2_led", O_WRONLY);
    pwr = open("/dev/pwr_led", O_WRONLY);

    while(1)
    {
        ledCommand_t cmd;
        my_buffer->popBuffer(cmd);
        switch(cmd.led_cmd)
        {
            case OSC_1_ON:
                ioctl(osc1, PWR, 1);
                break;

            case OSC_1_OFF:
                ioctl(osc1, PWR, 0);
                break;

            case OSC_1_BLK:
                ioctl(osc1, BLK, (int32_t*) &cmd.note);
                break;

            case OSC_2_ON:
                ioctl(osc2, PWR, 1);
                break;

            case OSC_2_OFF:
                ioctl(osc2, PWR, 0);
                break;

            case OSC_2_BLK:
                ioctl(osc2, BLK, (int32_t*) &cmd.note);
                break;

            case PWR_ON:
                system("echo 1 > /dev/pwr_led");
                break;

            case PWR_OFF:
                system("echo 0 > /dev/pwr_led");
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
