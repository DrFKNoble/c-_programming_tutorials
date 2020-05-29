# Lecture 20: Using Special Classes, Functions, and Pointers

## What You'll Learn in this Lecture:

* What static member variables and static member functions are
* How to use static member variables and static member functions
* What friend functions and friend classes are
* How to use friend functions to solve special problems
* How to use pointers to member functions

## Static Member Data

Typically, an object owns its own data. For example, a `Dog`'s `age` is unique to each instance of that object. The `age` of `myDog` does not affect `yourDog`'s `age`.

Sometimes, however, you'll want to track information shared among many objects of a class. For example, you may want to keep track of how many `Dog` objects have been created and how many are still in existence.

Unlike other member variables, `static` member variables are shared among all instances of a class. They occupy the middle ground between global data and member data.

A static member can be thought of as belonging to the class, rather than to the object. Normal member data is one per object, but static members are one per class.

Listing 20.1's program demonstrates how a static variable can be used.

### Listing 20.1 The Full Text of listing20_1's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Student
{
public:
    Student(int newID) : ID(newID) { howManyStudents++; }
    virtual ~Student() { howManyStudents--; }

    virtual int getID() const { return ID; }
    virtual void setID(int newID) { ID = newID; }

    static int howManyStudents;

private:
    int ID;
};

int Student::howManyStudents = 0;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int maxStudents = 2;
    Student* course[maxStudents];
    int i;

    for (i = 0; i < maxStudents; i++)
    {
        course[i] = new Student(i);
    }

    for(auto s : course)
    {
        std::cout << "There are ";
        std::cout << Student::howManyStudents;
        std::cout << " in the course." << std::endl;

        std::cout << "Removing Student ";
        std::cout << s->getID() << "." << std::endl;

        delete s;
        s = nullptr;

    }

    std::cout << "There are ";
    std::cout << Student::howManyStudents;
    std::cout << " in the course." << std::endl;

    return a.exec();
}
```

When compiled and run, Listing 20.1's program produces the following output:

```Console
There are 2 in the course.
Removing Student 0.
There are 1 in the course.
Removing Student 1.
There are 0 in the course.
```

Here, a class `Student` is declared on lines 3-16. It has a public overloaded constructor and a public virtual destructor; two public virtual accessors, `getID()` and `setID()`; and one static variable, an `int` named `howManyStudents`. The class has one private variable, an `int` named ID. The constructor and destructor are defined inline and increment and decrement the static variable, respectively. `getID()` and `setID()` are also defined inline and get and set the private variable, respectively. 

The declaration of `howManyStudents` does not define an integer; no storage space is set aside for it. Unlike non-static member variables, no storage space is set aside for static members as a result of instantiating a `Student` object, because `howManyStudents` is not in the object. Therefore, it is defined and initialised on line 18.

Note, it is a common mistake to forget to define and initialise static member variables of a class. It is not necessary to do this for `ID` because it is a non-static member variable and defined each time a `Student` object is created.

On lines 23-25, a constant integer, an array of pointers to `Student` objects, and an integer are declared. These define the maximum number of objects stored in the array, and track the iterations of subsequent loops.

On lines 27-30, a `for` loop creates a new `Student` object and assigns its address to the array's corresponding index. Each time a new object is created, the object's constructor increments the static variable `howManyStudents`'s value.

On lines 32-44, a second `for` loop iterates over the array, displaying `howManyStudents`'s value before deleting the object pointed to by the array's corresponding index. Each time an object is deleted, the object's destructor decrements the static variable's value.

On lines 46-48, `main()` displays the remaining number of students in the class. Given two students were added and then two removed, there are zero objects pointed to left in the array.

Note that `howManyStudents` is public and is accessed directly via `main()`. It is preferable to make it private and provide a public accessor, as long as you always will access the data through an instance of `Student`. If you want to access this data directly, without necessarily having a `Student` object available, you have two options: 1) keep it public, or 2) use a static member function.

## Static Member Functions

Static member functions are like static member variables: they exist not in an object, but in the scope of the class. Therefore, they can be called without having an object of that class.

Listing 20.2's program demonstrates how a static member function can be used.

### Listing 20.2 The Full Text of listing20_2's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Student
{
public:
    Student(int newID) : ID(newID) { howManyStudents++; }
    virtual ~Student() { howManyStudents--; }

    virtual int getID() const { return ID; }
    virtual void setID(int newID) { ID = newID; }

    static int getClassSize() { return howManyStudents; }

private:
    int ID;
    static int howManyStudents;
};

int Student::howManyStudents = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int maxStudents = 2;
    Student* course[maxStudents];
    int i;

    for (i = 0; i < maxStudents; i++)
    {
        course[i] = new Student(i);
    }

    for(auto s : course)
    {
        std::cout << "There are ";
        std::cout << Student::getClassSize();
        std::cout << " in the course." << std::endl;

        std::cout << "Removing Student ";
        std::cout << s->getID() << "." << std::endl;

        delete s;
        s = nullptr;

    }

    std::cout << "There are ";
    std::cout << Student::getClassSize();
    std::cout << " in the course." << std::endl;

    return a.exec();
}
```

