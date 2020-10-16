#include "switch.h"
#include <Arduino.h>
#include <ArduinoLog.h>

Switch::Switch(int _pin) : Switch(_pin, true){};

Switch::Switch(int _pin, bool _closeState)
{
    pin = _pin;
    closeState = _closeState;
    pinMode(pin, INPUT);
    Log.notice(F("swicher pin %d, closeState %T," CR), pin, closeState);
};

int Switch::getState()
{
    int s = digitalRead(pin);
    Log.trace(F("swich state %d with pin %d" CR), s, pin);
    state = s;
    return s;
};
bool Switch::isClose()
{
    int s = getState();
    return closeState ? s == HIGH : s == LOW;
};
bool Switch::isOpen()
{
    int s = getState();
    return closeState ? s == LOW : s == HIGH;
};
