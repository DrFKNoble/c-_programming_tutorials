#include <QCoreApplication>
#include <iostream>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    Vehicle();
    ~Vehicle();

    int getWheels() const;
    void setWheels(int newWheels);

protected:
    int wheels;
};

class Car : public Vehicle
{
public:
    Car();
    ~Car();

    int getCC() const;
    void setCC(int newCC);

protected:
    int cc;
    MANUFACTURER make;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
