# Lecture 12: Creating References

## What You'll Learn in This Lecture

* What references are
* How references differ from pointers
* How to create and use references
* What the limitations of references are
* How to pass values and objects into and out of functions by reference

## What is a Reference?

A reference is an alias. When you create a reference, you initialise it with the name of another object, the target. From then on, the reference acts as an alternative name for the target and anything done to the reference is done to the target.

References are different from pointers. Pointers are variables that hold the address of another object. References are aliases to an object.

## Creating a Reference

A reference is created by writing the type of the target object, followed by the reference operator &, followed by the name of the reference. For example:

```C++
int myVar = 5;
int &rMyVar = myVar;
```

Here, an `int` variable named `myVar` is created and initialised with the value 5. Afterwards, a reference named `rMyVar` is created and assigned the target `myVar`.

References can use any legal variable name, but it is a convention to start a reference's name with a lowercase 'r' and capitalise the following letter.

Listing 12.1's program demonstrates how to use a reference.

### Listing 12.1 The Full Text of `listing_12_1.cpp`
```C++
#include <iostream>

int main()
{
    int intOne;
    int &rSomeRef = intOne;

    intOne = 5;
    
    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;

    rSomeRef = 7;

    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;

    return 0;
}
```

When compiled and run, Listing 12.1's program produces the following output:

```Console
intOne: 5
rSomeRef: 5
intOne: 7
rSomeRef: 7
```

Here, a local `int` variable named `intOne` is created on line 5. On line 6, a reference to an `int` named `rSomeRef` is created and initialised to refer to `intOne`. If you do not initialise a reference, the compiler will generate an error. References must be initialised.

On line 8, `intOne` is assigned the value 5.

On lines 10-11, the values in `intOne` and `rSomeRef` are displayed. They are the same as `rSomeRef` is the reference to `intSome`.

On line 13, `rSomeRef` is assigned the value 7. Because it is an alias for `intOne`, `intOne` will also be assigned the value 7.

lines 15-17 perform the same function as lines 10-11. The value of `intOne` is the same as `rSomeRef`.

> **Note**
>The reference operator & is the same symbol as the one used for the address-of operator. In this case, it is used in the declaration.
>
>Remember, with pointers, an asterisk * is used in the declaration. In a statement, it is the indirect operator.

## Using the Address of Operator on References

If you ask a reference for its address, it returns the address of its target. This makes sense - references are just aliases for a target.

Listing 12.2's program demonstrates the address-of operator being used on a reference.

### Listing 12.2 The Full Text of `listing_12_2.cpp`
```C++
#include <iostream>

int main()
{
    int intOne;
    int &rSomeRef = intOne;

    intOne = 5;

    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;

    std::cout << "&intOne: " << &intOne << std::endl;
    std::cout << "&rSomeRef: " << &rSomeRef << std::endl;

    return 0;
}
```

When compiled and run, Listing 12.2's program produces the following output:

```Console
intOne: 5
rSomeRef: 5
&intOne: 0x61fe14
&rSomeRef: 0x61fe14
```

Here, a local `int` variable named `intOne` is created on line 5. On line 6, a reference to an `int` named `rSomeRef` is created and initialised to refer to `intOne`. If you do not initialise a reference, the compiler will generate an error. References must be initialised.

On line 8, `intOne` is assigned the value 5.

One lines 10-11, the values of `intOne` and `rSomeRef` are displayed. Both have the same value.

One lines 13-14, the addresses of `intOne` and `rSomeRef` are displayed. Both have the same address.

Take care to distinguish the different use of the & symbol on lines 6 and 13-14. On line 6 it is used as the reference operator to create a reference to `intOne`. On lines 13-14 it is used as the address-of operator to get `intOne` and `rSomeRef`'s addresses.

Even experienced C++ programmers, who know that references cannot be reassigned and are always aliases of their target, can be confused by what happens when you try to reassign a reference. What appears to be a reassignment turns out to be the assignment of a new value to the target.

Listing 12.3's program demonstrates what happens when you try to reassign a reference.