When compiled and run, Listing 20.2's program produces the following output:

```Console
There are 2 in the course.
Removing Student 0.
There are 1 in the course.
Removing Student 1.
There are 0 in the course.
```

Here, Listing 20.2's program is very similar to Listing 20.1's. One difference is that there is a new public static accessor, `getClassSize()`. Another difference is that `howManyStudents` is now a private static member variable. `getClassSize()` is defined inline and returns the private variable's value.

In `main()`, we see that instead of accessing `howManyStudents` directly, this time, `getClassSize()` is used to display the variable's value. Note how it is not accessed via an object of the type `Student`. On lines 36 and 48, `getClassSize()` is able to access the public static accessor even though it has no access to a `Student` object.

>**Note** Static member functions do not have a `this` pointer, so they cannot be declared `const`. Also, because member variables are accessed in member functions using the `this` pointer, static member functions cannot access and non-static member variables.

## Containment of Classes

It is possible for the member data of a class to include objects of another class. This establishes a "contains" relationship between the enclosing class (the outer class) and a class used as data members (the inner class). C++ programmers say the inner class is contained by the outer class. A `Student` class may contain `String` objects that define a student's name.

Listing 20.3 defines the `String` class, which is used in Listing 20.4's program.

### Listing 20.3 The Full Text of `string.hpp`
```C++
#include <iostream>
#include <string.h>

class String
{
public:
    String();
    String(const char *const);
    String(const String &);
    ~String();

    char &operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String &);
    void operator+=(const String &);
    String &operator=(const String &);

    int getLen() const { return len; }
    const char *getString() const { return value; }

private:
    String(int);
    char *value;
    int len;
};

String::String()
{
    value = new char[1];
    value[0] = '\0';
    len = 0;
    // std::cout << "Default String constructor()." << std::endl;

    return;
}

String::String(int newLen)
{
    value = new char[newLen + 1];
    int i;

    for (i = 0; i < newLen; i++)
        value[i] = '\0';

    len = newLen;
    // std::cout << "Overloaded String constructor(int)." << std::endl;

    return;
}

String::String(const char *const cString)
{
    len = strlen(cString);
    value = new char[len + 1];
    int i;

    for (i = 0; i < len; i++)
        value[i] = cString[i];

    value[len] = '\0';
    // std::cout << "Overloaded String constructor(const char *const)." << std::endl;

    return;
}

String::String(const String &rhs)
{
    len = rhs.getLen();
    value = new char[len + 1];
    int i;

    for (i = 0; i < len; i++)
        value[i] = rhs[i];

    value[len] = '\0';
    // std::cout << "Overloaded String constructor(const String&)." << std::endl;

    return;
}

String::~String()
{
    delete[] value;
    len = 0;
    // std::cout << "Default String destructor()." << std::endl;

    return;
}

String &String::operator=(const String &rhs)
{
    if (this == &rhs)
        return *this;

    delete[] value;
    len = rhs.getLen();
    value = new char[len + 1];
    int i;

    for (i = 0; i < len; i++)
        value[i] = rhs[i];

    value[len] = '\0';
    // std::cout << "String operator=(const String&)." << std::endl;

    return *this;
}

char &String::operator[](int offset)
{
    if (offset > len)
        return value[len - 1];
    else
        return value[offset];
    // std::cout << "String operator[](int)." << std::endl;

    return value[0]; // need to return a value like this; otherwise, compiler complains.
}

char String::operator[](int offset) const
{
    if (offset > len)
        return value[len - 1];
    else
        return value[offset];
    // std::cout << "String operator[](int)." << std::endl;

    return value[0]; // need to return a value like this; otherwise, compiler complains.
}

String String::operator+(const String &rhs)
{
    int totalLen = len + rhs.getLen();
    int i, j;

    String temp(totalLen);

    for (i = 0; i < totalLen; i++)
        temp[i] = value[i];

    for (j = 0; j < rhs.getLen(); i++, j++)
        temp[i] = rhs[j];

    temp[totalLen] = '\0';
    // std::cout << "String operator+(const String&)." << std::endl;

    return temp;
}

void String::operator+=(const String &rhs)
{
    int rhsLen = rhs.getLen();
    int totalLen = len + rhsLen;
    int i, j;

    String temp(totalLen);

    for (i = 0; i < len; i++)
        temp[i] = value[i];

    for (j = 0; j < rhs.getLen(); i++, j++)
        temp[i] = rhs[i - len];

    temp[totalLen] = '\0';

    *this = temp;
    // std::cout << "String operator+=(const String&)." << std::endl;

    return;
}
```

