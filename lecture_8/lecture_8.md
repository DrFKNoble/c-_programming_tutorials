# Lecture 8: Creating Basic Classes

## What You'll Learn in This Lecture

* What types are
* What classes and objects are
* How to define a new class and crate objects of that class

## What is a Type?

A type is an object with data and a set of abilities. C++ has built-in types including `int`, `float`, and `double`. We can also define our own types.

When writing a computer program to solve a complex problem, it is helpful to create representations of the objects that interact within the problem's definition.

For example, if you want to optimise a university's timetable, you could have objects that represent each course, objects that represent each room, and objects that represent each student. The closer the objects are to reality, the easier it is to write a program to solves the underlying problem.

## Creating New Types

The type of a variable tells you a lot about the variable. For example, if `height` is a `short`, we know that it can hold a value between 0 and 65,535.

The type of a variable tells you:

* Its size in memory
* The information it can hold
* The actions that can be performed on it

In C++ you define your own types to model a problem you are trying to solve. The mechanism for declaring a new type is to create a class. A class is a definition of a new type.

## Class and Members

A C++ class is a template used to create objects. After you define a class, objects created from that class can be used, just like any other data type.

A class is a collection of related variables and functions bundled together. The variables can be of any other type, including other classes.

Variables make up the data in the class, and functions perform tasks using that data. Bundling these together is called encapsulation.

Consider a bike. It can be thought of as a collection of objects, such as a frame, wheels, a seat, pedals, gears, a chain, and a handlebar. When we push the bike's pedals, it accelerates; when we push the bike's brakes, it decelerates. Combining these objects and how they work together is an example of encapsulation.

Encapsulation of a class makes it possible for other programs to use the class without knowing how it works. Users of the class only need to know what it does, not how it does it.

The variables of a class are called member variables. A `Bike` class might have member variables representing the bike's speed, wheels' diameters, the number of gears, and its colour. 

Member variables, also known as data members or instance variables, are part of a class, lust like wheels and brakes are part of a bike.

The functions in a class use and modify the member variables. They are called the member functions or methods. Member functions of a `Bike` class might include `pedal()` and `brake()`.

### Declaring a Class

To declare a class, use the `class` keyword followed by the information about the class's member variables and member functions. An opening brace and a closing brace enclose the class's definition. For example:

```C++
class Bike
{
public:
    unsigned int speed;
    unsigned int wheelSize;
    void pedal();
    void brake();
};
```

Here, a class named `Bike` is created with two member variables, `speed` and `wheelSize`, and two member functions, `pedal()` and `brake()`. All four can be used by other classes because the `public` keyword precedes them in the class definition.

Declaring this class does not allocate memory for a `Bike`. It just tells the compile what the `Bike` class is, what data it contains, and what it does.

It also tells the compiler how much room it must set aside for each of the Bike objects that are created. Here, `Bike` requires eight bytes of memory (`speed` requires four bytes and `wheelSize` requires four bytes). `Bike`'s member functions require no memory.

### Defining an Object

An object is created from a class by specifying its class and a variable name. For example:

```C++
Bike myBike;
```

This statement creates a `Bike` object named `myBike`. The `Bike` class is used as a template for the object. The object will have all member variables and member functions defined for the class.

C++ differentiates between the class `Bike`, which is the concept of a bicycle, and each instance of `Bike`.

An object is an individual instance of a class. When you create an object, you have "instantiated" it from the class.

> **Note**
Because C++ is case sensitive, all class names should follow the same convention to minimise errors. A common convention is to capitalise the first letter of a class's name.

## Accessing Class Members

After creating an object, the dot operator (.) can be used to access its member variables and member functions. For example:

```C++
Bike myBike;
myBike.speed = 1;
myBike.pedal();
myBike.brake();
```

## Private Versus Public Access

The `Bike` class has two public member variables and two public member functions. The `public` keyword makes these parts of the class available to the public, i.e. other classes and programs that use `Bike` objects.

All member variables and functions are private by default. They can only be accessed within the class's member functions. Public members can be accessed everywhere else. For example:

```C++
class Bike
{
    unsigned int speed;
    unsigned int wheelSize;
    void pedal();
    void brake();
};
```

Here, the member variables and member functions are private and accessible only to `Bike`'s member functions.

When the `public` keyword is used in a class's definition, all member variables and member functions after the keyword are public. For example:

```C++
class Bike
{
    char name[] = "Racer";   
public:
    unsigned int speed;
    unsigned int wheelSize;
    void pedal();
    void brake();
}
```

Here, the member variable `name` is private and accessible only to `Bike`'s member functions. The remaining member variables and member functions are public and accessible everywhere.

The keyword `private` makes all subsequent member variables and member functions private.

Each use of `public` and `private` changes access control from that point on to the end of the class, or until the next access control keyword.

Keeping member variables private limits access and controls how their values can be changed.

Although member variables can be public, it's a good idea to keep them private and make them accessible via member functions.

