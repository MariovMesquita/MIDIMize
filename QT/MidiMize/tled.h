#ifndef TLED_H
#define TLED_H

#include <pthread.h>
#include "cprotectedbuffer.h"

struct ledCommand_t
{
    int note;
    char* cmdBuffer;
};

class TLed
{
    private:
        CProtectedBuffer<ledCommand_t> cmdBuffer;
        pthread_t threadId;
        pthread_attr_t threadAttr;
    public:
        TLed();
        ~TLed();
        void* job(void*);
        int create();
        int join();
        int exit();
};

#endif // TLED_H
