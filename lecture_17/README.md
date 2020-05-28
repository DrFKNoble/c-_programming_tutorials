# Lecture 17: Using Polymorphism and Derived Classes

## What You'll Learn in this Lecture:

* What virtual member functions are
* How to use virtual destructors and copy constructors
* How virtual member functions enable you to use your base classes polymorphically
* The costs and dangers in using virtual member functions

## Polymorphism Implemented with Virtual Member Functions

A class derived from a base class inherits the base class's member variables and member functions. 

Polymorphism allows derived objects to be treated as if they were base objects. For example, suppose your derive the `Dog` and `Cat` classes from the  `Mammal` class. `Mammal` has a number of member functions factored out of the derived classes, such as `speak()`, which implements the capability of all mammals to make noise.

Each derived class has a specialised way to speak. A dog says "woof", a cat says "meow". Each class overrides the base class's implementation of the `speak()` function.

When you have a collection of `Mammal` objects, such as a `Farm` with `Dog` and `Cat` objects, you want the farm to be able to tell each of these objects to `speak()` without worrying about how they implement `speak()`. When you treat these objects as if they are all mammals by calling `Mammal.speak()`, you are treating them polymorphically.

You can use polymorphism to declare a pointer to `Mammal` and assign it the address of a `Dog` object you create on the heap. Because a `Dog` "is a" `Mammal`, the following is allowed:

```C++
Mammal *pMammal = new Dog;
```

You can then use this pointer to invoke any member function on `Mammal`. What you would like is for those functions that are overridden in `Dog` to call the correct function.

Virtual member functions let you do that. When you treat these objects polymorphically, you call the member function on the mammal pointer and don't worry about what the actual object is or how it implements its function.

A virtual member function is declared with the `virtual` keyword. For example:

```C++
virtual void speak() const 
{
    std::cout << "Mammal, speak." << std::endl;
}
```

Listing 18.1's program demonstrates how to use virtual functions.

### Listing 17.1 The Full Text of `listing_17_1.cpp`
```C++
#include <iostream>

class Mammal
{
public:
    Mammal();
    ~Mammal();

    void move() const;

    virtual void speak() const;

protected:
    int age;
};

Mammal::Mammal() : age(1)
{
    std::cout << "Mammal() constructor." << std::endl;

    return;
}

Mammal::~Mammal()
{
    std::cout << "Mammal() destructor." << std::endl;

    return;
}

void Mammal::move() const
{
    std::cout << "Mammal, move 1 step." << std::endl;

    return;
}

void Mammal::speak() const
{
    std::cout << "Mammal, speak." << std::endl;

    return;
}

class Dog : public Mammal
{
public:
    Dog();
    ~Dog();

    void move() const;

    void speak() const;
};

Dog::Dog()
{
    std::cout << "Dog() constructor." << std::endl;

    return;
}

Dog::~Dog()
{
    std::cout << "Dog() destructor." << std::endl;

    return;
}

void Dog::move() const
{
    std::cout << "Dog, move 1 step." << std::endl;

    return;
}

void Dog::speak() const
{
    std::cout << "Woof woof." << std::endl;

    return;
}

int main()
{
    Mammal *pDog = new Dog;

    pDog->move();
    pDog->speak();

    return 0;
}
```

When compiled and run, Listing 17.1's program produces the following output:

```Console
Mammal() constructor.
Dog() constructor.
Mammal, move 1 step.
Woof woof.
```

Here, a class named `Mammal` is declared on lines 3-15. It has a public default constructor and destructor, and two member functions, `move()` and `speak()`. It has one protected member variable, `age`. The constructor is defined on lines 17-22 and displays a message before returning. The destructor is defined on lines 24-29 and displays a message before returning. `move()` is defined on lines 31-36 and displays a message before returning. `speak()` is declared as a virtual function and is defined on lines 38-43. It displays a message before returning. Because `speak()` is declared with the `virtual` keyword, it is expected that another class will be derived from `Mammal` and that it will probably override this function's definition.

A second class named `Dog` is declared on lines 45-54 and derives from `Mammal`. It has a public default constructor and destructor, and two public member functions, `move()` and `speak()`, which override the base class's implementation. The constructor is defined on lines 56-61 and displays a message before returning. The destructor is defined on lines 63-68 and displays a message before returning. `move()` is defined on lines 70-75 and displays a message before returning. `speak()` is defined on lines 77-82 and displays a message before returning.

