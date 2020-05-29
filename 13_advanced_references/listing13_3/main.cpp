#include <QCoreApplication>
#include <iostream>

class Computer
{
public:
    Computer();             // constructor
    Computer(Computer&);    // copy constructor
    ~Computer();            // destructor

    int GetStorage() const;
    void SetStorage(int newStorage);

private:
    int storage;
};

Computer::Computer()
{
    std::cout << "Computer Constructor." << std::endl;

    storage = 20000;

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

int Computer::GetStorage() const
{
    return storage;
}

void Computer::SetStorage(int newStorage)
{
    storage = newStorage;

    return;
}

const Computer & Function2(const Computer &pc);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Creating a desktop computer." << std::endl;

    Computer desktop;

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    desktop.SetStorage(50000);

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    std::cout << "Passing desktop to Function2()" << std::endl;

    Function2(desktop);

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    return a.exec();
}

const Computer & Function2(const Computer &pc)
{
    std::cout << "Function2." << std::endl;

    std::cout << "Computer has " << pc.GetStorage() << " MB's." << std::endl;

    // pc->SetStorage(1000); // Can't do this! const class.

    return pc;
}