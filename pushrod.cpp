#include "pushrod.h"
#include <Arduino.h>
#include <ArduinoLog.h>

Pushrod::Pushrod() : Pushrod(true)
{
}
Pushrod::Pushrod(bool _forwardState)
{
    forwardState = _forwardState;
}

void Pushrod::go(bool direction, unsigned int step)
{
    
}
void Pushrod::forward(unsigned int step)
{
}
void Pushrod::backward(unsigned int step)
{
}
void Pushrod::resetStep()
{
}