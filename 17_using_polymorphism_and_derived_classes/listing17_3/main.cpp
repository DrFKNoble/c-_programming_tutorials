#include <QCoreApplication>
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

void valueFunction(Mammal);
void ptrFunction(Mammal *);
void refFunction(Mammal &);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mammal *ptr = nullptr;
       bool loop = true;

       while (loop)
       {
           int choice = 0;

           std::cout << "(1) Dog, (2) Cat, (0) Quit: ";
           std::cin >> choice;

           switch (choice)
           {
           case 0:
               loop = false;
               break;
           case 1:
               ptr = new Dog;
               break;
           case 2:
               ptr = new Cat;
               break;
           default:
               break;
           }

           ptrFunction(ptr);
           refFunction(*ptr);
           valueFunction(*ptr);
       }

    return a.exec();
}

void valueFunction(Mammal vMammal)
{
    vMammal.speak();

    return;
}

void ptrFunction(Mammal *pMammal)
{
    pMammal->speak();

    return;
}

void refFunction(Mammal &rMammal)
{
    rMammal.speak();

    return;
}