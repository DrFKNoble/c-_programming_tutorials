#include <QCoreApplication>
#include <iostream>

class Bike
{
public:
    Bike();
    ~Bike();

    int getSpeed() const;
    void setSpeed(int newSpeed);

    Bike operator=(const Bike&);

private:
    int *speed;
};

Bike::Bike()
{
    speed = new int;

    *speed = 0;

    return;
}

Bike::~Bike()
{
    return;
}

int Bike::getSpeed() const
{
    return *speed;
}

void Bike::setSpeed(int newSpeed)
{
    *speed = newSpeed;

    return;
}

Bike Bike::operator=(const Bike& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    delete speed;
    speed = new int;

    *speed = rhs.getSpeed();

    return *this;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bike myBike;
    std::cout << "myBike's speed: " << myBike.getSpeed() << " m/s" << std::endl;

    std::cout << "Setting myBike's speed to 5 m/s." <<std::endl;
    myBike.setSpeed(5);
    std::cout << "myBike's speed: " << myBike.getSpeed() << " m/s" << std::endl;

    Bike yourBike;
    std::cout << "yourBike's speed: " << yourBike.getSpeed() << " m/s" << std::endl;

    std::cout << "Copying myBike to yourBike." << std::endl;
    yourBike = myBike;

    std::cout << "myBike's speed: " << myBike.getSpeed() << " m/s" << std::endl;
    std::cout << "yourBike's speed: " << yourBike.getSpeed() << " m/s" << std::endl;

    return a.exec();
}