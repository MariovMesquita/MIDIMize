#ifndef CMIDIMIZE_H
#define CMIDIMIZE_H

#include "cSynth.h"
#include "cprotectedbuffer.h"
#include "tled.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define N_SYNTHS 2

struct QtWrapper
{
    CProtectedBuffer<ledCommand_t>* led_ctrl;
    cSynth* synth[2];
    bool solo;
};

struct SynthWrapper
{
    CProtectedBuffer<ledCommand_t>* led_ctrl;
};

class CMidiMize
{
    private:
        static CMidiMize* instance;
        cSynth synths [N_SYNTHS];
        TLed led_thread;


        CMidiMize(QtWrapper &QtWrap);

    public:
        static CMidiMize* getInstance(QtWrapper &QtWrap)
        {
            if (!instance)
            {
                instance = new CMidiMize(QtWrap);
            }
            return instance;
        }

        ~CMidiMize()
        {
            delete instance;
            system("rmmod pwr_led_rpi4");
            system("rmmod osc1_led_rpi4");
            system("rmmod osc2_led_rpi4");
        }

        CProtectedBuffer<ledCommand_t> led_cmds;
};

#endif // CMIDIMIZE_H
