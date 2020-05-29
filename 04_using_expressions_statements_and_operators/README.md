## Lecture 4: Using Expressions, Statements, and Operators

## What You'll Learn in this Lecture:

* How to write statements
* How to create expressions
* How to run code if a condition is met
* What the different operators accomplish

## Statements

All C++ programs are made up of statements, which are commands that end with a semicolon. A statement controls the program's sequence of execution, evaluates an expression, or even can do nothing at all (the `null` statement). A common statement is an assignment:

```C++
x = a + b;
```

This statement assigns the variable x to equal the sum of variables a and b's values. The assignment operator = assigns the value on the right side of the operator to a variable on the left side. If `a` equals 4 and `b` equals 13, `x` equals 17 after the statement is executed.

### Whitespace

In the source code of a C++ program, any spaces, tabs, and newline characters are called whitespace. The compiler generally ignores whitespace, which serves the purpose of making the code more readable for programmers.

The previous statement could be written in the following ways and still work the same:

```C++
x = a + b;
x   =   a   +   b   ;
```

The compiler ignores whitespace. Whitespace cannot be used inside a variable's name, so the variable `playerScore` could not be referred to as `player Score`.

The tabs or spaces that serve the purpose of indentation in programs are whitespace. Proper indentation makes it easier to see when a program block or function block begins and ends.

### Compound Statements

Several statements can be grouped together as a compound statement, which begins with an opening brace { and ends with a closing brace }. A compound statement can appear anywhere a single statement could.

Although every statement in a compound statement must end with a semicolon, the compound statement itself does not end with a semicolon. For example:

```C++
{
    temp = a;
    a = b;
    b = temp;
}
```

This compound statement swaps variables `a` and `b`'s values by using a temporary variable named `temp`.

## Expressions

An expression is any part of a statement that returns a value. For example:

```C++
x = y + 13;
```

Here, this statement makes the variable `x` equal to the variable `y` plus 13. So, if `y` equals 20, `x` equals 33. The entire statement returns the final value of `x`, so it's also an expression. 

Consider the following:

```C++
z = x = y + 13;
```

This statement consists of three expressions:

* The result of the expression `y + 13` is stored in the variable `x`.
* The expression `x = y + 13` returns the value of `x`, which is stored in variable `z`.
* The expression `z = x = y + 13` returns the value of `z`, which is not stored.

The assignment operator = causes the operand on the left side of the operator to have its value changed to the value on the right side of the operator.

Operand is a term referring to the part of an expression operated upon by an operator.

Listing 4.1 displays the values of three variables before and after they are used in a complex, multiple-expression statement.

