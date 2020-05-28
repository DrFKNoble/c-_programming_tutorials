# Lecture 2: Organising the Parts of a Program

## What You'll Learn in this Lecture:

* Why to use C++
* How C++ programs are organised
* How comments make programs easier to understand
* What functions can accomplish

## Introduction

Although more than 30 years old, the C++ programming language remains a world-class programming language.

The reason for its longevity is that C++ makes it possible to create fast executing programs with a small amount of code that can run on a variety of computing environments. Today's C++ programming tool enable the creation of complex and power applications in commercial, business, and open source development.

## Reasons to Use C++

During the seven decades of the computing age, computer programming languages have undergone a dramatic evolution. C++ is an evolution improvement of a language called C that was introduced in 1972.

The earliest programmers worked with the most primitive computer instructions: machine language. These instructions were represented by long strings of ones and zeros. Assemblers were devised that could map machine instructions to human-readable and manageable commands, such as ADD and MOV.

The instructions that make up a computer program called its source code.

In time, higher-level languages were introduced such as BASIC and COBOL. These languages made it possible for programmers to begin to craft programs using language closer to actual words and sentence, such as Let Average = .366. These instructions were translated back into machine language by tools that were called either interpreters or compilers.

An interpreter-based language translates a program as it reads each line, acting on each instruction.

A compiler-based language translates a program into what is called object code through a process called compiling. This code is stored in an object file. Next, a linker transforms the object file into an executable program that can be run on an operating system.

Because interpreters read the code as it is written and execute the code on the fly, they're easy for programmers to work with. Compilers require the additional step of compiling and linking programs. The benefit to this approach is that the programs run significantly faster than programs run by an interpreter.

For many years, the principal goal of programmers was to write short pieces of code that would execute quickly. Programs needed to be small because memory was expensive, and they needed to be fast because processing power also was expensive. As computers have become cheaper, fast, and more power and the cost and capacity of memory has fallen, these priorities diminished in importance.

Today, the greatest expense in programming is the cost of a programmer's time. Modern languages such as C++ make it faster to produce well-written, easy-to-maintain programs that can be extended and enhanced.

## Styles of Programming

As programming languages have evolved, languages have been created to cater to different styles of programming.

In procedural programming, programs are conceived of as a series of actions performed on a set of data. Structured programming was introduced to provide a systematic approach to organising these procedures and managing large amounts of data.

The principal idea behind structured programming is to divide and conquer. Take a task that needs to be accomplished in a program, and if it is too complex, break it down to a set of smaller component tasks. If any of those tasks is still too complicated, break it down into even smaller tasks. The end goal is tasks that are small and self-contained enough to be easily understood.

As an example, pretend you're a lecturer and you need to write a program that computes the average grade of a class of students. This job can be broken down into these subtasks:

1. Find out each student's grade.
2. Count how many students are in the class.
3. Total all the students' grades.
4. Divide the total grades by the number of students.

Although structured programming has been widely used, this approach has some drawbacks. The separation of data from the tasks that manipulate the data becomes harder to comprehend and maintain as the amount of data grows. The more things that must be done with data, the more confusing a program becomes.

Procedural programmers often find themselves reinventing new solutions to old problems instead of producing reusable programs. The idea behind reusability is to build program components that can be plugged into programs as needed. This approach is modelled after the physical world, where devices are built out of individual parts that each perform a specific task and have already been manufactured. A person designing a bicycle doesn't have to create a brake system from scratch. Rather, they can incorporate an existing brake into the design and take advantage of its existing functionality.

The component-based approach became available to computer programmers for the first time with the introduction of object-orientated programming.

## C++ and Object-Orientated Programming

C++ helped popularise a revolutionary style of programming, Object-Orientated Programming (OOP).

The essence of OOP is to treat data and the procedures that act upon the data as a single object - a self-contained entity.

The C++ language fully supports object-orientated programming, including three concepts that have come to be known as the pillars of object-orientated development: encapsulation, inheritance, and polymorphism.

### Encapsulation

Encapsulation is defined as wrapping up of data and information under a single unit. In Object-Orientated Programming, encapsulation is defined as binding together the data and the functions that manipulate them.

C++ supports the properties of encapsulation through the creation of user-defined types called classes. A well-defined class acts as a fully encapsulated entity that is used as an entire unit or not at all. The inner workings of the class should be hidden on the principle that the programs that use a well-define class do not need to know how the class works.

### Inheritance and Reuse

The capability of a class to derive properties and characteristics from another class is called inheritance.

A class that inherits properties from another class is called the sub class or derived class.

A class whose properties are inherited by the derived class is called the base class or super class.

C++ supports the idea of reuse through inheritance. A new type can be declared that is an extension of an existing type. This new subclass is said to derive from the existing type.

### Polymorphism

Polymorphism is defined as having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

C++ Polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

