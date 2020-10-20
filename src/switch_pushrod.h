#ifndef SWICHER_PUSHROD_H
#define SWICHER_PUSHROD_H
#include "switch.h"
#include "pushrod.h"

class SwitchPushrod{
    private:
        Pushrod *pushrod = &Pushrod();
        Switch start = Switch(-1);
        Switch end = Switch(-1);
    public:
        SwitchPushrod();
        SwitchPushrod(Pushrod *_pushrod, Switch& _start, Switch& _end);
        void setup(Pushrod *_pushrod, Switch& _start, Switch& _end);
        void setPushrod(Pushrod *_pushrod);
        void setStart(Switch& _start);
        void setSwitch(Switch& _end);
        void forward();
        void backward();
};
#endif
