#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int intOne;
    int &rSomeRef = intOne;

    intOne = 5;

    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;

    rSomeRef = 7;

    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;

    return a.exec();
}