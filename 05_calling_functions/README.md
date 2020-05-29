# Lecture 5: Calling Functions

## What You'll Learn in this Lecture:

* What a function does
* How to declare and define a function
* How to call functions with arguments
* How to return a value from a function

## What is a Function?

A function is a section of a program that can act on data and return a value. Every C++ program has at least one function, the `main()` function, which is called automatically when the program runs. This function can contain statements that call other functions, some of which call others, and so on.

Each function has a name that's used to call the function. The execution of the program branches to the first statement in that function and continues until it reaches a `return` statement or the last statement of the function. At that point, execution resumes at the place where the function was called.

A well-design function performs a specific task. Complicated tasks should be broken down into multiple functions, each of which can be called in turn. This makes code easier to understand and maintain.

## Declaring and Defining Functions

Before you write a function, you must declare it.

A function declaration tells the compiler the function's name, the type of data the function produces, and the types of any parameters received by the function. A function's declaration, which is also called its prototype contains no code.

The declaration tells the compiler how the function works. The function prototype is a single statement, which ends with a semicolon. For example:

```C++
int addNumbers(int num1, int num2);
```

The three parts of the declaration are the following:

* The return type, `int`
* The name, `addNumbers`
* The type and name of two parameters, an `int` named `x` and an `int` named `y`

The function prototype must match the three elements of the three elements of the function, or the program won't compile. the only thing that does not need to match are the names of the parameters. A function declaration doesn't need to name parameters at all. For example:

```C++
int addNumbers(int, int);
```

Although permitted, this approach results in code that is less clear than if parameter names were used.

The function's name is a short identifier that describes the task it performs. Because the name cannot contain spaces, a common convention is to capitalise each word in the name except for the first, e.g. `findArea`, `addNumbers`, `killMonster`, etc.

All functions are structured the same as a program's `main()` function. The statements in the function are enclosed within an opening { brace and closing } brace. If the function returns a value, there should be a `return` statement that returns a literal or variable of the proper return type. In C++, the `auto` keyword can be used to let the compiler choose the date type returned by a function.

Any C++ data type can be returned by a function. If a function doesn't produce a value, the declaration should use a `void` data type. A function that returns `void` does not need a return statement, although one can be used. For example:

```C++
return;
```

A function's definition includes looks like its declaration, but rather than end with a semicolon, it is followed by a compound statement defining what the function does. For example:

```C++
int addNumbers(int num1, int num2)
{
    sum = num1 + num2;
    return sum;
}
```

Here, this function adds two integers together and returns the sum. Listing 5.1 demonstrates how a function can be used in a program.

### Listing 5.1 The Full Text of listing5_1's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

int findArea(int length, int width);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int length = 0;
    int width = 0;
    int area = 0;

    std::cout << "How wide is your room (m)? ";
    std::cin >> width;
    std::cout << "How long is your room (m)? ";
    std::cin >> length;

    area = findArea(length, width);

    std::cout << "Your room's area is " << area << " m^2." << std::endl;

    return a.exec();
}

int findArea(int l, int w)
{
    return l * w;
}
```

When compiled and run, Listing 5.1's program produces the following output:

```Console
How wide is your room (m)? 3
How long is your room (m)? 2
Your room's area is 6 m^2.
```

The function prototype of `findArea()` is on line 3. The code for the function is written on lines 23-26. Compare `findArea()`'s prototype and definition's name, return type and parameter types: they're the same, but the names of the parameters are different. This is permitted if the types match.

> **Note**
If the definition of the function in Listing 5.1 was placed before `main()`, then we wouldn't need to declare the function. This is fine for smaller programs; however, in larger programs, it can be cumbersome to ensure all functions are defined before they are used. Declaring functions with prototypes means you don't have to worry about this issue.

## Using Variables with Functions

A function works with variables in several different ways. Variables can be specified as arguments when calling a function. Variables can be created in a function and cease to exist when the function completes. Variables can also be shared by the function and the rest of the program.

### Local Variables

A variable created in a function is called a local variable because it only exists locally within the function itself. When the function returns, all its local variables are no longer available for use in the program.

Local variables are created like any other variable. The parameters received by a function are also considered local variables. 

Listing 5.2 demonstrates the use of local variables.

### Listing 5.2 The Full Text of listing5_2's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

float convertFtoC(float fahrenheit);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    float fahrenheit = 0;
    float celcius = 0;

    std::cout << "Please enter the temperature in Fahrenheit: ";
    std::cin >> fahrenheit;

    celcius = convertFtoC(fahrenheit);

    std::cout << fahrenheit << " F is " << celcius << " C";

    return a.exec();
}

// function to convert temperature expressed in degrees Fahrenheit to degrees Celsius.
float convertFtoC(float fahrenheit)
{
    float celcius = 0;

    celcius = ((fahrenheit - 32) * 5) / 9;

    return celcius;
}
```

