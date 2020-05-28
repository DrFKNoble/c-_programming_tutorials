#include <iostream>

int main()
{
    int rows = 0, columns = 0;
    char character = 0;

    std::cout << "How many rows? ";
    std::cin >> rows;

    std::cout << "How many columns? ";
    std::cin >> columns;

    std::cout << "What character to display? ";
    std::cin >> character;

    std::cout << std::endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << character;
        }
        
        std::cout << std::endl;

    }

    std::cout << std::endl;

    return 0;
}