A function that is used to get or set a member variable is called an accessor. Other classes must call the accessor instead of working directly with the variable.

Accessors allow you to separate how data is stored from how it is used. If you change how data is stored, you don't need to rewrite functions that use the data.

## Implementing Member Functions

Every class member function that is declared must be defined.

A member function definition begins with the name of the class followed by the scope resolution operator (::) and the name of the function. For example:

```C++
void Bike::pedal()
{
    speed += 1;
    std::cout << "Pedalling. Speed: " << speed << " m/s" << std::endl;

    return 0;
}
```

Class member functions behave the same as regular functions; they can have parameters and return a value.

Listing 8.1's program demonstrate how to declare a class, define its member functions, and create an instance of it.

### Listing 8.1 The Full Text of `listing_8_1.cpp`
```C++
#include <iostream>

class Bike 
{
public:
    int getSpeed();
    void setSpeed(int);
    void pedal();
    void brake();
private:
    int speed;
};

int Bike::getSpeed() 
{
    return speed;
}

void Bike::setSpeed(int newSpeed)
{
    if (newSpeed > 0)
    {
        speed = newSpeed;
    }

    return;
}

void Bike::pedal()
{
    setSpeed(speed + 1);
    std::cout << "Pedalling. Speed: " << speed << " m/s" << std::endl;

    return;
}

void Bike::brake()
{
    setSpeed(speed - 1);
    std::cout << "Braking. Speed: " << speed << " m/s" << std::endl;

    return;
}

int main()
{

    Bike myBike;

    myBike.setSpeed(0);
    myBike.pedal();
    myBike.pedal();
    myBike.pedal();
    myBike.brake();

    return 0;
}
```

When compiled and run, Listing 8.1's program produces the following output:

```Console
Pedalling. Speed: 1 m/s
Pedalling. Speed: 2 m/s
Pedalling. Speed: 3 m/s
Braking. Speed: 2 m/s
```

Here, an instance of the `Bike` class named `myBike` is created. Its initial speed is set to 0 and the `pedal()` and `brake()` member functions are called a couple of times, increasing the object's `speed` member variable's value.

Lines 3-12 contain the definition of the `Bike` class. Line 5 contains the `public` keyword, which tells the compiler that the following member functions are publicly accessible. Line 6 declares the accessor `getSpeed()`, which returns an object's `speed` member variable's value. Line 7 declares the accessor `setSpeed()`, which takes and integer and sets an object's `speed` member variable's value to its parameter.

Line 10 begins the class's private section, which includes a single member variable, `speed`.

Lines 14-17 contain the definition of the member function `getSpeed()`. This function takes no parameters and returns an integer. Here, the scope resolution operator is used to tell the compiler that this definition belongs to the `Bike` class. `getSpeed`'s body includes only one statement, which returns the member variable `speed`'s value.

The program's `main()` function can't access `speed` directly because it is private in the `Bike` class. `main()`, however, has access to the public accessor `getSpeed()`. Because `getSpeed()` is a member function of `Bike`, it has access to `Bike`'s member variables. This access enables the member function to return `speed`'s value to `main()`.

Lines 19-27 contain the definition of the member function `setSpeed()`. This function takes an integer parameter and doesn't return a value. `setSpeed()`'s body includes statements that check if the function's parameter is greater than zero, if it is, then `speed`'s value is set to new; else, nothing happens. By using an accessor and making `speed` private, `Bike` controls how the variable is set. Here, it prevents `speed` from being negative.

Line 29 begins the definition of the `pedal()` member function. Its body calls the `setSpeed()` member function, increasing the instance's speed by 1 m/s and then displays the current speed.

Line 37 begins the definition of the `brake()` member function. Its body calls the `setSpeed()` member function, decreasing the instance's speed by 1 m/s and then displays the current speed. Because `setSpeed()` won't allow a negative speed, the minimum speed the instance can have is 0 m/s.

Line 45 begins the body of the program with the `main()` function. Its body creates an instance of the `Bike` class named `myBike`. It then sets `myBike`'s initial speed as 0 m/s and calls the object's `pedal()` and `brake()` member functions to accelerate and decelerate the instance's speed, respectively.

## Creating and Deleting Objects

There are two ways to define built-in types, such as `int`, `float`, and `double`. First, the variable can be declared and then a value can be assigned to it. For example:

```C++
int weight;
weight = 105;
```

Second, the variable can be declared and initialised at the same time. For example:

```C++
int weight = 105;
```

Defining the variable with an initial assignment ensures the variable always has a value. The value can be changed at any other point in the program.

Classes have a special member function called a constructor, which is called when an object of the class is instantiated. The constructor's job is to create a valid object, which often includes initialising its member variables. The constructor is a function with the same name as the class and do not return a value. Constructors may have parameters, like any other function in the class. For example:

```C++
Bike::Bike(int initialSpeed)
{
    setSpeed(initialSpeed);
}
```

Here, a `Bike`'s constructor sets its member variable `speed`'s value to `initialSpeed`'s value.

