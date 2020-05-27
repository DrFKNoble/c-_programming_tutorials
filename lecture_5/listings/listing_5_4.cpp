#include <iostream>

bool isLeapYear(int year);

int main()
{

    int input = 0;

    std::cout << "Enter a year: ";
    std::cin >> input;

    if (isLeapYear(input))
        std::cout << input << " is a leap year." << std::endl;
    else
        std::cout << input << " is not a leap year." << std::endl;

    return 0;
}

bool isLeapYear(int year)
{
    
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;

}