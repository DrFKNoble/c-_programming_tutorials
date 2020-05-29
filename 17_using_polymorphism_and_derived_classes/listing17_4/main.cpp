#include <QCoreApplication>
#include <iostream>

class Mammal
{
public:
    Mammal();
    virtual ~Mammal();
    Mammal(const Mammal &rhs);
    virtual Mammal *clone();

    int getAge() const;
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

Mammal::Mammal(const Mammal &rhs) : age(rhs.getAge())
{
    std::cout << "Mammal() copy constructor." << std::endl;

    return;
}

Mammal *Mammal::clone()
{
    return new Mammal(*this);
}

int Mammal::getAge() const
{
    return age;
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
    virtual ~Dog();
    Dog(const Dog &rhs);
    virtual Mammal *clone();

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

Dog::Dog(const Dog &rhs) : Mammal(rhs)
{
    std::cout << "Dog() copy constructor." << std::endl;

    return;
}

Mammal *Dog::clone()
{
    return new Dog(*this);
}

void Dog::speak() const
{
    std::cout << "Woof woof." << std::endl;

    return;
}

class Cat : public Mammal
{
public:
    Cat();
    virtual ~Cat();
    Cat(const Cat &rhs);
    virtual Mammal *clone();

    void speak() const;
};

Cat::Cat()
{
    std::cout << "Cat() constructor." << std::endl;

    return;
}

Cat::~Cat()
{
    std::cout << "Cat() destructor." << std::endl;

    return;
}

Cat::Cat(const Cat &rhs) : Mammal(rhs)
{
    std::cout << "Cat() copy constructor." << std::endl;

    return;
}

Mammal *Cat::clone()
{
    return new Cat(*this);
}

void Cat::speak() const
{
    std::cout << "Meow meow." << std::endl;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mammal *array[3];
    Mammal *ptr;

    int choice, i;

    for (i = 0; i < 3; i++)
    {
        std::cout << "(1) Dog, (2) Cat, (3) Other: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ptr = new Dog;
            break;
        case 2:
            ptr = new Cat;
            break;
        case 3:
            ptr = new Mammal;
            break;
        default:
            break;
        }

        array[i] = ptr;
    }

    Mammal *otherArray[3];

    for (i = 0; i < 3; i++)
    {
        array[i]->speak();
        otherArray[i] = array[i]->clone();
    }

    for (i = 0; i < 3; i++)
    {
        otherArray[i]->speak();
    }

    return a.exec();
}
