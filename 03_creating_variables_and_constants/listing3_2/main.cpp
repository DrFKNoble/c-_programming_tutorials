#include <iostream>

int main(int argc, char *argv[])
{
    // set up width and length
    unsigned short width = 26, length;
    length = 40;

    // create an unsigned short initialised with the
    // result of multiplying width by length
    unsigned short area = width * length;

    std::cout << "Width: " << width << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}
