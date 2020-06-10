#include <QCoreApplication>
#include <iostream>

int add(int x, int y)
{
    // add the numbers x and y together and return the sum.
    std::cout << "Adding..." << std::endl;
    return (x + y);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
        This program calls add(), adding two numbers together.
    */
    std::cout << "What is 1 + 2 ?" << std::endl;
    std::cout << add(1, 2) << std::endl;

    return a.exec();
}