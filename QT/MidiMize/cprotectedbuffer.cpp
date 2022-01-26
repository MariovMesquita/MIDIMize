#include "cprotectedbuffer.h"

template <typename DataType>
void CProtectedBuffer<DataType>::pushBuffer(DataType& toPush)
{
    pthread_mutex_lock(&this->bufferMutex);
    printf("I'm in push!\ntail:%d\nfront:%d\n", this->tail, this->front);
    while(this->front == this->tail && this->frontOdd != this->tailOdd)
        pthread_cond_wait(&this->bufferNotFull, &this->bufferMutex);
    if(this->front == this->tail && this->frontOdd == this->tailOdd)
        pthread_cond_signal(&this->bufferNotEmpty);
    this->dataBuffer[this->front] = toPush;
    this->front++, this->front &= 0xFF;
    if(!this->front)
        this->frontOdd = !this->frontOdd;
    pthread_mutex_unlock(&this->bufferMutex);
}

template <typename DataType>
void CProtectedBuffer<DataType>::popBuffer(DataType& toPop)
{
    pthread_mutex_lock(&this->bufferMutex);
    printf("I'm in pop!\ntail:%d\nfront:%d\n", this->tail, this->front);
    while(this->front == this->tail && this->frontOdd == this->tailOdd)
        pthread_cond_wait(&this->bufferNotEmpty, &this->bufferMutex);
    if(this->front == this->tail && this->frontOdd != this->tailOdd)
        pthread_cond_signal(&this->bufferNotFull);
    toPop = this->dataBuffer[this->tail];
    this->tail++, this->tail &= 0xFF;
    if(!this->tail)
        this->tailOdd = !this->tailOdd;
    pthread_mutex_unlock(&this->bufferMutex);
}
