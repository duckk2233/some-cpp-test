#include <iostream>
#include "include/Switch.h"
#include "include/Log.h"

#ifdef DEBUG
void Log::Err(const char* message)
{
    if(outputSwitch.Read(1))
        std::cout << "[ERROR] : " << message << std::endl;
}
void Log::Warn(const char* message)
{
    if(outputSwitch.Read(2))
        std::cout << "[WARNING] : " << message << std::endl;
}
void Log::Info(const char* message)
{
    if(outputSwitch.Read(3))
        std::cout << "[INFO] : " << message << std::endl;
}
void Log::ErrOn() { outputSwitch.On(1); }
void Log::WarnOn() { outputSwitch.On(2); }
void Log::InfoOn() { outputSwitch.On(3); }
void Log::ErrOff() { outputSwitch.Off(1); }
void Log::WarnOff() { outputSwitch.Off(2); }
void Log::InfoOff() { outputSwitch.Off(3); }
void Log::SwitchState()
{
    if(outputSwitch.Read(1))
        std::cout << "Error output on\n";
    else
        std::cout << "Error output off\n";
    if(outputSwitch.Read(2))
        std::cout << "Warning output on\n";
    else
        std::cout << "Warning output off\n";
    if(outputSwitch.Read(3))
        std::cout << "Info output on" << std::endl;
    else
        std::cout << "Info output off" << std::endl;
}
#endif