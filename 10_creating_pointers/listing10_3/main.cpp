#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    unsigned short int myAge = 33, yourAge = 29;
    unsigned short int *pAge = &myAge; // pointer

    std::cout << "myAge: " << myAge << ", yourAge: " << yourAge << std::endl;
    std::cout << "&myAge: " << &myAge << ", &yourAge: " << &yourAge << std::endl;
    std::cout << "pAge: " << pAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    pAge = &yourAge; // reassign the pointer

    std::cout << "myAge: " << myAge << ", yourAge: " << yourAge << std::endl;
    std::cout << "&myAge: " << &myAge << ", &yourAge: " << &yourAge << std::endl;
    std::cout << "pAge: " << pAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    std::cout << "&pAge: " << &pAge << std::endl;

    return a.exec();
}
