#include <iostream>

void convertFtoC();

float fahrenheit = 0;
float celcius = 0;

int main()
{

    std::cout << "Please enter the temperature in Fahrenheit: ";
    std::cin >> fahrenheit;

    convertFtoC();

    std::cout << fahrenheit << " F is " << celcius << " C";

    return 0;
}

// function to convert temperature expressed in degrees Fahrenheit to degrees Celsius.
void convertFtoC()
{
    celcius = ((fahrenheit - 32) * 5) / 9;

    return;
}