This is a header file. It has no `main()` function and can't be run as a program. Its purpose is to be included in another source file.

Any time you need to use this class, you can include it using the `#include` directive. For example, Listing 20.4's program includes this file via the `#include "string.hpp"` statement. This adds the `String` class to the program. This statement is telling the compiler to add a file that is in the current working directory. Compiler flags can be used to include files from other directories.

Listing 20.4's program demonstrates how an outer class can contain an inner class.

### Listing 20.4 The Full Text of listing20_4's `main.cpp`
```C++
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
```

When compiled and run, Listing 20.4's program produces the following output:

```Console
Name: Beasley, Rob
ID: 1000
Name: Tropper, Barry
ID: 999
```

Here, a class named `Student` is declared on lines 3-24. It has a public default constructor, a public overloaded constructor, a public copy constructor, and a public destructor; an overloaded assignment operator; and six public accessors, `getFirstName()`, `setFirstName()`, `getLastName()`, `setLastName()`, `getID()`, and `setID()`. The class has three private member variables, two `String` objects named `firstName` and `lastName`, and an `int` named ID. All the accessors are defined inline and get and set their respective private variables. 

`Student`'s default constructor is defined on lines 26-32 and initialises `firstName`, `lastName`, and `ID` with default values. The overloaded constructor is defined on lines 34-40 and initialises `firstName`, `lastName`, and `ID` with the constructor's parameters' values. The copy constructor is defined on lines 42-48 and initialises `firstName`, `lastName`, and `ID` with the values returned from the constructor's parameter's object's `getFirstName()`, `getLastName()`, and `getID()` member functions. The destructor is defined on lines 50-53 and does nothing. 

The class's assignment operator is defined on lines 55-65. It first checks to see if the function's parameter's address is the same as the current object. If it is, it returns a dereferenced `this` pointer; otherwise, it assigns `firstName`, `lastName`, and `ID` the values returned from the function's parameter's object's `getFirstName()`, `getLastName()`, and `getID()` member functions and then returns a dereferenced `this` pointer.

On line 69, a `Student` object, `mrBeasly`, is created and its `firstName`, `lastName`, and `ID` member variables are initialised as "Rob", "Beasly", and 0, respectively. On line 71, `mrBeasly`'s `setID()` accessor is used to change the object's `ID` variable's value to 1000.

On lines 73-75, two `String` objects, `firstName` and `lastName`, and an `int` are initialised as "Barry", "Tropper", and 999, respectively. On line 77 a `Student` object, `mrTropper` is created and its member variables are initialised as the default values. On lines 79-91, `mrTropper`'s accessors are used to change the object's member variables' values to `fistName`'s, `lastName`'s, and `id`'s values, respectively.

On lines 83-84 and 86-87, `main()` displays the attributes of the `mrBeasly` and `mrTropper`.

### Accessing Members of the Contained Class

