#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // set up enumeration
    enum Direction  { North, Nortwest, East, Southeast, South, Southwest, West, Northwest };

    // create a variable to hold it
    Direction heading;
    // initalise that variable
    heading = Southeast;

    std::cout << "Moving " << heading << std::endl;

    return a.exec();
}