On line 86, a pointer to a `Mammal` object is created and it is assigned the address of a new `Dog` object. Because `Dog` is a `Mammal`, this is a legal assignment. On lines 88-89, the pointer is used to call the `move()` and `speak()` functions. Here, `Mammal`'s `move()` is called; however, because `Mammal`'s `speak` was declared `virtual`, `Dog`'s overridden `speak()` is called.

Here, a `Mammal` pointer called a `Dog` function.

If you have an array of pointers to a `Mammal`, each of which points to a derived class of `Mammal`, you can call each in turn and see that the correct function is called. Listing 18.2's program demonstrates this idea.

### Listing 17.2 The Full Text of `listing_17_2.cpp`
```C++
#include <iostream>

class Mammal
{
public:
    Mammal() : age(1){ }
    ~Mammal(){ }

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
    Dog(){ }
    ~Dog(){ }

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
    Cat(){ }
    ~Cat(){ }

    void speak() const;
};

void Cat::speak() const
{
    std::cout << "Meow meow." << std::endl;

    return;
}

int main()
{
    Mammal *array[2];
    Mammal *ptr;
    int choice, i;

    for (i = 0; i < 2; i++)
    {
        std::cout << "(1) Dog, (2) Cat: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ptr = new Dog;
            break;
        case 2:
            ptr = new Cat;
            break;
        default:
            ptr = nullptr;
            break;
        }

        array[i] = ptr;
    }

    for (i = 0; i < 2; i++)
    {
        array[i]->speak();
    }

    return 0;
}
```

When compiled and run, Listing 17.2's program produces the following output:

```Console
(1) Dog, (2) Cat: 1
(1) Dog, (2) Cat: 2
Woof woof.
Meow meow.
```

Here, Listing 18.2's program is very similar to Listing 18.1's. A difference is that there is another class, `Cat`, which is, functionally, the same as `Dog`. 

On line 56-57 an array of pointers to `Mammal` objects and a pointer to a `Mammal` object is created, respectively. On line 58 two `int`s are created; these are used for the subsequent for loops' iterations and to track the user input.

On lines 60-76, a `for` loop iterates twice, asking the user for input. Each time, a `switch-case` statement creates a new `Dog` or `Cat` object based on the user's choice and assigns it to a `Mammal` pointer. The pointer is then assigned to the array's corresponding index.

On lines 81-84, a second `for` loop iterates twice, calling the array's corresponding object's `speak()` object.

Here, we can see that the correct function is called for each type of animal, even though we're using pointers to `Mammal` objects.

## How Virtual Member Functions Work

When a derived object, such as a `Dog` object, is created, first the constructor for the base class is called, and then the constructor for the derived class is called. The `Mammal` part of the object is contiguous in memory with `Dog` part.

When a virtual function is created in an object the object must keep track of that function. Many compilers build a virtual function table, called a v-table. One of these is kept for each type, and each object of that type keeps a virtual table pointer (a v-pointer), which points to that table.

Each object's v-pointer points to the v-table that, in turn, has a pointer to each of the virtual member functions. When the `Mammal` part of the `Dog` is created, the v-pointer is initialised to point to the virtual member functions for `Mammal`.

When the `Dog` constructor is called and the `Dog` part of this object is added, the v-pointer is adjusted to point to the virtual function overrides in the `Dog` object.

When a pointer to a `Mammal` is used, the v-pointer continues to point to the correct function, depending on the real type o the object. Thus, when `speak()` is invoked, the correct function is invoked.

### You Can't Get There from Here

If the `Dog` object had a member function called `wagTail()` that wasn't in `Mammal`, you couldn't use the pointer to `Mammal` to access that function. Because `wagTail()` is not a virtual function and it is not in a `Mammal` object, you can get there without either a `Dog` object or `Dog` pointer.

### Slicing

Note that the virtual function magic only works on pointers and references. Passing an object by value will not enable the virtual member functions to be invoked.

Listing 18.3's program demonstrates what happens when passing an object by value, with a pointer, and with a reference.

### Listing 17.3 The Full Text of `listing_17_3.cpp`
```C++
#include <iostream>

class Mammal
{
public:
    Mammal() : age(1){ }
    ~Mammal(){ }

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
    Dog(){ }
    ~Dog(){ }

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
    Cat(){ }
    ~Cat(){ }

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

int main()
{
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

    return 0;
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
```

When compiled and run, Listing 17.3's program produces the following output:

```Console
(1) Dog, (2) Cat, (0) Quit: 1
Woof woof.
Woof woof.
Mammal, speak.
(1) Dog, (2) Cat, (0) Quit: 2
Meow meow.
Meow meow.
Mammal, speak.
(1) Dog, (2) Cat, (0) Quit: 0
Meow meow.
Meow meow.
Mammal, speak.
```

