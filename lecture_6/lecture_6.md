# Lecture 6: Controlling the Flow of a Program

## What You'll Learn in This Lecture

* What loops are and how they are used
* How to build various loops
* Using `switch-case` for complex conditional tests

## Looping

One of the things that a computer does well is doing the same thing repeatedly. Software doesn't get tired.

Many tasks in a program are done by doing the same thing either a fixed number of times or until a specific condition is met. A block of code that's executed more than once in a row in a program is called a loop. Each pass through the loop is called an iteration.

## `while` Loops

A `while` loop causes a program to repeat a group of statements if a starting condition remains true. The `while` keyword is followed by an expression in parenthesis. If the expression is true, the statement inside the loop block are executed. They are repeated until the expression is false. 

Consider the following:

```C++
int x = 0;
while (x < 100)
{
    std::cout << x << std::endl;
    x++;
}
```

Here, the `while` keyword is followed by an expression in parentheses. This statement doesn't end with a semicolon. The statements inside the loop are a block statement surrounded by opening { and closing } braces.

The loop has the conditional expression `x < 100`. Each time `x` is less than 100, the body of the loop is executed, and the value of `x` is displayed.

When `x` equals 100, the loop ends.

Without the statement `x++`, the value of `x` would remain 0 and the loop would iterate endlessly. This is called an infinite loop.

Listing 6.1's program demonstrates how a `while` loop can be used.

### Listing 6.1 The Full Text of `listing_6_1.cpp`
```C++
#include <iostream>

int main()
{
    int counter = 0;

    while (counter < 500)
    {
        counter++;

        if (counter % 13 == 0)
        {
            std::cout << counter << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 6.1's program produces the following output:

```Console
13 26 39 52 65 78 91 104 117 130 143 156 169 182 195 208 221 234 247 260 273 286 299 312 325 338 351 364 377 390 403 416 429 442 455 468 481 494
```

Here, a condition is tested and the body of the `while` loop is executed while it is true. The condition on line 7 tests whether the `counter` variable's value is less than 500. If this condition is true, the loop's body is executed.

On line 9, `counter` is incremented. On line 11, an `if` statement checks if the current value of `counter` is divisible by 13. If it is, the value is displayed.

The conditional on line 7 is false when `counter` is no longer less than 500, causing the `while` loop to end. The program skips over the loop's body and ends.

### Breaking Out of Loops

The `break` statement causes a loop to end immediately, instead of waiting for its condition to be false. This statement appears in a loop.

Listing 6.2's program demonstrates how a `break` statement can be used.

### Listing 6.2 The Full Text of `listing_6_2.cpp`
```C++
#include <iostream>

