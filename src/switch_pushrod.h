#ifndef SWICHER_PUSHROD_H
#define SWICHER_PUSHROD_H
#include "switch.h"
#include "pushrod.h"

#define EVENT_STEP_STOP 0
#define EVENT_STEP_CONTINUE 1

#define STEP_BACKWARD 0
#define STEP_FORWARD 1

class SwitchPushrod
{
private:
    int _steps = 0;
    Pushrod *pushrod = &Pushrod();
    Switch *start = &Switch(&Pin(-1, INPUT));
    Switch *end = &Switch(&Pin(-1, INPUT));    
    int (*user_onStep)(int, bool) = [](int, bool) { return EVENT_STEP_CONTINUE; };
public:
    SwitchPushrod();
    SwitchPushrod(Pushrod *_pushrod, Switch *_start, Switch *_end);
    void setup(Pushrod *_pushrod, Switch *_start, Switch *_end);
    void setPushrod(Pushrod *_pushrod);
    void setStartSwitch(Switch *_start);
    void setEndSwitch(Switch *_end);
    /**
     * @return steps
     */
    int forward();
    /**
     * @return steps
     */
    int backward();
    int steps();
    void onStep(int (*)(int, bool));
};
#endif
