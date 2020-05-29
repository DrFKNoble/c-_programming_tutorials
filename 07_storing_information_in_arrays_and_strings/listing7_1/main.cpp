#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    float goal[4];

    goal[0] = 0.9;
    goal[1] = 0.75;
    goal[2] = 0.5;
    goal[3] = 0.25;

    float weight, target;

    std::cout << "Enter current weight (kg): ";
    std::cin >> weight;

    std::cout << "Enter target weight (kg): ";
    std::cin >> target;

    for (int i = 0; i < 4; i++)
    {
        float loss = (weight - target) * goal[i];
        std::cout << "Goal " << i << ": " << target + loss << std::endl;
    }

    return a.exec();
}