### Listing 4.1 The Full Text of listing4_1's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x = 12, y = 42, z = 88;

    std::cout << "Before -- x: " << x << " y: " << y << " z: " << z << std::endl;

    z = x = y + 13;

    std::cout << "After -- x: " << x << " y: " << y << " z: " << z << std::endl;


    return a.exec();
}
```

Listing 4.1's program produces the following output:

```Console
Before -- x: 12 y: 42 z: 88
After -- x: 55 y: 42 z: 55
```

The variables are declared and given initial values in line 5, then those values are displayed. An expression in line 9 assigns values to `x` and `z`, in that order. The new values are displayed, and the program ends.

## Operators

An operator is a symbol that causes the compiler to take an action such as assigning a value or performing multiplication, division, or another operation.

### Assignment Operator

An expression consists of an assignment operator, an operand to its left called an l-value, and an operand to its right called and r-value. In the expression `grade = 95`, the l-value is `grade` and the r-value is 95.

Constants are r-values, but cannot be l-values. The expression `95 = grade` is not permitted in C++ because the constant 95 cannot be assigned a new value.

The primary reason to learn the terms l-value and r-value is because they may appear in compiler error messages.

### Mathematical Operators

There are five mathematical operators: addition (+), subtraction (-), multiplication (*), division (/), and modulus (%). 

Addition, subtraction, and multiplication act as expected; however, division is slightly more complex.

Integer division differs from ordinary division. When you divide 21 by 4, the ordinary result is a real number that has a decimal value. By contrast, the integer result is an integer value with no decimal value. Integer division returns the value 5.

The modulus operator % returns the remainder value of integer division, so 21 % 4 equals 1. The integer division of 21 / 4 is five, leaving 1 remaining.

> **Note**
When describing an expression using the modulus operator, it is called modulo, so 21 % 4 is "21 modulo 4." Modulo is the operation performed by the modulus operator and the result is called the modulus.

### Combining Operators

It is not uncommon to want to add a value to a variable and then assign the result back into the variable. For example:

```C++
score = score + 10;
```

Here, the expression takes the existing value of `score` and adds 10 to it, and stores the result in `score`.

This expression can be written simply using the += self-assigned addition operator. For example:

```C++
score += 10;
```

The self-assigned operator, += adds the r-value to the l-value, and then assigns the result to the l-value. There self-assigned subtraction (-=), division (/=), multiplication (*=), and modulus (%=) operators as well.

These operators do the same thing as longer expressions, so either form can be used.

### Increment and Decrement Operators

The most common value to add or subtract from a variable is 1. Increasing a variable by 1 is called incrementing, and decreasing a variable by 1 is called decrementing. C++ includes a ++ increment operator and a -- decrement operator to do this. For example:

```C++
score++;
monsters--;
```

These statements increase `score` by 1 and decrease `monsters` by 1, respectively. They are equivalent to the following:

```C++
score = score + 1; // or score += 1;
monsters = monsters - 1; // or monsters -= 1;
```

The ++ operator is said aloud as "plus-plus" and -- as "minus-minus".

> **Note**
Consider the name of the C++ programming language. See how it includes the ++ operator? It's supposed to infer that C++ is an incremental improvement over the older C programming language.

### Prefix and Postfix Operators

The increment operator ++ and the decrement operator -- can be used either before or after a variable's name to achieve different results. An operator placed before a variable's name is called a prefix operator. For example:

```C++
++count;
```

An operator placed after a variable's name is called a postfix operator. For example:

```C++
count++;
```

In these statements, the operators accomplish the same thing. `count` is incremented by 1.

The reason for the existence of the prefix and postfix operators becomes apparent in more complex expressions, where a variable is being incremented or decremented and assigned to another variable. The prefix operator occurs before the variable's value is used in the expression. The postfix operator is evaluated after.

Consider the following:

```C++
int x = 5;
int sum = ++x;
```

After these statements are executed, the `x` variable and `sum` variable both equal 6. The prefix operator in `++x` causes `x` to be incremented from 5 to 6 before it is assigned to `sum`.

Consider the following:

```C++
int x = 5;
int sum = x++;
```

After these statements are executed, the `x` variable is equal to 6 and `sum` is equal to 5. The postfix operator in `x++` causes `x` to be increment from 5 to 6 after it is assigned to `sum`.

Listing 4.2 demonstrates counting forward several years using prefix and postfix increment operators.

### Listing 4.2 The Full Text of listing4_2's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int year = 2019;

    std::cout << "The year " << ++year << " passes" << std::endl;
    std::cout << "The year " << ++year << " passes" << std::endl;
    std::cout << "The year " << ++year << " passes" << std::endl;

    std::cout << "It is now: " << year << std::endl;

    std::cout << "The year " << year++ << " passes" << std::endl;
    std::cout << "The year " << year++ << " passes" << std::endl;
    std::cout << "The year " << year++ << " passes" << std::endl;

    std::cout << "It is now: " << year << std::endl;

    return a.exec();
}
```

Listing 4.2's program produces the following output:

```Console
The year 2020 passes
The year 2021 passes
The year 2022 passes
It is now: 2022
The year 2022 passes
The year 2023 passes
The year 2024 passes
It is now: 2025
```

Listing 4.2's program counts forward three years. The program begins by setting the `year` variable to 2019 in line 5.

Line 7 produces the first output of the program: "The year 2020 passes". Note that the year is 2020 and not 2019! This is because the prefix operator was used in that line.

Several years pass, and in line 11, `year` equals 2022.

Line 13 produces the output: "The year 2022 passes". `year` remains 2022 because the postfix operator changes the value of `year` after it is displayed.

### Operator Precedence

The values produced by a complex expression depend on the order of precedence, which is the order in which expressions are evaluated. Consider the following expression:

```C++
int x = 5 + 3 * 8;
```

Without know the order of multiplication and addition, it's impossible to know what `x` equals after this statement executes.

This expression sets `x` to 64 if addition takes place before multiplication; otherwise, it sets `x` to 29 if multiplication takes place before addition.

Every operator has a precedence value in C++. Multiplication has a higher precedence than addition, so the expression does in fact set `x` to 29.

