#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    unsigned short shortVar = 5;
    unsigned long longVar = 65535;
    long sVar = -65535;

    std::cout << "shortVar: " << shortVar;
    std::cout << " Address of shortVar: " << &shortVar << std::endl;
    std::cout << "sizeof(shortVar): " << sizeof(shortVar) << std::endl;
    std::cout << "longVar: " << longVar;
    std::cout << " Address of longVar: " << &longVar << std::endl;
    std::cout << "sizeof(longVar): " << sizeof(longVar) << std::endl;
    std::cout << "sVar: " << sVar;
    std::cout << " Address of sVar: " << &sVar << std::endl;
    std::cout << "sizeof(sVar): " << sizeof(sVar) << std::endl;

    return a.exec();
}