When compiled and run, Listing 5.2's program produces the following output:

```Console
Please enter the temperature in Fahrenheit: 77
77 F is 25 C
```

The program has a functioned named `convertFtoC()`, which is defined on lines 22-29, and takes one argument: a `float` value called `f`.

A local variable named `c` is declared on line 24 and assigned a value on line 26. The value is determined using the three-step formula for converting Fahrenheit to Celcius:

1. Subtract 32 from the number
2. Multiply the result by 5
3. Divide that result by 9

The converted value is return by the function in line 28. When the function ends, the local variables `fahrenheit` and `celcius` cease to exist and no longer can be used.

In the `main()` function, a variable named `fahrenheit` is created to hold a value input by a user. A variable named `celcius` is created to hold the converted temperature's value. These variables have the same names as the local variables in the `convertFtoC()` function, but they are different variables.

The reason is because they were created in a different scope. The scope of a variable is the portion of the program in which it exists. Scope determines how long a variable is available to your program and where it can be accessed. Variables declared within a block have the scope of that block. When the block ends with a closing } brace, the variables become unavailable.

You can declare variables within any block, such as an `if` conditional statement or function.

### Global Variables

Variables can be defined outside of all functions in a C++ program, including `main()`. These are called global variables because they are available everywhere in the program.

Variables defined outside of any function have global scope and are available from any function, including `main()`.

Listing 5.3 demonstrates the use of global variables.

### Listing 5.3 The Full Text of listing5_3 `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

void convertFtoC();

float fahrenheit = 0;
float celcius = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Please enter the temperature in Fahrenheit: ";
    std::cin >> fahrenheit;

    convertFtoC();

    std::cout << fahrenheit << " F is " << celcius << " C";

    return a.exec();
}

// function to convert temperature expressed in degrees Fahrenheit to degrees Celsius.
void convertFtoC()
{
    celcius = ((fahrenheit - 32) * 5) / 9;

    return;
}
```

When compiled and run, Listing 5.3's program produces the following output:

```Console
Please enter the temperature in Fahrenheit: 77
77 F is 25 C
```

Listing 5.3's program behaves the same as Listing 5.2's, despite the code being significantly different.

The float variables `fahrenheit` and `celcius` are declared in lines 5-6, outside of the `main()` and `convertFtoC()` functions. This makes them global variables that can be used anywhere, without regard to scope.

Because the variables are global, the `convertFtoC()` function takes no parameters and uses the global `fahrenheit` variable to convert the temperature to Celcius. The function also returns no value, using `void` as its return type, because it stores the converted temperature in the global `celcius` variable.

Although global variables might seem useful, they invite trouble in larger, more complex programs. They tend to create erroneous behaviour, which is difficult to debug. A global variable's value can be changed on any line, so if there's an error, the program needs to be checked line-by-line until the error is found.

One of the advantages of variable scope is that it limits the section of a program that must be checked when a variable either contains a value you weren't expecting or has been used incorrectly.

It's advised that you stick to using local variables to avoid any global variable-related issues.

## Function Parameters

A function receives information in the form of function parameters. There can be more than one parameter if they are separated by commas, or a function can be called with no parameters at all. The parameters sent to a function don't have to be of the same date type. For example:

```C++
int myAwesomeFunction(int name, float tower, char c);
```

Any valid C++ expression can be a function parameter, including constants, mathematical and logical expressions, and other functions that return a value.

The parameters passed to a function are local variables within that function, even if they have the same name as variables within the scope of the statement calling the function.

Consider the following:

```C++
int x = 4, y = 13;

