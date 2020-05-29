# Lecture 9: Advanced Classes

## What You'll Learn in this Lecture:

* What constant member functions are
* How to separate the class interface from its implementation
* How to manage your classes
* How to find and avoid bugs

## `const` Member Functions

If you declare a member function with the `const` keyword, it indicates that the function won't change the value of any members of the class. To declare a function as constant, put the keyword `const` after the function's parentheses. For example:

```C++
void greetUser() const;
```

Accessors used to retrieve a variable's value, which are also called getter functions, often are constant functions. Listing 8.2's program contained two accessors:

```C++
void setSpeed(int newSpeed);
int getSpeed();
```

The `setSpeed()` member function cannot be a `const` function as it changes the member variable `speed`'s value. The `getSpeed()` member function can be a `const` function as it doesn't change any values. As such, `getSpeed()` can be written as:

```C++
int getSpeed() const;
```

If a function is declared to be `const`, but it changes the object by changing the value of any of its member variables, the compiler will flag it as an error.

It's good practice to declare as many functions to be `const` as possible. This enables the compiler to catch unintended changes to member variables,  instead of letting these errors appear when the program runs.

## Interface Versus Implementation

The parts of a program that create and use objects are the clients of the class. The class declaration serves as a contract with these clients. The contract tells the clients what data the class has available and what it can do.

For example, in the `Bike` class, the contract promises that every instance of `Bik`, its speed can be initialised, that its speed can be get and set, and that it can use `pedal()` and `brake()` functions.

If `getSpeed()` is made a `const` function, the contract promises it won't change the `Bike` on which it is called in that function.

## Organising Class Declarations and Function Definitions

Class definitions are often kept separate from the implementations in the source code of C++ programs. Each function declared in a class must have a definition. Like functions, the definition of a class function has a header and a body.

The definition must be in a file that the compiler can find. Most C++ compilers expect that file to end with `.cpp`.

Although you can put the declaration in the source code file, a common convention is to put the declaration in a header file ending with `.hpp` (or `.h`).

So if the declaration of the `Bike` class is in `Bike.hpp`, the definition of the class's functions would be in `Bike.cpp`. The header file can be incorporated into the `.cpp` file using a preprocessor directive. For example:

```C++
#include "Bike.hpp"
```

The reason to separate them is because clients of a class don't care about the implementation. Everything they need to know is in the header file.

## Inline Implementation

Just as a function can be defined inline, a class's member functions can be defined inline. The keyword `inline` appears before the return value. For example:

```C++
inline int Bike::getSpeed()
{
    return speed;
}
```

You can also put the definition of a member function in the class's declaration, which automatically makes the function inline. For example:

```C++
class Bike
{
public:
    int getSpeed() const
    {
        return speed;
    }
    void setSpeed(int newSpeed);
};
```

Here, the `getSpeed()` definition has changed. Instead of a semicolon after `const`, there is a short block of code. The body of an inline function begins immediately after the declaration of the member function; there's no semicolon after the parentheses.

Listing 9.1 and 9.2's program demonstrate how Listing 8.2's program can be divided into separate source and header files.

### Listing 9.1 The Full Text of listing9_1's `main.hpp`
```C++
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

class Bike
{
public:
    Bike(int initialSpeed);
    ~Bike();
    int getSpeed() const
    {
        return speed;
    }
    void setSpeed(int newSpeed)
    {
        if (newSpeed >= 0)
        {
            speed = newSpeed;
        }

        return;
    }
    void pedal();
    void brake();

private:
    int speed;
};

#endif // MAIN_HPP
```

### Listing 9.2 The Full Text of listing9_1's `main.cpp`
```C++
#include <QCoreApplication>

#include "main.hpp"

Bike::Bike(int initialSpeed)
{
    setSpeed(initialSpeed);
}

Bike::~Bike()
{
}

void Bike::pedal()
{
    setSpeed(speed + 1);
    std::cout << "Pedaling. Speed: " << speed << " m/s" << std::endl;

    return;
}

void Bike::brake()
{
    setSpeed(speed - 1);
    std::cout << "Braking. Speed: " << speed << " m/s" << std::endl;

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bike myBike(5);

    myBike.pedal();
    myBike.pedal();
    myBike.brake();

    return a.exec();
}
```

