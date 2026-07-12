#ifndef DTOOLS_H
#define DTOOLS_H

#include <iostream>
#include <ostream>
#include <cstring>

class Vector3
{
public:
    Vector3(float x, float y, float z);

    Vector3 operator+(const Vector3& other) const;
    Vector3 operator*(const Vector3& other) const;
    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

    Vector3 Add(const Vector3& other) const;
    Vector3 Multiply(const Vector3& other) const;
    float GetX() const;
    float GetY() const;
    float GetZ() const;

private:
    float x{};
    float y{};
    float z{};
};

class String
{
public:
    String(const char* string);
    String(const String& other);
    ~String();

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    char& operator[](size_t index);

private:
    char* buffer{};
    unsigned int size{};
};

template<typename T>
class ScopedPtr
{
public:
    explicit ScopedPtr(T* obj)
        :obj(obj)
    {}
    ~ScopedPtr()
    {
        delete obj;
    }
    ScopedPtr(const ScopedPtr& other) = delete;

    T* operator->()
    {
        return obj;
    }
    const T* operator->() const
    {
        return obj;
    }
    ScopedPtr& operator=(const ScopedPtr& other) = delete;
    
private:
    T* obj{};
};

#endif