swap(x, y);

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
```

It would seem that the variables `x` and `y`'s values are swapped; however, `swap()` can't do this. The reason is that the parameters received by `swap()` are local variables within that function. Changing their values does not affect the variables with the same name that were created right before `swap()` was called.

Because variables are passed by value to functions, `swap()` doesn't work.

In future lectures, we'll look at how we can address this problem.

## Returning Values from Functions

Functions return a value or `void`.

To return a value from a function, the keyword `return` is followed by a value to return. The value can be a literal, a value, or an expression, because all expressions produce a value. For example:

```C++
return 5;
return (x > 1);
return (convertFtoC(100));
```

These are all permitted `return` statements, assuming `convertFtoC()` returns a value. The value returned in the second statement is false if `x` is less than 1 or equal to 1, otherwise it is true.

It is permitted to have more than one return statement in a function.

Listing 5.4 demonstrates `return` statements being used.

### Listing 5.4 The Full Text of listing5_4's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

bool isLeapYear(int year);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int input = 0;

    std::cout << "Enter a year: ";
    std::cin >> input;

    if (isLeapYear(input))
        std::cout << input << " is a leap year." << std::endl;
    else
        std::cout << input << " is not a leap year." << std::endl;

    return a.exec();
}

bool isLeapYear(int year)
{

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;

}
```

When compiled and run, Listing 5.4's program produces the following output:

```Console
Enter a year: 2016
2016 is a leap year.
```

Leap years, which have 366 days rather than 365, obey the following rules:

* If the year is divisible by 4, it is a leap year,
* Unless the year is also divisible by 100, in which case it is not a leap year,
* Unless the year is divisible by 400, then it is a leap year.

The `isLeapYear()` function in lines 21-39 uses several `if` and `else` statements to implement these rules. The function returns a `bool` value `true` if a year is a leap year and `false` otherwise. The function takes an integer argument, the year to check.

There are four different `return` statements in the function, each of which ends the execution of the function in a different circumstance. Unlike other functions, the last line is not a `return` statement executed automatically. It is part of the conditional.

## Default Function Parameters

When a function is declared in a prototype to receive one or more parameters, the function only can be called with parameters of the proper data types. Consider the following:

```C++
bool isLeapYear(int year);
```

Here, `isLeapYear()` must take an integer value as the parameter. Calling a function with a missing or invalid value causes a compiler error.

An exception to this is if the function's prototype declares a default parameter value, in which case, it can be called without defining a value for that parameter. For example:

```C++
bool isLeapYear(int year = 2016); // function prototype.

bool leapYear = isLeapYear() // function being called without specifying a parameter value.
```

If `isLeapYear()` is called without specifying a year, the default of 2016 is used.

A function's definition does not change when default parameters are declared in the prototype.

When a function has more than one parameter, default values are assigned based on the order of the parameters. Any parameters can be assigned a default value, with one important restriction: if a parameter does not have a default value, no previous parameter may have a default value.

For example, here is a prototype with four parameters:

```C++
long set4DPoint(int x, int y, int z, int t);
```

The following change is not permitted:

```C++
long set4DPoint(int x, int y, int z = 3, int t);
```

The reason is because the parameter before `t`, has a default value.

Giving `t` a default value will change the prototype into a permitted form:

```C++
long set4DPoint(int x, int y, int z = 3, int t = 5);
```

This function could be called successfully with the following statement:

```C++
set4DPoint(1, 2);
```

The arguments' values would be 1, 2, 3, and 5 for `x`, `y`, `z`, and `t`, respectively.

Listing 5.5 demonstrates the use of default function parameters.

### Listing 5.5 The Full Text of listing5_5's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

int findVolume(int length, int width = 20, int height = 12);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int length = 100;
    int width = 50;
    int height = 2;
    int volume = 0;

    volume = findVolume(length, width, height);

    std::cout << "Volume 1: " << volume << " m^3" << std::endl;

    volume = findVolume(length, width);

    std::cout << "Volume 2: " << volume << " m^3" << std::endl;

    volume = findVolume(length);

    std::cout << "Volume 3: " << volume << " m^3" << std::endl;

    return a.exec();
}

