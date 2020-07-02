#include <QCoreApplication>

#include <iostream>
#include <string>

#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Here is a standard string

    std::string myStdString = "Hello Std!";

    // Here it is displayed using the std character out stream

    std::cout << myStdString << std::endl;

    // Debugging using Std

    std::clog << myStdString << std::endl;

    std::cerr << myStdString << std::endl;

    // Here is a Qt string

    QString myQtString = "Hello Qt!";

    // Here is it is displayed using the std character out stream. Note that since it's not a std::string object, it needs to be converted.

    std::cout << myQtString.toStdString() << std::endl;

    // Debugging using Qt

    qDebug() << myQtString;
    // qDebug(myQtString);

    qWarning() << myQtString;
    //qWarning(myQtString);

    qCritical() << myQtString;
    //qCritical(myQtString);

    return a.exec();
}
