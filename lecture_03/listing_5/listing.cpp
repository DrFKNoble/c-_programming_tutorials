#include <iostream>

int main()
{
    //define character values
    auto strength = 80;
    auto accuracy = 45.5;
    auto dexterity = 24.0;

    // define constants
    const auto MAXIMUM = 50;

    // calculate character combat stats
    auto attack = strength * (accuracy / MAXIMUM);
    auto damage = strength * (dexterity / MAXIMUM);

    std::cout << "Attack rating: " << attack << std::endl;
    std::cout << "Damage rating: " << damage << std::endl;

    return 0;
}