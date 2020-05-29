#include <QCoreApplication>
#include <iostream>
#include <string>

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

Vehicle::Vehicle() : wheels(2)
{
    std::cout << "Vehicle constructor." << std::endl;

    return;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle destructor." << std::endl;

    return;
}

int Vehicle::getWheels() const
{
    return wheels;
}

void Vehicle::setWheels(int newWheels)
{
    wheels = newWheels;

    return;
}

class Car : public Vehicle
{
public:
    Car();
    ~Car();

    std::string getMake() const;
    void setMake(MANUFACTURER newMake);

    int getCC() const;
    void setCC(int newCC);

protected:
    int cc;
    MANUFACTURER make;
};

Car::Car() : cc(1000), make(Nissan)
{
    std::cout << "Car constructor." << std::endl;

    return;
}

Car::~Car()
{
    std::cout << "Car destructor." << std::endl;

    return;
}

std::string Car::getMake() const
{
    switch (make)
    {
    case 0:
        return "Nissan";
        break;
    case 1:
        return "Toyota";
        break;
    default:
        break;
    }

    return "Other";
}

void Car::setMake(MANUFACTURER newMake)
{
    make = newMake;
}

int Car::getCC() const
{
    return cc;
}

void Car::setCC(int newCC)
{
    cc = newCC;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Car myCar;

    std::cout << "myCar is made by " << myCar.getMake();
    std::cout << ", has " << myCar.getWheels() << " wheels and a " << myCar.getCC() << " cc sized engine." << std::endl;

    return a.exec();
}
