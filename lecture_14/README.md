# Lecture 14: Advanced Functions

## What You'll Learn in this Lecture:

* How to overload member functions
* How to support classes with dynamically allocated variables
* How to initialise objects
* How to create copy constructors

## Overloaded Member Functions

Like regular functions, a class's member functions can also be overloaded.

Listing 14.1's program demonstrates how a class's member functions can be overloaded.

### Listing 14.1 The Full Text of `listing_14_1.cpp`
```C++
#include <iostream>

class Drawer
{
public:
    Drawer(int rows, int cols);
    ~Drawer();

    void drawShape() const;
    void drawShape(int newRows, int newCols) const;

private:
    int rows;
    int cols;
};

Drawer::Drawer(int newRows, int newCols)
{
    rows = newRows;
    cols = newCols;

    return;
}

Drawer::~Drawer()
{
    return;
}

void Drawer::drawShape() const
{
    drawShape(rows, cols);

    return;
}

void Drawer::drawShape(int newRows, int newCols) const
{
    for (int i = 0; i < newRows; i++)
    {
        for (int j = 0; j < newCols; j++)
        {
            std::cout << "*";

        }

        std::cout << std::endl;

    }

    return;
}

int main()
{

    Drawer rect(3, 3);

    std::cout << "rect.drawShape()" << std::endl;
    rect.drawShape();

    std::cout << std::endl;

    std::cout << "rect.drawShape(5, 5)" << std::endl;
    rect.drawShape(5, 5);

    return 0;
}
```

When compiled and run, Listing 14.1's program produces the following output:

```Console
rect.drawShape()
***
***
***

rect.drawShape(5, 5)
*****
*****
*****
*****
*****
```

Here, a class named `Drawer` is declared on lines 3-15. It is used to draw a rectangle of characters. The class has a public constructor, destructor, and overloaded function, `drawShape()`. It has two private variables, `rows` and `cols`. The constructor is defined on lines 17-23 and assigns its parameters to `rows` and `cols`. The destructor is defined on lines 25-28 and does nothing. The version of `drawShape()`, which takes no parameters is defined on lines 30-35. It calls the version of `drawShape()` that takes parameters, passing the class's private variables as arguments. The version of `drawShape()`, which takes parameters is defined on lines 37-53. It iterates over its `newRows` and `newCols` parameters' values, displaying a '*' character each time.

On line 57, `main()` creates an instance of `Drawer` named `rect`. The values 3 and 3 are assigned to the object's `rows` and `cols` private member variables, respectively, using the object's constructor.

On lines 59-60, `main()` displays a message and calls the `rect`'s member function `drawShape()` with no parameters. A 3 x 3 grid of '*' is displayed. Here, the values assigned to the object's private member variables are used for the dimensions of the grid.

On lines 64-65, `main()` displays a message and calls `rect`'s member function `drawShape()` with the arguments 5 and 5. A 5 x 5 grid of '*' is displayed. Here, the value passed as arguments to the overloaded function are used for the dimensions of the grid.

To decide between which member function to call, the compiler uses the number and type of parameters.

## Using Default Values

Like regular functions, a class's member functions can have default values.

Listing 14.2's program demonstrates how a class's member function's parameters can have default values.

### Listing 14.2 The Full Text of `listing_14_2.cpp`
```C++
#include <iostream>

class Drawer
{
public:
    Drawer(int rows, int cols);
    ~Drawer();

    void drawShape() const;
    void drawShape(int newRows, int newCols, bool useCurrentValue = true) const;

private:
    int rows;
    int cols;
};

Drawer::Drawer(int newRows, int newCols)
{
    rows = newRows;
    cols = newCols;

    return;
}

Drawer::~Drawer()
{
    return;
}

void Drawer::drawShape() const
{
    drawShape(rows, cols);

    return;
}

void Drawer::drawShape(int newRows, int newCols, bool useCurrentValue) const
{

    int tempRows;
    int tempCols;

    if (useCurrentValue == true)
    {
        tempRows = rows;
        tempCols = cols;
    }
    else
    {
        tempRows = newRows;
        tempCols = newCols;
    }
    
    for (int i = 0; i < tempRows; i++)
    {
        for (int j = 0; j < tempCols; j++)
        {
            std::cout << "*";

        }

        std::cout << std::endl;

    }

    return;
}

int main()
{   
    Drawer rect(3, 3);

    std::cout << "rect.drawShape(0, 0)" << std::endl;
    rect.drawShape(0, 0);

    std::cout << std::endl;

    std::cout << "rect.drawShape(5, 5, false)" << std::endl;
    rect.drawShape(5, 5, false);

    return 0;
}
```

