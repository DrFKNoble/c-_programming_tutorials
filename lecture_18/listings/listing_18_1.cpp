#include <iostream>

class Mammal
{
public:
    Mammal() : age(1) { std::cout << "Mammal constructor()." << std::endl; }
    virtual ~Mammal() { std::cout << "Mammal destructor()." << std::endl; }

    virtual void speak() const { std::cout << "Mammal speak()." << std::endl; }
protected:
    int age;
};

class Dog : public Mammal
{
public:
    Dog() { std::cout << "Dog constructor()." << std::endl; }
    ~Dog() { std::cout << "Dog destructor()." << std::endl; }

    void speak() const { std::cout << "Woof." << std::endl; }
};

int main()
{

    Mammal *pDog = new Dog;

    pDog->speak();

    delete pDog;
    pDog = nullptr;

    return 0;
}