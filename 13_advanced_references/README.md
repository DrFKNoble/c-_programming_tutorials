# Lecture 13: Advanced References and Pointers

## What You'll Learn in this Lecture:

* How to use pass by reference to make your programs more efficient
* How to decide when to use references and when to use pointers
* How to avoid memory problems
* How to avoid the pitfalls of using references

## Passing by Reference for Efficiency

Each time you pass an object into a function by value, a copy of that object is made. Each time you return an object from a function by value, another copy is made.

With large, user-created objects, the cost of these copies is substantial. You'll use more memory than you need, and your program will run more slowly.

The size of a user-created object on the stack is the sum of each of its member variables. These in turn, can each become user-created objects. Passing such a massive structure by copying it onto the stack can be expensive in terms of performance and memory consumption.

There is another cost too. With the classes you create, each of these temporary copies is created when the compiler calls a special constructor: the copy constructor.

A copy constructor is called each time a temporary copy of an object is put on the stack. When the temporary object is destroyed, which happens when the function returns, the object's destructor is called. If an object is returned by value, a copy of that object must also be made and destroyed.

With large objects, these constructor and destructor calls can be expensive in speed and use of memory.

Listing 13.1's program demonstrates how an object's constructor, copy constructor, and destructor are called when the object is passed to a function.

### Listing 13.1 The Full Text of listing13_1's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Computer
{
public:
    Computer();             // constructor
    Computer(Computer&);    // copy constructor
    ~Computer();            // destructor
};

Computer::Computer()
{
    std::cout << "Computer Constructor." << std::endl;

    return;
}

Computer::Computer(Computer&)
{
    std::cout << "Computer Copy Constructor." << std::endl;

    return;
}

Computer::~Computer()
{
    std::cout << "Computer Destructor." << std::endl;

    return;
}

Computer Function1(Computer pc);
Computer* Function2(Computer *pc);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Creating a desktop computer." << std::endl;

    Computer desktop;

    std::cout << "Passing desktop to Function1()" << std::endl;

    Function1(desktop);

    std::cout << "Passing desktop to Function2()" << std::endl;

    Function2(&desktop);

    return a.exec();
}

Computer Function1(Computer pc)
{
    std::cout << "Function1." << std::endl;

    return pc;
}

Computer* Function2(Computer *pc)
{
    std::cout << "Function2." << std::endl;

    return pc;
}
```

When compiled and run, Listing 13.1's program produces the following output:

```Console
Creating a desktop computer.
Computer Constructor.
Passing desktop to Function1()
Computer Copy Constructor.
Function1.
Computer Copy Constructor.
Computer Destructor.
Computer Destructor.
Passing desktop to Function2()
Function2.
Computer Destructor.
```

Here, Listing 13.1's program creates a `Computer` object and then calls two functions. The first function receives the object by value and then returns it by value. The second function receives the object by reference, meaning it receives a pointer to the object, and returns a pointer to the object.

Passing by reference avoids creating the copy and calling the copy constructor and is therefore more efficient. However, it does mean that the object could be changed in the called function.

On lines 3-9, a class named `Computer` is declared. Its constructor, copy constructor, and destructor are defined on lines 11-30. Each function displays a message describing its name and returns.

On lines 32-33, two functions are declared: `Function1()` and `Function2()`. The first function accepts a `Computer` object by value and returns a `Computer` object by value. The second function accepts a pointer to a `Computer` and returns a pointer to a `Computer`. The functions are defined on lines 53-65. Each function displays a message describing its name.

On line 38, `main()` displays a message. On line 40, an object of the `Computer` class named `desktop` is instantiated. This causes the constructor to be called.

On line 42, `main()` displays a message. On line 44, `desktop` is passed to `Function1()`. Because it is passed by value, a copy is made, and the copy constructor is called. Because `Function1()` returns by value, the copy constructor is called again(). The return value of `Function1()` is not assigned to an object, so the temporary object created for the return statement is discarded, and the destructor called. As the function goes out of scope, its local copy goes out of scope and the destructor is called again.

On line 46, `main()` displays a message. On line 48, `desktop` is passed to `Function2()`. Because it is passed by reference, a copy is not made. Also, because `Function2()` returns by reference, a copy is not made. Because `desktop` was passed by reference, no copy was made and so the copy constructor and destructor weren't called.

As the program ends, `desktop` goes out of scope and the destructor is called.

Because `Function1()` passed and returned the object by value, it called the copy constructor and destructor twice. `Function2()` didn't generate any calls to the copy constructor or destructor.

## Passing a `const` Pointer

Though passing a pointer to `Function2()` is Listing 12.1 is more efficient, it is dangerous. `Function2()` is not supposed to change the `Computer` object it is passed, yet it can do this using its address. This exposes the object to undesired changes and defeats the protection offered by passing by value.

If you want to provide the security of pass by value and the efficiency of pass by reference, the solution is to pass a `const` pointer. This prevents calling any non-`const` member functions of `Computer`.

Listing 13.2's program demonstrates how a `const` pointer to an object can be used.

### Listing 13.2 Full Text of listing13_2's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Computer
{
public:
    Computer();             // constructor
    Computer(Computer&);    // copy constructor
    ~Computer();            // destructor

    int GetStorage() const;
    void SetStorage(int newStorage);

private:
    int storage;
};

Computer::Computer()
{
    std::cout << "Computer Constructor." << std::endl;

    storage = 20000;

    return;
}

Computer::Computer(Computer&)
{
    std::cout << "Computer Copy Constructor." << std::endl;

    return;
}

Computer::~Computer()
{
    std::cout << "Computer Destructor." << std::endl;

    return;
}

int Computer::GetStorage() const
{
    return storage;
}

void Computer::SetStorage(int newStorage)
{
    storage = newStorage;

    return;
}

const Computer* Function2(const Computer * const pc);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Creating a desktop computer." << std::endl;

    Computer desktop;

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    desktop.SetStorage(50000);

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    std::cout << "Passing desktop to Function2()" << std::endl;

    Function2(&desktop);

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    return a.exec();
}

const Computer* Function2(const Computer * const pc)
{
    std::cout << "Function2." << std::endl;

    std::cout << "Computer has " << pc->GetStorage() << " MB's." << std::endl;

    // pc->SetStorage(1000); // Can't do this! const class.

    return pc;
}
```

