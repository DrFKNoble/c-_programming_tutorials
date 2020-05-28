# Lecture 7: Storing Information in Arrays and Strings

## What You'll Learn in This Lecture

* How to store related data in arrays
* How to declare arrays
* How to create strings from character arrays
* How to copy strings

## What is an array?

An array is a collection of related data of the same data type. An array can be thought of as a series of data storage locations. Each location is called an element of the array.

An array is declared by writing the data type and its name followed by the number of elements in the array inside square brackets. For example:

```C++
long numbers[10];
```

The `numbers` array holds 10 `long` integers. This statement tells the compiler to set aside enough memory to hold 10 elements. Because a `long` integer requires 4 bytes, this statement sets aside 40 contiguous bytes of memory.

Array elements are number 0 up to the largest element, so the `numbers` array holds elements from 0 through 9. Each element is accessed by using its number in square braces. For example:

```C++
numbers[0] = 1;
```

Here, the first element of `numbers` is assigned the value 1.

The number of an array element is also called its subscript.

Arrays use a zero-based numbering of array elements, which can be confusing. An array with three elements has elements numbered 0, 1, and 2 (not 1, 2, and 3).

Listing 7.1's program demonstrates how an array can be used. 

### Listing 7.1 The Full Text of `listing_7_1.cpp`
```C++
#include <iostream>

int main()
{
    float goal[4];

    goal[0] = 0.9;
    goal[1] = 0.75;
    goal[2] = 0.5;
    goal[3] = 0.25; 

    float weight, target;

    std::cout << "Enter current weight (kg): ";
    std::cin >> weight;

    std::cout << "Enter target weight (kg): ";
    std::cin >> target;

    for (int i = 0; i < 4; i++)
    {
        float loss = (weight - target) * goal[i];
        std::cout << "Goal " << i << ": " << target + loss << std::endl;
    }

    return 0;
}
```

When compiled and run, Listing 7.1's program produces the following output:

```Console
Enter current weight (kg): 105
Enter target weight (kg): 90
Goal 0: 103.5
Goal 1: 101.25
Goal 2: 97.5
Goal 3: 93.75
```

Here, the program stores the user's current weight and their target weight in the `weight` and `target` variables, respectively. Both hold floating-point values.

The goal array holds four values, which will be used to calculate the weight milestones. The four-element array is created on line 5 and values are assigned to it on lines 7-10.

A `for` loop iterates through the elements of the array. The amount to reach a milestone is stored in the `loss` variable. This variable is the total amount of weight to lose multiplied by the percentage.

The `loss` total is added to `target` and displayed as a milestone.

## Writing Past the End of Arrays

When you assign a value to an array element, the compiler computes where to store the value in memory based on the size of each element and its subscript. If you store a new value in `goal[3]`, the compiler multiplies the offset of 3 by the size of each element, which for a `long` integer is four bytes. The compiler then moves that many bytes, i.e. 12, from the beginning of the array and stores the new value at that location.

The `goal` array in Listing 7.1 only has four elements. If you try to store something in `goal[4]`, the compiler ignores the fact that there is no such element. Instead, it stores it in memory 16 bytes past the beginning of the first element, replacing whatever data is stored at that location. This can be almost any data, so writing the new out-of-bounds value might have unpredictable results, such as the program crashing.

These errors can be difficult to spot as a program runs, so it's important to pay attention to the size of arrays when they are created.

## Initialising Arrays

You can initialise a simple array of built-in types, such as integers or characters, when you first declare the array. After the array name, put an equal sign and a list of comma-separated values enclosed in braces. For example:

```C++
float goals[4] = {0.90, 0.75, 0.50, 0.25};
```

This declares `goals` as an array of four floating-point values. It assigns `goals[0]` the value 0.90, `goals[1]` the value 0.75, and so on up to `goals[3]` the value of 0.25.

If you omit the size of the array, an array just big enough to hold the initialisation is created. For example:

```C++
float posts[] = {1.0, 2.0, 3.0, 4.0, 5.0};
```

This declares `posts` as an array with five floating-point values. It assigns `posts[0]` the value 1.0, `posts[1]` the value 2.0, and so on.

The built-in C++ function `sizeof()` can be used to count the number of elements in an array. For example:

```C++
const int size = sizeof(posts) / size(posts[0]);
```

Here, the size of `posts` is determined by dividing the size of the entire array by the size of an individual element. The result is the number of elements in the array.

You cannot initialise more elements that you've declared for the array. For example:

```C++
int error[3] = {1, 2, 3, 4, 5};
```

This creates an error because a three-element array has been initialised with 5 values. 

It is permitted to initialise an array with fewer values than it can hold. For example:

```C++
int noError[5] = {1, 2, 3};
```

## Multidimensional Arrays

