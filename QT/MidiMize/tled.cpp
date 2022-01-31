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

    while(1)
    {
        ledCommand_t cmd;
        my_buffer->popBuffer(cmd);
        //float freq=note_to_freq(cmd.note);
    }
}

float note_to_freq(int note)
{
    return noteFreqs[note];
}
