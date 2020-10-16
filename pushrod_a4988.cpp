#include "pushrod_a4988.h"
#include <Arduino.h>
#include <ArduinoLog.h>

Pushrod_A4988::Pushrod_A4988(int _dirPin, int _stepPin) : Pushrod_A4988(_dirPin, _stepPin, -1, true) {}
Pushrod_A4988::Pushrod_A4988(int _dirPin, int _stepPin, bool _forwardState) : Pushrod_A4988(_dirPin, _stepPin, -1, _forwardState) {}
//Pushrod_A4988::Pushrod_A4988(int _dirPin, int _stepPin, int _enablePin) : Pushrod_A4988(_dirPin, _stepPin, _enablePin, true) {}
Pushrod_A4988::Pushrod_A4988(int _dirPin, int _stepPin, int _enablePin, bool _forwardState) : Pushrod(_forwardState)
{
    dirPin = _dirPin;
    stepPin = _stepPin;
    enablePin = _enablePin;
    forwardState = _forwardState;
    pinMode(dirPin, OUTPUT);
    digitalWrite(dirPin, LOW);
    pinMode(stepPin, OUTPUT); 
    digitalWrite(stepPin, LOW);
    if (enablePin >= 0) {
        pinMode(enablePin, OUTPUT); 
        digitalWrite(enablePin, LOW);
    }
    Log.notice(F("dirPin %d, stepPin %d, enablePin %d, forwardState %T" CR), dirPin, stepPin, enablePin, forwardState);
}

void Pushrod_A4988::go(bool direction, unsigned int step)
{
    Log.trace(F("dirPin %d, stepPin %d, enablePin %d, forwardState %T, direction %T" CR), dirPin, stepPin, enablePin, forwardState, direction);
    digitalWrite(dirPin, direction); // Set Dir forward
    for (unsigned int i = 0; i < step; i++)
    {
        digitalWrite(stepPin, HIGH); // Output high
        delayMicroseconds(800);      // Wait 1/2 a ms
        digitalWrite(stepPin, LOW);  // Output low
        delayMicroseconds(800);      // Wait 1/2 a ms
    }
}
void Pushrod_A4988::forward(unsigned int step)
{
    go(forwardState, step);
}
void Pushrod_A4988::backward(unsigned int step)
{
    go(!forwardState, step);
}

void Pushrod_A4988::enable()
{
    if (enablePin >= 0)
    {
        digitalWrite(enablePin, LOW);
    }
}
void Pushrod_A4988::disable()
{
    if (enablePin >= 0)
    {
        digitalWrite(enablePin, HIGH);
    }
}
void Pushrod_A4988::resetStep()
{
}
