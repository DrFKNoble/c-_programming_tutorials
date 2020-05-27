#include <iostream>
#include <string.h>

int main()
{
    char literal[] = "She's a witch!";
    char buffer[80];

    strcpy_s(buffer, literal);

    std::cout << "Literal: " << literal << std::endl;
    std::cout << "Buffer: " << buffer << std::endl;

    return 0;
}