`Student` objects do not have special access to the member variables of `String`. If the `Student` object `mrBeasly` tries to access the member variable `len` of its own `firstName` member variable, this will cause a compiler error. This lack of access is not much of a burden, however. The accessor function provides an interface for the `String` class. The `Student` class need not worry about the implementation details any more that it worries about how the integer variable, `id`, stores its information.

### Filtering Access to Contained Members

Note that `String` class provides `operator+`. The designer of the `Student` class has blocked access to `operator+` being called on `Student` by declaring that all the `String` accessors, such as `getFirstName()`, return a constant reference. `operator+` can't be a `const` function because it changes the object it is called on, so attempting to write the following causes a compiler error:

```C++
String buffer = mrBeasly.getFirstName() + mrBeasly.getLastName();
```

The `getFirstName()` function returns a constant `String`; you can't call `operator+` on a constant object.

To fix this, overload `getFirstName()` to be non-`const`:

```C++
const String &getFirstName() const { return firstName; }
String& getFirstName() { return firstName; }
```

Note that the return value is no longer `const` and that the member function is no longer `const`. Changing the return value is not sufficient to overload the function, the function's constancy needs to be changed too. Because a `const` and non-`const` version is defined, the compiler invokes the `const` version where possible, and the non-`const` version when needed.

### Copying by Value Versus by Reference

When you pass `Student` objects by value, all their contained strings are copied as well, so copy constructors are called too. This is very expensive; it takes up a lot of memory and time.

When you pass `Student` objects by reference using pointers or references, all this time is saved. This is why C++ programmers work hard never to pass anything larger than a few bytes by value.

## Friend Classes and Functions

Sometimes classes are created as a set. These paired classes might need access to each other private members, but you might not want to make that information public.

If you want to expose your private member data or functions to another class, you must declare that class to be a friend. This extends the interface of your class to include the friend class.

The friendship cannot be transferred and is not inherited. It is also not commutative. Assigning class `A` to be a friend of class `B` does not make `B` a friend of `A`. For example:

```C++
class A;
class B;

class A
{
public:
    A() : id(2) {}

    friend class B;

private:
    int id;
};

class B
{
public:
    B() : id(2) {}

    void showA(A &rA) { std::cout << rA.id << std::endl; }

private:
    int id;
};

```

Declarations of friend classes should be used with extreme caution. If two classes are inextricably entwined, and one must frequently access data in the other, there might be a good reason to use this declaration. It is also just as easy to use public accessors. Doing so allows you to change one class without having to recompile the other.

At times, you will want to grant the friend level of access not to an entire class, but only to one or two functions of that class. You can do this by declaring the member functions of the other class to be friends. For example:

```C++
class A;
class B;

class A
{
public:
    A() : id(2) {}

    friend void A::showB(B &rB);

private:
    int id;
};

class B
{
public:
    B() : id(2) {}

    void showA(A &rA);

private:
    int id;
};

void B::showA(A &rA)
{
    std::cout << rA.id << std::endl;

    return;
}
```

### Pointers to Functions

Just as an array name is a constant pointer to the first element of that array, a function name is a constant pointer to that function. It is possible to declare a pointer variable that points to a function and to invoke the function by using the pointer. This can prove useful as it allows you to create programs that decide which functions to invoke based on user input.

The only tricky part about function pointers is understanding the type of the object being pointed to. A pointer to `int` points to an integer variable, and a pointer to a function must point to a function of the appropriate return type and signature. 

Consider the following:

```C++
long (*funcPtr)(int);
```

The `funcPtr` variable is declared to be a pointer that points to a function that takes an integer parameter and returns a `long`. The parentheses around `*funcPtr` are necessary because the parentheses around `int` have higher precedence that the indirection operator (*). Without the first parentheses, this would declare a function that takes an integer and returns a pointer to a `long`.

Consider the following:

```C++
long *funcPtr(int);
long (*funcPtr)(int);
```

The first line is a function that takes an integer and returns a pointer to a `long`. The second line is a pointer to a function that takes an integer and returns a `long`.

The declaration of a function pointer always includes the return type and parentheses indicating the type of the parameters, if any. 

Listing 20.5's program demonstrates how to use function pointers.

### Listing 20.5 The Full Text of listing20_5's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

