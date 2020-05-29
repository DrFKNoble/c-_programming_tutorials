#include <QCoreApplication>
#include <iostream>

class Dog
{
public:
    Dog();
    ~Dog();

private:
    int age;
};

Dog::Dog()
{
    std::cout << "Constructor called." << std::endl;
    age = 1;

    return;
}

Dog::~Dog()
{
    std::cout << "Destructor called." << std::endl;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Dog myFirstDog;" << std::endl;
    Dog myFirstDog;

    std::cout << "Dog *mySecondDog = new Dog;" << std::endl;
    Dog *mySecondDog = new Dog;

    std::cout << "delete mySecondDog" << std::endl;
    delete mySecondDog;

    std::cout << "myFirstDog" << std::endl;

    return a.exec();
}
