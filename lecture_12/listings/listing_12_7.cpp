#include <iostream>

enum ERROR_CODE { SUCCESS, ERROR };

ERROR_CODE addMul(const int &in1, const int &in2, int *sum, int *prod);

int main()
{

    int a = 0, b = 0, sum = 0, prod = 0;

    std::cout << "Enter a positive number (> 0): ";
    std::cin >> a;
    std::cout << "Enter a positive number (> 0): ";
    std::cin >> b;

    if(addMul(a, b, &sum, &prod) == SUCCESS)
    {
        std::cout << "a + b = " << sum << std::endl;
        std::cout << "a * b = " << prod << std::endl;
    }
    else
    {
        std::cout << "Error: numbers must be positive (> 0)." << std::endl;
    }

    return 0;
}

ERROR_CODE addMul(const int &in1, const int &in2, int *sum, int *prod)
{
    if (in1 > 0 && in2 > 0)
    {
        *sum = in1 + in2;
        *prod = in1 * in2;

        return SUCCESS;
    }
    else
    {
        *sum = 0;
        *prod = 0;

        return ERROR;        
    }
  
}