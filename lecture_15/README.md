# Lecture 15: Using Operator Overloading

## What You'll Learn in this Lecture:

* How to overload operators in member functions
* How to overload the assignment operator to manage memory
* How to support classes with dynamically allocated variables

## Operator Overloading

The built-in types in C++ work with operators such as addition (+), multiplication (*), subtraction (-), and division (/), making it easy to use these in expressions. For example:

```C++
int a = 1, b = 2, c = 3, d;
d = a * b + c;
```

Here, the variables `a` and `b`'s values are multiplied together, and the result added with `c`'s value, the result of which is then assigned to `d`. The C++ compiler knows to multiply and add the integers when it sees the * and + operators in the expression.

A class could provide the same functionality with `multiply()` and `add()` member functions, but the syntax is a lot more complicated. For example:

```C++
Number a(1);
Number b(2);
Number c(3);
Number d, temp;

temp = a.multiply(b);
d = temp.add(c);
```

Here, the objects `a` and `b` are multiplied together and the result added with `c`, the result is then assigned to `d`. 

It is obvious that this code is longer and more complex than the previous snippet's expression. To make things simpler, classes can be manipulated with operators by using a technique called operator overloading.

Operator overloading defines what happens when a specific operator is used with an object of a class. Almost all operators in C++ can be overloaded.

Expressions written using operators are easier to read and understand.

Listing 15.1's program provides a basic class, which will be extended to use operator overloading in additional listings.

### Listing 15.1 The Full Text of `listing_15_1.cpp`
```C++
#include <iostream>

class Counter
{
public:
    Counter();
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

int main()
{
    Counter count;
    std::cout << "count's value is: " << count.getValue() << std::endl;

    return 0;
}
```

When compiled and run, Listing 15.1's program produces the following output:

```Console
count's value is: 0
```

Here, a class named `Counter` is declared on lines 3-14. It is used to control a counter's value. The class has a public constructor, destructor, and two accessors, `getValue()` and `setValue()`. It has one private member variable, `value`. The constructor is defined on lines 16-19 and initialises the class's member variable. The destructor is defined on lines 21-24 and does nothing. The accessors are defined on lines 26-36 and get and set `value`, respectively.

On lines 40-41, a `Count` object named `count` is created and a message displaying its `value` variable's value is displayed.

Unlike a built-in type, such as an `int`, the `Counter` object cannot be incremented, decremented, added, subtracted, multiplied, or divided, or otherwise manipulated with any operators. 

Operator overloading overcomes this limitation.

### Writing an Increment Method

Operator overloading provides functionality that would otherwise be missing in user-defined classes, such as `Counter`. When you implement an operator for a class, you are overloading that operator.

The most common way to overload an operator in a class is to use a member function. The function's declaration takes the following form:

```C++
returnType operatorsymbol(parameter list)
{
    // body
}
```

The name of the function is `operator` followed by the operator being defined, such as + or ++. The `returnType` is the function's return type and the parameter list holds zero, one, or two parameters (depending on the operator).

Listing 15.2's program illustrates how to overload the increment operator.

### Listing 15.2 The Full Text of `listing_15_2.cpp`
```C++
#include <iostream>

class Counter
{
public:
    Counter();
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    void increment();
    const Counter& operator++();

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

void Counter::increment()
{
    ++value;

    return;
}

const Counter& Counter::operator++()
{
    ++value;

    return *this;
}

int main()
{
    Counter count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    count1.increment();
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    ++count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    Counter count2 = ++count1;
    std::cout << "count1's value is: " << count1.getValue();
    std::cout << ", count2's value is: " << count2.getValue() << std::endl;
    
    return 0;
}
```

When compiled and run, Listing 15.2's program produces the following output:

```Console
count1's value is: 0
count1's value is: 1
count1's value is: 2
count1's value is: 3, count2's value is: 3
```

Here, a class named `Counter` is declared on lines 3-14. It is used to control a counter's value. The class has a public constructor, destructor, two accessors, `getValue()` and `setValue()`, and two member functions, `increment()` and `operator++()`. It has one private member variable, `value`. The constructor is defined on lines 19-22 and initialises the class's member variable. The destructor is defined on lines 24-27 and does nothing. The accessors are defined on lines 29-39 and get and set `value`, respectively. `increment()` is defined on lines 41-46 and uses the prefix increment operator to increment `value`. `operator++()` is defined on lines 48-53 and uses the prefix increment operator to increment `value` and returns a reference to the class's instance.

On lines 57-58, a `Count` object named `count1` is created and its `value` value is displayed. Here, 0 is displayed.

