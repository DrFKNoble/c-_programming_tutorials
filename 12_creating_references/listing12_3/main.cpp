#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int intOne;
    int &rSomeRef = intOne;

    intOne = 10;

    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;
    std::cout << "&intOne: " << &intOne << std::endl;
    std::cout << "&rSomeRef: " << &rSomeRef << std::endl;

    int intTwo = 20;

    rSomeRef = intTwo;

    std::cout << std::endl;
    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "intTwo: " << intTwo << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;
    std::cout << "&intOne: " << &intOne << std::endl;
    std::cout << "&intTwo: " << &intTwo << std::endl;
    std::cout << "&rSomeRef: " << &rSomeRef << std::endl;

    return a.exec();
}