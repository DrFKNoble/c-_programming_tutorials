#include <QCoreApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "There are " << argc << " command line arguments." << std::endl;

    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << std::endl;
        std::cout << argv[i] << std::endl;
    }

    return a.exec();
}