On lines 60-61, `count1`'s `increment()` member function is called and its `value` value is displayed. Here, 1 is displayed.

On lines 63-64, the prefix increment operator is used on `count1` and its `value` value is displayed. Here, 2 is displayed. The compiler interprets this as a call to the implementation of `operator++()`.

On lines 66-68, a second `Count` object named `count2` is created. It is assigned the value of `count1` once the prefix incremented operator is applied. Afterwards, `count1` and `count2`'s values are displayed. Here, 3 and 3 are displayed, respectively.

### Overloading the Postfix Operator

In Listing 15.2, the prefix increment operator was used to increment the `Counter` class's `value` member variable. Given that the symbol ++ was used for the prefix increment operation, it raises the question of how can the same symbol be used for the postfix increment operation? The name of the function is not enough to differentiate between the two.

To handle this and overload the postfix operator, include an `int` variable as the only parameter to the `operator++()` member function. The integer is not used; it's just a signal that the function defines the postfix operator.

The prefix operator changes a variable's value before returning it in expressions. The postfix operator returns the value before changing it.

To do this in an overloaded member function, a temporary object must be created to hold the original value while the original object is incremented. The temporary object is then returned because the postfix operator requires the original value, not the incremented value.

The temporary object must be returned by value and not by reference. Otherwise, it goes out of scope as soon as the function returns.

Listing 15.3's program demonstrates how to overload the increment operator.

### Listing 15.3 The Full Text of `listing_15_3.cpp`
```C++
#include <iostream>

class Counter
{
public:
    Counter();
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    const Counter& operator++();        // prefix operator
    const Counter operator++(int);      // postfix operator

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

const Counter& Counter::operator++()
{
    ++value;

    return *this;
}

const Counter Counter::operator++(int)
{
    Counter temp(*this);
    ++value;
    
    return temp;
}

int main()
{
    Counter count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    count1++;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    ++count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    Counter count2 = ++count1;
    std::cout << "count1's value is: " << count1.getValue();
    std::cout << ", count2's value is: " << count2.getValue() << std::endl;
    
    count2 = count1++;
    std::cout << "count1's value is: " << count1.getValue();
    std::cout << ", count2's value is: " << count2.getValue() << std::endl;
    
    return 0;
}
```

When compiled and run, Listing 15.3's program produces the following output:

```Console
count1's value is: 0
count1's value is: 1
count1's value is: 2
count1's value is: 3, count2's value is: 3
count1's value is: 4, count2's value is: 3
```

Here, a class named `Counter` is declared on lines 3-17. It is used to control a counter's value. The class has a public constructor, destructor, two accessors, `getValue()` and `setValue()`, and two member functions, `operator++()` and `operator++()`. It has one private member variable, `value`. The constructor is defined on lines 19-22 and initialises the class's member variable. The destructor is defined on lines 24-27 and does nothing. The accessors are defined on lines 29-39 and get and set `value`, respectively. The first `operator++()` member function is defined on lines 41-46 and uses the prefix increment operator to increment `value`. The second `operator++()` member function is defined on lines 48-53 and uses the postfix increment operator to increment `value` and returns a copy of a temporary `Counter` object. The second `operator++()` function is differentiated from the first by the use of a `int` parameter, which isn't used.

On lines 58-59, a `Counter` object named `count1` is created and its value is displayed. Here, 0 is displayed.

On lines 61-65, the postfix operator is used to increment `count1`'s `value`, which is then displayed. Here, 1 is displayed. The compiler interprets this as a call to the second implementation of `operator++()`.

On lines 64-65, the prefix operator is used to increment `count1`'s `value`, which is then displayed. Here, 2 is displayed. The compiler interprets this as a call to the first implementation of `operator++()`.

On lines 67-69, a second `Count` object named `count2` is created. It is assigned the value of `count1` once the prefix increment operator is applied. Afterwards, `count1` and `count2`'s values are displayed. Here, 3 and 3 are displayed, respectively.

On lines 71-73, `count2` is assigned the value of `count1` once the postfix operator is applied. Afterwards, `count1` and `count2`'s values are displayed. Here, 4 and 3 are displayed, respectively. `count2`'s value is different to `count1`'s because the postfix operator returns the value before incrementing it.

### Overloading the Addition Operator

The increment is a unary operator, which means that it takes only one operand. The addition operator (+) is a binary operator that adds two operands together.

Listing 15.4's program demonstrates how the addition operator can be overloaded.

