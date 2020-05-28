# Lecture 10: Creating Points

## What You'll Learn in This Lecture

* What pointers are
* How to declare and use pointers
* What the heap is and how to manipulate memory

## Understanding Pointers and Their Usage

One of the most powerful tools available to a C++ programmer is the pointer. Pointers provide the capability to manipulate computer memory directly. 

A variable is an object that can hold a value. An integer variable holds a number. A character variable holds a letter. A pointer is a variable that holds a memory address.

Computer memory is where variables are stored. By convention, memory is divided into sequentially numbered memory locations. Each of these locations is a memory address.

Every variable of every type is located at a unique address in memory. Figure 10.1 illustrates how an `unsigned long` integer variable `theAge` could be stored in memory.

### Figure 10.1 A schematic representation of `theAge`.
 Each location is 1 byte long. An unsigned long int is 4 bytes long, which equals 32 bits. Here, the address of `theAge` is 101.
<p align="center">  
    <img src="./images/Fig_10_1.png"><br>
</p>

Different computers number their memory using different schemes. Usually, programmers don't need to know the address of any given variable because the compiler handles the details. If you want to know a variable's address, you can use the address-of operator (&).

Listing 10.1's program demonstrates how the address-of operator can be used.

### Listing 10.1 The Full Text of `listing_10_1.cpp`
```C++
#include <iostream>

int main()
{
    unsigned short shortVar = 5;
    unsigned long longVar = 65535;
    long sVar = -65535;

    std::cout << "shortVar: " << shortVar;
    std::cout << " Address of shortVar: " << &shortVar << std::endl;
    std::cout << "sizeof(shortVar): " << sizeof(shortVar) << std::endl;
    std::cout << "longVar: " << longVar;
    std::cout << " Address of longVar: " << &longVar << std::endl;
    std::cout << "sizeof(longVar): " << sizeof(longVar) << std::endl;
    std::cout << "sVar: " << sVar;
    std::cout << " Address of sVar: " << &sVar << std::endl;
    std::cout << "sizeof(sVar): " << sizeof(sVar) << std::endl;

    return 0;
}
```

When compiled and run, Listing 10.1's program produces the following output:

```Console
shortVar: 5 Address of shortVar: 0x61fe1e
sizeof(shortVar): 2
longVar: 65535 Address of longVar: 0x61fe18
sizeof(longVar): 4
sVar: -65535 Address of sVar: 0x61fe14
sizeof(sVar): 4
```

Note, the actual address of each pointer will differ because each computer stores variables at different addresses, depending on what else is in memory and how much is available.

Here, three variables were declared and initialised: an `unsigned short` in line 5, an `unsigned long` in line 6, and a `long` in line 7. Their values and addresses are displayed in lines 9-14 by using the address-of operator.

Consider `longVar` and `sVar`'s addresses. See how they are separated by four bytes: the same size as the length of an `unsigned long` integer. Note that, while the addresses of where the variables are saved in memory may change each time the program is run, the difference between their addresses will remain the same.

There is no reason why you need to know the actual numeric value of the address of each variable. What you do care about is that each one has an address and that the right amount of memory has been allocated.

The compiler knows how much memory to allocate a variable when you tell it what a variable's type is. If you declare a `long` variable, the compiler knows to set aside four bytes. It takes care of assigning the actual address.

When a pointer is allocated, the compiler assigns enough memory to hold an address in your hardware and operating system.

### Storing the Address in a Pointer

Every variable has an address. Even without knowing a variable's specific address, you can store it in a pointer.

For example, suppose there is an integer variable named `myAge`. To declare a pointer named `pAge` to store `myAge`'s address, you write the following statement:

```C++
int *pAge = nullptr;
```

This declares `pAge` to be a pointer to an `int`. It is declared to hold the address of an `int`.

Pointers can have any name that is legal for other variables. It's a common convention to name all pointers starting with a lowercase 'p' and capitalise the following letter, e.g. `pAge`, `pMedian`, and `pCap`.

