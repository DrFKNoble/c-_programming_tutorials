#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int value1 = 1000;
    int value2 = 2000;
    int *pointer2 = nullptr;

    std::cout << "value1: " << value1 << std::endl;
    std::cout << "value2: " << value2 << std::endl;

    pointer2 = &value2;     // give pointer the address of value2

    value1 = *pointer2;     // dereference the pointer and assign it to value1
    pointer2 = 0;

    std::cout << "value1: " << value1 << std::endl;
    std::cout << "value2: " << value2 << std::endl;

    return a.exec();
}
