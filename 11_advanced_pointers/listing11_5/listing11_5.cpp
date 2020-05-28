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

Cage::Cage() : animals(1), happy(true)
{
    return;
}

Cage::~Cage()
{
    return;
}

int Cage::GetAnimals() const
{
    return animals;
}

void Cage::SetAnimals(int newAnimals)
{
    if (newAnimals >= 0)
    {
        animals = newAnimals;
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

    Cage *pCage = new Cage;
    const Cage *pConstCage = new Cage;
    Cage *const pConstPtrCage = new Cage;

    std::cout << "There are " << pCage->GetAnimals() << " animals in pCage" << std::endl;
    std::cout << "There are " << pConstCage->GetAnimals() << " animals in pConstCage" << std::endl;
    std::cout << "There are " << pConstPtrCage->GetAnimals() << " animals in pConstPtrCage" << std::endl;

    pCage->SetAnimals(2);
    // pConstCage->SetAnimals(2); // won't work as pConstCage is a constant object, i.e. it can't be changed.
    pConstPtrCage->SetAnimals(2);

    std::cout << "There are " << pCage->GetAnimals() << " animals in pCage" << std::endl;
    std::cout << "There are " << pConstCage->GetAnimals() << " animals in pConstCage" << std::endl;
    std::cout << "There are " << pConstPtrCage->GetAnimals() << " animals in pConstPtrCage" << std::endl;

    return 0;
}