#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char name[50];
    char quest[50];
    char velocity[50];

    std::cout << "What, is your name? ";
    std::cin.getline(name, 49);

    std::cout << "What, is your quest? ";
    std::cin.getline(quest, 49);

    std::cout << "What, is the velocity of an unladen swallow? ";
    std::cin.getline(velocity, 49);

    return a.exec();
}
