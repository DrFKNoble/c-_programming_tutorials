#include <QCoreApplication>
#include <iostream>

class Bike
{
public:
    int getSpeed();
    void setSpeed(int);
    void pedal();
    void brake();
private:
    int speed;
};

int Bike::getSpeed()
{
    return speed;
}

void Bike::setSpeed(int newSpeed)
{
    if (newSpeed > 0)
    {
        speed = newSpeed;
    }

    return;
}

void Bike::pedal()
{
    setSpeed(speed + 1);
    std::cout << "Pedaling. Speed: " << speed << " m/s" << std::endl;

    return;
}

void Bike::brake()
{
    setSpeed(speed - 1);
    std::cout << "Braking. Speed: " << speed << " m/s" << std::endl;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bike myBike;

    myBike.setSpeed(0);
    myBike.pedal();
    myBike.pedal();
    myBike.pedal();
    myBike.brake();

    return a.exec();
}