### Table 4.1 Operator Precedence
| Level       | Operators                           | Evaluation Order |
|-------------|-------------------------------------|------------------|
| 1 (highest) | () . [] -> ::                       | Left to Right    |
| 2           | * & ! ~ ++ -- + -                   | Right to left    |
| 2           | sizeof new delete                   | Left to right    |
| 3           | .* -> *                             | Left to right    |
| 4           | * /                                 | Left to right    |
| 5           | + -                                 | Left to right    |
| 6           | << >>                               | Left to right    |
| 7           | < <= >>=                            | Left to right    |
| 8           | == !=                               | Left to right    |
| 9           | &                                   | Left to right    |
| 10          | ^                                   | Left to right    |
| 11          | \|                                  | Left to right    |
| 12          | &&                                  | Left to right    |
| 13          | \|\|                                | Right to left    |
| 14          | ?:                                  | Right to left    |
| 15          | = *= /= += -= %= <<= >>= &= ^= \|=  | Right to left    |
| 16 (Lowest) | ,                                   | Left to right    |

When two operators have the same precedence, they are performed in a left-to-right order. Consider the following:

```C++
int x = 5 + 3 + 8 * 9 + 6 * 4;
```

Because multiplication has higher precedence than addition and the same operators have left-to-right order, 8 times 9 is evaluated first and becomes 72:

```C++
int x = 5 + 3 + 72 + 6 * 4;

Next, 6 times 4 is evaluated:

```C++
int x = 5 + 3 + 72 + 24;
```

Now addition operators are handled in left-to-right order. The result is that `x` equals 104.

Some operators, such as assignment, are evaluated in a right-to-left order. Consider the following:

```C++
int z = x = y + 13;
```

The first expression evaluated in `y + 13`, which is assigned to `x`, which is assigned to `z`.

When precedence order doesn't meet your needs, you can use parentheses to impose a different order. Items within parentheses are evaluated at a higher precedence than any mathematical operators.

> **Note**
When in doubt, use parentheses to make an expression's meaning clear. They do not affect a program's performance, so there's no harm in using them when, strictly speaking, they wouldn't be necessary.

### Relational Operators

Relational operators are used for comparisons to determine when two numbers are equal, or one is greater or less than the other. Every relational expression returns either true or false.

### Table 4.2 The Relational Operators
| Name                   | Operator | Sample                   | Evaluates  |
|------------------------|----------|--------------------------|------------|
| Equals                 | ==       | 100 == 50, 100 == 100` | false, true |
| Not equal              | !=       | 100 != 50, 50 != 50`   | true, false |
| Greater than           | >        | 100 > 50, 50 > 50`     | true, false |
| Greater than or equals | >=       | 100 >= 50, 50 >= 100`  | true, false |
| Less than              | <        | 100 < 50, 50 < 100`    | false, true |
| Less than or equals    | <=       | 100 <= 50, 50 <= 50`   | false, true |

If you have integer variables `myAge` and `yourAge`, the expression `myAge == yourAge` determines whether they are equal. The following statement uses this expression:

```C++
std::cout << (myAge == yourAge) << std::endl;
```

This statement displays 1 if they are the same, 0 if they are not.

> **Note**
Many novice C++ programmers confuse the assignment operator with the equality operator ==, which can introduce bugs into a program that are difficult to spot.

## `If-Else` Conditional Statement

In the previous listings, each program executed each line in order from top to bottom. The `if` keyword makes it possible to run code only if a condition is met, such as whether two variables are equal, if one variable is larger than the other, or if a `bool` variable is true.

The following statement displays a message only if the variable high score is greater than 100:

```C++
if (highScore > 100)
    std::cout << "Congratulations! You have a new high score." << std::endl;
```

The code displays "Congratulations! You have a new high score." only if highScore is greater than 100. The expression within the parentheses is the condition. If the expression is true, the statement following the `if` is executed. If it is false, the statement is skipped. For example, if `highScore` was only 25, nothing is displayed.

The expression must be true for the conditional code to be executed. Because `bool` variables can be true or false, one can be used as the condition. For example:

```C++
bool run = true;
if (run)
    std::cout << "Running!" << std::endl;
```

The code displays the text "Running!" only when the `bool` variable `run` equals true.

### The `Else` Clause

A program can execute on statement if an `if` condition is true and another if it is false. The `else` keyword identifies the statement to execute when the condition is false. For example:

```C++
if(monsters == 0)
    std::cout << "All the monsters are gone!" << std::endl;
else
    std::cout << "Beware! There are monsters about." << std::endl;
