#include "cmidimize.h"
#include "cSynth.h"

CMidiMize::CMidiMize()
{
    for (int i=0; i<N_SYNTHS ; i++)
    {
        synths[i]=cSynth();
    }
}

CMidiMize* CMidiMize::instance=0;

//CMidiMize* CMidiMize::getInstance()
//{
//    if (!instance)
//    {
//        instance = new CMidiMize;
//        return instance;
//    }
//}