### Listing 15.4 The Full Text of `listing_15_4.cpp`
```C++
#include <iostream>

class Counter
{
public:
    Counter();
    Counter(int initialValue);
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    const Counter operator+(const Counter&);

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::Counter(int initialValue) : value(initialValue)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

const Counter Counter::operator+(const Counter& rhs)
{
    return Counter(value + rhs.getValue());
}

int main()
{
    Counter count1(4), count2(13), count3;
    
    count3 = count1 + count2;
    
    std::cout << "count1's value is: " << count1.getValue() << std::endl;
    std::cout << "count2's value is: " << count2.getValue() << std::endl;
    std::cout << "count3's value is: " << count3.getValue() << std::endl;
     
    return 0;
}
```

When compiled and run, Listing 15.4's program produces the following output:

```Console
count1's value is: 4
count2's value is: 13
count3's value is: 17
```

Here, a class named `Counter` is declared on lines 3-17. It is used to control a counter's value. The class has a public default constructor, an overloaded constructor, a destructor, two accessors, `getValue()` and `setValue()`, and one member functions, ``operator+()`. It has one private member variable, `value`. The default constructor is defined on lines 19-22 and initialises the class's member variable. The overloaded constructor is defined on lines 24-27 and initialises `value` with the constructor's parameter's value. The destructor is defined on lines 29-32 and does nothing. The accessors are defined on lines 34-44 and get and set `value`, respectively. `operator+()` is defined on lines 46-49 and returns a `Counter` object initialised using the sum of the current `value` and the constructor's parameter's `value`.

On line 53, three `Counter` objects named `count1`, `count2`, and `count3` are created. `count1` and `count2`'s `value`s are assigned 4 and 13, respectively. `count3` is initialised with the default value, 0.

On line 55, `operator+()` is invoked and `count3` is assigned the sum of `count1` and `count2`. The compiler interprets this statement as if the following code had been written:

```C++
count3 = count1.operator+(count2);
```

There are two operands in an addition expression. The left operand is the object whose `operator+()` function is called. The right operand is the parameter of this function.

If an `add()` method was written, it could have been called with a statement like this:

```C++
count3 = count1.add(count2);
```

Operator overloading makes programs easier to use and understand by replacing explicit function calls.

### Limitations on Operator Overloading

Although operator overloading is one of the most powerful features in the C++ language, it has limitations.

Operators for built-in types, such as `int`, cannot be overloaded. The precedence order cannot be changed, and the "arity" of the operator - whether it is a unary, binary, or tertiary operator - cannot be changed. You cannot make up new operators either.

Operator overloading is one of the aspects of C++ most overused and abused by new programmers. It is tempting to create new and interesting uses for some of the more obscure operators, but this often leads to confusing and difficult to read code.

### `operator=`

The C++ compiler provides each class with a default constructor, destructor, and copy constructor. A fourth member function supplied by the compiler, when one has not been specified in the class, defines the assignment operator.

The assignment operator's overloaded function takes the form `operator=()` and is called when you assign a value to an object. For example:

```C++
Bike myBike;
myBike.setSpeed(5);
Bike yourBike;
yourBike.setSpeed(10);
myBike = yourBike;
```

Here, a `Bike` object named `myBike` is created and its member variable `speed` is given the value 5. Next, a `Bike` object named `yourBike` is created and its member variable `speed` is given the value of 10. Lastly, the assignment operator (=) is used.

Because of this assignment, `myBike`'s `speed` variable is assigned `yourBike`'s `speed` variable's value. After the statement executes, `myBike`'s `speed` is equal to 10.

In this case, the copy constructor is not called because `myBike` already exists, so there's no need to construct it. The compiler calls the assignment operator instead.

At this point, it's important to remember the difference between a shallow copy and a deep copy. A shallow copy just copies the members, making both objects point to the same area on the heap. A deep copy allocates the necessary memory.

The occurs here. Because the object `yourBike` already exists and has memory allocated, that memory must be deleted to prevent a memory leak.

As such, when overloading the assignment operator, the first thing that needs to be done is delete the memory assigned to the class's pointers. For example:

```C++
delete speed;
```

This works but doesn't account for the case where an object may be assigned to itself. For example:

```C++
myBike = myBike;
```

This isn't a likely example, but the class needs to be able to handle this situation. If you don't guard against this, the self-assignment causes `myBike` to delete its own memory allocation. After it does, when it's ready to copy the memory from the right side of the assignment, that memory is gone.

This can be prevented if the assignment operator checks to see whether the right side of the assignment operator is the object itself by using the `this` pointer.

Listing 15.5's program demonstrates how the assignment operator can be overloaded.

