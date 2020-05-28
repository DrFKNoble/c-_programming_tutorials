# Lecture 1: Writing Your First Program

## What You'll Learn in this Lecture:

1. How and why C++ was invented
2. How to find a C++ compiler
3. How to create and compile your first program
4. How to link and run the program

## Using C++

In 1979, a Danish computer scientist at Bell Labs in the United States began work on an enhancement to the C programming language. Bjarne Stroustrop explained on his personal website that he wanted a language "in which I could write programs that were both efficient and elegant".

A lot of other people wanted that too.

Strostrop's creation, which he dubbed C++, has held a spot among the world's top programming languages for decades. Many programming trends have come and gone over the years, but this language remains a contemporary and useful choice for software development on desktop computers, server, embedded devices like phones, and many other computing environments.

C++ is a portable language that works equally well on Microsoft Windows, Apple Mac OS, Linux, and UNIX systems. The best way to learn the language is to write programs without regard to the operating system the program runs on.

In this course, we make no assumptions about your operating system. Here, we cover standard C++ (also called ANSI/ISO C++), the international agreed-upon version of the language, which is portable to any platform and development environment.

The code presented in this course is standard ANSI/ISO C++ and should work with any development environment for C++ that's up-to-date.

C++ programs are developed by a set of tools that work together called the compiler and linker.

A compiler turns C++ programs into a form that can be run. The compiler translates a program from a human-readable form called source code into a machine-runnable form called machine code. The compiler produces an object. From the object file, a linker builds an executable file that can be run.

There are several popular environments for C++ programming, e.g. the GNU Compiler Collection (GCC), Microsoft Visual Studio, Microsoft Visual Studio Code, Eclipse, Code::Blocks, and Qt Creator.

If you don't have a C++ compiler, you can use GCC. Download MinGW and install it on your computer.

Microsoft Visual Studio also supports C++ programming, and a free version called Visual Studio Community is available from: https://visualstudio.microsoft.com/. 

## Compiling and Linking the Source Code

Before you create a C++ program, it's important to understand the process.

A C++ program begins as source code, which is just plain text typed into a text editor.

> **Note**
There are several free text editors, e.g. Visual Studio Code. It includes features you'll come to appreciate, such as code highlighting, which displays different elements of the language in different colours. You can download it from: https://code.visualstudio.com/. 

C++ files can be given filenames ending with the following extensions: `.cpp`, `.cxx`, `.cp`, `.cc`, or `.c`. Here, we use the default extension, `.cpp`.

Source code is the human-readable form of a C++ program. It can't be run until it has been compiled and linked.

After your source code is compiled, an object file is produced. This file is turned into an executable program by a linker.

C++ programs are created by linking together one or more object files with one or more libraries. A library is a collection of linkable files that provide useful functions and classes that you can use in your programs. A function is a block of code that performs a task, such as multiplying two numbers. A class is the definition of a new type of data and related functions.

The following are the steps to create a C++ program:

1. Create a source code file.
2. Use a compiler to convert the source code into an object file.
3. Use a linker to link the object file and any necessary libraries to produce an executable program.
4. Type the name of the executable to run it.

## Creating Your First Program

Now that you've been introduced to the process, it's time to create a C++ program.

Launch your text editor and create a new file. The first program that you create will display text on the screen.

Type the text of Listing 1.1. into the editor. Make sure to enter the punctuation on each line properly.

When done, save the file as `listing1_1.cpp`.

### Listing 1.1 The Full Text of `listing_1_1.cpp`
```C++
#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl; 
    
    return 0;

}
```

After you save the file, it needs to be compiled and linked.

If you are using GCC, the following command accomplishes both tasks:

```Console
g++ listing1_1.cpp -o listing1_1.exe
```

This command tells the G++ compiler to compile named listing1_1.cpp and link it into an executable program named listing1_1.exe. If it compiles successfully, no message is displayed. The compiler says something only if there's a problem, displaying an error message and the line (or lines) where the error appeared.