int findVolume(int length, int width, int height)
{
    return (length * width * height);
}
```

When compiled and run, Listing 5.5's program produces the following output:

```Console
Volume 1: 10000 m^3
Volume 2: 60000 m^3
Volume 3: 24000 m^3
```

On line 3, the `findVolume()` prototype specifies that the function takes three integer parameters, the last two with default values.

The function computes the volume of a cube. If no `height` value is provided, the default `height` value of 12 is used. If no `width` value is provided, the default `width` value of 20 and default `height` value of 12 is used. It is not possible to provide a `height` value without providing a `width` value.

On lines 8-10, the dimensions `length`, `width`, and `height` are initialised. They are passed to the `findVolume()` function on line 13. The value is computed displayed.

On line 17, `findVolume()` is called again, but this time, no `height` value is provided. The default value is used, and the volume of the cube is displayed.

On line 21, `findVolume()` is called again, but this time, no `width` value is provided. The default values are used, and the volume of the default cube is displayed.

## Overloading Functions

In C++, more than one function can have the same name if there are differences in their arguments, a practice called function overloading. The functions must have different data types for parameters, a different number of parameters, or both. For example:

```C++
int powerUp(int xp);
int powerUp(int xp, char c);
int powerUp(float xp, int c);
```

The `powerUp()` function is overloaded with three different parameter lists. The first and second differ in the number of parameters, and the third one differs in the data types.

The parameters the function is called with determine which function will be called.

The return types for overloaded functions do not factor into whether they are different. Several overloaded functions can have the same return type, or different types. You can't overload a function by changing the return type. The parameter types or number of parameters must differ.

Function overloading is also called function polymorphism.

Overloading makes it possible to create a function that performs a similar task on different types of data without creating unique names for each function. If a program needs to average two numbers expressed in different formats, it could have functions named `averageInts()`, `averageFloats()`, etc.

To simplify, an overloaded function called `average()` could be used. For example:

```C++
int average(int, int);
float average(float, float);
double average(double, double);
```

All that is required that the correct combination of data types are passed to `average()` when calling it.

### Inline Functions

When you define a function, the C++ compiler creates just one set of instructions in memory. Execution of the program jumps to those instructions when the function is called and jumps back after the function returns to the next line in the calling function. If the program calls the function 10 times, it jumps 10 times to the same set of instructions each time. There is only one copy of the instructions that make up the function, not 10 copies.

Some performance overhead is required to jump in and out of functions. When a function consists of a small number of statements, you gain some efficiency if the program avoids making the jumps. The program runs faster if the function call can be avoided.

If a C++ function is declared with the keyword `inline`, the compiler does not create a real function. Rather, it copies the code from the inline function directly into the place where the function was called. It is just as if you had written the statements of the function right there.

If an inline function is called 10 times, the inline code is copied 10 times. The tiny improvement is speed could be swamped by the increase in the size of the executable program.

> **Note**
The `inline` keyword is a hint to the compiler that you would like the function to be in-lined. The compile can ignore this hint and make a real function call. Current compilers do a great job of optimising C++ code, so there's little to be gained from declaring an `inline` function.

The `inline` keyword is used as follows:

```C++
inline int double(int);
```

The function's definition does not change. For example:

```C++
int double(int input) 
{
    return (2 * input)
}
```

## Auto-Typed Return Value

A feature added in C++14 was the automatic deduction of a function's return type with the `auto` keyword. 

To make a function's return type determined by deduction, use `auto` where the return type is specified. For example:

```C++
auto addNumbers(int x, int y)
{
    return (x + y);
}
```

Because `x` and `y` are integers, the sum of them is also an `int`.

Keep in mind, though, that if a function has multiple `return` statements, they must all return the same data type.

Listing 5.6 demonstrates the use of the `auto` keyword to deduce a function's returned value's type. Note, the function must be defined before the code that uses it.

### Listing 5.6 The Full Text of listing5_6's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

auto findVolume(int length, int width = 20, int height = 12);

auto findVolume(int length, int width, int height)
{
    return (length * width * height);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int length = 100;
    int width = 50;
    int height = 2;
    int volume = 0;

    volume = findVolume(length, width, height);

    std::cout << "Volume 1: " << volume << " m^3" << std::endl;

    volume = findVolume(length, width);

    std::cout << "Volume 2: " << volume << " m^3" << std::endl;

    volume = findVolume(length);

    std::cout << "Volume 3: " << volume << " m^3" << std::endl;

    return a.exec();
}
```

