#ifndef CMIDIMIZE_H
#define CMIDIMIZE_H

#include "cSynth.h"
#include "cprotectedbuffer.h"
#include "tled.h"

#define N_SYNTHS 2

struct QtWrapper
{
    CProtectedBuffer<ledCommand_t>* led_ctrl;
    cSynth* synth[2];
};

class CMidiMize
{
    private:
        static CMidiMize* instance;
        cSynth synths [N_SYNTHS];
        TLed led_thread;
        bool soloMode;

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
        }

        CProtectedBuffer<ledCommand_t> led_cmds;
};

#endif // CMIDIMIZE_H