C++ supports the idea that different objects do the right thing through a language feature called function polymorphism and class polymorphism.

## The Parts of a Program

The following source code contains the basic framework of a C++ program:
 
### Listing 2.1 The Full Text of `listing_1_1.cpp`.
```C++
#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```
The program produces a single line of output:

```console
Hello World!
```

On line 1 of Listing 2.1, a file named `iostream` is included in the source code. This line causes the compiler to act as if the entire contents of that file were typed at the place in `listing1_1.cpp`.

### Preprocessor Directives

A C++ compiler's first action is to call another tool called the preprocessor that examines the source code. This happens automatically each time the compiler runs.

The first character in line 1 is the # symbol, which indicates that the line is a command to be handled by the preprocessor. These commands are called preprocessor directives. The preprocessor's job is to read source code looking for directives and modify the code according to the indicated directive. The modified code is fed to the compiler.

The preprocessor serves as an editor of code right before it is compiled. Each directive is a command telling that editor what to do.

The `#include` directive tells the preprocessor to include the entire contents of a designated filename at that spot in a program. C++ includes a standard library of source code that can be used in your programs to perform useful functionality. The code in the iostream file supports input and output tasks such as displaying information onscreen and taking input from a user.

The `<` and `>` brackets around the filename `iostream` tell the preprocessor to look in a standard set of locations for the file. Because of the brackets, the processor looks for the `iostream` file in the folder that holds header files for the compiler. These files also are called include files because they are included in a program's source code.

The full contents of `iostream` are included in place of line 1.

> **Note**
Header files traditionally ended with the filename extension .h and were also called h files, so that used a directive of the form `include <iostream.h>`.  
Modern compilers don't require that extension, but if you refer to files using it, the directive might still work for compatibility reasons. Here, we omit the extraneous .h in include files.

The contents of the file `iostream` are used by the cout command in line 5, which displays information to the screen.

There are no other directives in the source code, so the compiler handles the rest of `listing1_1.cpp`.

## Source Code Line by Line

Line 4 begins the actual program by declaring a function named `main()`. Functions are blocks of code that perform one or more related actions. Functions do some work and then return to the spot in the program where they are called.

Every C++ program has a `main()` function. When a program starts, `main()` is called automatically.

All functions in C++ must return a value of some kind after their work is done. The `main()` function always returns an integer value. Integers are specified using the keyword, `int`.

Functions, like other blocks of code in a C++ program, are grouped together using the brace marks `{` and `}`. All functions begin with an opening brace `{` and end with a closing brace `}`.

The braces for the `main()` function of `listing1_1.cpp` are on line 4 and 7, respectively. Everything between the opening and closing braces is part of the function.

In line 5, the cout command is used to display a message on the screen. The object has the designation `std::` in front of it, which tells the compiler to use the standard C++ input/output library.

The reference to `std::cout` in line 5 is followed by `<<`, which is called the output redirection operator. Operators are characters in lines of code that perform an action in response to some kind of information. The `<<` operator displays the information that follows it on the line. In line 5, the text `"Hello World!"` is enclosed with double quotes. This displays a string of characters on the screen followed by a newline character that advances the program's output to the beginning of the next line.

On line 6, the program returns the integer value 0. This value is received by the operating system after the program finishes running. Typically, a program returns the value 0 to indicate that it ran successfully. Any other number indicates a failure of some kind.

The closing brace on line 7 ends the `main()` function, which ends the program. All your programs use the same basic framework demonstrated by this program.

## Comments

As you write a program, it will be clear to you what each line of the source code does. However, as time passes and you come back to the program to fix a bug or add a new feature, you may find yourself completely confused by your own work.

To avoid this, you can document your source code with comments. Comments are lines of text that explain what a program is doing. The compiler ignores them, so they are strictly for the benefit of people reading the code.

There are two types of comments in C++. A single-line comment begins with two slash marks (`//`) and causes the compiler to ignore everything that follows the slashes on the same line. For example:

```C++
// This is a single line comment.
```

A multiline comment begins with the slash and asterisk (`/*`) and ends with the same characters reversed (`*/`). Everything within the opening `/*` and the closing `*/` is a comment, even if the stretches over multiple lines. If a program contains `/*` that is not followed by `*/` somewhere, that's an error likely to be flagged by the compiler. For example:

```C++
/*
    This is a multiline comment. 
    This is a multiline comment.
*/
```

> **Note**
An important thing to remember about multiline comments is that they do not nest inside each other. If you use `/*` to start a comment and then use another `/*` a few lines later, the first `*/` mark encountered by the compiler will end all multiline comments. The second `*/`  mark will result in a compiler error. Most C++ IDE's display comments in a different colour, e.g. green.

It's a good idea to include a lot of comments in your program. The more detailed the source code, the easier it is to understand what the source does when you read it later.

## Functions

