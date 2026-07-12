#ifndef TIMER_H
#define TIMER_H

#include <vector>

class Timer
{
public:
    Timer();

    long long Break();

private:
    long long start{}, end{};
    long long duration{};
};

class TimerManager
{
public:
    TimerManager(const char* name);
    ~TimerManager();

    friend TimerManager* FindTimer(const char* name);

    std::vector<TimerManager*>::iterator GetPosition();
    void Stop();

private:
    const char* name;
    int id;
    Timer timer{};
    inline static int timerQuantity{};
    inline static std::vector<TimerManager*> timerList;
};
using Timerm = TimerManager;

TimerManager* FindTimer(const char* name);

#endif