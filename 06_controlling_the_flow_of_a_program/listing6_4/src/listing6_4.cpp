#include <iostream>

int main()
{
    int badger = 0;

    std::cout << "How many badgers are there? ";
    std::cin >> badger;

    do
    {
        std::cout << "Badger" << std::endl;
        badger--;
    } while(badger > 0);

    std::cout << std::endl;

    return 0;
}

// as an aside, have a look at https://www.youtube.com/watch?v=EIyixC9NsLI.