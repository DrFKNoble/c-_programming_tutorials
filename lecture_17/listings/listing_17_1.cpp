#include <iostream>

class Mammal
{
public:
    Mammal();
    ~Mammal();

    void move() const;

    virtual void speak() const;

protected:
    int age;
};

Mammal::Mammal() : age(1)
{
    std::cout << "Mammal() constructor." << std::endl;

    return;
}

Mammal::~Mammal()
{
    std::cout << "Mammal() destructor." << std::endl;

    return;
}

void Mammal::move() const
{
    std::cout << "Mammal, move 1 step." << std::endl;

    return;
}

void Mammal::speak() const
{
    std::cout << "Mammal, speak." << std::endl;

    return;
}

class Dog : public Mammal
{
public:
    Dog();
    ~Dog();

    void move() const;

    void speak() const;
};

Dog::Dog()
{
    std::cout << "Dog() constructor." << std::endl;

    return;
}

Dog::~Dog()
{
    std::cout << "Dog() destructor." << std::endl;

    return;
}

void Dog::move() const
{
    std::cout << "Dog, move 1 step." << std::endl;

    return;
}

void Dog::speak() const
{
    std::cout << "Woof woof." << std::endl;

    return;
}

int main()
{
    Mammal *pDog = new Dog;

    pDog->move();
    pDog->speak();
    
    return 0;
}