If you are using CMake, launch your text editor and create a new file. Type the text in Listing 1.2 into the editor. When done, save the file as `CMakeLists.txt`. Save it in the same directory as `listing1_1.cpp`.

### Listing 1.2 The full text of `CMakeLists.txt`
```
cmake_minimum_required(VERSION 3.17.2)

project(listing1_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(listing1_1 listing1_1.cpp)

install(TARGETS listing DESTINATION ${PROJECT_SOURCE_DIR}/bin)
```

These commands tell CMake to create a project named `listing1_1`; that it should be compiled using the C++17 standard; that the executable is named `listing1_1.exe`; and that it should be installed into the `bin` sub-directory. 

Next, type the following commands into the terminal:

```console
mkdir build
cd build
cmake ..
cmake --build . --target install
```

These will build the project and install the built executable into the project's `bin` sub-directory.

If you get a compiler error, recheck the program line by line. Make sure that all the punctuation is included, particularly the semicolons at the end of lines.

After fixing any potential problems, try the compiler again.

When the program has been compiled properly, you can run `listing1_1.exe` like any other program on your computer. Type its name, `listing1_1.exe`, as a command and press Enter.

The listing1_1.exe program displays the following output:

```console
Hello World!
```

## Summary

Congratulations! You can now call yourself a (novice) C++ programmer. 

The C++ language has been a popular choice for software development for more than three decades. The language has its peculiarities, but once you become used to it, it is easy to build your knowledge to create sophisticated programs.

Throughout this course, you will learn the basic building blocks C++.

## Workshop

### Q & A

Q. What is the difference between a text editor and a word processor?

A. A text editor produces files with plain text in them - just letters, numbers, spaces, and punctuation. There are no formatting commands for things such as bold or italic text, etc. You don't need any of that formatting in C++ source code and using a word processor can save things in the file that the compiler won't understand.

Q. My compiler has a built-in editor. Is that the right thing to use?

A. It sounds like you're using an Integrated Development Environment (IDE), a graphical tool that speeds the process of writing, debugging, and testing programs. Sophisticated compilers such as Microsoft Visual Studio include a full IDE, enabling the programmer to edit and compile source code, and to resolve compile and link errors without ever leaving the environment. These offer a much better way to write C++ program, but only if you know how to use the IDE.

Q. Can I ignore warning messages from my compiler?

A. Absolutely not. C++ uses the compiler to warn you when you're doing something as a programmer that you might not intend. The best approach is to heed those warning and do what is required to make them go away. Getting an error means that the compiler cannot figure out how to convert what you wrote into machine language. A warning means that it can convert it but maybe not in the way you expected.

### Quiz

1. What tool turns C++ source code into object code?  
    
    A. A compiler  
    B. A linker  
    C. An integrated development environment  

<!-- 1. The compiler takes a file of C++ source code and turns it into object code. The linker links that object file and other necessary object files to create an executable program. -->

2. What filename extension is most common for source code files?  
    
    A. `.cpp`  
    B. `.c`  
    C. `.h`  

<!-- 1. Compilers can handle any source code file regardless of extension, but .cpp is in wide use as the file extension for C++ code. Using this extension makes it easier later when you're looking around your computer's file folders for a program's source code. -->

3. What tools can you use to edit your source code?  
    
    A. A text editor  
    B. A word processor  
    C. Either   

<!-- You can use any tool that saves the code as plain text. You can use the simple editors that come with your operating system, e.g. Notepad, or others. -->

### Activities

1. Modify Listing 1.1's program to display the text "Dungeon and Dragons is awesome!".

2. If you don't have a C++ IDE, have a look at Microsoft's Visual Studio Code (https://code.visualstudio.com/) and CMake (https://cmake.org/), or Microsoft's Visual Studio (https://visualstudio.microsoft.com/).
