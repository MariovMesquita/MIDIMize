#include "cmidimize.h"

CMidiMize::CMidiMize(QtWrapper &QtWrap) : led_thread(&this->led_cmds, tLed_job)
{
    /* QT Wrapper init */
    QtWrap.led_ctrl=&this->led_cmds;
    QtWrap.synth[0]=&this->synths[0];
    QtWrap.synth[1]=&this->synths[1];
    QtWrap.solo=true;
    /*******************/

    /* Start LED thread */
    this->led_thread.create();
    /********************/

    /* PWR LED ON*/
    ledCommand_t cmd={55, PWR_ON};
    this->led_cmds.pushBuffer(cmd);
    /************/

    system("amixer set Headphone 0%"); // START MUTED
}

CMidiMize* CMidiMize::instance=NULL;
