#include <QCoreApplication>
#include "string.hpp"

class Student
{
public:
    Student();
    Student(const char*, const char*, int);
    Student(const Student&);
    ~Student();

    Student& operator=(const Student&);

    const String& getFirstName() const { return firstName; }
    void setFirstName(const String& newFirstName) { firstName = newFirstName; }
    const String& getLastName() const { return lastName; }
    void setLastName(const String& newLastName) { lastName = newLastName; }
    int getID() const { return ID; }
    void setID(int newID) { ID = newID; }

private:
    String firstName;
    String lastName;
    int ID;
};

Student::Student() :
firstName(""),
lastName(""),
ID(-1)
{
    return;
}

Student::Student(const char* newFirstName, const char* newLastName, int newID) :
firstName(newFirstName),
lastName(newLastName),
ID(newID)
{
    return;
}

Student::Student(const Student &rhs) :
firstName(rhs.getFirstName()),
lastName(rhs.getLastName()),
ID(rhs.getID())
{
    return;
}

Student::~Student()
{
    return;
}

Student& Student::operator=(const Student& rhs)
{
    if (this == &rhs)
        return *this;

    firstName = rhs.getFirstName();
    lastName = rhs.getLastName();
    ID = rhs.getID();

    return *this;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Student mrBeasly("Rob", "Beasly", 0);

    mrBeasly.setID(1000);

    String firstName("Barry");
    String lastName("Tropper");
    int id(999);

    Student mrTropper;

    mrTropper.setFirstName(firstName);
    mrTropper.setLastName(lastName);
    mrTropper.setID(id);

    std::cout << "Name: " << mrBeasly.getLastName().getString() << ", " << mrBeasly.getFirstName().getString() << std::endl;
    std::cout << "ID: " << mrBeasly.getID() << std::endl;

    std::cout << "Name: " << mrTropper.getLastName().getString() << ", " << mrTropper.getFirstName().getString() << std::endl;
    std::cout << "ID: " << mrTropper.getID() << std::endl;

    return a.exec();
}