`pAge` is a variable like any other variable. When you declare an integer variable, it is set up to hold an integer value. When you declare a pointer, it is set up to hold an integer variable's address. A pointer is just a special type of variable that holds an address of an object in memory. Here, `pAge` is holding the address of an integer variable.

You declare the type of variable you want the pointer to point to. This tells the compiler how to treat the memory at the location the pointer points to. The pointer itself contains an address.

Here, `pAge` is initialised as `nullptr`, which represents a pointer whose address points to nothing. A pointer with this value is called a null pointer. All pointers, when they are created should be initialised to something. A pointer that isn't initialised is a wild pointer. Wild pointers are dangerous, because the cause a program to behave unpredictably when the pointer is used.

You may also see pointers initialised to 0. For example:

```C++
int *pAge = 0;
```

This achieves similar results to initialising the pointer with `nullptr`.

If you initialise a pointer with `nullptr`, you must specifically assign the address of the variable to the pointer. For example:

```C++
int myAge = 33;
int *pAge = nullptr;
pAge = &myAge;
```

Here, the first line defines an integer variable named `myAge` and assigns it the value 33. The second line defines a pointer to an integer named `pAge` and assigns it `nullptr`. The asterisk after the type, but before the variable's name indicates that `pAge` is a pointer.

The third line assigns `myAge`'s address to the pointer `pAge`. The address-of operator is being used to get `myAge`'s address.

>**Note**
Assigning a non-pointer to a pointer variable is a common error. Fortunately, the compiler will detect this and fail with an "invalid conversion" error.

At this point, `pAge` has its value the address of `myAge` and `myAge` has the value 33. A more concise approach to achieve the same is as follows:

```C++
int myAge = 33;     // define a variable
int *pAge = &myAge; // make a pointer to myAge
```

Here, `pAge` now contains the address of the `myAge` variable. Using `pAge`, you can determine the value of `myAge`, which is 33. Accessing `myAge` by using a pointer is called indirection: you're indirectly accessing `myAge` by using `pAge`.

Indirection access the value at the address held by a pointer. The pointer provides an indirect way to get the value held at that address.

### The Indirection Operator, or Using Pointer Indirectly

The indirection operator (*) is also called the dereference operator. When a pointer is dereferenced, the value at the address stored by the pointer is retrieved. Consider the following:

```C++
int myAge = 33;
int yourAge = 29;
myAge = yourAge;
```

A pointer provides indirect access to the value of the variable whose address it stores. To assign the value of `yourAge` to `myAge` using the pointer `pAge`, you write the following:

```C++
int myAge = 33;     // create a variable named myAge
int yourAge = 29;   // create a variable named yourAge
int *pAge = &myAge; // create a pointer and assign it myAge's address
*pAge = yourAge;    // change the value stored where pAge is pointing to yourAge's value.
```

The indirection operator * in front of the variable means "the value stored at". Here, it is used to make `myAge` equal to `yourAge`. The assignment says, "take the value stored in `yourAge` and assign it to the address where `pAge` is pointing to".

>**Note**
> The indirection operator * is used in two ways: declaration and dereference.
> When a pointer is declared, the asterisk indicates that a variable is a pointer. For example:
>
> ```C++
> int *pNumber = nullptr; // make a pointer to an int
> ```
> 
> When the pointer is dereferenced, the indirection operator indicates that the value at the memory location stored in the pointer is to be accessed, rather than the address itself. For example:
>
> ```C++
> *pNumber = 10;  // assign 10 to the value of pAge
> ```
>
> Note that the asterisk character is also used at the multiplication operator. The compiler knows which operate to call based on context.

### Pointers, Addresses, and Variables

It is important to distinguish between a pointer, the address the pointer holds, and the value at the address held by the pointer. This is the source of much of the confusion about pointers.

Consider the following:

```C++
int theVariable = 33;
int *pPointer = &theVariable;
```

`theVariable` is declared to be an integer variable initialised with the value 33. `pPointer` is declared to be a pointer to an integer; it was initialised with the address of `theVariable`. The address that `pPointer` holds is the address of `theVariable`. The value at that address is 33.

