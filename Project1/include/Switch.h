#ifndef SWITCH_H
#define SWITCH_H

#include <vector>

//#include <bitset> //use to Switch class test
class Switch
{
public:
    explicit Switch(const std::vector<short>& positions);
    explicit Switch();

    void On(const int& pos);
    void Off(const int& pos);
    bool Read(const int& pos) const;
    void Onib(const std::vector<short>& positions); // On in bulk
    void Offib(const std::vector<short>& positions); // Off in bulk
    void Clear();

    // void GetData()
    // {
    //     std::cout << std::bitset<32>(data) << std::endl;
    // } //use to test

private:
    unsigned int data{0};
};

#endif