### Listing 15.5 The Full Text of `listing_15_5.cpp`
```C++
#include <iostream>

class Bike
{
public:
    Bike();
    ~Bike();

    int getSpeed() const;
    void setSpeed(int newSpeed);

    Bike operator=(const Bike&);

private:
    int *speed;
};

Bike::Bike()
{
    speed = new int;

    *speed = 0;

    return;
}

Bike::~Bike()
{
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

Bike Bike::operator=(const Bike& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    delete speed;
    speed = new int;
    
    *speed = rhs.getSpeed();
    
    return *this;
}

int main()
{
    Bike myBike;
    std::cout << "myBike's speed: " << myBike.getSpeed() << " m/s" << std::endl;

    std::cout << "Setting myBike's speed to 5 m/s." <<std::endl;
    myBike.setSpeed(5);
    std::cout << "myBike's speed: " << myBike.getSpeed() << " m/s" << std::endl;

    Bike yourBike;
    std::cout << "yourBike's speed: " << yourBike.getSpeed() << " m/s" << std::endl;

    std::cout << "Copying myBike to yourBike." << std::endl;
    yourBike = myBike;

    std::cout << "myBike's speed: " << myBike.getSpeed() << " m/s" << std::endl;
    std::cout << "yourBike's speed: " << yourBike.getSpeed() << " m/s" << std::endl;

    return 0;
}
```

When compiled and run, Listing 15.5's program produces the following output:

```Console
myBike's speed: 0 m/s
Setting myBike's speed to 5 m/s.
myBike's speed: 5 m/s
yourBike's speed: 0 m/s
Copying myBike to yourBike.
myBike's speed: 5 m/s
yourBike's speed: 5 m/s
```

Here, a class named `Bike` is declared on lines 3-16. It emulates a bike, allowing for its speed to increase or decrease. The class has a public constructor and destructor; two public accessors, `getSpeed()` and `setSpeed()`; and an overloaded assignment member function, `operator=()`. The class has one private member variable, a pointer to an `int`, `speed`. The constructor is defined on lines 18-25 and allocates memory to `speed` and assigns it the value 0. The destructor is defined on lines 27-30 and does nothing. The accessors are defined on lines 32-42 and get and set `speed`'s value, respectively. The overloaded assignment operator is defined on lines 44-57 and assigns the parameter's `speed` value to the current object's `speed` variable before returning a dereferenced pointer to the current object.

On lines 61-62, a `Bike` object named `myBike` is created and its `speed`'s value is displayed. Here, 0 is displayed.

On lines 64-66, `main()` displays a message and sets `myBike`'s speed to 5. Afterwards, the changed speed is displayed. Here, 5 is displayed.

On lines 68-69, a second `Bike` object named `yourBike` is created and its `speed`'s value is displayed. Here, 0 is displayed.

On lines 71-72, `main()` displays a message and `myBike` is assigned to `yourBike`. This invokes the `operator=()` member function. The function takes one parameter, a constant reference to a `Bike` object. In the function, an `if` statement tests whether the current object's address is the same as the parameter's address. If it is, the function returns a dereferenced pointer to the current object; otherwise, the current object's `speed`'s memory is freed and new memory on the heap allocated. Afterwards, `speed` is assigned the parameter's `speed` variable's value. Lastly, a dereferenced pointer to the current object is returned.

On lines 74-75, `myBike` and `yourBike`'s `speed` values are displayed. Here, 5 and 5 are displayed, respectively.

> **Note** On lines 51-52, the member variable `speed` is deleted and recreated on the heap. Although this is not strictly required, it's a good practice that avoids memory leaks when working with variable-length objects that do not overload this assignment operators.

## Conversion Operators

What happens when you try to assign a variable of a built-in type, such as an `int`, to an object of a user-defined class?

Listing 15.6's program demonstrates what happens in this case.

### Listing 15.6 The Full Text of `listing_15_6.cpp`
```C++
#include <iostream>

class Counter
{
public:
    Counter();
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

int main()
{
    int count1 = 5;
    
    Counter count2 = count1;
    std::cout << "count2's value is: " << count2.getValue() << std::endl;

    return 0;
}
```

When you try to compile the program, the following error message is generated:

```Console
.\listing_15_6.cpp: In function 'int main()':
.\listing_15_6.cpp:42:22: error: conversion from 'int' to non-scalar type 'Counter' requested
     Counter count2 = count1;
```

Here, the `Counter` class doesn't declare a member function that turns an `int` into a `Counter` object and so line 42 triggers a compile error. The compiler cannot figure out, without a corresponding function, that an `int` should be assigned to the object's member variable `value`.