void square(int &, int &);
void cube(int &, int &);
void swap(int &, int &);
void getVals(int &, int &);
void printVals(int, int);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void (*pFunc)(int &, int &);
    bool loop = true;

    int val1 = 1, val2 = 2;
    int choice;

    while (loop)
    {
        std::cout << "(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap." << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pFunc = getVals;
            break;
        case 2:
            pFunc = square;
            break;
        case 3:
            pFunc = cube;
            break;
        case 4:
            pFunc = swap;
            break;
        }

        if (!loop)
            break;

        printVals(val1, val2);
        pFunc(val1, val2);
        printVals(val1, val2);
    }

    return a.exec();
}


void square(int &rVal1, int &rVal2)
{
    rVal1 *= rVal1;
    rVal2 *= rVal2;

    return;
}

void cube(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    rVal1 *= rVal1;
    rVal1 *= temp1;

    int temp2 = rVal2;
    rVal2 *= rVal2;
    rVal2 *= temp2;

    return;
}

void swap(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    int temp2 = rVal2;

    rVal2 = temp1;
    rVal1 = temp2;

    return;
}

void getVals(int &rVal1, int &rVal2)
{
    std::cout << "Value 1: ";
    std::cin >> rVal1;

    std::cout << "Value 2: ";
    std::cin >> rVal2;

    return;
}

void printVals(int val1, int val2)
{
    std::cout << "Value 1: " << val1 << " , Value 2: " << val2 << "." << std::endl;

    return;
}
```

When compiled and run, Listing 20.5's program produces the following output:

```Console
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
1
Value 1: 1 , Value 2: 2.
Value 1: 2
Value 2: 3
Value 1: 2 , Value 2: 3.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
2
Value 1: 2 , Value 2: 3.
Value 1: 4 , Value 2: 9.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
3
Value 1: 4 , Value 2: 9.
Value 1: 64 , Value 2: 729.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
4
Value 1: 64 , Value 2: 729.
Value 1: 729 , Value 2: 64.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
0
```

Here, four functions, `square()`, `cube()`, `swap()`, and `getVals()` are declared on lines 3-6. Each function accepts two parameters, two references to integers, and does not return a value. 

On line 11, a pointer to a function that accepts two `int` references as parameters and does not return a value, `pFunc` is declared. `pFunc` can point to any of `square()`,`cube()`, `swap()`, or `getVals()`. 

On lines 17-47, the user is prompted to choose one of the four functions and `pFunc` is assigned a function based on their choice. Afterwards, `main()` displays the current values of two integers, `pFunc` is passed the integers, and `main()` again displays the new values of the two integers.

The pointer to the function does not need to be dereferenced, although you are free to do so. Therefore, if `pFunc` is a pointer to a function taking an integer and returning a variable of type long, and you assign `pFunc` to a matching function, you can invoke that function with either of the following statements:

```C++
pFunc(x);
(*pFunc)(x);
```

The two statements are identical. The former is just shorthand for the latter.

### Arrays of Pointers to Functions

Just as you can declare an array of pointers to integers, you can declare an array of pointers to functions returning a specific value type and with a specific signature.

Listing 20.6's program demonstrates how to do this.

### Listing 20.6 The Full Text of listing20_6's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

void square(int &, int &);
void cube(int &, int &);
void swap(int &, int &);
void getVals(int &, int &);
void printVals(int, int);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int val1 = 1, val2 = 2;
    int choice, i;

    const int maxArray = 3;
    void (*pFuncArray[maxArray]) (int&, int&);

    for (i = 0; i < maxArray; i++)
    {
        std::cout << "(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap." << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            pFuncArray[i] = 0;
            break;
        case 1:
            pFuncArray[i] = getVals;
            break;
        case 2:
            pFuncArray[i] = square;
            break;
        case 3:
            pFuncArray[i] = cube;
            break;
        case 4:
            pFuncArray[i] = swap;
            break;
        }

    }

    for(auto i : pFuncArray)
    {
        i(val1, val2);
        printVals(val1, val2);
    }

    return a.exec();
}

void square(int &rVal1, int &rVal2)
{
    rVal1 *= rVal1;
    rVal2 *= rVal2;

    return;
}

void cube(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    rVal1 *= rVal1;
    rVal1 *= temp1;

    int temp2 = rVal2;
    rVal2 *= rVal2;
    rVal2 *= temp2;

    return;
}

void swap(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    int temp2 = rVal2;

    rVal2 = temp1;
    rVal1 = temp2;

    return;
}

void getVals(int &rVal1, int &rVal2)
{
    std::cout << "Value 1: ";
    std::cin >> rVal1;

    std::cout << "Value 2: ";
    std::cin >> rVal2;

    return;
}

void printVals(int val1, int val2)
{
    std::cout << "Value 1: " << val1 << " , Value 2: " << val2 << "." << std::endl;

    return;
}
```

