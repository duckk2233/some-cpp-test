#include <vector>
#include <iostream>
#include "include/Switch.h"

Switch::Switch(const std::vector<short>& positions)
{
    for(int i : positions)
        On(i);
}
Switch::Switch() = default;
void Switch::On(const int& pos)
{
    if(pos >= 1 && pos <= sizeof(data) * 8)
        data |= (1 << (pos - 1));
    else
        std::cout << "wrong position" << std::endl;
}
void Switch::Off(const int& pos)
{
    if(pos >= 1 && pos <= sizeof(data) * 8)
        data &= ~(1 << (pos - 1));
    else
        std::cout << "wrong position" << std::endl;
}
bool Switch::Read(const int& pos) const
{
    if(pos >= 1 && pos <= sizeof(data) * 8)
        return static_cast<bool>((data & (1 << (pos - 1))) >> (pos - 1));
    else
    {
        std::cout << "wrong position" << std::endl;
        return {};
    }
}
void Switch::Onib(const std::vector<short>& positions) // On in bulk
{
    for(short i : positions)
        On(i);
}
void Switch::Offib(const std::vector<short>& positions) // Off in bulk
{
    for(short i : positions)
        Off(i);
}
void Switch::Clear()
{
    data = 0;
}