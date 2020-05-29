#include <QCoreApplication>
#include <iostream>

constexpr double getPi()
{
    return (double) 22/7;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    float radius;

    std::cout << "Enter the radius of a circle (cm): ";
    std::cin >> radius;

    double area = getPi() * radius * radius;

    std::cout << "The area of the circle is: " << area << " cm^2" << std::endl;

    return a.exec();
}