A one-dimensional array of data can be thought of a single, discrete row of elements. A two-dimensional array of data can be thought of as a table of data consisting of discrete rows and columns of elements. A three-dimensional array of data can be thought of as a discrete array of two-dimensional arrays. It consists of rows, columns, and depth indices. Higher orders of dimensions are possible, but it is difficult to visualise them in 3D space.

When declaring arrays, each dimension is represented as a subscript in the array. A two-dimensional array has two subscripts. A three-dimensional array has three subscripts. For example:

```C++
int grid[3][3];
grid[0][0] = 1;

int cube[3][3][3];
cube[0][0][0] = 2;
```

Arrays can have any number of dimensions, but it is unlikely to have arrays with more than two dimensions.

>**Note**
Multidimensional arrays can rapidly grow to exceed available memory, so keep that in mind when creating large arrays with multiple dimensions.

### Initialising Multidimensional Arrays

A multidimensional array can be initialised with a one-dimensional array. Values are assigned to array elements in order, with the last array subscript changing, and the former ones fixed. For example:

```C++
int mulArray[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
```

Here, the first value is assigned to `mulArray[0][0]`, the second value is assigned to `mulArray[0][1]`, and the third value is assigned to `mulArray[0][2]`. The next value is assigned to `mulArray[1][0]`, and so on.

Listing 7.2's program demonstrates how a multidimension array can be used.

### Listing 7.2 The Full Text of `listing_7_2.cpp`
```C++
#include <iostream>

int main()
{
    int mulArray[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) {
            
            std::cout << "mulArray[" << i << "]";
            std::cout << "[" << j << "]";
            std::cout << " = " << mulArray[i][j] << std::endl;
            
        }
    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 7.2's program produces the following output:

```Console
mulArray[0][0] = 1
mulArray[0][1] = 2
mulArray[0][2] = 3
mulArray[1][0] = 4
mulArray[1][1] = 5
mulArray[1][2] = 6
mulArray[2][0] = 7
mulArray[2][1] = 8
mulArray[2][2] = 9

```

Here, the `mulArray` variable is a 3-by-3, two-dimensional array.

Two `for` loops are used to iterate through the array, displaying each array element and its value.

An alternative way to initialise `mulArray` is to include inner braces. For example:

```C++
int mulArray[3][3] = {
    {1, 2, 3}, 
    {4, 5, 6},
    {7, 8, 9} };
```

The compiler ignores the inner braces. This makes it easier to see how the numbers are distributed.

Each value must be separated by a comma without regard to the braces. The entire initialisation must be within braces, and must end with a semicolon.

## Character Arrays

Understanding how arrays work makes it possible to work with text longer than a single character. A string is a series of characters. In previous listings and snippets, only string literals have been used. For example:

```C++
std::cout << "I'm literally a string literal!" << std::endl;
```

In C++, a string is an array of characters ending with a `null` character, a special character coded as '\0'. A string can be declared and initialised like any other array. For example:

```C++
char name[] = {'M', 'a', 'c', '\0'};
```

The last character is the `null` character, which terminates the string.

Because declaring a string in this way is tedious and error-prone, C++ enables a shorthand form of string initialisation using a literal. For example:

```C++
char name[] = "Mac";
```

This form of initialisation doesn't require the `null` character; the compiler adds it automatically.

It is possible to create uninitialized character arrays, which are called buffers. It is important that not too many characters are put in the buffer than there is room for.

Buffers can be used to store input typed by a user. For example:

```C++
char buffer[100];

std::cout << "What is your first name? ";
std::cin >> buffer;
```

While this works, there are two common problems. First, if the user enters more characters than the size of the buffer, `cin` writes past the end of the buffer, making the program run improperly. Second, if the user enters a space, `cin` thinks this is the end of the line and stops writing to the buffer.

To solve these, you must call a function of the `cin` object called `getline()` with two arguments:

* The buffer to fill
* The maximum number of characters to read

The following snippet demonstrates how to use `std::cin`'s `getline()` member function:

```C++
char buffer[100];
std::cout.getline(buffer, 99);
```

Here, a maximum of 100 characters are read into the buffer, `buffer`.

`getline()` can also be called with a third argument, the delimiter that terminates the input. For example:

```C++
char buffer[100];
std::cout.getline(buffer, 99, ' ');
```

Here, the statement terminates input at the first space. When the third argument is omitted, the newline character ('\n') is the default delimiter.

Listing 7.3's program demonstrates how buffers can be used.

### Listing 7.3 The Full Text of `listing_7_3.cpp`
```C++
#include <iostream>