### Listing 12.3 The Full Text of `listing_12_3.cpp`
```C++
#include <iostream>

int main()
{
    int intOne;
    int &rSomeRef = intOne;

    intOne = 10;

    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;
    std::cout << "&intOne: " << &intOne << std::endl;
    std::cout << "&rSomeRef: " << &rSomeRef << std::endl;

    int intTwo = 20;

    rSomeRef = intTwo;

    std::cout << "intOne: " << intOne << std::endl;
    std::cout << "intTwo: " << intTwo << std::endl;
    std::cout << "rSomeRef: " << rSomeRef << std::endl;
    std::cout << "&intOne: " << &intOne << std::endl;
    std::cout << "&intTwo: " << &intTwo << std::endl;
    std::cout << "&rSomeRef: " << &rSomeRef << std::endl;

    return 0;
}
```

When compiled and run, Listing 12.3's program produces the following output:

```Console
intOne: 10
rSomeRef: 10
&intOne: 0x61fe14
&rSomeRef: 0x61fe14

intOne: 20
intTwo: 20
rSomeRef: 20
&intOne: 0x61fe14
&intTwo: 0x61fe10
&rSomeRef: 0x61fe14
```

Here, a local `int` variable named `intOne` is created on line 5. On line 6, a reference to an `int` named `rSomeRef` is created and initialised to refer to `intOne`. If you do not initialise a reference, the compiler will generate an error. References must be initialised.

On line 8 `intOne` is assigned the value 10.

On lines 10-13, `intOne` and `rSomeRef`'s values and addresses are displayed. They are identical.

On line 15 a `int` variable named `intTwo` is created and initialised with the value 20. One line 17, `rSomeRef` is assigned `intTwo`. 

Now, it would seem that the program is reassigning `rSomeRef` to now be an alias to the variable `intTwo`, but that's not what happens. Instead, `rSomeRef` continues to act as an alias for `intOne`, so this assignment is the same as:

```C++
intOne = intTwo;
```

On lines 19-25, `intOne`, `intTwo`, and `rSomeRef`'s values and addresses are displayed. `intOne` and `intTwo`'s values are the same. This is because `rSomeRef` continues to refer to `intOne` and not `intTwo`.

## What can be Referenced?

Any object can be referenced, including user-defined objects. Note that you create a reference to an object, not to a class or a data type such as `int`. For example, you can't do this:

```C++
int &rIntRef = int; // No, bad programmer!
```

You must initialise `rIntRef` to a particular integer. For example:

```C++
int aNumber = 100;
int &rIntRef = aNumber;
```

References to objects are used just like the object itself. Memory data and functions are accessed using the normal class member access operator (.). As with the built-in types, the reference acts as an alias to the object.

## Null Pointers and Null References

When pointers are not initialised, or when they are deleted, they should to be assigned a `nullptr`. A reference cannot be null, and a program with a reference to a null object is considered an invalid program. When a program is invalid, just about anything can happen.

Most compilers support null references without much complaint, crashing only if you try to use the reference in some way. Taking advantage of this, however, is not a good idea.

## Passing Function Arguments by Reference

Functions have two limitations: arguments are passed by value and the return statement only can return one value.

Passing values to a function by reference can overcome both of these limitations. In C++, passing by reference is accomplished in two ways: using pointers and using references. The syntax is different, but the result is the same: rather than create a copy  of variables in the scope of the function, the actual object is passed into the function.

Passing an object by reference enables the function to change the object being referred to.

Listing 12.4's program demonstrates what happens when passing variables by value.

### Listing 12.4 The Full Text of `listing_12_4.cpp`
```C++
#include <iostream>

void swap(int x, int y);

int main()
{
    int x = 10, y = 20;

    std::cout << "main(). Before swap(). x: " << x << ", y: " << y << std::endl;

    swap(x, y);

    std::cout << "main(). After swap(). x: " << x << ", y: " << y << std::endl;

    return 0;
}

void swap(int x, int y) {

    int temp;

    std::cout << "swap(). Before swap. x: " << x << ", y: " << y << std::endl;

    temp = x;
    x = y;
    y = temp;

    std::cout << "swap(). After swap. x: " << x << ", y: " << y << std::endl;

    return;
}
```

