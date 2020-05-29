# Lecture 11: Advanced Pointers

## What You'll Learn in this Lecture:

* How to create objects on the heap
* How to use pointers effectively
* How to prevent memory problems when using pointers

## Creating Objects on the Heap

One of the most powerful tools available to a C++ programmer is the capability to directly manipulate computer memory by using pointers.

You can create a pointer to any object. If you have created a class named `Dog`, you can declare a pointer to that class and instantiate a `Dog` object on the heap. For example:

```C++
Dog *myDog = new Dog;
```

This calls the default constructor - the constructor with no parameters. A constructor is called whenever an object is created on the stack or on the heap.

## Deleting Objects

When you call delete on a pointer to an object on the heap, the object's destructor is called before the memory is released. This gives a class a chance to clean up after itself, just as it would if it had been destroyed on the stack.

Listing 11.1's program demonstrates how to create and delete objects on the heap.

### Listing 11.1 The Full Text of listing11_1's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Dog
{
public:
    Dog();
    ~Dog();

private:
    int age;
};

Dog::Dog()
{
    std::cout << "Constructor called." << std::endl;
    age = 1;

    return;
}

Dog::~Dog()
{
    std::cout << "Destructor called." << std::endl;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Dog myFirstDog;" << std::endl;
    Dog myFirstDog;

    std::cout << "Dog *mySecondDog = new Dog;" << std::endl;
    Dog *mySecondDog = new Dog;

    std::cout << "delete mySecondDog" << std::endl;
    delete mySecondDog;

    std::cout << "myFirstDog" << std::endl;

    return a.exec();
}
```

When compiled and run, Listing 11.1's program produces the following output:

```Console
Dog myFirstDog;
Constructor called.
Dog *mySecondDog = new Dog;
Constructor called.
delete mySecondDog
Destructor called.
myFirstDog
Destructor called.
```

Here, lines 3-11 declare a class named `Dog`. `Dog`'s constructor is defined on lines 13-19. The constructor displays a message when it is called and assigns the value 1 to the class's private data member `age`. `Dog`'s destructor is defined on lines 21-26. The destructor displays a message when it calls and does nothing else.

Lines 30-31 create an instance of the `Dog` class named `myFirstDog` on the stack and displays a corresponding message to the user. When the object is created, its constructor is called.

Lines 33-34 create an instance of the `Dog` class named `mySecondDog` on the heap and displays a corresponding message to the user. When the object is created, its constructor is called.

Lines 36-37 deletes `mySecondDog`'s memory, freeing the memory allocated on the heap. When the object is deleted, its destructor is called.

Line 39 displays one last message.

As the program ends, `myFirstDog` goes out of scope and its destructor is called.

## Accessing Data Members Using Pointers

Member variables and member functions are accessed using the dot operator (.) for objects created locally. To access an object on the heap, you must dereference the pointer and call the do operator on the object pointed to by the pointer. For example:

```C++
(*mySecondDog).GetAge();
```

Here, parentheses are used to assure that `mySecondDog` is dereferenced before `GetAge()` is accessed.

Because this is cumbersome, C++ provides a shorthand operator for indirect access: the points-to operator ->, which is created by typing a dash followed by the greater than symbol. C++ treats this as a single symbol.

Listing 11.2's program demonstrates accessing member variables and member functions of objects created on the heap.

### Listing 11.2 The Full Text of listing11_2's `main.cpp`
```C++
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
```

When compiled and run, Listing 11.2's program produces the following output:

```Console
My dog is 1 years old.
My dog is 10 years old.
```

Here, lines 3-12 declare a class named `Dog`. The class has one private member variable named `age`. `Dog`'s constructor is defined on lines 14-19. The constructor assigns the value 1 to the class's private member variable `age` and does nothing else. `Dog`'s destructor is defined on lines 21-24 and does nothing. `Dog`'s accessor `GetAge()` is defined on lines 26-29 and returns the value of `age`. `Dog`'s accessor `SetAge()` is defined on lines 31-34 and assigns an integer value to `age`.

On line 39, an instance of `Dog` is created on the heap. The default constructor sets its age to 1.

On line 41, a message stating the object's `age` member variable's value is displayed to the user. Because `myDog` is a pointer, the points-to operator is used to access the object's member functions.

On line 43, the object's `age` member variable's value is set to 10. Again, because `myDog` is a pointer, the points-to operator is used to access the object's member functions.

Line 45 performs the same action as line 41.

On line 47, `myDog`'s memory is deleted, and the memory allocated on the heap is freed.

## Member Data on the Heap

One or more of a class's data member can be a pointer to an object on the heap. The memory can be allocated in the class constructor or in one of its member functions, and it can be deleted in the class's destructor.

Listing 11.3's program demonstrates memory being allocated in a class.

### Listing 11.3 The Full Text of listing11_3's `main.cpp`
```C++
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
```

When compiled and run, Listing 11.3's program produces the following output:

```Console
My dog is 5 years old.
My dog weighs 7 kgs.
```

Here, lines 3-16 declare a class named `Dog`. The class has two private member variables, two pointers to an `int` named `age` and `weight`. `Dog`'s constructor is defined on lines 18-25. It allocates memory on the heap to `age` and `weight` and assigns them the values 5 and 5, respectively. `Dog`'s destructor is defined on lines 27-31. It deletes `age` and `weight` and frees up the memory allocated to them. `Dog`'s accessors are defined on lines 33-55 and get and set `age` and `weight`, respectively.

On line 59, an instance of `Dog` is created, which in turn calls its constructor. The constructor allocates `age` and `weight` memory on the heap and assigns them initial values.

On line 61, a message stating the object's `age` value is displayed to the user. Because `myDog` is a pointer, the points-to operator is used to access its member functions.

On line 63, the object's `weight` value is set to 7. Again, because `myDog` is a pointer, the points-to operator is used to access its member functions.

On line 61, a message stating the object's `weight` value is displayed to the user. Again, because `myDog` is a pointer, the points-to operator is used to access its member functions.

On line 67, `myDog` is deleted and the memory allocated to it on the heap is freed. Deleting `myDog` calls its destructor, which deletes `age` and `weight` and the memory allocated to them is freed.

Here, `main()` is unaware `age` and `weight` are pointers to memory on the heap. It just uses `GetAge()` and `SetWeight()`, irrespective of their implementations.

## The `this` pointer

Every class member function has a hidden parameter: the `this` pointer, which points to the individual object in which the function is running. So, in each call to `GetAge()` or `SetWeight()`, the `this` pointer for the object can be referenced.

The job of the `this` pointer is to point to the individual object whose function has been invoked. Usually, you don't need `this`; you just call functions and set member variables. Occasionally, however, you need to access the object itself, e.g. to return a pointer to the current object. It's then when `this` becomes useful.

Listing 11.4's program demonstrates how the `this` pointer can be used.

###  Listing 11.4 The Full Text of listing 11_4's `main.cpp`
```C++
#include <QCoreApplication>
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    return a.exec();
}
```

When compiled and run, Listing 11.4's program produces the following output:

```Console
There are 1 animals in the cage.
The animals are happy
There are 2 animals in the cage.
The animals are sad
```

Here, a class named `Cage` is declared on lines 3-18. It has two private member variable: an `int` named `animals` and a `bool` named `happy`. Its constructor is defined on lines 20-26 and assigns the value 1 to `animals`. `Cage`'s destructor is defined on lines 28-31 and does nothing. The class's accessors are defined on lines 33-59. They get and set `animals`'s and `happy`'s values, respectively.

On line 64, an instance of `Cage` named `aCage` is created.

One lines 66-75, messages indicating `aCage`'s `animals` and `happy` values are displayed to the user. An `if` statement checks to see if `happy` is true, if it is, then the message displays "happy"; otherwise, the message displays "sad".

On lines 77-78, the `setAnimals` and `setMood` accessors are used to change `animals` and `happy`'s values to 2 and `false`, respectively.

Lines 80-89 perform the same function as lines 66-75.

Here, the `GetAnimals()` and `SetAnimals()` accessors explicitly use the `this` pointer. The `GetMood()` and `SetMood()` accessors do not. There's no difference in their behaviour; although, the function that used `this` may be easier to read.

## Stray or Dangling Pointers

A source of bugs that are difficult to find is stray pointers. A stray pointer is created when you call `delete` on a pointer and later try to use that pointer again without reassigning it.

Take care not to use a pointer after you have called `delete` on it. The pointer still points to the old area, but the compiler is free to put other data there; using the pointer can cause your program to crash. Worse, your program might continue to work for some time and crash later. This is called a time bomb.

To be safe, after your `delete` a pointer, set it to `nullptr`. This disarms the pointer.

> **Note**
Stray pointers are often called wild pointers or dangling pointers.

## `const` Pointers

You can use the `const` keyword for pointers before the type, after the type, or in both places. For example:

```C++
const int *pOne;
int * const pTwo;
const int * const pThree;
```

These three statements do not mean the same thing. `pOne` is a pointer to a constant integer. The value pointed to can't be changed using this pointer. For example, you can't do the following:

```C++
*pOne = 10;
```

If you try to, the compiler will fail with an error.

`pTwo` is a constant pointer to an integer. The integer can be changed, but the pointer can't point to anything else. A constant pointer can't be reassigned. For example, you can't do the following:

```C++
pTwo = &mood;
```

`pThree` is a constant pointer to a constant integer. The value that it points to can't be change, and the pointer can't point to anything else.

## `const` Pointers and `const` Member Functions

When a function is declared as `const`, the compiler flags an error if there is any attempt to change data in the object from within that function.

If you declare a pointer to a `const` object, the only functions that you can call with that pointer are `const` functions.

Listing 11.5 demonstrates how a pointer to a `const` object can be used.

### Listing 11.5 The Full Text of listing11_5's `main.cpp`
```C++
#include <QCoreApplication>
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    return a.exec();
}
```

When compiled and run, Listing 11.5's program produces the following output:

```Console
There are 1 animals in pCage
There are 1 animals in pConstCage
There are 1 animals in pConstPtrCage
There are 2 animals in pCage
There are 1 animals in pConstCage
There are 2 animals in pConstPtrCage
```

Here, a class named `Cage` is declared on lines 3-17. It has two private member variable: an `int` named `animals` and a `bool` named `happy`. Its constructor is defined on lines 19-22 and assigns the value 1 to `animals` and `true` to `happy`. `Cage`'s destructor is defined on lines 24-27 and does nothing. The class's accessors are defined on lines 29-54. They get and set `animals`'s and `happy`'s values, respectively.

On lines 59-61, declare three pointers and allocates them memory on the heap: a pointer to a `Cage` object named `pCage`, a pointer to a constant `Cage` object, and a constant`pointer to a `Cage` object.