### Figure 10.2
A schematic representation of memory.
<p align="center">  
    <img src="./images/Fig_10_1.png"><br> 
    <!-- Need to update this to Fig_10_3.png tomorrow when I get into work -->
</p>

### Manipulating Data by Using Pointers

After a pointer is assigned the address of a variable, you can use that pointer to access the data in that variable.

Listing 10.2's program demonstrates how a pointer can be used to manipulate a variable's value.

### Listing 10.2 The Full Text of `listing_10_2.cpp`
```C++
#include <iostream>

int main()
{
    int myAge;              // a variable
    int *pAge = nullptr;    // a pointer

    myAge = 33;
    pAge = &myAge;           // assign address of myAge to pAge

    std::cout << "myAge: " << myAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    std::cout << "*pAge = 29" << std::endl;
    *pAge = 29;             // sets myAge to 29

    std::cout << "myAge: " << myAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    myAge = 33;

    std::cout << "myAge: " << myAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl;

    return 0;
}
```

Note, because Listing 10.2's program uses `nullptr`, it must be compiled with the `--std=c++14` flag.

When compiled and run, Listing 10.2's program produces the following output:

```Console
myAge: 33
*pAge: 33

*pAge = 29

myAge: 29
*pAge: 29

myAge: 33
*pAge: 33
```

Here, the program declares two variables: an `int` named `myAge` and a pointer to an `int` named `pAge`. 

On lines 8-9, `myAge` is assigned the value 33 and `pAge` is assigned the address of `myAge`. To assign the address, the address-of operator & is used.

Lines 11-12 display the values of `myAge` and the value at the address that `pAge` stores. To access the value at the address `pAge` stores, the deference operator * is used.

On lines 15, the value 29 is assigned to the variable at the address store in `pAge`. This sets `myAge` to 29.

Lines 17-18 display the changed values of `myAge` and the value at the address that `pAge` stores. Again, to access the value at the address `pAge` stores, the deference operator * is used.

On line 20, `myAge` is assigned the value 33.

Lines 17-18 display the, again, changed values of `myAge` and the value at the address that `pAge` stores. Again, to access the value at the address `pAge` stores, the deference operator * is used.

### Examining Addresses Store in Pointers

Pointers enable you to manipulate address without ever knowing their real value.

Listing 10.3 demonstrates how to check the address of a variable stored in a pointer.

### Listing 10.3 The Full Text of `listing_10_3.cpp`
```C++
#include <iostream>

int main()
{
    unsigned short int myAge = 33, yourAge = 29;
    unsigned short int *pAge = &myAge; // pointer

    std::cout << "myAge: " << myAge << ", yourAge: " << yourAge << std::endl;
    std::cout << "&myAge: " << &myAge << ", &yourAge: " << &yourAge << std::endl;
    std::cout << "pAge: " << pAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    pAge = &yourAge; // reassign the pointer

    std::cout << "myAge: " << myAge << ", yourAge: " << yourAge << std::endl;
    std::cout << "&myAge: " << &myAge << ", &yourAge: " << &yourAge << std::endl;
    std::cout << "pAge: " << pAge << std::endl;
    std::cout << "*pAge: " << *pAge << std::endl << std::endl;

    std::cout << "&pAge: " << &pAge << std::endl;

    return 0;
}
```

When compiled and run, Listing 10.3's program produces the following output:

```Console
myAge: 33, yourAge: 29
&myAge: 0x61fe1e, &yourAge: 0x61fe1c
pAge: 0x61fe1e
*pAge: 33

myAge: 33, yourAge: 29
&myAge: 0x61fe1e, &yourAge: 0x61fe1c
pAge: 0x61fe1c
*pAge: 29

&pAge: 0x61fe10
```

Note, the output will differ because each computer stores variables at different addresses, depending on what else is in memory and how much memory is available.

Here, the program declares three variables: two `unsigned short int`s named `myAge` and `yourAge` and a pointer to an `unsigned short int` named `pAge`. `myAge` is assigned the value 33, `yourAge` is assigned the value of 29, and `pAge` is assigned the address of `myAge` using the address-of operator &.

