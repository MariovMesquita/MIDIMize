#ifndef CPROTECTEDBUFFER_H
#define CPROTECTEDBUFFER_H


#include <pthread.h>

#define SIZE 256
#define BUFFER_SIZE 20

template <typename DataType>
class CProtectedBuffer
{
    private:
        DataType dataBuffer[SIZE];
        unsigned int front;
        unsigned int tail;
        pthread_mutex_t bufferMutex;
        pthread_cond_t bufferNotEmpty;
        pthread_cond_t bufferNotFull;
        bool frontOdd;
        bool tailOdd;
    public:
        CProtectedBuffer() : front(0), tail(0), bufferMutex(PTHREAD_MUTEX_INITIALIZER),
         bufferNotEmpty(PTHREAD_COND_INITIALIZER), bufferNotFull(PTHREAD_COND_INITIALIZER), frontOdd(false), tailOdd(false)
        {}
        void pushBuffer(DataType& toPush);
        void popBuffer(DataType& toPop);
};

#endif // CPROTECTEDBUFFER_H
