#include <iostream>

float convertFtoC(float fahrenheit);

int main()
{

    float fahrenheit = 0;
    float celcius = 0;

    std::cout << "Please enter the temperature in Fahrenheit: ";
    std::cin >> fahrenheit;

    celcius = convertFtoC(fahrenheit);

    std::cout << fahrenheit << " F is " << celcius << " C";

    return 0;
}

// function to convert temperature expressed in degrees Fahrenheit to degrees Celsius.
float convertFtoC(float fahrenheit)
{
    float celcius = 0;

    celcius = ((fahrenheit - 32) * 5) / 9;

    return celcius;
}