When compiled and run, Listing 12.4's program produces the following output:

```Console
main(). Before swap(). x: 10, y: 20
swap(). Before swap. x: 10, y: 20
swap(). After swap. x: 20, y: 10
main(). After swap(). x: 10, y: 20
```

Here, on line 7, two `int` variables named `x` and `y` are initialised with the values 10 and 20, respectively. On line 9, the values of `x` and `y` are displayed.

On line 11, `swap()` is called and passed `x` and `y`. The function displays the values passed to it, swaps them, and displays the new values.

On line 13, the values of `x` and `y` are displayed. However, the values are unchanged.

The problem here is `x` and `y` are passed to `swap()` by value. Local copies are made in the function and those copies were swapped, and the originals unchanged.

There are two ways to solve this problem in C++: you can make the parameters of `swap()` pointers to the original values, or you can pass in references to the original values.

### Making `swap()` Work with Pointers

When you pass in a pointer, you pass in the actual address of the object. Thus, the function can manipulate the value at that address.

To make `swap()` change the actual values using pointers, the function should be declared to accept to `int` pointers. Then, by dereferencing them, the values of `x` and `y` will be swapped.

Listing 12.5 demonstrates how pointers can be used with a function.

### Listing 12.5 The Full Text of `listing_12_5.cpp`
```C++
#include <iostream>

void swap(int *pX, int *pY);

int main()
{
    int x = 10, y = 20;

    std::cout << "main(). Before swap(). x: " << x << ", y: " << y << std::endl;

    swap(&x, &y);

    std::cout << "main(). After swap(). x: " << x << ", y: " << y << std::endl;

    return 0;
}

void swap(int *pX, int *pY)
{
    int temp;

    std::cout << "swap(). Before swap. x: " << *pX << ", y: " << *pY << std::endl;

    temp = *pX;
    *pX = *pY;
    *pY = temp;

    std::cout << "swap(). After swap. x: " << *pX << ", y: " << *pY << std::endl;

    return;
}
```

When compiled and run, Listing 12.5's program produces the following output:

```Console
main(). Before swap(). x: 10, y: 20
swap(). Before swap. x: 10, y: 20
swap(). After swap. x: 20, y: 10
main(). After swap(). x: 20, y: 10
```

Here, on line 7, two `int` variables named `x` and `y` are initialised with the values 10 and 20, respectively. On line 9, the values of `x` and `y` are displayed.

On line 11, `swap()` is called and passed the addresses of `x` and `y`. The function uses the dereference operator to display the values passed to it, swaps them, and displays the new values.

On line 13, the values of `x` and `y` are displayed. This time, the values are swapped successfully.

### Implementing `swap()` with References

Listing 12.5's program works, but `swap()`'s syntax is cumbersome in a couple ways. First, the repeated need to dereference the pointers in the function makes it error-prone and hard to read. Second, the need to pass the address of the variables in the calling function makes the function's inner workings overly apparent to its users.

A goal of C++ is to prevent the caller of a function from worrying how it works, instead focusing on what it does and the value it returns. Passing by pointers puts the burden on the calling function, which is not where it belongs. The calling function must know to pass in the address of the object it wants to swap.

The burden of understanding the reference semantics should be on the function implementing the swap. To accomplish this, you use references. 

Listing 12.6's program demonstrates how references can be used with a function.

### Listing 12.6 The Full Text of `listing_12_6.cpp`
```C++
#include <iostream>

void swap(int &rX, int &rY);

int main()
{
    int x = 10, y = 20;

    std::cout << "main(). Before swap(). x: " << x << ", y: " << y << std::endl;

    swap(x, y);

    std::cout << "main(). After swap(). x: " << x << ", y: " << y << std::endl;

    return 0;
}

void swap(int &rX, int &rY)
{
    int temp;

    std::cout << "swap(). Before swap. x: " << rX << ", y: " << rY << std::endl;

    temp = rX;
    rX = rY;
    rY = temp;

    std::cout << "swap(). After swap. x: " << rX << ", y: " << rY << std::endl;

    return;
}
```

