#include <QCoreApplication>
#include <iostream>

enum COLOR
{
    Black,
    White,
    Brown
};

class Animal
{
public:
    Animal(int newAge) : age(newAge) { std::cout << "Animal constructor()." << std::endl; }
    virtual ~Animal() { std::cout << "Animal destructor()." << std::endl; }

    virtual int getAge() const { return age; }
    virtual void setAge(int newAge) { age = newAge; }

    virtual void eat() const = 0;
    virtual void sleep() const = 0;
    virtual void reproduce() const = 0;
    virtual void speak() const = 0;

protected:
    int age;
};

class Mammal : public Animal
{
public:
    Mammal(int newAge) : Animal(newAge) { std::cout << "Mammal constructor()." << std::endl; }
    virtual ~Mammal() { std::cout << "Mammal destructor()." << std::endl; }

    virtual void reproduce() const { std::cout << "Mammal reproduce()." << std::endl; }
};

class Fish : public Animal
{
public:
    Fish(int newAge) : Animal(newAge) { std::cout << "Fish constructor()." << std::endl; }
    virtual ~Fish() { std::cout << "Fish destructor()." << std::endl; }

    virtual void eat() const { std::cout << "Fish eat()." << std::endl; }
    virtual void sleep() const { std::cout << "Fish sleep()." << std::endl; }
    virtual void speak() const {}
    virtual void reproduce() const { std::cout << "Fish reproduce()." << std::endl; }
};

class Dog : public Mammal
{
public:
    Dog(int newAge, COLOR newColor) : Mammal(newAge), color(newColor) { std::cout << "Dog constructor()." << std::endl; }
    virtual ~Dog() { std::cout << "Dog destructor()." << std::endl; }

    virtual COLOR getColor() const { return color; }

    virtual void eat() const { std::cout << "Dog eat()." << std::endl; }
    virtual void sleep() const { std::cout << "Dog sleep()." << std::endl; }
    virtual void speak() const { std::cout << "Woof." << std::endl; }
    virtual void reproduce() const { std::cout << "Dog reproduce()." << std::endl; }

private:
    COLOR color;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool loop = true;
    int choice = 0;
    Animal *pAnimal = nullptr;

    do
    {
        std::cout << "(1) Fish, (2) Dog, (0) Quit: ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pAnimal = new Fish(1);
            break;
        case 2:
            pAnimal = new Dog(2, Black);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
        }

        if (!loop)
            break;

        pAnimal->eat();
        pAnimal->sleep();
        pAnimal->reproduce();
        pAnimal->speak();

        delete pAnimal;
        pAnimal = nullptr;

        std::cout << std::endl;

    } while (loop);

    return a.exec();
}