Here, Listing 18.3's program is very similar to Listing 18.1 and Listing 18.2's. The main differences are the simplified versions of `Mammal`, `Dog`, and `Cat`, and the three functions, `valueFunction()`, `ptrFunction()`, and `refFunction()`. `valueFunction()` is defined on lines 93-98 and accepts a `Mammal` object by value as its parameter. The function calls the object's `speak()` function and then returns. `ptrFunction()` is defined on lines 100-105 and accepts a pointer to a `Mammal` object as its parameter. The function calls the object pointed to's `speak()` function and then returns. `refFunction()` is defined on lines 107-112 and accepts a reference to a `Mammal` object as its parameter. The function calls the reference object's `speak()` function and then returns.

In `main()`, a `while()` loop is used to continuously ask the user to choose an animal. A `switch-case` statement is used assign either a new `Dog` or `Cat` object to a pointer to a `Mammal` object. If the value 0 is entered the loop will stop after this iteration. Afterwards, the pointer is passed to `ptrFunction()`, `refFunction()`, and `valueFunction()`. For the first two function calls, the derived classes' member functions are called; however, on the third call, the base class's member function is called.

In the case where the object is being passed by value, the function expects a `Mammal` object; however, it's passed a `Dog` object. As such, the compiler slices the `Dog` object down to just the `Mammal` part. At that point, `Mammal`'s `speak()` is called.

The listing's output shows that this is true for when a `Cat` is chosen.

### Virtual Destructors

It is permitted and even common in C++ to pass a pointer to a derived object when a pointer to a base object is expected. What happens when that pointer to a derived object is deleted? If the destructor is virtual, as it should be, the right thing happens - the derived class's destructor is called. Because the derived class's destructor will automatically invoke the base class's destructor, the entire object will be properly destroyed.

The rule of thumb is as follows: if any of the functions in your class are virtual, the destructor should also be virtual.

### Virtual Copy Constructors

No constructor can be virtual; however, there are times, when you need to pass in a pointer to a base object and have a copy of the correct derived object that is created. A common solution to this problem is to create a clone member function in the base class and make it virtual. A clone function creates a new copy of the current object and returns that object.

Because each derived class overrides the clone function, a copy of the derived class is created.

Listing 18.3's program demonstrates how a clone member function can be used.

### Listing 17.4 The Full Text of `listing_17_4.cpp`
```C++
#include <iostream>

class Mammal
{
public:
    Mammal();
    virtual ~Mammal();
    Mammal(const Mammal &rhs);
    virtual Mammal *clone();

    int getAge() const;
    virtual void speak() const;

protected:
    int age;
};

Mammal::Mammal() : age(1)
{
    std::cout << "Mammal() constructor." << std::endl;

    return;
}

Mammal::~Mammal()
{
    std::cout << "Mammal() destructor." << std::endl;

    return;
}

Mammal::Mammal(const Mammal &rhs) : age(rhs.getAge())
{
    std::cout << "Mammal() copy constructor." << std::endl;

    return;
}

Mammal *Mammal::clone()
{
    return new Mammal(*this);
}

int Mammal::getAge() const
{
    return age;
}

void Mammal::speak() const
{
    std::cout << "Mammal, speak." << std::endl;

    return;
}

class Dog : public Mammal
{
public:
    Dog();
    virtual ~Dog();
    Dog(const Dog &rhs);
    virtual Mammal *clone();

    void speak() const;
};

Dog::Dog()
{
    std::cout << "Dog() constructor." << std::endl;

    return;
}

Dog::~Dog()
{
    std::cout << "Dog() destructor." << std::endl;

    return;
}

Dog::Dog(const Dog &rhs) : Mammal(rhs)
{
    std::cout << "Dog() copy constructor." << std::endl;

    return;
}

Mammal *Dog::clone()
{
    return new Dog(*this);
}

void Dog::speak() const
{
    std::cout << "Woof woof." << std::endl;

    return;
}

class Cat : public Mammal
{
public:
    Cat();
    virtual ~Cat();
    Cat(const Cat &rhs);
    virtual Mammal *clone();

    void speak() const;
};

Cat::Cat()
{
    std::cout << "Cat() constructor." << std::endl;

    return;
}

Cat::~Cat()
{
    std::cout << "Cat() destructor." << std::endl;

    return;
}

Cat::Cat(const Cat &rhs) : Mammal(rhs)
{
    std::cout << "Cat() copy constructor." << std::endl;

    return;
}

Mammal *Cat::clone()
{
    return new Cat(*this);
}

void Cat::speak() const
{
    std::cout << "Meow meow." << std::endl;

    return;
}

int main()
{
    Mammal *array[3];
    Mammal *ptr;

    int choice, i;

    for (i = 0; i < 3; i++)
    {
        std::cout << "(1) Dog, (2) Cat, (3) Other: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ptr = new Dog;
            break;
        case 2:
            ptr = new Cat;
            break;
        case 3:
            ptr = new Mammal;
            break;
        default:
            break;
        }

        array[i] = ptr;
    }

    Mammal *otherArray[3];

    for (i = 0; i < 3; i++)
    {
        array[i]->speak();
        otherArray[i] = array[i]->clone();
    }

    for (i = 0; i < 3; i++)
    {
        otherArray[i]->speak();
    }

    return 0;
}
```

