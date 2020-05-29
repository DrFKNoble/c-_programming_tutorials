#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number = 0;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "First 10 multiples of " << number << " are: ";

    for (int i = number; i <= 10*number; i += number)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return a.exec();
}
