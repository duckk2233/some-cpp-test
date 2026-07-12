#ifndef LOG_H
#define LOG_H

#include "include/Switch.h"

#ifdef DEBUG
class Log
{
public:
    void Err(const char* message);
    void Warn(const char* message);
    void Info(const char* message);
    void ErrOn();
    void WarnOn();
    void InfoOn();
    void ErrOff();
    void WarnOff();
    void InfoOff();
    void SwitchState();

    /*
    Switch GetData()
    {
        return outputSwitch;
    }
    */ //use to test

private:
    Switch outputSwitch = Switch({1, 2, 3});
};
#else
class Log
{
public:
    inline void Err(const char* message) {}
    inline void Warn(const char* message) {}
    inline void Info(const char* message) {}
    inline void ErrOn() {}
    inline void WarnOn() {}
    inline void InfoOn() {}
    inline void ErrOff() {}
    inline void WarnOff() {}
    inline void InfoOff() {}
    inline void SwitchState() {}
};
#endif

#endif