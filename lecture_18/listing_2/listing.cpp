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
    void growl() const { std::cout << "Grrrr." << std::endl; }
};

class Cat : public Mammal
{
public:
    Cat() { std::cout << "Cat constructor()." << std::endl; }
    ~Cat() { std::cout << "Cat destructor()." << std::endl; }

    void speak() const { std::cout << "Meow." << std::endl; }
    void purr() const { std::cout << "Purrr." << std::endl; }
};

int main()
{
    Mammal *zoo[3];
    Mammal *pMammal;
    int choice, i;

    for (i = 0; i < 2; i++)
    {
        std::cout << "(1) Dog, (2) cat: ";
        std::cin >> choice;

        switch(choice)
        {
        case 1:
            pMammal = new Dog;
            break;
        case 2:
            pMammal = new Cat;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
        }

        zoo[i] = pMammal;
    }

    std::cout << std::endl;

    for (i = 0; i < 2; i++)
    {
        zoo[i]->speak();

        Cat *pRealCat = dynamic_cast<Cat *> (zoo[i]);

        if (pRealCat)
            pRealCat->purr();
        else
            std::cout << "Not a cat." << std::endl;

        delete zoo[i];
        zoo[i] = nullptr;

        std::cout << std::endl;
    }
  
    return 0;
}