#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int counter = 0;
    int multiples = 0;

    while (multiples < 19)
    {
        counter++;

        if (counter % 15 != 0)
            continue;

        std::cout << counter << " ";
        multiples++;
    }

    std::cout << std::endl;

    return a.exec();
}