When compiled and run, Listing 12.6's program produces the following output:

```Console
main(). Before swap(). x: 10, y: 20
swap(). Before swap. x: 10, y: 20
swap(). After swap. x: 20, y: 10
main(). After swap(). x: 20, y: 10
```

Here, on line 7, two `int` variables named `x` and `y` are initialised with the values 10 and 20, respectively. On line 9, the values of `x` and `y` are displayed.

On line 11, `swap()` is called and references to `x` and `y`. The function displays the values passed to it, swaps them, and displays the new values.

On line 13, the values of `x` and `y` are displayed. Again, the values are swapped successfully.

References provide the convenience and ease of use of normal variables with the power and pass-by-reference capability of pointers.

## Understanding Function Headers and Prototypes

The `swap()` function that takes references is easier to use and the code is easier to read. However, how does the calling function know if the values are passed by reference or by value? As a user of `swap()`, the programmer must ensure that the function will in fact change the parameters.

This is another use for the function prototype. By examining the parameters declared in the prototype, which is typically in a header file along with all the other prototypes, the programmer knows that the values passed into `swap()` are passed by reference and this will be swapped properly.

If `swap()` had been a member function of a class, the class declaration, also available in a header file, would have supplied this information.

In C++, users of classes rely on the header file to tell them all that is needed. This file acts as the interface to the class or function. The actual implementation is hidden from the client, which enables the programmer to focus on the problem at hand and to use the class or function without concern for how it is implemented.

## Returning Multiple Values

Functions only return one value; however, what if you need to get two or more values back from a function? One way to solve this is to pass two objects into the function by reference. the function can then fill the objects with the correct values. Because passing by reference enables a function to change the original objects, this effectively lets the function return multiple pieces of information. This approach bypasses the return value of the function, which can then be used to report errors.

This can be done with either pointers or references.

Listing 12.7's program demonstrates how pointers can be used to return multiple values.

### Listing 12.7 The Full Text of `listing_12_7.cpp`
```C++
#include <iostream>

enum ERROR_CODE { SUCCESS, ERROR };

ERROR_CODE addMul(const int &in1, const int &in2, int *sum, int *prod);

int main()
{

    int a = 0, b = 0, sum = 0, prod = 0;

    std::cout << "Enter a positive number (> 0): ";
    std::cin >> a;
    std::cout << "Enter a positive number (> 0): ";
    std::cin >> b;

    if(addMul(a, b, &sum, &prod) == SUCCESS)
    {
        std::cout << "a + b = " << sum << std::endl;
        std::cout << "a * b = " << prod << std::endl;
    }
    else
    {
        std::cout << "Error: numbers must be positive (> 0)." << std::endl;
    }

    return 0;
}

ERROR_CODE addMul(const int &in1, const int &in2, int *sum, int *prod)
{
    if (in1 > 0 && in2 > 0)
    {
        *sum = in1 + in2;
        *prod = in1 * in2;

        return SUCCESS;
    }
    else
    {
        *sum = 0;
        *prod = 0;

        return ERROR;        
    }
  
}
```

When compiled and run, Listing 12.7's program produces the following output:

```Console
Enter a positive number (> 0): 10
Enter a positive number (> 0): 20
a + b = 30
a * b = 200
```

Here, on line 10, four `int` variables named `a`, `b`, `sum`, and `prod` are all initialised with the values 0.

On lines 12-15, the user is asked to enter two positive, non-zero numbers. These are stored in `a` and `b`.

On line 17, `addMul()` is called and passed the values of `a` and `b` and the addresses of `sum` and `prod`. If the function returns a `SUCCESS` value, lines 19-20 display the computed values; else, line 24 displays a warning message.

The function checks to see if the passed parameters are both positive, non-zero values. If they are, it uses the dereference operator to assign `sum` and `prod` the sum and product of the first two parameters passed to the function, respectively, and returns `SUCCESS`; else, it assigns the value 0 to `sum` and `prod` and returns `ERROR`.