```

Listing 4.3 demonstrates the use of conditional statements.

### Listing 4.3 The Full Text of listing4_3's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int grade;

    std::cout << "Enter a grade (1-100): ";
    std::cin >> grade;

    if (grade >= 70)
        std::cout << "Congratulations! You passed." << std::endl;
    else
        std::cout << "I'm sorry. You failed." << std::endl;

    return a.exec();
}
```

Listing 4.3's program produces the following output:

```Console:
Enter a grade (1-100): 85
Congratulations! You passed.
```

In the previous listings, the `#include` directive was used to include the standard C++ library `iostream`. This allowed for the `std::cout` object to be used to display information to a user. 

In Listing 4.3, the `std::cin` object was used to read data from a user. Line 7 prompts the user to enter a number between 1 and 100. Line 8 uses `std::cin` to receive keyboard input from the user and store it in the integer variable, `grade`.

Listing 4.3 displays different output depending on what the user enters as a grade. The variability uses the `if-else` conditional in lines 10-13.

### Compound `If` Statements

Compound statements can be used anywhere in code that single statement could be placed. The `if` and `if-else` conditionals often are followed by compound statements. For example:

```C++
if (monsters == 0)
{
    std::cout << "Yeet! No more monsters." << std::endl;
    score += 100;
}
```

This code does two things when monsters equals 0: first, it displays "Yeet! No more monsters."; second, it increments `score` by 100. If `monsters` doesn't equal 100, neither of these things occurs.

Any statement can be used with an `if` conditional, even another `if` or `else` statement.

Listing 4.4 expands upon Listing 4.3, displaying different messages for different grades.

### Listing 4.4 The Full Text of lisitng4_4's `main.cpp`
```C++
#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int grade;

    std::cout << "Enter a grade (1-100): ";
    std::cin >> grade;

    if (grade >= 70)
    {
        if (grade >= 90)
        {
            std::cout << "Congratulations! You got an A." << std::endl;
            return 0;
        }
        if (grade >= 80)
        {
            std::cout << "Good work! You got a B." << std::endl;
            return 0;
        }
        std::cout << "You got a C." << std::endl;
    }
    else
        std::cout << "I'm sorry. You failed." << std::endl;

    return a.exec();
}
```

Listing 4.4's program produces the following output:

```Console:
Enter a grade (1-100): 93
Congratulations! You got an A.
```

Listing 4.4's program has a main `if-else` conditional that handles when the user-input, `grade` is 70 or higher and when it isn't.

Grades 70 or higher are handled by lines 10-23. Two `if` statements cover grades 90 or higher and 80 or higher and display messages for A and B students. After the message is displayed, the `return 0` statement immediately ends the `main()` function so the program ends.

If the program is still running when line 22 is reached, a message for C students is displayed.

The `else` conditional is paired with the `if` in line 10. It covers grades lower than 70 and displays a corresponding message.

Listing 4.4 uses braces only around compound statements. The `else` conditional is followed with a single statement, so it doesn't need braces.

Some programmers always use braces with conditionals and other blocks of code, even when unnecessary. For example:

```C++
if (10 > 1)
{
    std::cout << "10 is more than 1" << std::endl;
}
```

This is permitted by the compiler and makes the `if` block of code more visually distinct. It also helps avoids bugs that occur when a single statement is turned into a compound statement, but forgets to enclose it within braces.

> **Note**
Remember that whitespace and indentation are meaningful to you as a programmer, but are ignored by the compiler. It doesn't care how `if` statements line up.

## Logical Operators

The previous listings' `if-else` conditionals have so far only used a single expression as the condition. It's possible to test more than one condition using the logical operators && (`AND`) and || (`OR`). The logical operator ! (`NOT`) tests whether an expression is false.

These operators are listed below:

### Table 4.3 Logical Operators
| Operator | Symbol | Example                     |
|----------|--------|-----------------------------|
| AND      | &&     | grade >= 70 && grade < 80   |
| OR       | \|\|   | grade > 100 \|\| grade < 1  |
| NOT      | !      | !grade >= 70                |

### `AND` Operator

The logical `AND` operator evaluates two expressions. If both expressions are true, the logical `AND` expression is true. Consider the following:

```C++
if ((x == 5) && (y == 5))
{
    // do something.
}
```

If `x` and `y` both equal 5, the expression is true. If either `x` or `y` does not equal 5, the expression is false. Both sides must be true for the entire expression to be true and for the conditional statement to execute.

### `OR` Operator

The logical `OR` operator evaluates two expressions. If either expressions are true, the logical `OR` expression is true. Consider the following:

```C++
if ((x == 5) || (y == 5))
{
    // do something.
}
```

