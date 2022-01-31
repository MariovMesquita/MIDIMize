#ifndef CMIDIMIZE_H
#define CMIDIMIZE_H

#include "cSynth.h"
#include "cprotectedbuffer.h"
#include "tled.h"

#define N_SYNTHS 2

class CMidiMize
{
    private:
        static CMidiMize* instance;
        cSynth synths [N_SYNTHS];
        TLed led_thread;
        bool soloMode;

        CMidiMize();

    public:
        static CMidiMize* getInstance()
        {
            if (!instance)
            {
                instance = new CMidiMize;
                return instance;
            }
        }

        ~CMidiMize()
        {
            delete instance;
        }

        CProtectedBuffer<ledCommand_t> led_cmds;
};

#endif // CMIDIMIZE_H
