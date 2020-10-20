#ifndef PUSHROD_H
#define PUSHROD_H

class Pushrod
{
public:
    Pushrod();
    Pushrod(bool forwardState);
    virtual void go(bool direction, unsigned int step);
    virtual void forward(unsigned int step);
    virtual void backward(unsigned int step);
    virtual void resetStep();

private:
    bool forwardState = true;
};

#endif
