#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int year = 2019;

    std::cout << "The year " << ++year << " passes" << std::endl;
    std::cout << "The year " << ++year << " passes" << std::endl;
    std::cout << "The year " << ++year << " passes" << std::endl;

    std::cout << "It is now: " << year << std::endl;

    std::cout << "The year " << year++ << " passes" << std::endl;
    std::cout << "The year " << year++ << " passes" << std::endl;
    std::cout << "The year " << year++ << " passes" << std::endl;

    std::cout << "It is now: " << year << std::endl;

    return a.exec();
}
