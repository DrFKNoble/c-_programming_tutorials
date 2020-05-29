#include <QCoreApplication>
#include <iostream>

class Dog
{
public:
    Dog() {}
    ~Dog() {}

    void speak() const { std::cout << "Woof." << std::endl; }
    void move() const { std::cout << "The dog runs." << std::endl; }
    void eat() const { std::cout << "Nom nom nom." << std::endl; }
    void growl() const { std::cout << "Grrrr." << std::endl; }
};

typedef void (Dog::*PDF)() const;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int maxFunctions = 4;

    PDF dogFunctions[maxFunctions] =
    {
        &Dog::speak,
        &Dog::move,
        &Dog::eat,
        &Dog::growl
    };

    Dog *pDog = nullptr;
    int method = 0;
    bool loop = true;

    while(loop)
    {
        std::cout << "(0) Quit, (1) Speak, (2) Move, (3) Eat, or (4) Growl: ";
        std::cin >> method;

        if (method == 0)
        {
            loop = false;
        }
        else
        {
            pDog = new Dog;
            (pDog->*dogFunctions[method-1])();
            delete pDog;
        }

        if (!loop)
            break;

    }

    return a.exec();
}
