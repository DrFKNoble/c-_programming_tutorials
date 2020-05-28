#include <iostream>

class Bike
{
public:
    Bike(int initialSpeed);
    ~Bike();
    int getSpeed() const
    {
        return speed;
    }
    void setSpeed(int newSpeed)
    {
        if (newSpeed >= 0)
        {
            speed = newSpeed;
        }

        return;
    }
    void pedal();
    void brake();

private:
    int speed;
};