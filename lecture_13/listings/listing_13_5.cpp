#include <iostream>

class Computer
{
public:
    Computer();
    ~Computer();

    int GetStorage() const;
    void SetStorage(int newStorage);

private:
    int storage;
};

Computer::Computer()
{
    storage = 10000;

    return;
}

Computer::~Computer()
{
    return;
}

int Computer::GetStorage() const
{
    return storage;
}

void Computer::SetStorage(int newStorage)
{
    storage = newStorage;

    return;
}

Computer & BadFunction();

int main()
{
    Computer &rDesktop = BadFunction();

    std::cout << "Computer has " << rDesktop.GetStorage() << "MB's." << std::endl;

    return 0;
}

Computer & BadFunction()
{
    Computer *pLocalDesktop = new Computer;

    return *pLocalDesktop;
}