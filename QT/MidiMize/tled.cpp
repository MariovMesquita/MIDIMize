#include "tled.h"

TLed::TLed()
{
    this->cmdBuffer = (CProtectedBuffer<ledCommand_t>());
}
