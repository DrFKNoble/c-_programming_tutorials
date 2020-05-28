#include <iostream>

class Mammal
{
public:
    Mammal() : age(1) {}
    ~Mammal() {}

    virtual void speak() const;

protected:
    int age;
};

void Mammal::speak() const
{
    std::cout << "Mammal, speak." << std::endl;

    return;
}

class Dog : public Mammal
{
public:
    Dog() {}
    ~Dog() {}

    void speak() const;
};

void Dog::speak() const
{
    std::cout << "Woof woof." << std::endl;

    return;
}

class Cat : public Mammal
{
public:
    Cat() {}
    ~Cat() {}

    void speak() const;
};

void Cat::speak() const
{
    std::cout << "Meow meow." << std::endl;

    return;
}

int main()
{
    Mammal *array[2];
    Mammal *ptr;
    int choice, i;

    for (i = 0; i < 2; i++)
    {
        std::cout << "(1) Dog, (2) Cat: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ptr = new Dog;
            break;
        case 2:
            ptr = new Cat;
            break;
        default:
            ptr = nullptr;
            break;
        }

        array[i] = ptr;
    }

    for (i = 0; i < 2; i++)
    {
        array[i]->speak();
    }

    return 0;
}