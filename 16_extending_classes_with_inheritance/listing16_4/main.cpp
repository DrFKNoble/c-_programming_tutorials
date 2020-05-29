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
    Vehicle(int initialWheels);
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

Vehicle::Vehicle(int initialWheels) : wheels(initialWheels)
{
    std::cout << "Vehicle(int) constructor." << std::endl;

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
    Car(int initialWheels);
    Car(int initialWheels, int initialCC);
    Car(int initialWheels, int initialCC, MANUFACTURER initialMake);
    ~Car();

    std::string getMake() const;
    void setMake(MANUFACTURER newMake);

    int getCC() const;
    void setCC(int newCC);

protected:
    int cc;
    MANUFACTURER make;
};

Car::Car() : Vehicle(4), cc(1000), make(Nissan)
{
    std::cout << "Car constructor." << std::endl;

    return;
}

Car::Car(int initialWheels) : Vehicle(initialWheels), cc(1000), make(Nissan)
{
    std::cout << "Car(int) constructor." << std::endl;

    return;
}

Car::Car(int initialWheels, int initialCC) : Vehicle(initialWheels), cc(initialCC), make(Nissan)
{
    std::cout << "Car(int, int) constructor." << std::endl;

    return;
}

Car::Car(int initialWheels, int initialCC, MANUFACTURER initialMake) : Vehicle(initialWheels), cc(initialCC), make(initialMake)
{
    std::cout << "Car(int, int, MANUFACTURER) constructor." << std::endl;

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

    return "None";
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

    Car myCar1;
    Car myCar2(3, 1500);
    Car myCar3(4, 2000, Toyota);

    std::cout << "myCar1 is a " << myCar1.getMake();
    std::cout << " and it has " << myCar1.getWheels() << " wheels and a " << myCar1.getCC() << " cc sized engine." << std::endl;
    std::cout << "myCar2 is a " << myCar2.getMake();
    std::cout << " and it has " << myCar2.getWheels() << " wheels and a " << myCar2.getCC() << " cc sized engine." << std::endl;
    std::cout << "myCar3 is a " << myCar3.getMake();
    std::cout << " and it has " << myCar3.getWheels() << " wheels and a " << myCar3.getCC() << " cc sized engine." << std::endl;

    return a.exec();
}