When compiled and run, Listing 20.6's program produces the following output:

```Console
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
1
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
2
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
3
Value 1: 2
Value 2: 3
Value 1: 2 , Value 2: 3.
Value 1: 4 , Value 2: 9.
Value 1: 64 , Value 2: 729.
```

Here, Listing 20.6's program is very similar to Listing 20.5's program. The main difference is that it has an array of pointers to functions instead of a single pointer to a function. 

On lines 18-42, a `for` loop is used to prompt the user to select one of four functions. Based on the user's choice, the array's current index is assigned a corresponding function.

On lines 44-48, a second `for` loop iterates over the array, passing the values to the function pointed to in the array's current index. Afterwards, the values of two integers are displayed.

### Passing Pointers to Functions to Other Functions

The pointers of functions (and arrays of pointers to functions) can be passed to other functions that may act and then call the right function using the pointer.

For example, you might improve Listing 20.6's program by passing the chosen function pointer to another function (outside of `main()`) that will display the values, invoke the function, and then display the values.

Listing 20.7's program demonstrates how to do this.

### Listing 20.7 The Full Text of listing20_7's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

void square(int &, int &);
void cube(int &, int &);
void swap(int &, int &);
void getVals(int &, int &);
void printVals(void (*)(int&, int&), int&, int&);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int val1 = 1, val2 = 2;
    int choice, i;
    bool loop = true;

    void (*pFunc)(int&, int&);

    while(loop)
    {
        std::cout << "(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap." << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pFunc = getVals;
            break;
        case 2:
            pFunc = square;
            break;
        case 3:
            pFunc = cube;
            break;
        case 4:
            pFunc = swap;
            break;
        }

        if(!loop)
            break;

        printVals(pFunc, val1, val2);

    }

    return a.exec();
}

void square(int &rVal1, int &rVal2)
{
    rVal1 *= rVal1;
    rVal2 *= rVal2;

    return;
}

void cube(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    rVal1 *= rVal1;
    rVal1 *= temp1;

    int temp2 = rVal2;
    rVal2 *= rVal2;
    rVal2 *= temp2;

    return;
}

void swap(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    int temp2 = rVal2;

    rVal2 = temp1;
    rVal1 = temp2;

    return;
}

void getVals(int &rVal1, int &rVal2)
{
    std::cout << "Value 1: ";
    std::cin >> rVal1;

    std::cout << "Value 2: ";
    std::cin >> rVal2;

    return;
}

