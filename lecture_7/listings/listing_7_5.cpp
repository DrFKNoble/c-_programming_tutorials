#include <iostream>

int main()
{
    int production [] = {1000, 2000, 3000, 4000};
    
    for(auto element : production) 
    {
        std::cout << "Production: " << element << std::endl;
    }

    std::cout << std::endl;

    return 0;
}