When compiled and run, Listing 14.2's program produces the following output:

```Console
rect.drawShape(0, 0)
***
***
***

rect.drawShape(5, 5, false)
*****
*****
*****
*****
*****
```

Here, a class named `Drawer` is declared on lines 3-15. It is used to draw a rectangle of characters. The class has a public constructor, destructor, and overloaded function, `drawShape()`. It has two private variables, `rows` and `cols`. The constructor is defined on lines 17-23 and assigns its parameters to `rows` and `cols`. The destructor is defined on lines 25-28 and does nothing. The version of `drawShape()`, which takes no parameters is defined on lines 30-35. It calls the version of `drawShape()` that takes parameters, passing the class's private variables as arguments. The version of `drawShape()`, which takes parameters is defined on lines 37-64. It uses an `if-else` statement to test whether the `useCurrentValue` parameter is true; if it is, it uses the class's private member variables to define a grid of '*' characters' dimensions; otherwise, it uses the function's parameters. `useCurrentValue` has a default value of `true`.

On line 71, `main()` creates an instance of `Drawer` named `rect`. The values 3 and 3 are assigned to the object's `rows` and `cols` private member variables, respectively, using the object's constructor.

On lines 73-74, `main()` displays a message and calls the `rect`'s member function `drawShape()` with just two parameters. Here, the third parameter's default value is being used implicitly. Because it is `true`, the values assigned to the object's private member variables are used for the dimensions of the grid and a 3 x 3 grid of '*' characters is displayed.

On lines 78-79, `main()` displays a message and calls `rect`'s member function `drawShape()` with the arguments 5, 5, and true. Here, the third parameter's value is defined explicitly. Because it is `false`, the values passed as arguments to the function are used for the dimensions of the grid and a 5 x 5 grid of '* characters is displayed.

> **Note** While Listing 14.1 and Listing 14.2's programs achieve the same results, Listing 14.1's program is the simpler of the two and easier to understand. Also, it's a lot easier to extend overloaded functions. The default values approach can quickly become complex.

## Initialising Objects

Constructors, like member functions, can be overloaded. This capability is powerful and flexible.

For example, a `Drawer` object could have two constructors. The first could take no parameters and default values could be assigned to `rows` and `cols`. The second could accept two parameters and assign their values to the class's private data members. The compiler decides which constructor to use based on the type and number of parameters.

While you can overload constructors, you cannot overload a class's destructor. Destructors always have the same signature: a tilde (~) before the class's name and no parameters.

Constructors are created in two steps: first they are initialised, then the constructor's body is created. A class's member variables can be set during the initialisation or by assigning it a value in the constructor's body. For example:

```C++
Drawer::Drawer():
rows(3),
cols(3)
{
    // body of the constructor.
}
```

To assign values in a constructor's initialisation, put a colon after the closing parentheses of the constructor's parameter list. After the colon, list the name of the member variables followed by a pair of parentheses. Inside the parentheses, put an expression that initialises the member variable. If more than one variable is being initialised, separate them with a comma.

Here, `rows` and `cols` are initialised with the values 3 and 3, respectively.

> **Note** Because references and constants cannot be assigned values, they must be initialised using this approach.

## The Copy Constructor

In addition to providing a default constructor and destructor, the compiler also provides a default copy constructor. The copy constructor is called every time a copy of an object is made.

When you pass an object by value, either into a function or as the function's return value, a temporary copy of that object is made. If it is a user-defined object, the class's copy constructor is called.

All copy constructors take one parameter: a reference to an object of the same class. It's a good idea to make it a constant reference, because the constructor will not have to alter the object passed in. For example:

```C++
Drawer(const Drawer &draw);
```

Here, the `Drawer` constructor takes a constant reference to an existing `Drawer` object. The goal of the copy constructor is to make a copy of `draw`.

The default copy constructor simply copies each member variable from the object passed as a parameter to the member variables of the new object. This is called a shallow copy. While it works for most member variables, it doesn't work for member variables that are pointers to objects on the heap.

A shallow copy copies the exact values of one object's member variables into another object. Pointers in both objects end up pointing to the same memory. A deep copy, on the other hand copies the values allocated on the heap to newly allocated memory.

Listing 14.3 demonstrates how to perform a deep copy using a copy constructor.