When compiled and run, Listing 12.2's program produces the following output:

```Console
Creating a desktop computer.
Computer Constructor.
Computer has 20000 MB's
Computer has 50000 MB's
Passing desktop to Function2()
Function2.
Computer has 50000 MB's.
Computer has 50000 MB's
Computer Destructor.
```

Here, a class named `Computer` is declared on lines 3-15. It has one private member variable: an `int` named `storage`. The class's constructor, copy constructor, and destructor are defined on lines 17-38. Each function displays a message describing its name and then returns. In addition, the constructor assigns the value 20000 to `storage`. `Computer`'s accessors, `GetStorage()` and `SetStorage()` and defined on lines 40-50 and get and set `storage`'s value, respectively.

On line 52, `Function2()` is declared. The function accepts and returns a constant pointer to a `Computer` object. `Function2()` is defined on lines 76-85. It displays a message and shows how much memory the `Computer` object has.

On line 59, `main()` displays a message. On line 59, an instance of `Computer` named `desktop` is created. 

On line 61, `main()` displays a message. On line 63, `desktop`'s `storage` is set to 50000.

On lines 65 and 67, `main()` displays two messages.

On line 69, the address of `desktop` is passed to `Function2()`. The function displays a message and shows how much memory the object has. Because the object is passed by reference, no copies are made, and the copy constructor is not called. Also, because `desktop` is passed as a constant, the accessor `SetStorage()` cannot be called. It was, the program wouldn't compile.

It's worth noting that, on line 63, `desktop`'s storage was changed. This is allowed because the object is not `const` in `main()`'s scope. `desktop` is not allowed to be changed in `Function2()` because it is `const` in the function's scope.

## References as an Alternative to Pointes

Listing 13.2's program solves the problem of making extra copies, saving the calls to the copy constructor and destructor. It uses constant pointers to constant objects, thereby solving the problem of a called function making changes to the objects passed as parameters. The is still cumbersome, however, because the objects passed to the function are pointers.

Because the parameters will never by NULL, it is easier to work with the function if references are passed instead of pointers.

Listing 13.3's program demonstrates how references can be used.

### Listing 13.3 The Full Text of listing13_3's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Computer
{
public:
    Computer();             // constructor
    Computer(Computer&);    // copy constructor
    ~Computer();            // destructor

    int GetStorage() const;
    void SetStorage(int newStorage);

private:
    int storage;
};

Computer::Computer()
{
    std::cout << "Computer Constructor." << std::endl;

    storage = 20000;

    return;
}

