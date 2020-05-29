#include <iostream>

class Bike
{
public:
    Bike();
    Bike(const Bike &);
    ~Bike();

    int getSpeed() const;
    void setSpeed(int newSpeed);

    void pedal();
    void brake();

private:
    int *speed;
};

Bike::Bike()
{
    speed = new int;
    *speed = 0;

    return;
}

Bike::Bike(const Bike &newBike)
{
    speed = new int;
    *speed = newBike.getSpeed();

    return;
}

Bike::~Bike()
{
    delete speed;
    speed = nullptr;

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

void Bike::pedal()
{
    *speed += 1;

    std::cout << "Pedaling. Speed is now " << getSpeed() << " m/s" << std::endl;

    return;
}

void Bike::brake()
{
    if (*speed > 0)
    {
        *speed -= 1;
    }

    std::cout << "Braking. Speed is now " << getSpeed() << " m/s" << std::endl;

    return;
}

int main()
{

    std::cout << "Creating myBike" << std::endl;
    Bike myBike;

    myBike.pedal();

    std::cout << "Creating yourBike" << std::endl;
    Bike yourBike(myBike);

    std::cout << "My bike's speed: " << myBike.getSpeed() << std::endl;
    std::cout << "Your bike's speed: " << yourBike.getSpeed() << std::endl;

    std::cout << "Setting myBike speed to 5 m/s" << std::endl;
    myBike.setSpeed(5);

    std::cout << "My bike's speed: " << myBike.getSpeed() << std::endl;
    std::cout << "Your bike's speed: " << yourBike.getSpeed() << std::endl;

    return 0;
}