If either `x` or `y` equals 5, or both equal 5, the expression is true. In fact, if `x` equals 5, the compiler doesn't bother checking `y`.

### `NOT` Operator

A logical `NOT` statement reverses a normal expression, return true if the expression is false and false if the expression is true. For example:

```C++
if (!(grade < 70))
{
    // do something.
}
```

This expression is true if `grade` is 70 or greater and false otherwise.

### Relational Precedence

Relational operators and logical operators, like other operators, return a value of true or false and have a precedence order that determines which relations are evaluation first. This is important when determining the value of a statement like the following:

```C++
if (x > 5 && y > 5 || z > 5)
{
    // do something.
}
```

The logical `AND` and `OR` operators have the same precedence, so are evaluated in left-to-right order. For this expression to be true, both `x` and `y` must be greater than 5, or `z` must be greater than 5.

Parentheses can be used to impose a different order. For example:

```C++
if (x > 5 && (y > 5 || z > 5))
{
    // do something.
}
```

For this expression to be true, `x` must be greater than 5 and either `y` or `z` must be greater than 5.

> **Note**
It is a good idea to use extra parentheses in complex logical expressions, just to clarify what the statement is doing. The left-to-right precedence of logical operators is easy for the compiler to understand, but not always for programmers.

## Alternative Expression Values

Expressions produce values true or false. In C++, the value 0 is considered false and any other value is true. Some C++ programmers use this feature in `if` statements. For example:

```C++
if (monsters)
    std::cout << "Beware! There are monsters about." << std::endl;
```

When `monsters` equals 0, the message is not displayed; else, when `monsters` is greater than 0, the message is displayed. This code is the same as the following:

```C++
if (monsters != 0)
    std::cout << "Beware! There are monsters about." << std::endl;
```

These statements are equivalent:

```C++
if (!x)
if (x == 0)
```

Both statements are true when `x` equals 0; however, the second statement is easier to understand.

## Summary

In this lecture, we've covered statements, expressions, and operators, the basic building blocks of C++.

Statements are individual lines of code that perform specific tasks. A program consists of hundreds, thousands, or even millions of statements. Each statement ends with a semicolon.

Expressions are statements or portions of statements that produce a value. The value can be assigned to a variable using the assignment operator, =.

Operators are symbols that cause the compiler to act. Operators can assign values, perform mathematical operations, and handle logical comparisons.

The conditional statements `if` and `else` can cause statements to be executed only if a specific condition is true. These conditions often are defined as expressions.

## Q & A

Q. Because precedence determines which operators are acted on first, why use parentheses when you don't need them?

A. Precedence isn't always as clear to a programmer looking at your code as it is to the C++ compiler. Using parenthesis to make a program more understandable to the people working on it will make things a lot easier.

Q. What effect do tabs, spaces, and newline characters have on a program?

A. These characters, which are called whitespace, are ignored by the compiler and have no effect on the program. Their purpose is to make programs easier for humans to understand. Poor indentation can make it difficult to determine which statements belongs to an `if` conditional, where a compound statement begins and ends, and so on.

Q. Are negative numbers true or false?

A. Every number except for 0, whether positive or negative, is treated as true.

## Workshop

### Quiz

1. What is the difference between `x++` and `++x`?

    A. They increment the value of `x` at different times.  
    B. The second form is not permitted in C++.  
    C. The first form is not permitted in C++.

<!-- A. The first uses the postfix operator and the second uses the prefix operator. Postfix evaluates the `x` before incrementing it, whereas prefix increments x before it is evaluated. The choice of postfix or prefix affects the value when it is used in an expression. -->

2. What is the difference between an l-value and an r-value?
    
    A. Only r-values can be used in expressions.
    B. Some r-values cannot be l-values, but all l-values can be r-values.
    C. Both A. and B.

<!-- B. An l-value appears on the left side of an = assignment operator, whereas an r-value appears on the right. All l-values also can appear on the right side of the operator, but some r-values (such as literals) cannot act as l-values. -->

3. What does the modulo operator `%` do?

    A. It performs integer division.
    B. It produces the remainder of an integer division.
    C. It produces the square root of a number.

<!-- B. It calculates the remainder after performing integer division on the supplied operands. -->

### Activities

1. Write a program that asks a person for a number between 0-20. If they type less than 15, display "You missed!"; otherwise, display "You hit; do 10 damage.".

2. Write a program that asks a person how much money they have. If they have more than $100, display "Wow! Can I have some?"; otherwise, display "Oh no! I'll buy you lunch."