When compiled and run, Listing 5.6's program produces the following output:

```Console
Volume 1: 10000 m^3
Volume 2: 60000 m^3
Volume 3: 24000 m^3
```

Because Listing 5.6's program makes use of a new feature of C++14, it may need to be compiled with the `--std=c++14` flag. For example:

```Console
g++ listing_5_6.cpp -o listing_5_6.exe -std=c++14
```

In Listing 5.6, the definition of `findVolume()` was moved above `main()`; if it hadn't, the compiler would have halted with the following error message:

```Console
listing_5_6.cpp: In function 'int main()':
listing_5_6.cpp:13:46: error: use of 'auto findVolume(int, int, int)' before deduction of 'auto'
     volume = findVolume(length, width, height);
                                              ^
listing_5_6.cpp:17:38: error: use of 'auto findVolume(int, int, int)' before deduction of 'auto'
     volume = findVolume(length, width);
                                      ^
listing_5_6.cpp:21:31: error: use of 'auto findVolume(int, int, int)' before deduction of 'auto'
     volume = findVolume(length);
                               ^
```

Note that the program produces the same output as Listing 5.5's program.

## Summary

Functions are a widely used aspect of C++. Every task a program performs is represented by a function. When that task can be broken down into smaller tasks, each of those can be a function, as well.

All functions should be declared using function prototypes, which are statements that identify the function's name, the order and type of parameters, and the data type that it returns. A function's return type can be figured out by the compiler using the `auto` keyword, a C++14 feature.

Each function in a program is written to perform a discrete task. The more specific the function, the smaller the function.

Function overloading makes it possible to use the same function name with several related functions. The data type and number of parameters to the function are used to differentiate between them. The C++ compiler figures out which one to execute using these differences.

## Q & A

Q. Why not make all variables global?

A. Although this used to be common in programming, as programs became more complex it became extremely difficult to find bugs in programs with globally accessible variables. The reason is because data could be misused in any part of the program. To minimise the change of error and make debugging easier, data should be kept in as local a scope as possible.

Q. Why aren't changes to the value of a function's parameters reflected in the calling function?

A. Parameters passed to a function are passed by value. That means that the parameter received by the function is a copy of the original value, even if it shares the same variable name. 

Q. What happens if I have the following two functions?

```C++
int findArea(int width, int length = 11);
int findArea(int size);
```

Will these overload? There are a different number of parameters, but the first on has a default value.

A. The declarations will compile; however, calling `findArea()` with one parameter will cause a compile-time error about "ambiguity between `findArea(int, int)` and `findArea(int)`."

## Workshop

### Quiz

1.  What happens when a variable is a parameter received by a called function?

    A. A copy of the variable is passed to the function.
    B. The actual variable is passed to the function.
    C. A compiler error occurs.

<!-- A. A copy of the variable is made, which is called "passing by value". Any changes to the variable within the function do not affect the original value. -->

2. When three overloaded functions have the same name, how does C++ know which one to call?

    A. The function's return types are different.
    B. The function's parameters are different.
    C. The order of the function, from top to bottom.

<!-- B. Overloaded functions must have parameters of different types or a different number of parameters. The compiler uses this difference to determine which function to call. The return type of the functions does not matter. -->

3. How many values can a `return` statement return?

    A. One.
    B. One or more.
    C. None or One.

<!-- C. A function can return no more than one value. When a function doesn't return any value, the `void` data type is used. -->

### Activities

1. Write a program that converts a temperature from Celsius to Fahrenheit. The formula to do this is to multiply the Celsius temperature by 9, divide the result by 5, and then add 32.
