#include <iostream>
#include <ostream>
#include "include/DTools.h"

// Vector3 Class
Vector3::Vector3(float x, float y, float z)
    :x(x), y(y), z(z)
{}
Vector3 Vector3::operator+(const Vector3& other) const
{
    return Add(other);
}
Vector3 Vector3::operator*(const Vector3& other) const
{
    return Multiply(other);
}
bool Vector3::operator==(const Vector3& other) const
{
    return x == other.x && y == other.y && z == other.z;
}
bool Vector3::operator!=(const Vector3& other) const
{
    return !(*this == other);
}
std::ostream& operator<<(std::ostream& os, const Vector3& vec)
{
    os << vec.x << " " << vec.y << " " << vec.z;
    return os;
}
Vector3 Vector3::Add(const Vector3& other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}
Vector3 Vector3::Multiply(const Vector3& other) const
{
    return Vector3(x * other.x, y * other.y, z + other.z);
}
float Vector3::GetX() const
{
    return x;
}
float Vector3::GetY() const
{
    return y;
}
float Vector3::GetZ() const
{
    return z;
}

// String Class
String::String(const char* string)
{
    size = strlen(string);
    buffer = new char[size + 1];
    memcpy(buffer, string, size + 1);
}
String::String(const String& other)
    :size(other.size), buffer(new char[other.size +1])
{
    memcpy(buffer, other.buffer, size);
}
String::~String()
{
    delete[] buffer;
}
std::ostream& operator<<(std::ostream& os, const String& str)
{
    return os << str.buffer;
}
char& String::operator[](size_t index)
{
    return buffer[index];
}