Lines 8-11 display `myAge` and `yourAge`'s values; `myAge` and `yourAge`'s addresses; the address stored in `pAge`; and the value at the address of the variable stored in `pAge`. To get the address of the variables, the address-of operator & is used. To access the value at the address `pAge` stores, the deference operator * is used.

On line 13, `pAge` is assigned the address of `yourAge`.

Lines 15-18 achieve the same results as lines 8-11. The output shows that `pAge` now has the address of `yourAge`. The value at the address is accessed using the dereference operator.

Line 20 displays the address of `pAge` itself. Like any variable it too has an address, and that address can be stored in a point.

### Why Use Pointers?

Pointers are mostly used to:

* Manage data on the heap
* Access a class's member variables and member functions
* Pass variables by reference to functions

## The Stack and the Heap

Programmers generally deal with five areas of memory:

* Global name space
* The heap
* Registers
* Code space
* The stack

Local variables are on the stack. Code is in the code space. Global variables are in the global space. Registers are used for internal functions, such as keeps track of the top of the stack and the instruction pointer. The remaining memory is allocated to the heap, which is sometimes referred to as the free store.

The limitation of local variables is that they don't persist. When a function returns, the local variables are discarded. Global variables solve that problem, but at the cost of being accessible without restriction, which leads to the creation of bug-prone code. Putting data in the heap solves both problems.

The heap can be thought of as a large block of memory with many sequentially numbered boxes. You can't label these boxes, unlike  the stack; however, you can get the address of a box and store that in a pointer.

The stack is cleaned automatically when a function returns. All the local variables go out of scope, and they are removed. The heap is not cleaned until a program ends, and you must free any memory you have allocated when it does. Leaving items hanging around in the heap when you no longer need them is known as a memory leak.

The advantage of the heap is that memory you reserve remains available until you explicitly free it. If you reserve memory on the heap while in a function, the memory is still available when the function returns.

The advantage of accessing memory in this way, instead of using global variables, is that only functions with access to the pointer have access to the data. This provides a tightly controlled interface to that data, and it eliminates the problem of one function changing that data in unexpected ways.

### Using the `new` Keyword

You allocate memory on the heap in C++ using the `new` keyword followed by the type of the object you want to allocate so that the compiler knows how much memory is required. For example, `new unsigned short int` allocates two bytes in the heap, and `new long` allocates four.

The value returned from `new` is a memory address. It must be assigned to a pointer. For example:

```C++
unsigned short int *pPointer = nullptr;

pPointer = new unsigned short int;
```

Here, an `unsigned short` has been created on the heap. The pointer can also be initialised at its creation. For example:

```C++
unsigned short int *pPointer = new unsigned short int;
```

In either case, `pPointer` now points to an `unsigned short int` on the heap. You can use this like any other pointer to a variable and assign a value into that area of memory. For example:

```C++
*pPointer = 33;
```

Here, the value 33 is assigned to the area of the heap where `pPointer` points.

If `new` cannot create memory on the heap, it throws an exception. 

### Using the `delete` Keyword

When you have finished with your area of memory, you must call `delete` on the pointer, which returns the memory to the heap. Remember that the pointer is a local variable. When the function it is declared in returns, the pointer is out of scope and is discarded. The memory allocated with the `new` operator is not freed automatically. That memory becomes unavailable. This situation is called a memory leak because that memory can't be recovered until the program ends. It's as if memory has leaked out of your program.

To restore the memory on the heap, use the `delete` keyword. For example:

```C++
delete pPointer;
```

When you delete a pointer, you are freeing up the memory whose address is store in the pointer. You are returning to the heap the memory that this pointer points to. The pointer is still a pointer, and it can be reassigned.

When you call `delete` on a pointer, the memory it points to is freed. Calling `delete` on that pointer again will crash your program. When you delete a pointer, set it to `nullptr`. Calling `delete` on a `nullptr` is guaranteed to be safe. For example:

