#include <iostream>

void swap(int x, int y);

int main()
{
    int x = 10, y = 20;

    std::cout << "main(). Before swap(). x: " << x << ", y: " << y << std::endl;

    swap(x, y);

    std::cout << "main(). After swap(). x: " << x << ", y: " << y << std::endl;

    return 0;
}

void swap(int x, int y) 
{
    int temp;

    std::cout << "swap(). Before swap. x: " << x << ", y: " << y << std::endl;

    temp = x;
    x = y;
    y = temp;

    std::cout << "swap(). After swap. x: " << x << ", y: " << y << std::endl;

    return;
}