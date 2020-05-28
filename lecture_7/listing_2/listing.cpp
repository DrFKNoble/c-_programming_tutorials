#include <iostream>

int main()
{
    int mulArray[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) {
            
            std::cout << "mulArray[" << i << "]";
            std::cout << "[" << j << "]";
            std::cout << " = " << mulArray[i][j] << std::endl;

        }
    }

    std::cout << std::endl;

    return 0;
}