int main()
{
    char name[50];
    char quest[50];
    char velocity[50];

    std::cout << "What, is your name? ";
    std::cin.getline(name, 49);

    std::cout << "What, is your quest? ";
    std::cin.getline(quest, 49);

    std::cout << "What, is the velocity of an unladen swallow? ";
    std::cin.getline(velocity, 49);

    return 0;
}
```

<!-- Relevant: https://www.youtube.com/watch?v=liIlW-ovx0Y -->

<!-- Also relevant: https://www.youtube.com/watch?v=dPOyOM7wxlE -->

When compiled and run, Listing 7.3's program produces the following output:

```Compile
What, is your name? Arthur, King of the Britons.
What, is your quest? To seek the Holy Grail!
What, is the velocity of an unladen swallow? 11 m/s
```

Here, line 10 calls `cin`'s `getline()` function. The buffer declared in line 5 is passed in as the first argument. The second argument is the maximum number of characters allowed as input. Because `name` can hold 50 characters, the argument must be 49 to allow for the `null` terminating character. The default delimiter is also used. The statements on lines 13 and 16 behave in a similar fashion.

## Copying Strings

C++ inherits from C a library of functions for dealing with strings. This library can be incorporated in a program by including the header file ```string.h```. For example:

```C++
#include <string.h>
```

Among the functions provided are two for copying one string to another: `strcpy_s()` and `strncpy_s()`.

The `strcpy_s()` function copies the entire contents of one string into a designated buffer.

Listing 7.4's program demonstrates how `strcpy_s()` can be used.

### Listing 7.4 The Full Text of `listing_7_4.cpp`
```C++
#include <iostream>
#include <string.h>

int main()
{
    char literal[] = "She's a witch!";
    char buffer[80];

    strcpy_s(buffer, literal);

    std::cout << "Literal: " << literal << std::endl;
    std::cout << "Buffer: " << buffer << std::endl;

    return 0;
}
```

When compiled and run, Listing 7.4's program produces the following output:

```C++
Literal: She's a witch!
Buffer: She's a witch!
```

Here, a character array is created on line 6 and initialised with the value of a string literal. The `strcpy_s()` function of line 9 takes two-character arrays: a destination array and a source array. If the source array is larger than the destination, `strcpy_s()` writes data past the end of the buffer.

To prevent against writing past the length of the destination buffer's size, the `strncpy_s()` function can be used. This function takes an additional argument, which specifies the maximum number of characters to copy. For example:

```C++
strncpy_s(buffer, literal, 80);
```

## Reading Arrays with Foreach Loops

A recent addition to C++ was a new type of `for` loop, which can iterate through each element in an array. It's commonly called a foreach loop because it can loop through each element in an array once.

The foreach loop uses the keyword `for`, like other `for` loops. Unlike other `for` loops, the foreach loop has two sections separated by a colon (:) instead of three sections separated by semicolons.

The first section is a variable that will hold an element of the array. The second is the name of the array.

Listing 7.5's program demonstrates how a foreach loop can be used.

### Listing 7.5 The Full Text of `listing_7.5.cpp`
```C++
#include <iostream>

int main()
{
    int production [] = {1000, 2000, 3000, 4000};
    
    for(auto element : production) 
    {
        std::cout << "Production: " << element << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 7.5's program produces the following output:

```Console
Production: 1000
Production: 2000
Production: 3000
Production: 4000

```

Here, an array named `production` is initialised with four integer values.

In line 7, a `for` loop is declared, which will iterate once for each element in `production`. The elements are stored in the variable `element`, which deduces its type using the `auto` keyword.

The value is displayed on line 9.

## Summary

One thing that makes software useful is the ability to process large amounts of similar data.

Arrays are collections of data that share the same data type.

Strings are a type of arrays, which store characters.

There are many other ways to represent data in C++.

## Q & A

Q. What happens if I write to element 25 in a 24-member array?

A. When you store a value past the end of an array, you write to other memory with potentially dangerous effects on your program. Memory used by the program could be overwritten and the software could run improperly.

Q. What is in an uninitialized array element?

A. The value is whatever happens to be in memory at a given time. The results of using this element without assigning a value are unpredictable.

## Workshop

### Quiz

1. What is the minimum array subscript for an array?

    A. 0
    B. 1
    C. There is not a minimum array subscript.

<!-- A. All arrays start with zero. The last element is the size of the array minus 1. -->

2. What happens if you try to store data beyond the maximum allowed array subscript?

    A. The compiler reports an error
    B. The data is ignored
    C. The data is written in memory past the array.

<!-- C. The data is written to the address right after the end of the array. It's difficult to tell what will happen. If lucky, the data will be stored in an area of memory the computer doesn't want you to access and you'll get an error. If unlucky, another variable is changed in some strange way that is difficult to debug. -->

3. What is another name for a character array that doesn't have an initial value?

    A. A string
    B. A buffer
    C. A `null` character

<!-- B. A buffer can be used to store user input or any other character data. -->

## Activities

1. Write a program that asks a user their first name and displays it as part of a sentence greeting them.

2. Write a program that uses a `foreach` loop that displays each letter in a user's last name on a new line.

