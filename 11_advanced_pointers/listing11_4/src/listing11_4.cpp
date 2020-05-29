#include <iostream>

class Cage
{
public:
    Cage();
    ~Cage();

    int GetAnimals() const;
    void SetAnimals(int newAnimals);
    bool GetMood() const;
    void SetMood(bool newMood);


private:
    int animals;
    bool happy;
};

Cage::Cage()
{
    animals = 1;
    happy = true;

    return;
}

Cage::~Cage()
{
    return;
}

int Cage::GetAnimals() const
{
    return this->animals;
}

void Cage::SetAnimals(int newAnimals)
{
    if (newAnimals >= 0)
    {
        this->animals = newAnimals;
    }

    return;
}

bool Cage::GetMood() const
{
    return happy;
}


void Cage::SetMood(bool newMood)
{
    happy = newMood;

    return;
}

int main()
{

    Cage aCage;

    std::cout << "There are " << aCage.GetAnimals() << " animals in the cage." << std::endl;
    std::cout << "The animals are ";
    if(aCage.GetMood())
    {
        std::cout << "happy" << std::endl;
    }
    else
    {
        std::cout << "sad" << std::endl;   
    }    

    aCage.SetAnimals(2);
    aCage.SetMood(false);

    std::cout << "There are " << aCage.GetAnimals() << " animals in the cage." << std::endl;
    std::cout << "The animals are ";
    if(aCage.GetMood())
    {
        std::cout << "happy" << std::endl;
    }
    else
    {
        std::cout << "sad" << std::endl;   
    }    

    return 0;
}