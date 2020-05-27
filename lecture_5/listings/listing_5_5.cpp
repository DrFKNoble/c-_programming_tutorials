#include <iostream>

int findVolume(int length, int width = 20, int height = 12);

int main()
{

    int length = 100;
    int width = 50;
    int height = 2;
    int volume = 0;

    volume = findVolume(length, width, height);

    std::cout << "Volume 1: " << volume << " m^3" << std::endl;

    volume = findVolume(length, width);

    std::cout << "Volume 2: " << volume << " m^3" << std::endl;

    volume = findVolume(length);

    std::cout << "Volume 3: " << volume << " m^3" << std::endl;

    return 0;
}

int findVolume(int length, int width, int height) 
{
    return (length * width * height);
}