```C++
cv::Mat *pImage = new cv::Mat;
delete pImage;      // frees the memory
pImage = nullptr;   // sets the pointer to null
// ...
delete pImage;      // does nothing
```

Here, an object is instantiated on the heap. A built-in type can also be allocated on the heap. For example:

```C++
int *pInt = new int;
delete pInt;
pInt = nullptr;
// ...
delete pInt;
```

Listing 10.4's program demonstrates how to allocate a variable on the heap.

### Listing 10.4 The Full Text of `listing_10_4.cpp`
```C++
#include <iostream>

int main()
{
    int localVariable = 33;
    int *pLocalVariable = &localVariable;
    int *pHeap = new int;
    
    if (pHeap == nullptr)
    {
        std::cout << "Error! No memory for pHeap." << std::endl;
    
        return 1;
    }

    *pHeap = 29;

    std::cout << "localVariable: " << localVariable << std::endl;
    std::cout << "*pLocalVariable: " << *pLocalVariable << std::endl;
    std::cout << "*pHeap: " << *pHeap << std::endl;

    delete pHeap;

    pHeap = new int;

    if (pHeap == nullptr)
    {
        std::cout << "Error! No memmory for pHeap." << std::endl;
    
        return 1;
    }

    *pHeap = 33;
    
    std::cout << "*pHeap: " << *pHeap << std::endl;

    delete pHeap;

    return 0;
}
```

Note, because Listing 10.4's program uses `nullptr`, it must be compiled with the `--std=c++14` flag.

When compiled and run, Listing 10.4's program produces the following output:

```Console
localVariable: 33
*pLocalVariable: 33
*pHeap: 29
*pHeap: 33
```

Here, lines 5-7 declares and initialises three variables: an `int` named `localVariable`, and two pointers to an `int` named `pLocalVariable` and `pHeap`. `localVariable` is assigned the value 33, `pLocalVariable` is assigned the address of `localVariable`, and `pHeap` is allocated memory on the heap.

Lines 9-14 check to see if memory was allocated on the heap, if not, an error message is displayed; otherwise, the program's execution continues.

Lines 18-20 display the value stored in `localVariable`, the value at the address of the variable stored in `pLocalVariable`, and value at the memory stored in `pHeap`. To access value at the address of the variable stored in `pLocalVariable` and the memory address stored in `pHeap`, the dereference operator * is used.

On line 22, the memory allocated to `pHeap` is freed. 

On Line 24, new memory is allocated to `pHeap`.

Lines 26-31 achieve the same results as lines 9-14.

On line 33, the value 33 is assigned to the memory address stored in the pointer `pHeap`. 

On line 35, the value at the address of the variable stored in `pHeap` is displayed. Again, to access the value at the address of the variable stored in `pHeap`, the deference operator * is used.

### Avoiding Memory Leaks

Another way a memory leak can be inadvertently created is by reassigning a pointer before deleting the memory it points to. For example:

```C++
unsigned short int *pPointer = new unsigned short int;
*pPointer = 33;
pPointer = new unsigned short int;
*pPointer = 29;
```

Here, line 1 creates a pointer to an `unsigned short int` named `pPointer` and allocates it memory on the heap. On line 2, the value 33 is assigned to the memory address stored in the pointer `pPointer`. On line 3, `pPointer` is allocated more memory. On line 4, the value 29 is assigned to the memory address store in the pointer `pPointer`. The original area, which held 33, is no longer available. There is no way to access the original memory.

This snippet should be written as follows:

```C++
unsigned short int *pPointer = new unsigned short int;
*pPointer = 33;
delete pPointer;
pPointer = new unsigned short int;
*pPointer = 29;
```

Here, the original memory pointed to by `pPointer` is deleted and freed in line 3.

>**Note**
Every time you call `new`, there should be a call to `delete`. It is important to keep track of which pointer owns an area of memory and ensure that memory is returned to the heap.

## Null Pointer Constant

It's important when using pointers to make sure they always have a value. A pointer not initialised could be pointing to anything in memory. These wild pointers pose a security and stability risk to your programs.

