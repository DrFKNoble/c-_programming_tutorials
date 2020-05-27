#include <iostream>

class Computer
{
public:
    Computer();             // constructor
    Computer(Computer&);    // copy constructor
    ~Computer();            // destructor
};

Computer::Computer()
{
    std::cout << "Computer Constructor." << std::endl;

    return;
}

Computer::Computer(Computer&)
{
    std::cout << "Computer Copy Constructor." << std::endl;

    return;
}

Computer::~Computer()
{
    std::cout << "Computer Destructor." << std::endl;

    return;
}

Computer Function1(Computer pc);
Computer* Function2(Computer *pc);

int main()
{

    std::cout << "Creating a desktop computer." << std::endl;

    Computer desktop;

    std::cout << "Passing desktop to Function1()" << std::endl;

    Function1(desktop);

    std::cout << "Passing desktop to Function2()" << std::endl;

    Function2(&desktop);

    return 0;
}

Computer Function1(Computer pc) 
{
    std::cout << "Function1." << std::endl;

    return pc;
}

Computer* Function2(Computer *pc) 
{
    std::cout << "Function2." << std::endl;

    return pc;
}