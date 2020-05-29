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
    void accelerate();
    void accelerate(int acc);

protected:
    int cc;
};

void Vehicle::accelerate()
{
    std::cout << "Vehicle accelerates 1 m/s^2." << std::endl;

    return;
}

void Vehicle::accelerate(int acc)
{
    std::cout << "Vehicle accelerates " << acc << " m/s^2." << std::endl;

    return;
}

class Car : public Vehicle
{
public:
    void accelerate(); // You may receive a warning that you are hiding a function.

protected:
    MANUFACTURER make;
};

void Car::accelerate()
{
    std::cout << "Car accelerates 5 m/s^2." << std::endl;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vehicle myVehicle;

    myVehicle.accelerate();
    myVehicle.accelerate(2);

    Car myCar;

    myCar.accelerate();
    // myCar.accelerate(10);

    return a.exec();
}