#include "switch_pushrod.h"

SwitchPushrod::SwitchPushrod() {}

SwitchPushrod::SwitchPushrod(Pushrod *_pushrod, Switch &_start, Switch &_end)
{
    pushrod = _pushrod;
    start = _start;
    end = _end;
}

void SwitchPushrod::setup(Pushrod *_pushrod, Switch &_start, Switch &_end)
{
    pushrod = _pushrod;
    start = _start;
    end = _end;
}
void SwitchPushrod::setPushrod(Pushrod *_pushrod)
{
    pushrod = _pushrod;
}
void SwitchPushrod::setStart(Switch &_start)
{
    start = _start;
}
void SwitchPushrod::setSwitch(Switch &_end)
{
    end = _end;
}
void SwitchPushrod::forward()
{
    pushrod->resetStep();
    while (end.isOpen())
    {
        pushrod->forward(1);
    }
}
void SwitchPushrod::backward()
{
    pushrod->resetStep();
    while (start.isOpen())
    {
        pushrod->backward(1);
    }
}
