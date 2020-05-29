#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int production [] = {1000, 2000, 3000, 4000};

    for(auto element : production)
    {
        std::cout << "Production: " << element << std::endl;
    }

    std::cout << std::endl;

    return a.exec();
}
