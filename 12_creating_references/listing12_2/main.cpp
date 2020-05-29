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

    std::cout << "&intOne: " << &intOne << std::endl;
    std::cout << "&rSomeref: " << &rSomeRef << std::endl;

    return a.exec();
}
