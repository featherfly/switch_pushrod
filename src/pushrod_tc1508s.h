#ifndef PUSHROD_TC15008S_H
#define PUSHROD_TC15008S_H
#include "pushrod.h"

class Pushrod_Tc15008s : public Pushrod
{
public:
    Pushrod_Tc15008s(int pin1, int pin2, int pin3, int pin4);
    Pushrod_Tc15008s(int pin1, int pin2, int pin3, int pin4, bool forwardState);
    Pushrod_Tc15008s(int pin1, int pin2, int pin3, int pin4, bool forwardState, unsigned int stepperSpeed);
    void go(bool direction, unsigned int step);
    void forward(unsigned int step);
    void backward(unsigned int step);
    void resetStep();

private:
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    bool forwardState = true;
    unsigned int stepperSpeed = 20;
    unsigned int _step = 0;
    void f(unsigned int step);
    void b(unsigned int step);
};

#endif
