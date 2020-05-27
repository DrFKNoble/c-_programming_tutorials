#include <iostream>

int main()
{
    // set up enumeration
    enum Direction  { North, Nortwest, East, Southeast, South, Southwest, West, Northwest };

    // create a variable to hold it
    Direction heading;
    // initalise that variable
    heading = Southeast;

    std::cout << "Moving " << heading << std::endl;
    
    return 0;
}