When compiled and run, Listing 9.1 and 9.2's program produces the following output:

```Console
Pedalling. Speed: 6 m/s
Pedalling. Speed: 7 m/s
Braking. Speed: 6 m/s
```

Here, Listing 9.1 declares the class's member variables and member functions and Listing 9.2 defines them. The `getSpeed()` and `setSpeed()` member functions defined on lines 8-20 in Listing 9.1 have been define inline.

Line 1 of Listing 9.2 is a preprocessor directive that includes the header file `main.hpp` in the source code.

## Classes with Other Classes as Member Data

It is not uncommon to build a complex class by declaring simpler classes and including them in the declaration of the more complicated class.

For example, `Wheel`, `Motor`, and `Gearbox` classes might be declared and then combined in a `Car` class. This arrangement declares a "has-a" relationship: a car has a motor, a car has wheels, and a car has a gearbox.

Consider another example. A rectangle is comprised of four lines. Each line is defined by two points. A point is defined by x and y coordinates.

Listing 9.3 and 9.4's program demonstrates how a class can be used within another class.

### Listing 9.3 The Full Text of listing9_2's `main.hpp`
```C++
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

class Point
{
public:
    Point();
    Point(int newX, int newY);
    ~Point();

    void setX(int newX);
    void setY(int newY);
    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

class Rectangle
{
public:
    Rectangle();
    Rectangle(Point newTopLeft, Point newBottomRight);
    ~Rectangle();

    void setTopLeft(Point newTopLeft);
    void setBottomRight(Point newBottomRight);
    Point getTopLeft() const;
    Point getBottomRight() const;
    void display() const;

private:
    Point topLeft;
    Point bottomRight;
};

#endif // MAIN_HPP
```

### Listing 9.4 The Full Text of listing9_2's `main.cpp`
```C++
#include <QCoreApplication>

#include "main.hpp"

Point::Point()
{
    x = 0;
    y = 0;

    return;
}

Point::Point(int newX, int newY)
{
    x = newX;
    y = newY;

    return;
}

Point::~Point()
{
    // do nothing.

    return;
}

void Point::setX(int newX)
{
    x = newX;

    return;
}

void Point::setY(int newY)
{
    y = newY;

    return;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

Rectangle::Rectangle()
{
    topLeft.setX(0);
    topLeft.setY(0);
    bottomRight.setX(0);
    bottomRight.setY(0);

    return;
}

Rectangle::Rectangle(Point newTopLeft, Point newBottomRight)
{
    topLeft = newTopLeft;
    bottomRight = newBottomRight;

    return;
}

Rectangle::~Rectangle()
{
    // do nothing

    return;
}

void Rectangle::setTopLeft(Point newTopLeft)
{
    topLeft = newTopLeft;

    return;
}

void Rectangle::setBottomRight(Point newBottomRight)
{
    bottomRight = newBottomRight;

    return;
}

Point Rectangle::getTopLeft() const
{
    return topLeft;
}

Point Rectangle::getBottomRight() const
{
    return bottomRight;
}

void Rectangle::display() const
{
    std::cout << "Rect: [(" << topLeft.getX() << "," << topLeft.getY() << ")";
    std::cout << ",(" << bottomRight.getX() << "," << bottomRight.getY() << ")]" << std::endl;

    return;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Point topLeft(1, 1);
    Point bottomRight(10, 10);

    std::cout << "topLeft.x: " << topLeft.getX() << ", topLeft.y: " << topLeft.getY() << std::endl;
    std::cout << "bottomRight.x: " << bottomRight.getX() << ", bottomRight.y: " << bottomRight.getY() << std::endl;

    Rectangle rect(topLeft, bottomRight);

    rect.display();

    return a.exec();
}
```

When compiled and run, Listing 9.3 and 9.4's program produces the following output:

```Console
topLeft.x: 1, topLeft.y: 1
bottomRight.x: 10, bottomRight.y: 10
Rect: [(1,1),(10,10)]
```

Here, two classes `Point` and `Rectangle` are declared and defined in Listing 9.3 and 9.4, respectively. The class `Rectangle` uses the class `Point` to define a rectangle in terms of a top-left and bottom-right pair of points. Each point is a pair of x and y values. 

