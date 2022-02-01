#include "cmidimize.h"

CMidiMize::CMidiMize(QtWrapper &QtWrap) : led_thread(&this->led_cmds, tLed_job)
{
    QtWrap.led_ctrl=&this->led_cmds;
    QtWrap.synth[0]=&this->synths[0];
    QtWrap.synth[1]=&this->synths[1];
}

CMidiMize* CMidiMize::instance=NULL;