When compiled and run, Listing 17.4's program produces the following output:

```Console
(1) Dog, (2) Cat, (3) Other: 1
Mammal() constructor.        
Dog() constructor.
(1) Dog, (2) Cat, (3) Other: 2
Mammal() constructor.        
Cat() constructor.
(1) Dog, (2) Cat, (3) Other: 3
Mammal() constructor.
Woof woof.
Mammal() copy constructor.
Dog() copy constructor.
Meow meow.
Mammal() copy constructor.
Cat() copy constructor.
Mammal, speak.
Mammal() copy constructor.
Woof woof.
Meow meow.
Mammal, speak.
```

Here, Listing 17.4's program is similar to the previous listings. One of the differences is that each class's destructor has been declared using the `virtual` keyword. Another difference is that each class includes a clone member function, `clone()`. The clone function takes no parameters, and returns a pointer to a new `Mammal` object by calling the copy constructor, passing in itself as a `const` reference.

`Dog` and `Cat` both override the `clone()` function, initialising their data and passing in copies of themselves to their own copy constructors. Because `clone()` is virtual, this creates a virtual copy constructor.

The user is prompted to choose dogs, cats, or other, and these are created on lines 156-169.

As the program iterates over the array, each object has its `speak()` and `clone()` functions called, in turn, on lines 178-179. The result of the `clone()` call is a pointer to a copy of the object, which is then stored in a second array.

### The Cost of Virtual Member Functions

Because objects with virtual member functions must maintain a v-table, some overhead is required to employ them. If you have a small class from which you do not expect to derive other classes, there may be no reason to have any virtual functions at all.

After you declare any functions virtual, you'd paid most of the price of the v-table. At that point, you want the destructor to be virtual, and the assumption will be that all other functions will also be virtual. Consider any non-virtual function and be sure to understand why they aren't virtual.

## Summary

Polymorphism enables the same interface to be implemented with different member functions in a set of classes related by inheritance.

This make it possible for related objects to be used in the same manner, even if each object implements the behaviour differently.

Polymorphism achieves an important goal in object-orientated programming by letting similar objects handle related functionality by reusing an interface.

## Q & A

Q. Why not make all class functions virtual?

A. There is overhead with the first virtual function in the creation of a v-table. After that, the overhead is trivial. Many C++ programmers feel that if one function is virtual, all others should be too. Other C++ programmers disagree, believing that there should always be an explicit reason for what you do in a program.

Q. If a function `foo()` is virtual in a base class and is also overloaded so as to take one or two integers, and the derived class overrides the function take one parameter, what is called when a pointer to a derived object calls the two-integer function?

A. This causes an error. The overriding of the one-integer form of the function hides the entire base class function. The compiler fails, stating `foo()` only takes one parameter.

### Workshop

### Quiz

1. How does a C++ program know which virtual function to call when the objects are stored in a variable of the base class type?

    A. The function has a `virtual` keyword
    B. A v-table is used
    C. It is not possible

<!-- B. The v-table keeps track of this information for you. It is the overhead associated with this table that makes virtual functions slightly more expensive to use than regular functions. -->

2. What type of member function cannot be virtual?

    A. Constructor
    B. Destructor
    C. Clone

<!-- A. The constructor (including the copy constructor). -->

3. What is it called when a pointer is bound to an object at runtime, as in polymorphism?

    A. Late binding
    B. Static binding
    C. Derefencing

<!-- A. Late binding is when it occurs at runtime. Static binding is when it occurs during compilation. -->

### Activities

1. Modify Listing 18.1's program by removing `Dog`'s `speak()` member function. Can you think of examples where it makes sense to do this?

2. Modify Listing 17.3's program to remove the `virtual` keyword on line 9. Can you see why the override functions are never called?