Computer::Computer(Computer&)
{
    std::cout << "Computer Copy Constructor." << std::endl;

    return;
}

Computer::~Computer()
{
    std::cout << "Computer Destructor." << std::endl;

    return;
}

int Computer::GetStorage() const
{
    return storage;
}

void Computer::SetStorage(int newStorage)
{
    storage = newStorage;

    return;
}

const Computer & Function2(const Computer &pc);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Creating a desktop computer." << std::endl;

    Computer desktop;

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    desktop.SetStorage(50000);

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    std::cout << "Passing desktop to Function2()" << std::endl;

    Function2(desktop);

    std::cout << "Computer has " << desktop.GetStorage() << " MB's" << std::endl;

    return a.exec();
}

const Computer & Function2(const Computer &pc)
{
    std::cout << "Function2." << std::endl;

    std::cout << "Computer has " << pc.GetStorage() << " MB's." << std::endl;

    // pc->SetStorage(1000); // Can't do this! const class.

    return pc;
}
```

When compiled and run, Listing 13.3's program produces the following output:

```Console
Creating a desktop computer.
Computer Constructor.
Computer has 20000 MB's
Computer has 50000 MB's
Passing desktop to Function2()
Function2.
Computer has 50000 MB's.
Computer has 50000 MB's
Computer Destructor.
```

Here, the output is the same as Listing 13.2's output. The only difference between Listing 13.2 and Listing 13.3 is, here, references are used instead of pointers.

## When to Use References and When to Use Pointers

Generally, C++ programmers strongly prefer references to pointers because they are cleaner and easier to use. References cannot be reassigned, however. If you need to point first to one object and then to another, you must use a pointer. References cannot be NULL, if there's any change that the object in question might be, you must use a pointer. If you want to allocate dynamic memory from the heap, you must use a pointer.

### References to Objects Not in Scope

A reference is an alias that refers to some other object. If you pass a reference into or out of a function, be sure to check whether the object will exist when you go to use it next.

Listing 13.4's program demonstrates the danger of returning a reference to an object that no longer exists.

### Listing 13.4 The Full Text of listing13_4's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Computer
{
public:
    Computer();
    ~Computer();

    int GetStorage() const;
    void SetStorage(int newStorage);

private:
    int storage;
};

Computer::Computer()
{
    storage = 10000;

    return;
}

Computer::~Computer()
{
    return;
}

int Computer::GetStorage() const
{
    return storage;
}

void Computer::SetStorage(int newStorage)
{
    storage = newStorage;

    return;
}

Computer & BadFunction();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Computer &rDesktop = BadFunction();

    std::cout << "Computer has " << rDesktop.GetStorage() << "MB's." << std::endl;

    return a.exec();
}

Computer & BadFunction()
{

    Computer localDesktop;

    return localDesktop;
}
```

When compiled and run, Listing 13.4's program produces the following output:

```Console
.\listing_13_4.cpp: In function 'Computer& BadFunction()':
.\listing_13_4.cpp:55:14: warning: reference to local variable 'LocalDesktop' returned [-Wreturn-local-addr]
     Computer LocalDesktop;
              ^~~~~~~~~~~~
```

> **Note** Some compilers are smart enough to see the reference to a null object and report a compile error. Other compilers will compile and even run. It's bad practice to try and take advantage of a dumb compiler.

Here, a class named `Computer` is declared on lines 3-14. It has one private member variable: an `int` named `storage`. The class's constructor and destructor are defined on lines 16-26. The constructor assigns the value 10000 to `storage`. `Computer`'s accessors, `GetStorage()` and `SetStorage()` and defined on lines 28-38 and get and set `storage`'s value, respectively.

On line 40, `BadFunction()` is declared. The function has not parameters and returns a reference to a `Computer` object. `BadFunction()` is defined on lines 52-58. It creates `Computer` object named `localDesktop`, which it returns.

On line 45, a reference to a `Computer` object named `rDesktop` is created. It is assigned the object returned from `BadDesktop()`. On line 47, a message is displayed, showing how much storage the object `rDesktop` refers to has. However, because the object is now out of scope, there is an error. The object doesn't exist anymore.

### Returning a Reference to an Object on the Heap

You may be tempted to solve the problem in Listing 13.4 by having `BadFunction()` declare `localDesktop` on the heap. That way, when the function returns, `localDesktop` still exists.

The problem with this is: what do you do with `localDesktop`'s memory when you are finished with it. You can't delete a reference.

