#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "The size of an integer: ";
    std::cout << sizeof(int) << " bytes." << std::endl;
    std::cout << "The size of an short integer: ";
    std::cout << sizeof(short) << " bytes." << std::endl;
    std::cout << "The size of an long integer: ";
    std::cout << sizeof(long) << " bytes." << std::endl;
    std::cout << "The size of an character: ";
    std::cout << sizeof(char) << " bytes." << std::endl;
    std::cout << "The size of an boolean: ";
    std::cout << sizeof(bool) << " bytes." << std::endl;
    std::cout << "The size of an float: ";
    std::cout << sizeof(float) << " bytes." << std::endl;
    std::cout << "The size of an double float: ";
    std::cout << sizeof(double) << " bytes." << std::endl;
    std::cout << "The size of an long long integer: ";
    std::cout << sizeof(long long int) << " bytes." << std::endl;

    return a.exec();
}