In previous versions of C++, a pointer was assigned a null value when created by using either 0 or `NULL` as the value. For example:

```C++
int *pPointer1 = 0;
int *pPointer2 = NULL;
```

These achieve the same result because `NULL` is a preprocessor macro that is converted to 0.

Setting null pointers like this worked well most of the time, but created ambiguity when a class relies on function overloading. For example:

```C++
void displayBuffer(char *);
void displayBuffer(int);
```

If this function was called with a null pointer, the `displayBuffer(int)` member function will be called, which may not be what was intended.

The `nullptr` keyword solves this problem:

```C++
int *pBuffer = nullptr;
```

The constant 0 also remains valid as a null pointer value, but `nullptr` is preferred.

A `nullptr` is not implicitly converted to an integer type, except for `bool` values, where a `nullptr` converts to the value `false`.

Listing 10.5's program demonstrates how a `nullptr` can be used.

### Listing 10.5 The Full Text of `listing_10_2.cpp`
```C++
#include <iostream>

int main()
{
    int value1 = 1000;
    int value2 = 2000;
    int *pointer2 = nullptr;

    std::cout << "value1: " << value1 << std::endl;
    std::cout << "value2: " << value2 << std::endl;

    pointer2 = &value2;     // give pointer the address of value2

    value1 = *pointer2;     // dereference the pointer and assign it to value1
    pointer2 = 0;

    std::cout << "value1: " << value1 << std::endl;
    std::cout << "value2: " << value2 << std::endl;

    return 0;
}
```

Note, because Listing 10.5's program uses `nullptr`, it must be compiled with the `--std=c++14` flag.

When compiled and run, Listing 10.5's program produces the following output:

```Console
value1: 1000
value2: 2000
value1: 2000
value2: 2000
```

Here, three variables are declared and initialised: two `int`s named `value1` and `value2`, and a pointer to an `int` named `pointer2`. `value1` is assigned the value 1000, `value2` is assigned the value 2000, and `pointer2` is assigned the value `nullptr`.

Lines 9-10 display the values of `value1` and `value2`.

Line 12 assigns the address of `value2` to `pointer2` using the address-of operator.

Lines 14-15 assign `value1` the value at the address of the variable stored in `pointer2` and assigns the value 0 to `pointer2`.

Lines 17-18 perform the same action as lines 9-10. They show that `value1` now has the same value as `value2`.

## Summary

Variable values are stored in computer memory, which is organised into sequential memory locations. Each location is a memory address. Pointers are special variables that store a memory address's value.

Pointers make is possible to manipulate computer memory directly in a program. When you know the memory address of data, you don't have to use a variable to access that data. You can work with a pointer to that address instead.

There are tasks where it makes more sense to use pointers than variables. Pointers are one of the most power parts of the C++ language.

It's important you understand what a pointer is; make sure you do.

## Q & A

Q. Why are pointers so important?

A. Pointers are important because they hold the address of objects on the heap and pass arguments by reference.

Q. Why should I bother to declare anything on the heap?

A. Objects on the heap persist after the return of a function. In addition, the capability to store objects on the heap enables you to decide at runtime how many objects you need, instead of having to declare this in advanced.

## Workshop

### Quiz

1. What is the difference between 0 and `nullptr` when initialising a pointer?

    A. `nullptr` creates a null pointer
    B. 0 creates a null pointer
    C. Both create a null pointer

<!-- C. Both 0 and `nullptr` create a pointer to no address, making it a null pointer. Using `nullptr` is clearer as it's obvious it's a pointer. When supported, `nullptr` should be used instead of either 0 or NULL. -->

2. What is it called when you don't free heap space after you're done with it?

    A. A memory leak
    B. A memory hole
    C. A heap mountain

<!-- A. Memory leak. The program continues to allocate new space as it needs it, but less and less memory is available. -->

3. How do I free up memory allocated with `new`?

    A. `return`
    B. `delete`
    C. `*`

<!-- B. Use the `delete` keyword. It's good practice to `delete` as soon as you're done with the contents of a variable on the heap. -->

### Activities

1. 

2.  
