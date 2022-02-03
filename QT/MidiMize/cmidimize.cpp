#include "cmidimize.h"

CMidiMize::CMidiMize(QtWrapper &QtWrap) : led_thread(&this->led_cmds, tLed_job)
{
    QtWrap.led_ctrl=&this->led_cmds;
    QtWrap.synth[0]=&this->synths[0];
    QtWrap.synth[1]=&this->synths[1];
    this->led_thread.create();
    this->soloMode=1;
    QtWrap.solo=this->soloMode;

    ledCommand_t cmd={55, PWR_ON};
    this->led_cmds.pushBuffer(cmd);
    system("amixer set Headphone 0%");
}

CMidiMize* CMidiMize::instance=NULL;