int main()
{
    int counter = 0;
    int multiples = 0;

    while (true)
    {
        counter++;

        if (counter % 14 == 0)
        {
            std::cout << counter << " ";
            multiples++;
        }
        if (multiples > 19)
            break;
    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 6.2's program produces the following output:

```Console
14 28 42 56 70 84 98 112 126 140 154 168 182 196 210 224 238 252 266 280
```

Here, the variable `counter` is incremented from 0 and each time it is divisible 14, its value is displayed.

The `while` conditional on line 8 differs from the Listing 6.1's `while` conditional:

```C++
while (true)
```

Because a `while` loop executes if its condition is true, this loop is designed to loop forever.

The `break` statement on line 18 is what causes the loop to end. A `multiples` variable tracks the number of times a multiple of 14 has been displayed. When it exceeds 19, `break` ends the loop.

>**Note**
Infinite loops, such as `while (true)` can cause a program to run forever if the exit condition is never reached. Press `ctrl + C` to end the execution of a program that isn't ending on its own.

### Continuing to the Next Loop

A `continue` statement is another way to alter the performance on a loop. When `continue` is encountered in a loop, the execution skips the loop's remaining statements and begins a new iteration.

Listing 6.3's program demonstrates how the `continue` statement is used.

### Listing 6.3 The Full Text of `listing_6_3.cpp`
```C++
#include <iostream>

int main()
{
    int counter = 0;
    int multiples = 0;

    while (multiples < 19)
    {
        counter++;

        if (counter % 15 != 0)
            continue;

        std::cout << counter << " ";
        multiples++;        
    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 6.3's program produces the following output:

```Console
15 30 45 60 75 90 105 120 135 150 165 180 195 210 225 240 255 270 285
```

Here, a `while` is used to iterate a `counter` variable like Listing 6.1 and Listing 6.2's programs. The `while` statement in line 8 causes the program to keep going until 20 multiples of 15 have been displayed.

`counter` is incremented on line 10.

An `if` statement on line 12 tests if `counter` is not divisible by 15. If this is true, the `continue` statement in line 12 is executed, and the rest of the loop's statements are skipped. Execution of the program resumes with line 8.

If `counter` is divisible by 15, the `continue` statement is ignored and lines 15-16 are executed. The value of `counter` is displayed and `multiples` is incremented.

C++ offers several different ways to complete similar tasks. If your program does what you want it to, you can choose whichever technique you want.

## `do-while` Loops

The `while` loop tests a conditional expression before executing the statements in the loop. If the condition is never true, the loop's statements will never execute.

A loop can test the condition at the end of the loop with the `do-while` statement.

Consider the following:

```C++
int x = 60;
do 
{
    std::cout << x << std::endl;
    x++;
} while (x < 50);
```

Here, the loop's conditional is only true when `x < 50`. Because `x` is initialised as being equal to 60, the condition is not met.

Despite this, the loop's statements will be executed once the value 60 will be displayed. This is because the `do-while` loop doesn't consider the condition until after the loop completes an iteration.

A `do-while` loop always executes the body at least once.

Listing 6.4's program demonstrates how a `do-while` is used.

### Listing 6.4 The Full Text of `listing_6_4.cpp`
```C++
#include <iostream>

int main()
{
    int badger = 0;

    std::cout << "How many badgers are there? ";
    std::cin >> badger;

    do
    {
        std::cout << "Badger" << std::endl;
        badger--;
    } while(badger > 0);

    std::cout << std::endl;

    return 0;
}

// as an aside, have a look at https://www.youtube.com/watch?v=EIyixC9NsLI.
```

When compiled and run, Listing 6.4's program produces the following output:

```Console
How many badgers are there? 3
Badger
Badger
Badger

```

Here, the user is prompted for a starting value on line 7, which is stored in the integer variable `badger`. In the `do-while` loop, the body of the loop is entered before the condition is tested, which means it is will be executed at least once. On line 12, "badger" is displayed; on line 12 `badger` is decremented; and on line 14, the condition is tested. If the condition is true, the execution jumps to line 12; otherwise, it continues to line 15.

The `continue` and `break` statements work in a `do-while` loop in the same way as they do in a `while` loop. The only difference between a `do-while` loop and a `while` loop is when the condition is tested.

## `for` Loops

When using loops in a program, often you'll use a counter variable, testing whether it meets a condition and changing the variable's value each loop iteration. For example:

```C++
int x = 0;
while (x < 10)
{
    std::cout << "X" << std::endl;
    x++;
}
```

Here, "X" is displayed 10 times on 10 new lines.

A `for` loop is a loop that combines all three aspects of these steps into a single statement. The statement consists of the keyword `for` followed by a pair of parentheses. Within the parentheses are three statements separated by semicolons:

* The initialisation of the counter
* The condition test
* The change to the counter

The previous snippet can be expressed as the following `for` loop:

```C++
for (int x = 0; x < 10; x++)
{
    std::cout << "X" << std::endl;
}
```

The first section of the loop is the initialisation. Any C++ statement can be put here, but, typically, it is used to declare and initialise a counter variable.

The second section of the loop is the test. Any C++ expression can be used. It serves the same purpose as a `while` and `do-while` loop's condition.

The third section of the loop is the action that changes the counter variable. Any C++ statement can be put here, but, typically it is used to increment or decrement the counter variable's value.

Listing 6.5's program demonstrates how a `for` loop can be used.

### Listing 6.5 The Full Text of `listing_6_5.cpp`
```C++
#include <iostream>

int main()
{
    int number = 0;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "First 10 multiples of " << number << " are: ";

    for (int i = number; i <= 10*number; i += number)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 6.5's program produces the following output:

```Console
Enter a number: 3
First 10 multiples of 3 are: 3 6 9 12 15 18 21 24 27 30
```

Here, the `for` loop on line 12 combines a variable's initialisation, a conditional expression, and an action applied to the variable, all on one line. The body of the `for` loop is line 14.

>**Note**
A common mistake made when writing a `for` loop is to use commas (,) instead of semicolons (;) to separate the loop's sections. Another common mistake is to place a semicolon after the closing parenthesis of the `for` statement. This makes the loop do nothing, but loop.

### Advanced `for` Loops

A `for` loop is flexible. It is common to initialise more than one variable, test a complex conditional expression, and execute multiple statements.

When the initialisation and action sections contain more than one statement, they are separated by commas. For example:

```C++
for (int x = 0, y = 0; x < 10; x++, y++)
{
    std::cout << x * y << std::endl;
}
```

Here, The loop's initialisation section contains two variables: `x` and `y`. Note how the variables are separated by a comma.

The loop's test section testes whether `x < 10`.

The loop's action section increments the variables `x` and `y`. Note how the actions are separated by a comma.

The body of the loop displays the product of `x` and `y`.

Each section of the `for` loop can be empty. The semicolons are still there to separate sections, but they don't need to have a statement. For example:

```C++
int x = 0;
int y = 0;
for (; x < 10; x++, y++)
{
    std::cout << x * y << std::endl;
}
```

### Nested Loops

Loops can be nested within another loop. The inner loop will be executed in its entirety for every execution of the outer loop.

Listing 6.6's program demonstrates how a `for` loop can be nested within another `for` loop.

### Listing 6.6 The Full Text of `listing_6_6.cpp`
```C++
#include <iostream>

int main()
{
    int rows = 0, columns = 0;
    char character = 0;

    std::cout << "How many rows? ";
    std::cin >> rows;

    std::cout << "How many columns? ";
    std::cin >> columns;

    std::cout << "What character to display? ";
    std::cin >> character;

    std::cout << std::endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << character;
        }
        
        std::cout << std::endl;

    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 6.6's program produces the following output:

```Console
How many rows? 5
How many columns? 3
What character to display? *

***
***
***
***
***

```

Here, the outer for loop is defined on line 19. It initialises a variable `i` with the value 0, tests whether it is less than the variable `rows`'s value, and increments `i` each time the loop iterates. The outer loop's body contains the inner `for` loop and an additional statement, which displays a new line.

The inner loop is defined on line 21. It initialises a variable `j` with the value 0, tests whether it is less than the variable `columns`'s value, and increments `j` each time the loop iterates. The inner loop's body consists of one statement, and displays the variable `character` `j` times.

When `j` is not less than `columns`, the inner loop ends, and the outer loop displays a new line. The outer loop then tests whether `i` is less than `rows`'s value. If true, then the inner `for` loop is executed. If false, the outer `for` ends and the program's execution continues.

When you use a nested loop, the inner loop is executed for each iteration of the outer loop. Here, `character` is printed `columns` times per `rows` times.

## `switch` Statements

When you use a series of `if` or `if-else` conditionals on the same variable, your C++ code can become confusing and cumbersome. An alternative is to use a `switch`, a conditional that tests one expression for multiple values to decide which of several blocks of code to execute.

A `switch` statement consists of the keyword `switch` followed by an expression to test one or more `case` sections with possible values of that expression, and possibly a `default` section.

Consider the following:

```C++
char direction = 0;

std::cout << "Direction (W,S): ";
std::cin >> direction;

switch (direction)
{
    case 'W':
        std::cout << "Forward" << std::endl;
        break;
    case 'S':
        std::cout << "Backward" << std::endl;
        break;
    default:
        std::cout << "Error" << std::endl;
}
```

Here, the `switch` expression is the variable `direction`. The two `case` sections catch two different values of `direction`. If the letter is 'W', then display "Forward". If the value is 'S', then display "Backward". 

The `default` section handles all other values of `direction`, displaying "Error".

The evaluation in the `case` sections of a `switch` statement only can be for equality. There's no way to test relational operators or Boolean operations. If one of the `case` values matches the expression, execution humps to those statements and continues to the end of the `switch` block unless a `break` statement is encountered. If nothing matches, then execution branches to the optional `default` statement. If there is no `default` statement and no matches, execution falls through the `switch` statement and the statement ends.

If there are no `break` statements at the end of a `case` section, execution falls through to the next case, and its section is also executed.

Listing 6.7's program demonstrates how a `switch` statement can be used.

### Listing 6.7 The Full Text of `listing_6_7.cpp`
```C++
#include <iostream>

int main()
{
    char grade = 0;

    std::cout << "Enter your letter grade (A,B,C,D,E,F): ";
    std::cin >> grade;

    switch (grade)
    {
        case 'A':
            std::cout << "Fantastic!";
            break;
        case 'B':
            std::cout << "Great!";
            break;
        case 'C':
            std::cout << "Keep it up.";
            break;
        case 'D':
            std::cout << "I know you can do it.";
            break;
        case 'E':
            std::cout << "I believe in you.";
            break;
        case 'F':
            std::cout << "Have another go. I'm sure you'll do better next time!";
            break;
        default:
            std::cout << "Not an accepted letter grade.";
            break;
    }

    std::cout << std::endl;

    return 0;
}
```

When compiled and run, Listing 6.7's program produces the following output:

```Console
Enter your letter grade (A,B,C,D,E,F): A
Fantastic!

Enter your letter grade (A,B,C,D,E,F): B
Great!

Enter your letter grade (A,B,C,D,E,F): F
Have another go. I'm sure you'll do better next time!

Enter your letter grade (A,B,C,D,E,F): 0
Not an accepted letter grade.
```

Here, the user is prompted for a letter. That letter is tested with a `switch` statement in line 10. The `case` statement on line 12 tests if the variable `grade` is equal to the letter 'A'. If it's a match, line 13's statement is executed, and the `break` statement ends the statement.

## Summary

Loops are useful components of C++ programs.

The `while` loop runs a block of code until a condition is no longer true. If the condition is never true, the loop's code is never executed.

The `do-while` loop runs a block of code at least once, even if its condition is never true.

The `for` loop is consists of initialisation, test, and action sections. These sections make it possible to create a counter variable, test its value, and change its value all within the `for` statement.

Sophisticated loops can be created using the `continue` statement, which skips to the beginning of a loop, and the `break` statement, which ends a loop.

The `switch` statement simplifies the process of checking the same variable for a set of different equality values.

## Q & A

Q. How do you choose between `if-else` and `switch`?

A. If there's more than one or two `else` clauses and all are testing the same value, consider using a `switch` statement. If you need to compare relationships, e.g. `a > b`, you cannot use the `switch` statement.

Q. How do you choose between `while` and `do-while`?

A. If the body of the loop always should execute at least once, consider a `do-while` loop; otherwise, use the `while` loop.

Q. How do you choose between `while` and `for`?

A. If you are executing a statement a fixed number of times, considering using the `for` loop. If your variable is already initialised or is not incremented on each loop, a `while` loop might be the better choice.

## Workshop

### Quiz

1. What data type should be used for a `for` loop?

    A. Integer
    B. Integer or float
    C. Any type is acceptable

<!-- C. Most programmers limit their use of the `for` statement to integers, but that is not a limitation of the language; you can work with floats or strings or other types of data -->

2. Which loop cannot use the `break` or `continue` statements?

    A. `for`
    B. `for` or `while`
    C. None

<!-- C. The `break` and `continue` statements can be used in any type of loop, although they are less common in `for` loops. The reason is that those loops often loop a fixed number of times. -->

3. What does the `break` command do within a `switch` statement?

    A. Skip to the next `case`
    B. End the `switch` statement
    C. Skip to the `default` section

<!-- B. Within a `switch` statement, the break command causes execution to resume outside of the body of the `switch` statement. Without it, commands are executed from the first case condition that is true until the end of the switch body. -->

### Activities

1. Write a program that displays the first 100 multiples of 16.

2. Modify Listing 6.7 so that it handles letters G, H, and I, displaying a random message.