Lines 63-65 display `pCage`, `pConstCage`, and `pConstPtrCage`'s `animals` values. Here, the default constructor assigns `animals` the value 1 and `happy` the value `true`.

Lines 67-69 try to change `pCage`, `pConstCage`, and `pConstPtrCage`'s `animals` values to 2. However, because `pConstCage` is a pointer to a constant `Cage` object, the object cannot be changed. Trying to change it generates a warning message.

Lines 71-73 produce the same results as lines 63-65, but showed the changes `animal` values for `pCage` and `pConstPtrcage`.

## Summary

Pointers can be created to point to simple data types like integers and to objects as well. 

Objects can be created and deleted on the heap. If you have declared an object, you can declare a pointer to that class and instantiate the object on the heap.

Data members of a class can be pointers to objects on the heap. Memory can be allocated in the class constructor, or one of the class's functions, and deleted in the destructor.

The ability to directly ac cess computer memory by using pointers is one of the most powerful tools available to a C++ programmer.

## Q & A

Q. Why should I declare an object as `const` if it limits what I can do with it?

A. As a programmer, you want to enlist the compiler in helping you find bugs. One serious bug that is difficult to find is a function that changes an object in ways that aren't obvious to the calling function. Declaring an object `const` prevents such changes.

Q. Why should I bother to declare anything on the heap.

A. Objects on the heap persist after the return of a function. They are also dynamic - you can allocate as many as you need for an application or set of input data.

## Workshop

### Quiz

1. What keywords are used to allocate and release space from the heap in C++?

    A. alloc and deallac
    B. public and private
    C. new and delete

<!-- C. `new` is used to allocate space on the heap and `delete` is used to release it. -->

2. When is an object deleted (the destructor called) if you do not issue the delete yourself?

    A. When the program ends
    B. When the object's scope ends
    C. Both

<!-- B. When the scope for an object is exited, the object is automatically deleted. If an object is created in `main()` and not deleted by the programmer, when `main()` is exited, the destructor is called. -->

3. What is a pointer called that is used after a `delete` was performed on that pointer?

    A. A null pointer
    B. A stray pointer
    C. A blank pointer

<!-- B. A stray pointer. -->

### Activities

1. Add a dog named "barker" to Listing 11.1's program.

2. Modify Listing 11.2's program so that it does not use the points-to operator.
