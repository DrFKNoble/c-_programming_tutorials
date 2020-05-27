#include <iostream>

int main()
{
    int counter = 0;
    int multiples = 0;

    while (true)
    {
        counter++;

        if (counter % 14 == 0)
        {
            std::cout << counter << " ";
            multiples++;
        }
        if (multiples > 19)
            break;
    }

    std::cout << std::endl;

    return 0;
}