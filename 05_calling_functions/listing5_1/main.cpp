#include <QCoreApplication>
#include <iostream>

int findArea(int length, int width);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int length = 0;
    int width = 0;
    int area = 0;

    std::cout << "How wide is your room (m)? ";
    std::cin >> width;
    std::cout << "How long is your room (m)? ";
    std::cin >> length;

    area = findArea(length, width);

    std::cout << "Your room's area is " << area << " m^2." << std::endl;

    return a.exec();
}

int findArea(int l, int w)
{
    return l * w;
}