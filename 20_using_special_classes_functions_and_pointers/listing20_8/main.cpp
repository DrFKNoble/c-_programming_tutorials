#include <QCoreApplication>
#include <iostream>

class Mammal
{
public:
    Mammal() : age(1) {}
    virtual ~Mammal() {}

    virtual void speak() const = 0;
    virtual void move() const = 0;

protected:
    int age;
};

class Dog : public Mammal
{
public:
    Dog() {}
    ~Dog() {}

    void speak() const { std::cout << "Woof." << std::endl; }
    void move() const { std::cout << "The dog runs." << std::endl; }
};

class Cat : public Mammal
{
public:
    Cat() {}
    ~Cat() {}

    void speak() const { std::cout << "Meow." << std::endl; }
    void move() const { std::cout << "The cat prowls." << std::endl; }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void (Mammal::*pFunc)() const = 0;

    Mammal *pMammal = nullptr;
    int animal;
    int method;
    bool loop = true;

    while (loop)
    {
        std::cout << "(0) Quit, (1) Dog, or (2) Cat: ";
        std::cin >> animal;

        switch (animal)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pMammal = new Dog;
            break;
        case 2:
            pMammal = new Cat;
            break;
        default:
            loop = false;
            break;
        }

        if (!loop)
            break;

        std::cout << "(1) Speak, or (2) Move: ";
        std::cin >> method;

        switch (method)
        {
        case 1:
            pFunc = &Mammal::speak;
            break;
        case 2:
            pFunc = &Mammal::move;
            break;
        }

        (pMammal->*pFunc)();
        delete pMammal;

    }

    return a.exec();
}