Listing 13.5 demonstrates what happens when you return a reference to an object on the heap.

### Listing 13.5 The Full Text of listing13_5's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

class Computer
{
public:
    Computer();
    ~Computer();

    int GetStorage() const;
    void SetStorage(int newStorage);

private:
    int storage;
};

Computer::Computer()
{
    storage = 10000;

    return;
}

Computer::~Computer()
{
    return;
}

int Computer::GetStorage() const
{
    return storage;
}

void Computer::SetStorage(int newStorage)
{
    storage = newStorage;

    return;
}

Computer & BadFunction();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Computer &rDesktop = BadFunction();

    std::cout << "Computer has " << rDesktop.GetStorage() << "MB's." << std::endl;

    return a.exec();
}

Computer & BadFunction()
{
    Computer *pLocalDesktop = new Computer;

    return *pLocalDesktop;
}
```

When compiled and run, Listing 13.5's program produces the following output:

```Console
Computer has 10000MB's.
```

Here, the Listing 13.5's program looks almost identical to Listing 13.4's; however, this program compiles, links, and runs. Success? No, not at all: it's a time bomb waiting to go off.

`BadFunction()` has been changed to that it no longer returns a reference to a local variable. Memory is allocated on the heap and assigned to a pointer on line 53.

On line 44, a reference to a `Computer` object named `rDesktop` is created and initialised with the value returned from `BadFunction()`. On line 46, `main()` displays a message, showing how much the object referenced by `rDesktop` has.

It seems to work; however, what about the memory allocated on the heap? How will it be freed? You can't call `delete` on the reference.

There are two solutions. The first is to return a pointer to the memory. Then the calling function can delete the pointer when it is done. To do this, `BadFunction()` can be changed to return a pointer. For example:

```C++
Computer * BadFunction()
{
    Computer *pLocalDesktop = new Computer;

    return pLocalDesktop;
}
```

A better solution is to declare the object in the calling function and pass it to `BadFunction()` by reference. The advantage of this is that the function that allocates the memory is also the function for deallocating it.

### Keeping Track of Pointers

When your program allocates memory on the heap, a pointer is returned. It is imperative that you keep a pointer to that memory, because after the pointer is lost, the memory cannot be deleted and becomes a memory leak.

As you pass this block of memory between functions, one of the functions "owns" the pointer. Typically, the value in the block is passed using references, and the function that created the memory block is the one that deletes it. This is a general rule.

It is dangerous for one function to create space in memory and another to free it, however. Ambiguity about which owns the pointer can lead to one of two problems: forgetting to delete it or deleting it twice. It's safer to build functions so that they delete the memory they allocate.

If you write a function that needs to create a block of memory and pass it back to the calling function, consider changing your interface. Have the calling function allocate the memory and pass it to the function by reference.  This moves all memory management out of the function and into the function that is prepared to delete it.

## Summary

A pointer is a variable that holds a memory address. A reference is an alias.

Both provide forms of indirection that enable functions to be more functional. In many cases, however, you'll find references are the better choice.

## Q & A

Q. Why have pointers if references are easier?

A. References cannot be `NULL` and cannot be reassigned. Pointers offer greater flexibility, but are slightly more difficult to use.

Q. Why would you ever return by value from a function?

A. If the object being returned is local, you must return by value or you will be returning a reference to a non-existent object.

Q. Given the danger in returning by reference, why not always return by value?

A. There is much greater efficiency in returning by reference. Memory is saved, and the program runs faster.

## Workshop

### Quiz

1. When dealing with large amounts of data, which approach is better?

    A. Pass by reference
    B. Pass by value
    C. Pass by indirection

<!-- A. Pass by reference, because pass by value causes a copy to be made of the variables being passed. For a large object, this could take a considerable amount of time and memory. -->

2. What keyword prevents a called function from changing the value of a pointer?

    A. `static`
    B. `enum`
    C. `const`

<!-- C. Using `const` tells the compiler to prevent the calling function from changing the value of the pointer.-->

3. Can you create a reference to a pointer?

    A. Yes
    B. No
    C. Only in special cases

<!-- A. Yes, but you might want to be careful in doing so because it can get very confusing. -->

### Activities

1. Modify Listing 13.5 to use pointers in the call to `BadFunction()` and use the proper deletion method to prevent a memory leak.

2. Modify Listing 13.1 and Listing 13.4 to display the addresses of the variables before and after the function calls.