### Listing 14.3 The Full Text of `listing_14_3.cpp`
```C++
#include <iostream>

class Bike
{
public:
    Bike();
    Bike(const Bike &);
    ~Bike();

    int getSpeed() const;
    void setSpeed(int newSpeed);

    void pedal();
    void brake();

private:
    int *speed;
};

Bike::Bike()
{
    speed = new int;
    *speed = 0;

    return;
}

Bike::Bike(const Bike &newBike)
{
    speed = new int;
    *speed = newBike.getSpeed();

    return;
}

Bike::~Bike()
{
    delete speed;
    speed = nullptr;

    return;
}

int Bike::getSpeed() const
{
    return *speed;
}

void Bike::setSpeed(int newSpeed)
{
    *speed = newSpeed;

    return;
}

void Bike::pedal()
{
    *speed += 1;

    std::cout << "Pedalling. Speed is now " << getSpeed() << " m/s" << std::endl;

    return;
}

void Bike::brake()
{
    if (*speed > 0)
    {
        *speed -= 1;
    }

    std::cout << "Braking. Speed is now " << getSpeed() << " m/s" << std::endl;

    return;
}

int main()
{

    std::cout << "Creating myBike" << std::endl;
    Bike myBike;

    myBike.pedal();

    std::cout << "Creating yourBike" << std::endl;
    Bike yourBike(myBike);

    std::cout << "My bike's speed: " << myBike.getSpeed() << std::endl;
    std::cout << "Your bike's speed: " << yourBike.getSpeed() << std::endl;

    std::cout << "Setting myBike speed to 5 m/s" << std::endl;
    myBike.setSpeed(5);

    std::cout << "My bike's speed: " << myBike.getSpeed() << std::endl;
    std::cout << "Your bike's speed: " << yourBike.getSpeed() << std::endl;

    return 0;
}
```

When compiled and run, Listing 14.3's program produces the following output:

```Console
Creating myBike
Pedaling. Speed is now 1 m/s
Creating yourBike
My bike's speed: 1
Your bike's speed: 1
Setting myBike speed to 5 m/s
My bike's speed: 5
Your bike's speed: 1
```

Here, a class named `Bike` is declared on lines 3-18. It is used to emulate riding a bike. 

The class has a public constructor, copy constructor, and destructor; two public accessor functions, `getSpeed()` and `setSpeed()`; and two public member functions, `pedal()` and `brake()`. The class has one private variable, a pointer to an int named `speed`. The constructor is defined on lines 20-26 and allocates `speed` memory on the heap and assigns the value 0 to it. The copy constructor is defined on lines 28-34 and allocates `speed` memory on the heap and assigns the value returned by its argument's `getSpeed()` member function to it. The destructor is defined on lines 36-42 and deletes `speed` and assigns a `nullptr` to it for safety. `getSpeed()` is defined on lines 44-47 and returns `speed`'s value. `setSpeed()` is defined on lines 49-54 and assigns a value to `speed`. `pedal()` is defined on lines 56-63 and increments `speed`'s value. `brake()` is defined on lines 65-75 and decrements `speed`'s value.

On lines 80-81, `main()` displays a message and creates a `Bike` object named `myBike`.

On line 83, `myBike`'s `pedal()` member function is called to increment its `speed` value. It is now equal to 1.

On lines 85-86, `main()` displays a message and creates a second `Bike` object named `yourBike`. Here, `myBike` is passed as an argument to `yourBike`'s constructor. `yourBike`'s copy constructor then performs a deep copy, copying the value of `myBike`'s `speed`, which is stored on the heap, into new memory. This way, if `myBike`'s `speed` value changes, it won�t affect `yourBike`'s `speed` value.

On lines 91-92, `main()` displays a message and `myBike`'s `setSpeed()` member function is called. `myBike`'s `speed` value is now equal to 5.

On lines 94-95, `main()` displays `myBike` and `yourBike`'s `speed` values. Both objects have different speeds and that changing one object's `speed` variable's value doesn't change the other object's instance.

When both objects fall out of scope, their destructors are automatically invoked. Their pointers are deleted and assigned `NULL` for safety.

## Compile-Time Constant Expressions

C++ compilers do everything they can to make programs run faster, optimising code wherever possible. One opportunity for increased efficiency is when two constants are added together. For example:

```C++
const int myAge = 33;
int myNewAge = myAge + 1;
```

Because both halves of the expression `myAge + 1` are constants, compilers evaluate the expression and store it in the form as the result 34. The compiler acts as if `myNewAge` was assigned the value of 34.

Functions can use the `const` keyword to return a const value. For example:

```C++
const int getMyAge()
{
    return 33;
}
```

It could be reasoned that the following expression could be optimised:

```C++
int myNewAge = 1 + getMyAge();
```

Although the function returns a constant, the function itself might not be constant. It might change global variables or call non-constant member functions.

Constant expressions use the `constexpr` keyword. For example:

```C++
constexpr int getMyAge()
{
    return 33;
}
```

The constant expression must have a non-`void` return type and return an expression as its content. The expression returned can only contain literal values, calls to other constant expressions, or values that have also been defined with `constexpr`.

The following statements define a constant called `myAge` and a constant expression called `myNewAge` using the `constexpr` keyword:

```C++
const int myAge = 33;
constexpr int myNewAge = 1 + myAge;
```

Listing 14.4's program demonstrates how a `constexpr` can be used.

### Listing 14.4 The Full Text of `listing_14_4.cpp`
```C++
#include <iostream>

constexpr double getPi()
{
    return (double) 22/7;
}

int main()
{
    float radius;

    std::cout << "Enter the radius of a circle (cm): ";
    std::cin >> radius;

    double area = getPi() * radius * radius;

    std::cout << "The area of the circle is: " << area << " cm^2" << std::endl;
    
    return 0;
}
```

When compiled and run, Listing 14.4's program produces the following output:

```Console
Enter the radius of a circle (cm): 5
The area of the circle is: 78.5714 cm^2
```

Here, a function named `getPi()` is defined on lines 3-6. It accepts no parameters and returns an expression, which approximates the value of PI(3.14286).

On line 10, a `float` variable named `radius` is declared. On lines 12-13, `main()` prompts the user for a value, which is then assigned to `radius`.

On line 15, a `double` variable named `area` is created and assigned the area of a circle computed using the `getPi()` and `radius`'s values.

On line 17, `main()` displays the computer area.

Here, 22/7 is calculated as a constant expression. `getPi()` can do this because it contains only one statement, `return` followed by an expression, and only includes literals, constants, or constant expressions.

## Summary

Constructors, like functions, can be overloaded. The number and type of parameters enable the compiler to determine which constructor should be called by the class's users.

A constructor may have default values, just like member functions and regular functions.

When an object is copied, all member variables are copied by the default copy constructor. This creates a problem if member variables are pointers to objects on the heap. Both the original object and copy point to the same object. Also, when one object goes out of scope and is destroyed, the other is still has an active pointer. Any attempt to use that pointer will crash the program.

This problem can be solved by writing your own copy constructor, which performs a deep copy. The constructor takes one parameter: the original object that will be copied. In the constructor, car can be taken so that the pointer uses new heap memory.

# Q & A

Q. Why would you ever use default values when you can overload a function?

A. Because it's easier to maintain one function that two and easier to understand a function with default parameters than to study the bodies of two functions. Also, updating one of the functions and forgetting to update the other is a common source of bugs.

Q. Given the problems with overloaded methods, why not always use default values instead?

A. Overloaded methods supply capabilities not available with default variables, such as varying the list of parameters by type rather than just a value.

Q. When writing a class constructor, how do you decide what to put in the initialisation and what to put in the body of the constructor?

A. A simple rule is to do as much as possible in the initialisation phase and initialise all member variables there. Some things, such as computations and `std::cout` statements must be put in the constructor's body.

Q. Can an overloaded method have a default parameter?

A. Yes. There's no reason not to combine these powerful features. One or more overloaded methods can have their own default values, following the normal rules for default variables in any method.


## Workshop

### Quiz

1. With overloaded functions, how does the compiler know which version to call?

    A. The function's name
    B. The function's number and type of parameters
    C. The function's return type

<!-- B. The compiler ignores the return type. Only the name, number, and parameter type matter. -->

2. Can you use overloaded functions with defaults?

    A. Yes
    B. No
    C. Only if the parameter types are different

<!-- A. Yes, if the number and types of parameters remain unique among each version of the function. -->

3. When destroying a pointer in a destructor, what should be assigned to the pointer for safety?

    A. `nullptr`
    B. 0
    C. A and B

<!-- C. Setting it to `nullptr` or 0 has the same effect, making it a null pointer. -->

### Activities

1. Modify Listing 14.1's program's so that its `drawShape()` member function just uses default values.

2. Modify Listing 14.3's program to change `yourBike`'s `speed` value after `myBike`'s `speed` value has been changed. Does changing `yourBike`'s speed value affect `myBike`'s speed value?

