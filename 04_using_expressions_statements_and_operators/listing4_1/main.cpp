#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x = 12, y = 42, z = 88;

    std::cout << "Before -- x: " << x << " y: " << y << " z: " << z << std::endl;

    z = x = y + 13;

    std::cout << "After -- x: " << x << " y: " << y << " z: " << z << std::endl;


    return a.exec();
}