The `main()` function is unusual among C++ functions because it is called automatically when a program begins running.

A program is executed line by line in source code, beginning with start of `main()`. When a function is called, the program branches off to execute the function. After the function has done its work, it returns control to the line where the function was called. Functions may or may not return a value.

Functions consist of a header and a body. The header consists of three things:

* The type of data the function returns.
* The function's name.
* The parameters received by the function.

The function name is a short identifier that describes its purpose.

When a function does not return a value, it uses the void data type, which means nothing.

Arguments are data sent to the function that control what it does. These arguments are received by the function as parameters. A function can have zero, one, or more parameters. For example:

```C++
int add(int x, int y) 
{
    // body of function goes here.
}
```

The parameters are organised within parenthesis marks as a list separated by commas. In this function, the parameters are integers named `x` and `y`.

The name of a function, its parameters and the order of those parameters is called its signature. The function's signature uniquely identifies it.

A function with no parameters has an empty set of parentheses. For example:

```C++
int getFileName()
{
    // body of function goes here.
}
```

Function names cannot contain spaces, so the `getFileName()` function capitalises the first letter of each word after the first one. This naming convention is common among C++ programmers and adopted here.

The body of a function consists of an opening brace, zero or more statements, and a closing brace. A function that returns a value uses a return statement, as seen in `listing1_1.cpp`:

```C++
return 0;
```

The return statement causes a function to exit. If you don't include at least one return statement in a function, it automatically returns void at the end of the function's body. In this case, the function's return type must be `void`.

## Using Arguments with Functions

Listing 2.2 demonstrates how to create a function that takes two integer arguments and returns an integer value.

### Listing 2.2 The Full Text of `listing_2_1.cpp`
```C++ 
#include <iostream>

int add(int x, int y)
{
    // add the numbers x and y together and return the sum.
    std::cout << "Adding..." << std::endl;
    return (x + y);
}

int main()
{
    /*
        This program calls add(), adding two numbers together.
    */
    std::cout << "What is 1 + 2 ?" << std::endl;
    std::cout << add(1, 2) << std::endl;
    return 0;
}
```

The program produces the following output:

```Console
What is 1 + 2 ?
Adding...
3
```

Listing 2.1's program includes a single-line comment on line 5 and a multi-line comment starting on line 12.

The `add()` function takes two integer parameters named x and y and adds them together in a return statement.

The program's execution begins in the `main()` function. The first statement in line 15 uses the object std::cout and the redirection operator `<<` to display the text `"What is 1 + 2?"` followed by a new line.

The next line calls the `add()` function with the arguments 1 and 2. The execution of the program branches off to the `add()` function, which displays `"Adding..."`. 

The integer value returned by the function is displayed on a new line.

The formula `(x + y)` is an expression, which performs a mathematical operation.

## Summary

In this lecture, we've described how C++ has evolved from other styles of computer languages and embraced a methodology called object-orientated programming. This methodology has been so successful that C++ remains as contemporary today as it did as in 1979.

We've also described three important parts of a C++ program: preprocessor directives, comments, and functions.

All programs you will create in C++ will use the same basic framework as Listing 1.1 and Listing 2.1's programs.

## Q & A

Q. What does the `#` character do in a C++ program?

A. The `#` symbol signals that the line is a preprocessor directive, a command that is handled before the program is compiled. The `#include` directive includes the full text of a file at that position in the program. The compiler never sees the directive. Instead, it acts as if the contents of the file were typed in with the rest of the source code.

Q. What is the difference between `//` comments and `/*` style comments?

A. The comments that start with `//` are single-line comments that end with the end of the line on which they appear. The `/*` comments are multi-line comments that don't end until a `*/` is encountered. The end of a function won't even cause a multi-line comment to be ended. You must put in the closing */ mark or the compiler will fail with an error.

Q. What's the difference between function arguments and function parameters?

A. Arguments are the information sent to the function. Parameters are the same information received by the function. You call a function with arguments. Within a function, those arguments are received as parameters.

## Workshop

## Quiz

1. What data type does the main function return?

    A. `void`  
    B. `int`  
    C. It does not return a type

    <!-- B. The main function returns an int (integer). -->

2. What do the braces do in a C++ program?

    A. Indicate the start and end of a function  
    B. Indicate the start and end of a program
    C. Straighten the programmer's teeth

    <!-- A. Braces mark the start and end of functions and other blocks of code. -->

3. What is not part of a function's signature?

    A. Its name  
    B. Its arguments  
    C. Its return type

    <!-- C. A function's signature consists of its name, parameters, and the precise order of those parameters. It does not include its return type. -->

## Activities

1. Rewrite listing_1_1.cpp so that it displays a list of your favourite Dungeon and Dragons classes.

2. Rewrite listing_2_1.cpp so that it adds three integers together. Call `add()` twice with two sets of three different numbers. The program should display the results.
