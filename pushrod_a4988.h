#ifndef PUSHROD_A4988_H
#define PUSHROD_A4988_H
#include "pushrod.h"

class Pushrod_A4988 : public Pushrod
{
public:
    Pushrod_A4988(int dirPin, int stepPin);
    Pushrod_A4988(int dirPin, int stepPin, bool forwardState);
    //        Pushrod_A4988(int dirPin, int stepPin, int enablePin);
    Pushrod_A4988(int dirPin, int stepPin, int enablePin, bool forwardState);
    void go(bool direction, unsigned int step);
    void enable();
    void disable();
    void forward(unsigned int step);
    void backward(unsigned int step);
    void resetStep();

private:
    unsigned int dirPin;
    unsigned int stepPin;
    unsigned int enablePin;
    bool forwardState = true;
};

#endif
