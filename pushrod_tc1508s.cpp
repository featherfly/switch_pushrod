#include "pushrod_tc1508s.h"
#include <Arduino.h>
#include <ArduinoLog.h>

Pushrod_Tc15008s::Pushrod_Tc15008s(int _pin1, int _pin2, int _pin3, int _pin4) : Pushrod_Tc15008s(_pin1, _pin2, _pin3, _pin4, true) {}
Pushrod_Tc15008s::Pushrod_Tc15008s(int _pin1, int _pin2, int _pin3, int _pin4, bool _forwardState) : Pushrod_Tc15008s(_pin1, _pin2, _pin3, _pin4, _forwardState, 20) {}
Pushrod_Tc15008s::Pushrod_Tc15008s(int _pin1, int _pin2, int _pin3, int _pin4, bool _forwardState, unsigned int _stepperSpeed) : Pushrod(_forwardState)
{
    pin1 = _pin1;
    pin2 = _pin2;
    pin3 = _pin3;
    pin4 = _pin4;
    forwardState = _forwardState;
    stepperSpeed = _stepperSpeed;

    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    Log.notice(F("pin1 %d, pin2 %d, pin3 %d, pin4 %d ,forwardState %T" CR), pin1, pin2, pin3, pin4, forwardState);
}

void Pushrod_Tc15008s::go(bool direction, unsigned int step)
{
    if (forwardState)
    {
        if (direction)
        {
            f(step);
        }
        else
        {
            b(step);
        }
    }
    else
    {
        if (direction)
        {
            b(step);
        }
        else
        {
            f(step);
        }
    }
}
void Pushrod_Tc15008s::forward(unsigned int step)
{
    go(true, step);
}
void Pushrod_Tc15008s::backward(unsigned int step)
{
    go(false, step);
}

void Pushrod_Tc15008s::resetStep()
{
    _step = 0;
}

void Pushrod_Tc15008s::f(unsigned int step)
{
    for (unsigned int i = 0; i < step; i++)
    {
        if (_step > 3)
        {
            _step = 0;
        }
        switch (_step)
        {
        case 0:
            //stepperSpeed++;
            digitalWrite(pin3, HIGH);
            digitalWrite(pin4, LOW);
            break;
        case 1:
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;
        case 2:
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, HIGH);
            break;
        case 3:
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;
        default:
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;
        }
        _step++;

        delay(stepperSpeed);
    }
}
void Pushrod_Tc15008s::b(unsigned int step)
{
    for (unsigned int i = 0; i < step; i++)
    {
        if (_step > 3)
        {
            _step = 0;
        }
        switch (_step)
        {
        case 0:
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
            break;
        case 1:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            break;
        case 2:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, HIGH);
            break;
        case 3:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            break;
        default:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            break;
        }
        _step++;
        delay(stepperSpeed);
    }
}
