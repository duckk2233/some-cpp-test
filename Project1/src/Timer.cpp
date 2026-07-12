#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include <ranges>
#include "include/Timer.h"

//Timer class
Timer::Timer()
{
    start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
}
long long Timer::Break()
{
    end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
    return duration = end - start;
}

//TimerManager class
TimerManager::TimerManager(const char* name)
    :name(name)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dice(1, 100);
    id = dice(rng);
    while(1)
    {
        if(!timerList.empty())
        {
            if(std::ranges::any_of(timerList, [&](int TMid) { return this->id == TMid; }, &TimerManager::id))
                id = dice(rng);
            else
                break;
        }
        else
            break;
    }
    ++timerQuantity;
    timerList.emplace_back(this);
    std::cout << "Timer creat successfully, id: " << id << ", name: " << name << std::endl;
}
TimerManager::~TimerManager()
{
    Stop();
    --timerQuantity;
    timerList.erase(GetPosition());
}
std::vector<TimerManager*>::iterator TimerManager::GetPosition()
{
    return std::ranges::find_if(timerList, [&](int TMid) { return this->id == TMid; }, &TimerManager::id);
}
void TimerManager::Stop()
{
    std::cout << "Name: " << name << ", id: " << id << " timer took " << timer.Break() << " μs ( " << timer.Break() * 0.001f << " ms )" << std::endl;
}

//global function
TimerManager* FindTimer(const char* name)
{
    return *std::ranges::find_if(TimerManager::timerList, [&](const char* TMname) { return name == TMname; }, &TimerManager::name);
}