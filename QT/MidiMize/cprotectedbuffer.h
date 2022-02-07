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

template <typename DataType>
void CProtectedBuffer<DataType>::pushBuffer(DataType& toPush)
{
    pthread_mutex_lock(&this->bufferMutex);

    while(this->front == this->tail && this->frontOdd != this->tailOdd) // While buffer is full
    {
        pthread_cond_wait(&this->bufferNotFull, &this->bufferMutex); // Wait for NOT FULL signal
    }

    if(this->front == this->tail && this->frontOdd == this->tailOdd) // Buffer has at least one element
    {
        pthread_cond_signal(&this->bufferNotEmpty); // Send BUFFER NOT EMPTY signal
    }

    this->dataBuffer[this->front] = toPush; // Add data to buffer
    this->front++, this->front &= 0xFF; // Increment front

    if(!this->front) // One lap completed
    {
        this->frontOdd = !this->frontOdd;
    }
    pthread_mutex_unlock(&this->bufferMutex);
}

template <typename DataType>
void CProtectedBuffer<DataType>::popBuffer(DataType& toPop)
{
    pthread_mutex_lock(&this->bufferMutex);

    while(this->front == this->tail && this->frontOdd == this->tailOdd) // While buffer is empty
    {
        pthread_cond_wait(&this->bufferNotEmpty, &this->bufferMutex); // Wait for NOT EMPTY signal
    }

    if(this->front == this->tail && this->frontOdd != this->tailOdd) // Buffer has at least one free space
    {
        pthread_cond_signal(&this->bufferNotFull); // Send BUFFER NOT FULL signal
    }

    toPop = this->dataBuffer[this->tail]; // Read data from buffer
    this->tail++, this->tail &= 0xFF; // Increment tail

    if(!this->tail) // One lap completed
    {
        this->tailOdd = !this->tailOdd;
    }
    pthread_mutex_unlock(&this->bufferMutex);
}

#endif // CPROTECTEDBUFFER_H
