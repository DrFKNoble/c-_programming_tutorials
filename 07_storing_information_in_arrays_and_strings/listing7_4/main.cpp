#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char literal[] = "She's a witch!";
    char buffer[80];

    strcpy_s(buffer, literal);

    std::cout << "Literal: " << literal << std::endl;
    std::cout << "Buffer: " << buffer << std::endl;

    return a.exec();
}
