#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // create a type definition
    typedef unsigned short USHORT;

    // set up width and length
    USHORT width = 26;
    USHORT length = 40;

    // create an unsigned short initialised with the
    // result of multiplying width by length
    USHORT area = width * length;

    std::cout << "Width: " << width << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Area: " << area << std::endl;

    return a.exec();
}
