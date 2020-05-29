#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int counter = 0;

    while (counter < 500)
    {
        counter++;

        if (counter % 13 == 0)
        {
            std::cout << counter << " ";
        }
    }

    std::cout << std::endl;

    return a.exec();
}