### Returning Values by Reference

Although Listing 12.7's program works, it can be made easier to read and maintain by using references instead of pointers.

Listing 12.8's program demonstrates how references can be used to return multiple values.

### Listing 12.8 The Full Text of `listing_12_8.cpp`
```C++
#include <iostream>

enum ERROR_CODE { SUCCESS, ERROR };

ERROR_CODE addMul(const int &in1, const int &in2, int &sum, int &prod);

int main()
{

    int a = 0, b = 0, sum = 0, prod = 0;

    std::cout << "Enter a positive number (> 0): ";
    std::cin >> a;
    std::cout << "Enter a positive number (> 0): ";
    std::cin >> b;

    if(addMul(a, b, sum, prod) == SUCCESS)
    {
        std::cout << "a + b = " << sum << std::endl;
        std::cout << "a * b = " << prod << std::endl;
    }
    else
    {
        std::cout << "Error: numbers must be positive (> 0)." << std::endl;
    }

    return 0;
}

ERROR_CODE addMul(const int &in1, const int &in2, int &sum, int &prod)
{
    if (in1 > 0 && in2 > 0)
    {
        sum = in1 + in2;
        prod = in1 * in2;

        return SUCCESS;
    }
    else
    {
        sum = 0;
        prod = 0;

        return ERROR;        
    }
  
}
```

When compiled and run, Listing 12.8's program produces the following output:

```Console
Enter a positive number (> 0): 1
Enter a positive number (> 0): 2
a + b = 3
a * b = 2
```

Here, on line 10, four `int` variables named `a`, `b`, `sum`, and `prod` are all initialised with the values 0.

On lines 12-15, the user is asked to enter two positive, non-zero numbers. These are stored in `a` and `b`.

On line 17, `addMul()` is called and passed the values of `a` and `b` and the addresses of `sum` and `prod`. If the function returns a `SUCCESS` value, lines 19-20 display the computed values; else, line 24 displays a warning message.

The function checks to see if the passed parameters are both positive, non-zero values. If they are, it assigns `sum` and `prod` the sum and product of the first two parameters passed to the function, respectively, and returns `SUCCESS`; else, it assigns the value 0 to `sum` and `prod` and returns `ERROR`.

Listing 12.8's program differs from Listing 12.7's in that `addMul()`'s parameters are references and no dereference operator is used in the function's body.

## Summary

References serve a similar purpose to pointers and are sometimes mistaken for them. The difference is that pointers are variables holding the address of an object, whereas references are aliases to an object.

Pointers and references are distinct.

A reference is an alias to another object, which is called a target. The reference serves as an alternate name for the target. Any actions taken to the reference actually affect the target.

References provide the power of pointers with a simpler syntax.

## Q & A

Q. Why use references if pointers can do everything references can?

A. References are easier to use and understand. The indirection is hidden, and there is no need to repeatedly dereference the variable.

Q. Why use pointers if references are easier?

Q. References cannot be `NULL` and they cannot be reassigned. Pointers offer greater flexibility, but are more difficult to use.

## Workshop

### Quiz

1. What is a reference?

    A. An alias
    B. A synonym
    C. Both

<!-- C. A reference is an alias and a synonym for another variable or object. -->

2. What operator is used to create a reference?

    A. ->
    B. &
    C. *

<!-- B. The ampersand (&) is used when declaring a reference. References must be initialised when declared. You cannot have a null reference like you can with pointers. -->

3. What is the default mechanism for passing variables to a called function in C++? What are some of the techniques to override that mechanism?

    A. Pass by value
    B. Pass by reference
    C. Pass by pointer

<!-- A. Pass by value, where a copy of the variable is passed to the function, not the original - which prevents the function from changing the original value. Pass by reference is one way to overcome this limitation. -->

### Activities

1. Modify Listing 12.7's program top use references rather than pointers.

2. Rewrite Listing 12.6's program to swap three numbers.


