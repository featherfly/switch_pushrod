#include "switch_pushrod.h"

SwitchPushrod::SwitchPushrod() {}

SwitchPushrod::SwitchPushrod(Pushrod *_pushrod, Switch *_start, Switch *_end)
{
    pushrod = _pushrod;
    start = _start;
    end = _end;
}

void SwitchPushrod::setup(Pushrod *_pushrod, Switch *_start, Switch *_end)
{
    pushrod = _pushrod;
    start = _start;
    end = _end;
}
void SwitchPushrod::setPushrod(Pushrod *_pushrod)
{
    pushrod = _pushrod;
}
void SwitchPushrod::setStartSwitch(Switch *_start)
{
    start = _start;
}
void SwitchPushrod::setEndSwitch(Switch *_end)
{
    end = _end;
}
int SwitchPushrod::forward()
{
    _steps = 0;
    pushrod->resetStep();
    while (end->is_on())
    {
        pushrod->forward(1);
        _steps++;
        if (user_onStep(_steps, STEP_FORWARD) == EVENT_STEP_STOP)
        {
            break;
        }
    }
    return _steps;
}
int SwitchPushrod::backward()
{
    _steps = 0;
    pushrod->resetStep();
    while (start->is_on())
    {
        pushrod->backward(1);
        _steps++;
        if (user_onStep(_steps, STEP_BACKWARD) == EVENT_STEP_STOP)
        {
            break;
        }
    }
    return _steps;
}

int SwitchPushrod::steps()
{
    return _steps;
}

void SwitchPushrod::onStep(int (*function)(int, bool))
{
    user_onStep = function;
}