void printVals(void (*pFunc) (int&, int &), int &val1, int &val2)
{
    std::cout << "Value 1: " << val1 << " , Value 2: " << val2 << "." << std::endl;
    pFunc(val1, val2);
    std::cout << "Value 1: " << val1 << " , Value 2: " << val2 << "." << std::endl;

    return;
}
```

When compiled and run, Listing 20.7's program produces the following output:

```Console
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
1
Value 1: 1 , Value 2: 2.
Value 1: 7
Value 2: 9
Value 1: 7 , Value 2: 9.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
3
Value 1: 7 , Value 2: 9.
Value 1: 343 , Value 2: 729.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
2
Value 1: 343 , Value 2: 729.
Value 1: 117649 , Value 2: 531441.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
4
Value 1: 117649 , Value 2: 531441.
Value 1: 531441 , Value 2: 117649.
(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap.
0
```

Here, Listing 20.7's program is very similar to Listing 20.6's program. A main difference is that the function `printVals()` signature has changed; now it accepts a pointer to a function that takes two `int` references as its parameters and returns nothing, and two `int` references. The new definition of the function first displays the values of the integers, then calls the function pointed to (passing the function's other parameters as arguments), and lastly displays the values of the integers.

Because the pointer to a function used here, `void (*pFunc)(int&, int&)`, is difficult to read, a `typedef` could be used to make it more readable. 

### Using `typedef` with Pointers to Functions

The construct `void (*)(int&, int&)` used in Listing 20.7's program is cumbersome. It can be simplified, however, by using a `typedef` to declare a type `VPF` as a pointer to a function returning `void` and taking two integer references. For example:

```C++
typedef void (*VPF) (int&, int&);
```

The `pFunc` variable can be declared to be of type `VPG` as follows:

```C++
VPF pFunc;
```

The member function `printVals()` can be declared to take three parameters, a `VPF` and two integer references as follows:

```C++
void printVals(VPF pFunc, int &val1, int &val2);
```

Remember, the `typedef` creates a synonym; the only difference is readability.

### Pointers to Member Functions

It is also possible to create pointers to functions that are members of classes.

To create a pointer to member functions, use the same syntax as with a pointer to a function, but include the class's name and the scoping operator (::). Therefore, if `pFunc` points to a member of the class `Shape`, which takes two integers and returns `void`, the declaration is a follows:

```C++
void (Shape::*pFunc)(int, int);
```

Pointers to member functions are used in exactly the same way as pointers to functions, except that they require an object of the correct class on which to invoke them. 

Listing 20.8's program demonstrates how to use pointers to member functions.

### Listing 20.8 The Full Text of listing20_8's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Mammal
{
public:
    Mammal() : age(1) {}
    virtual ~Mammal() {}

    virtual void speak() const = 0;
    virtual void move() const = 0;

protected:
    int age;
};

class Dog : public Mammal
{
public:
    Dog() {}
    ~Dog() {}

    void speak() const { std::cout << "Woof." << std::endl; }
    void move() const { std::cout << "The dog runs." << std::endl; }
};

class Cat : public Mammal
{
public:
    Cat() {}
    ~Cat() {}

    void speak() const { std::cout << "Meow." << std::endl; }
    void move() const { std::cout << "The cat prowls." << std::endl; }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void (Mammal::*pFunc)() const = 0;

    Mammal *pMammal = nullptr;
    int animal;
    int method;
    bool loop = true;

    while (loop)
    {
        std::cout << "(0) Quit, (1) Dog, or (2) Cat: ";
        std::cin >> animal;

        switch (animal)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pMammal = new Dog;
            break;
        case 2:
            pMammal = new Cat;
            break;
        default:
            loop = false;
            break;
        }

        if (!loop)
            break;

        std::cout << "(1) Speak, or (2) Move: ";
        std::cin >> method;

        switch (method)
        {
        case 1:
            pFunc = &Mammal::speak;
            break;
        case 2:
            pFunc = &Mammal::move;
            break;
        }

        (pMammal->*pFunc)();
        delete pMammal;

    }

    return a.exec();
}
```

When compiled and run, Listing 20.8's program produces the following output:

```Console
(0) Quit, (1) Dog, or (2) Cat: 1
(1) Speak, or (2) Move: 1
Woof.
(0) Quit, (1) Dog, or (2) Cat: 2
(1) Speak, or (2) Move: 2
The cat prowls.
(0) Quit, (1) Dog, or (2) Cat: 0
```

Here, three classes are declared, `Mammal`, `Dog`, and `Cat`. `Mammal` is an abstract data type, and `Dog` and `Cat` inherit from `Mammal`. `Mammal` has a public default constructor and a public virtual destructor, and two public pure virtual accessors, `speak()` and `move()`. The class has one protected member variable, an `int` named `age`. `Dog` and `Cat` override `Mammal`'s `speak()` and `move()` functions; displaying messages corresponding to their respective namesake.

On line 39, a pointer to a member function that takes no parameters and returns `void` is created and assigned the value 0.  On lines 41-44, a pointer to a `Mammal` object, two `int`s, and a `bool` are created for the program to use later.

On lines 46-86, a `while()` loop is used to continuously prompt the user to choose an animal. Based on the user's choice, a `switch-case` statement is used to assign the address of a new `Cat` or `Dog` object to a pointer to a `Mammal` object. Afterwards, the user is prompted to choose what their chosen animal does. Based on the user's choice, a second `switch-case` statement is used to assign the address of either the `Mammal`'s `speak()` or `move()` function to a pointer to a member function. Lastly, the mammal pointer calls the member function pointer's function.

>**Note** There is no reason to call `delete` of `pFunc` because this is a pointer to code, not to an object on the heap. In fact, attempting to do so will generate a compiler error.

### Arrays of Pointers to Member Functions

As with pointers to functions, pointers to members functions can be stored in an array. The array can be initialised with the addresses of various member functions, and those can be invoked by offsets into the array.

Listing 20.9's program demonstrates how to do this.

### Listing 20.9 The Full Text of listing20_9's `main.cpp`
```C++
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
```

When compiled and run, Listing 20.9's program produces the following output:

```Console
(0) Quit, (1) Speak, (2) Move, (3) Eat, or (4) Growl: 1
Woof.
(0) Quit, (1) Speak, (2) Move, (3) Eat, or (4) Growl: 2
The dog runs.
(0) Quit, (1) Speak, (2) Move, (3) Eat, or (4) Growl: 3
Nom nom nom.
(0) Quit, (1) Speak, (2) Move, (3) Eat, or (4) Growl: 4
Grrrr.
(0) Quit, (1) Speak, (2) Move, (3) Eat, or (4) Growl: 0
```

Here, a `Dog` class is defined on lines 3-13. It has a public default constructor and a public destructor, and four public member functions, `speak()`, `move()`, `eat()`, and `growl()`. The class's member functions each display corresponding messages, and return `void`.

On line 15, a `typedef` declares the type `PDF` to be a pointer to a member function of `Dog`, which takes no parameters, returns `void`, and is `const`. This is the signature of the four functions defined in `Dog`.

On lines 21-27, the array `dogFunctions` is declared to hold four `Dog` member functions and initialised with the address of `speak()`, `move()`, `eat()`, and `growl()`.

On lines 33-52, a `while` loop is used to continuously prompt the user to select one of the four functions. An `if` statement checks to see if the loop should break. If the user chose 0, the loop ends; otherwise, the address of a new `Dog` object is assigned to a `Dog` pointer, the chosen member function called, and the object then deleted.

## Summary

Static member variables serve as a way to store information about an entire class of objects. They're also useful as a technique in which objects of the same class can exchange information with each other.

Static member functions provide a place for behaviours that fits a class, but does not require a specific object of that class to operate on.

Friend functions make it possible for one class to expose its private member variables and functions to another class that would not otherwise have access. Although these things are normally handled via inheritance, using friend functions gives special access to a class outside of its inheritance hierarchy.

## Q & A

Q. Why use static data when you can use global data?

A. Static data is scoped to the class. It therefore is available only through an object of the class - through an explicit and full call using the class name if the data is public, or by using a static member function. Static data is typed to the class type; however, and the restricted access and strong typing makes static data safer that global data.

Q. Why use static member functions when you can use global functions?

A. Static member functions are scoped to the class and can be called only by using an object of the class or an explicit full specification.

Q. Why not make all classes friends of the classes they use?

A. Making one class a friend of another exposes the implementation details and reduces the encapsulation. The ideal in object-orientated programming is to keep as many of the details of each class as hidden as possible from other classes.

## Workshop

### Quiz

1. How many copies of a static member variable exist for a class?
    A. None
    B. One
    C. One for each object of the class

<!-- B. Only one version is instantiated for all objects of that class. -->

2. What keyword makes a member function static?

    A. `static`
    B. `friend`
    C. `const`

<!-- A. The `static` keyword makes both member variables and functions static for the entire class. -->

3. When should you call `delete` after you're done using a pointer function?

    A. Always
    B. Never
    C. Sometimes

<!-- B. Unlike a pointer that holds an address in memory, which should be deleted when no longer needed, a function pointer points to code and cannot be freed with `delete`. -->

### Activities

1. Uncomment `string.hpp`'s commented lines. Compile and run Listing 20.4's program. Note the order the constructors, operators, and destructors are called.

2. Modify Listing 20.6's program to reject inappropriate input.