When declaring a constructor, its good practice to declare a destructor. Just as constructors create and initialise an object of a class, destructors clean up after objects and free any memory that was allocated to them. A destructor has the same name as the class preceded by a tilde (~) character. Destructors take no parameters and do not return a value. For example:

```C++
Bike::~Bike()
{
    // do nothing.
}
```

Here, the class requires no special actions to free up memory, so the destructor only includes a comment.

### Default Constructors

There are several ways to call constructors when setting up an object.

One way is to specify one or more parameters in parentheses. For example:

```C++
Bike myBike(1);
```

Here, the parameter is passed the class's constructor.

Another way is to not specify any parameters. For example:

```C++
Bike myBike();
```

Here, no parameters are passed to the class's constructor. This calls the class's default constructor.

### Constructors Provided by the Compiler

If a class doesn't include a constructor, such as in Listing 8.1's program, the compiler creates a default constructor.

The default constructor provided by the compiler takes no action; it's simply a constructor with no parameters and an empty body.

It's important to not:

* The default constructor is any constructor that takes no parameters. You can define it yourself or be provided one as a default by the compiler.
* If you define any constructor (with or without parameters), the compiler doesn't provide a default constructor.

If a class doesn't include a destructor, such as in Listing 8.1's program, the compiler creates a default destructor.

The default destructor provided by the compiler takes no action; it's simply a destructor with an empty body.

If you define a constructor, it's a good practice to define a destructor even if your destructor does nothing. It'll remind you to use the destructor when you need to explicitly free memory.

Listing 8.2's program demonstrates how to use a constructor to initialise an object's member variable's value.

### Listing 8.2 The Full Text of `listing_8_2.cpp`
```C++
#include <iostream>

class Bike 
{
public:
    Bike(int);
    ~Bike();
    int getSpeed();
    void setSpeed(int);
    void pedal();
    void brake();
private:
    int speed;
};

Bike::Bike(int initalSpeed)
{
    speed = initalSpeed;
}

Bike::~Bike()
{
    // do nothing.
}

int Bike::getSpeed() 
{
    return speed;
}

void Bike::setSpeed(int newSpeed)
{
    if (newSpeed > 0)
    {
        speed = newSpeed;
    }

    return;
}

void Bike::pedal()
{
    setSpeed(speed + 1);
    std::cout << "Pedalling. Speed: " << speed << " m/s" << std::endl;

    return;
}

void Bike::brake()
{
    setSpeed(speed - 1);
    std::cout << "Braking. Speed: " << speed << " m/s" << std::endl;

    return;
}

int main()
{

    Bike myBike(5);

    myBike.pedal();
    myBike.pedal();
    myBike.pedal();
    myBike.brake();

    return 0;
}
```

When compiled and run, Listing 8.2's program produces the following output:

```Console
Pedalling. Speed: 6 m/s
Pedalling. Speed: 7 m/s
Pedalling. Speed: 8 m/s
Braking. Speed: 7 m/s
```

Here, Listing 8.2's definition of `Bike` differs from Listing 8.1's by defining a constructor and a destructor. 

Lines 16-19 show the definition of the class's constructor. It takes an integer parameter and returns no value. The constructor's body initialises the class's member variable `speed`'s value with the parameter's value.

Lines 21-24 show the definition of the class's destructor. It takes no parameter, returns no value, and does nothing.

An instance of the `Bike` class is created on line 60 and given an initial value of 5 m/s.

## Summary

Throughout the programming's history, there have been several popular programming methodologies. Here, we have introduced the idea of Object Orientated Programming (OOP).

In OOP, a program consists of one or more objects, each containing its own member variables and member functions. The objects are separate from each other and specialise in a specific function.

By designing objects to be independent of each other, code is more easily reused elsewhere.

## Q & A

Q. How big is a class object?

A. A class object's size in memory is determined by the sum of the sizes of its member variables. Class functions don't take up room as part of the memory set aside for the object.

Some compilers align variables in memory in such a way that two-byte variables consume more than two-bytes.

Q. Why shouldn't I make all the member data public?

A. Making member data private enables the client of the class to use the data without worrying about how it is stored or computed. Public data is like global data - any code that uses the object can access the data. So if it becomes changed, it's often difficult figuring out what happened.

## Workshop

### Quiz

1. Which one of the following does not take up computer memory?

    A. Class
    B. Object
    C. Both

<!-- A. A class occupies no memory because it is just a definition of how an object would be created. An object is the implementation of that class. -->

2. What keywords prevent some member data and functions from being used outside of the class?

    A. `public`
    B. `private`
    C. Neither

<!-- B. Private data and functions can only be accessed only within the class itself. Public data and functions can be accessed outside of the class. Class data should be private and class functions should be public. -->

### Activities

1. Modify Listing 8.1 to add a second Bike. Give it an initial value and try the `pedal()` and `brake()` member functions on it.

2. Modify Listing 8.2 to add a member variable called `wheelSize()` that must have a value greater than 4 when set with an accessor.
