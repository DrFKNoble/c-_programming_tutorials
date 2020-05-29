#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char grade = 0;

    std::cout << "Enter your letter grade (A,B,C,D,E,F): ";
    std::cin >> grade;

    switch (grade)
    {
        case 'A':
            std::cout << "Fantastic!";
            break;
        case 'B':
            std::cout << "Great!";
            break;
        case 'C':
            std::cout << "Keep it up.";
            break;
        case 'D':
            std::cout << "I know you can do it.";
            break;
        case 'E':
            std::cout << "I belive in you.";
            break;
        case 'F':
            std::cout << "Have another go. I'm sure you'll do better next time!";
            break;
        default:
            std::cout << "Not an accepted letter grade.";
            break;
    }

    std::cout << std::endl;

    return a.exec();
}
