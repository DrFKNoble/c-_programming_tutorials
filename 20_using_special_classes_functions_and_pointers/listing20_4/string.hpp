#include <iostream>
#include <string.h>

class String
{
public:
    String();
    String(const char *const);
    String(const String &);
    ~String();

    char &operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String &);
    void operator+=(const String &);
    String &operator=(const String &);

    int getLen() const { return len; }
    const char *getString() const { return value; }

private:
    String(int);
    char *value;
    int len;
};

String::String()
{
    value = new char[1];
    value[0] = '\0';
    len = 0;
    // std::cout << "Default String constructor()." << std::endl;

    return;
}

String::String(int newLen)
{
    value = new char[newLen + 1];
    int i;

    for (i = 0; i < newLen; i++)
        value[i] = '\0';

    len = newLen;
    // std::cout << "Overloaded String constructor(int)." << std::endl;

    return;
}

String::String(const char *const cString)
{
    len = strlen(cString);
    value = new char[len + 1];
    int i;

    for (i = 0; i < len; i++)
        value[i] = cString[i];

    value[len] = '\0';
    // std::cout << "Overloaded String constructor(const char *const)." << std::endl;

    return;
}

String::String(const String &rhs)
{
    len = rhs.getLen();
    value = new char[len + 1];
    int i;

    for (i = 0; i < len; i++)
        value[i] = rhs[i];

    value[len] = '\0';
    // std::cout << "Overloaded String constructor(const String&)." << std::endl;

    return;
}

String::~String()
{
    delete[] value;
    len = 0;
    // std::cout << "Default String destructor()." << std::endl;

    return;
}

String &String::operator=(const String &rhs)
{
    if (this == &rhs)
        return *this;

    delete[] value;
    len = rhs.getLen();
    value = new char[len + 1];
    int i;

    for (i = 0; i < len; i++)
        value[i] = rhs[i];

    value[len] = '\0';
    // std::cout << "String operator=(const String&)." << std::endl;

    return *this;
}

char &String::operator[](int offset)
{
    if (offset > len)
        return value[len - 1];
    else
        return value[offset];
    // std::cout << "String operator[](int)." << std::endl;

    return value[0]; // need to return a value like this; otherwise, compiler complains.
}

char String::operator[](int offset) const
{
    if (offset > len)
        return value[len - 1];
    else
        return value[offset];
    // std::cout << "String operator[](int)." << std::endl;

    return value[0]; // need to return a value like this; otherwise, compiler complains.
}

String String::operator+(const String &rhs)
{
    int totalLen = len + rhs.getLen();
    int i, j;

    String temp(totalLen);

    for (i = 0; i < totalLen; i++)
        temp[i] = value[i];

    for (j = 0; j < rhs.getLen(); i++, j++)
        temp[i] = rhs[j];

    temp[totalLen] = '\0';
    // std::cout << "String operator+(const String&)." << std::endl;

    return temp;
}

void String::operator+=(const String &rhs)
{
    int rhsLen = rhs.getLen();
    int totalLen = len + rhsLen;
    int i, j;

    String temp(totalLen);

    for (i = 0; i < len; i++)
        temp[i] = value[i];

    for (j = 0; j < rhs.getLen(); i++, j++)
        temp[i] = rhs[i - len];

    temp[totalLen] = '\0';

    *this = temp;
    // std::cout << "String operator+=(const String&)." << std::endl;

    return;
}