#include <QCoreApplication>
#include <iostream>

class Dog
{
public:
    Dog();
    ~Dog();
    int GetAge() const;
    void SetAge(int newAge);
private:
    int age;
};

Dog::Dog()
{
    age = 1;

    return;
}

Dog::~Dog()
{
    return;
}

int Dog::GetAge() const
{
    return age;
}

void Dog::SetAge(int newAge)
{
    age = newAge;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Dog *myDog = new Dog;

    std::cout << "My dog is " << myDog->GetAge() << " years old." << std::endl;

    myDog->SetAge(10);

    std::cout << "My dog is " << myDog->GetAge() << " years old." << std::endl;

    delete myDog;

    return a.exec();
}
