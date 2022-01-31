#include "cmidimize.h"

CMidiMize::CMidiMize() : led_thread(&this->led_cmds, tLed_job){}

CMidiMize* CMidiMize::instance=0;

