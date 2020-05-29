#include <QCoreApplication>
#include <iostream>

auto findVolume(int length, int width = 20, int height = 12);

auto findVolume(int length, int width, int height)
{
    return (length * width * height);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    return a.exec();
}