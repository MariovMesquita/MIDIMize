#ifndef CMIDIMIZE_H
#define CMIDIMIZE_H

#include "cSynth.h"

#define N_SYNTHS 2

class CMidiMize
{
    private:
        static CMidiMize* instance;
        cSynth synths [N_SYNTHS];
        bool somoMode;

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
        ~CMidiMize();

};

#endif // CMIDIMIZE_H
