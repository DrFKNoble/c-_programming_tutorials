#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int myAge;              // a variable
    int *pAge = nullptr;    // a pointer

    myAge = 33;
    pAge = &myAge;           // assign address of myAge to pAge

    std::cout << "myAge: " << myAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    std::cout << "*pAge = 29" << std::endl << std::endl;
    *pAge = 29;             // sets myAge to 29

    std::cout << "myAge: " << myAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    myAge = 33;

    std::cout << "myAge: " << myAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl;


    return a.exec();
}