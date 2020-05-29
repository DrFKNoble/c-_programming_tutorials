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
    ~Car();

    std::string getMake() const;
    void setMake(MANUFACTURER newMake);

    int getCC() const;
    void setCC(int newCC);

    int getWheels() const;

protected:
    int cc;
    MANUFACTURER make;
};

Car::Car() : Vehicle(4), cc(1000), make(Nissan)
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

int Car::getWheels() const
{
    int tempWheels = wheels;

    return ++tempWheels;
}

int main()
{
    Car myCar1;

    std::cout << "myCar1 is a " << myCar1.getMake();
    std::cout << " and it has " << myCar1.getWheels() << " wheels and a " << myCar1.getCC() << " cc sized engine." << std::endl;

    return 0;
}