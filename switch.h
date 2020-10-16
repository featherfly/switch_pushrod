#ifndef SWITCH_H
#define SWITCH_H
class Switch
{
    public:
        Switch(int _pin);
        Switch(int _pin, bool _closeState);
        int getState();
        bool isClose();
        bool isOpen();
    private:
        int state;
        bool closeState = true;
        int pin;
};
#endif