This problem can be fixed with a conversion operator.

Listing 15.7's program demonstrates how a conversion operator can be used.

### Listing 15.7 The Full Text of `listing_15_7.cpp`
```C++
#include <iostream>

class Counter
{
public:
    Counter();
    Counter(int newValue);
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::Counter(int newValue) : value(newValue)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

int main()
{
    int count1 = 5;
    
    Counter count2 = count1;
    std::cout << "count2's value is: " << count2.getValue() << std::endl;

    return 0;
}
```

When compiled and run, Listing 15.7's program produces the following output:

```Console
count2's value is: 5
```

Here, Listing 15.7's `Counter` class differs from Listing 15.6's in that it has an overloaded constructor, which takes an `int` as a parameter. The overloaded constructor is defined on lines 22-25 and initialises the class's private member variable, `value` with the function's parameter's value.

Given this constructor, the compiler knows to call it when an integer is assigned to a `Counter` object.

### The `int()` Operator

Listing 15.7 demonstrated how to assign a built-in type to an object. It is also possible to assign an object to a built-in value. For example:

```C++
Counter count1(10);
int count2 = count1;
std::cout << "count2: " << count2 << std::endl ;
```

As this sample is, it would not compile. Listing 15.7's `Counter` class knows how to convert an `int` to a `Counter` object, but not the other way around.

C++ provides conversion operators that can be added to a class to specify how to implicit conversions to built-in types.

Listing 15.8's program demonstrates how to use conversion operators.

### Listing 15.8 The Full Text of `listing_15_8.cpp`
```C++
#include <iostream>

class Counter
{
public:
    Counter();
    Counter(int newValue);
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    operator unsigned int();

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::Counter(int newValue) : value(newValue)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

Counter::operator unsigned int()
{
    return (value);
}

int main()
{
    Counter count1(10);

    int count2 = count1;

    std::cout << "count1's value is: " << count2 << std::endl;
    std::cout << "count2's value is: " << count2 << std::endl;

    return 0;
}
```

When compiled and run, Listing 15.8's program produces the following output:

```Console
count1's value is: 10
count2's value is: 10
```

Here, Listing 15.8's `Counter` class differs from Listing 15.7's in that it includes a conversion operator declared on line 13. The conversion operator is defined on lines 46-49 and returns the private member variable, `value`'s value. The integer returned by the function matches the type in the function declaration.

Now the compiler knows how to turn integers into `Counter` objects and how to turn `Counter` objects into integers. Now, the two types can be assigned to each other freely.

Note that conversion operators do not specify a return value, even though are returning a converted value.

## Summary

Operator overloading is one of the most powerful aspects of the C++ language. By defining how operators behave in the classes you design, you make it easier to work with objects of those classes.

Almost all C++ operators can be overloaded.

Using operators to manipulate objects is a lot easier than calling member functions. It also results in programs that are easier to read.

Remember, don't overload an operator to do unusual things, such as making a postfix increment operator decrement a value. 

## Q & A

Q. Why would you overload an operator when you can just create a member function?
 
A. It is easier to use overloaded operators when their behaviour is well understood. Less code is required to accomplish the same task, and your classes can mimic the functionality of built-in types.

Q. What is the difference between the copy constructor and the assignment operator?

A. The copy constructor creates a new object with the same values as the existing object. The assignment operator changes an existing object so that it has the same values as another object.

Q. What happens to the int used in postfix operators?

A. Nothing. The `int` is only used as a flag to overload the prefix and postfix operators.

## Workshop

### Quiz

1. What can't you create totally new operators like ** for exponentiation?

    A. That operator isn't part of the language
    B. Because it uses an existing operator *
    C. You can create new operators

<!-- A. Because ** is not part of the language, the compiler doesn't know what to do with it. -->

2. Why is the overloaded syntax different for prefix and postfix increment and decrement operations?

    A. Because prefix and postfix return different values
    B. Because one uses ++ and the other uses --
    C. The syntax is the same

<!-- A. Because the behaviour differs depending on whether the ++ or -- appears before or after a variable, so the code must follow the same behaviour. -->

3. What do conversion operators do?

    A. Convert objects to built-in types
    B. Convert built-in types to objects
    C. Both A and B

<!-- A. They convert from the object type to a built-in type. -->

### Activities

1. Modify Listing 15.6's program to overload the equality operator (==). Use that operator to compare two `Bike` objects' `speed` values.

2. Modify Listing 15.5's program to overload the minus operator (-) and use it to perform a simple subtraction.
