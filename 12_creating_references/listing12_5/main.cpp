#include <QCoreApplication>
#include <iostream>

void swap(int *pX, int *pY);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x = 10, y = 20;

    std::cout << "main(). Before swap(). x: " << x << ", y: " << y << std::endl;

    swap(&x, &y);

    std::cout << "main(). After swap(). x: " << x << ", y: " << y << std::endl;

    return a.exec();
}

void swap(int *pX, int *pY)
{
    int temp;

    std::cout << "swap(). Before swap. x: " << *pX << ", y: " << *pY << std::endl;

    temp = *pX;
    *pX = *pY;
    *pY = temp;

    std::cout << "swap(). After swap. x: " << *pX << ", y: " << *pY << std::endl;

    return;
}