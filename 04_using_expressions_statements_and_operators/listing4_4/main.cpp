#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int grade;

    std::cout << "Enter a grade (1-100): ";
    std::cin >> grade;

    if (grade >= 70)
    {
        if (grade >= 90)
        {
            std::cout << "Congratulations! You got an A." << std::endl;
            return 0;
        }
        if (grade >= 80)
        {
            std::cout << "Good work! You got a B." << std::endl;
            return 0;
        }
        std::cout << "You got a C." << std::endl;
    }
    else
        std::cout << "I'm sorry. You failed." << std::endl;

    return a.exec();
}