#include <iostream>

int main()
{
    int year = 2019;
    
    std::cout << "The year " << ++year << " passes" << std::endl;
    std::cout << "The year " << ++year << " passes" << std::endl;
    std::cout << "The year " << ++year << " passes" << std::endl;

    std::cout << "It is now: " << year << std::endl;

    std::cout << "The year " << year++ << " passes" << std::endl;
    std::cout << "The year " << year++ << " passes" << std::endl;
    std::cout << "The year " << year++ << " passes" << std::endl;

    std::cout << "It is now: " << year << std::endl;

    return 0;
}