Lines 3-18 in Listing 9.3 declare the class `Point`, which is used to store a pair of x and y values.

The class has two constructors: a default constructor, which does nothing, and an overloaded constructor, which takes two integers as parameters. They are defined on lines 3-17 in Listing 9.4. The overloaded constructor takes the two integer parameters and assigns their values to `Point`'s member variables `x` and `y`. 

The class has a default destructor, which does nothing.

`Point` has four accessors to get and set the class's member variables `x` and `y`. They are defined on lines 26-48 in Listing 9.4. `setX()` and `setY()` set  `x` and `y`'s values, respectively. `getX()` and `getY()` return `x` and `y`'s values, respectively.

Lines 20-36 in Listing 9.3 declare the class `Rectangle`, which is used to store a pair of points.

The class has two constructors: a default constructor, which does nothing, and an overloaded constructor, which takes two Point objects as parameters. They are defined on lines 50-66 in Listing 9.4. The overloaded constructor takes the two Point object parameters and assigns them to `Rectangle`'s member variables `topLeft` and `bottomRight`.

The class has a default destructor, which does nothing.

`Rectangle` has four accessors to get and set the class's member variables `topLeft` and `bottomRight`. They are defined on lines 75-105 in Listing 9.4. `setTopLeft` and `setBottomRight` set `topLeft` and `bottomRight`'s values. `getTopLeft` and `getBottomRight` return `topLeft` and `bottomRight`'s values.

The class also contains a public member function, `display()`, which prints out the instance's points in a human-readable form.

On Lines 110-111 of Listing 9.4, two `Point` objects named `topLeft` and `bottomRight` are instantiated and their x and y values are initialised as 1 and 1 and 10 and 10, respectively. The program then displays their respective x and y values.

On line 116 of Listing 9.4, a `Rectangle` object named `rect` is instantiated and its corner points initialised as `topLeft` and `bottomRight`'s values. The program then uses the `display()` member function to display the rectangle.

## Summary

A C++ programmer doesn't need to use classes in their applications. Their programs can consist of just variables and functions, removing the need to know about Object-Orientated Programming (OOP).

Few programmers do this. It's much more effective to design a program as a series of classes that interact with each other.

Developing classes makes code more reusable. If an object that's useful in one program, it may be useful in another program.

Classes also make code more reliable. The tasks a program requires are packaged with the date necessary to get the work done. By thinking of a program as a set of objects with tasks to perform, the work is spread out and more easily organised. When there are issues, it's easier to determine the class where the error occurs.

## Q & A

Q. If using the `const` function to change a class may cause a compiler error, why shouldn't I just leave it out to avoid the error?

A. If you function logically shouldn't change the class, using the keyword `const` is a good way to enlist the compiler's help to find a simple mistake. For example:

```C++
class Go
{
public:
   void getSpeed() const
   {
       if (speed = 100)
       {
           std::cout << "So fast!";
       }
   }
private:
    int speed = 99;
};
```

Here, the public member function `getSpeed()` is supposed to check if the member variable `speed`'s value is equal to 100; however, the assignment operator has been used instead of the equality operator. As such, speed is being set to 100, which is not what is intended. Using `const` means that the compiler will find the error.

## Workshop

### Quiz

1. Which of the following file extensions is not common for C++ header files?

    A. .hpp
    B. .cpp
    C. .h

<!-- B. C++ header files normally end with .hpp (or .h). C++ source files end with .cpp.-->

2. What happens in Listing 9.3 and 9.4 if the `Point` class is not defined?

    A. A compiler error occurs
    B. The program runs incorrectly
    C. The results vary.

<!-- A. Assuming `Point` is not define elsewhere, the compiler reports an error about an undefined reference. -->

3. Where can you make a class function inline?

    A. In the class declaration
    B. In the class implementation
    C. Both

<!-- C. A class function that's included in the class declaration automatically is an inline function. Otherwise, a class function must include the `inline` keyword to request the function be executed inline. -->

### Activities

1. Split the `Point` class out of `listing_9_2.hpp` into its own header file and include it in `listing_9_2.cpp`. How does this change the compilation of `listing_9_2.cpp`? Do the results change?

2. Create a `Triangle` class that consists of three connected points, using the `Point` class.
