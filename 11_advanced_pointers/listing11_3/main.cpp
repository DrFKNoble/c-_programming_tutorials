#include <QCoreApplication>
#include <iostream>

class Dog
{
public:
    Dog();
    ~Dog();

    int GetAge() const;
    void SetAge(int newAge);
    int GetWeight() const;
    void SetWeight(int newWeight);
private:
    int *age;
    int *weight;
};

Dog::Dog()
{
    age = new int;
    weight = new int;

    *age = 5;
    *weight = 5;
}

Dog::~Dog()
{
    delete age;
    delete weight;
}

int Dog::GetAge() const
{
    return *age;
}

void Dog::SetAge(int newAge)
{
    *age = newAge;

    return;
}

int Dog::GetWeight() const
{
    return *weight;
}

void Dog::SetWeight(int newWeight)
{
    *weight = newWeight;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Dog *myDog = new Dog;

    std::cout << "My dog is " << myDog->GetAge() << " years old." << std::endl;

    myDog->SetWeight(7);

    std::cout << "My dog weighs " << myDog->GetWeight() << " kgs." << std::endl;

    delete myDog;


    return a.exec();
}