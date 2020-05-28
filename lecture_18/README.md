# Lecture 18

## What You'll Learn in This Hour

* What casting down is and why you might want to do it
* What abstract data types are
* What pure virtual functions are

## Problems with Single Inheritance

Previously, we saw how derived objects were treated polymorphically with their base class. Moreover, we saw that if the base class has a member function that is overridden in the derived class, a pointer to a base object that is assigned to a derived object will call the right function.

Listing 18.1's program demonstrates this idea.

### Listing 18.1 The Full Text of `listing_18_1.cpp`
```C++
#include <iostream>

class Mammal
{
public:
    Mammal() : age(1) { std::cout << "Mammal constructor()." << std::endl; }
    virtual ~Mammal() { std::cout << "Mammal destructor()." << std::endl; }

    virtual void speak() const { std::cout << "Mammal speak()." << std::endl; }
protected:
    int age;
};

class Dog : public Mammal
{
public:
    Dog() { std::cout << "Dog constructor()." << std::endl; }
    ~Dog() { std::cout << "Dog destructor()." << std::endl; }

    void speak() const { std::cout << "Woof." << std::endl; }
};

int main()
{

    Mammal *pDog = new Dog;

    pDog->speak();

    delete pDog;
    pDog = nullptr;

    return 0;
}
```

When compiled and run, Listing 18.1's program produces the following output:

```Console
Mammal constructor().
Dog constructor().
Woof.
Dog destructor().
Mammal destructor().
```

Here, two classes are declared, `Mammal` and `Dog`; where, `Dog` derives from `Mammal`. `Mammal` has a public default constructor and virtual destructor, and one public virtual member function, `speak()`. The class has one protected member variable, `age`. `Dog` has a public default constructor and destructor, and one public member function, `speak()`, which overrides `Mammal`'s implementation of the function.

On line 26, a pointer to a `Mammal` object is created and assigned the address of a `Dog` object. As such, we can treat the derived object as if it was a base object.

However, what happens if you want to add a member function to `Dog` that isn't relevant to `Mammal`? Suppose you want to add a function named `growl()`. Dogs growl, but other mammals do not. You would declare the class as follows:

```C++
class Dog : public Mammal
{
public:
    Dog() { std::cout << "Dog constructor()." << std::endl; }
    ~Dog() { std::cout << "Dog destructor()." << std::endl; }

    void speak() const { std::cout << "Woof." << std::endl; }
    void growl() const { std::cout << "Grrrr." << std::endl; }
};
```

The problem is: if you call `growl()` using a pointer to a `Mammal` object, you get a compiler error stating "'class Mammal' has no member named 'growl'".

When the compiler tries to resolve `growl()` in its `Mammal` virtual table, there is no entry. You can move this function up to the base class, but that's a bad idea. Although it works, populating your base class with functions specific to derived classes is poor programming practice and a recipe for hard-to-maintain code.

In fact, Listing 18.1 is a badly design programmed. Generally, if you have a pointer to a base class that is assigned to a derived class object, it is because you intend to use that object polymorphically, and in this case, you out not to even try to access functions that are specific to the derived class.

The problem is not that you have such specific function, it is that you are trying to get at them with the base class pointer. In an ideal world, when you have such a pointer, you would not try to access those functions.

However, in the case where you absolutely need to access the specific functions of a derived class, there is a way: cast your base class pointer to your derived type. You say to the compiler, "this is really a derived object". 

To make this work, use the `dynamic_cast` operator. This operator ensures that when you cast, you cast safely.

It works as follows: if you have a pointer to a base class, such as `Mammal`, and you assign it to a pointer to a derived class, such as `Dog`, you can use the pointer polymorphically to access virtual functions. Then, if you need to access `Dog`'s `growl()` member function, you create a `Dog` pointer using the `dynamic_cast` operator. At runtime, the base pointer is examined. If the conversion is okay, your new `Dog` pointer is okay. If the conversion is wrong, your new `Dog` pointer will be `null`. If the conversion is improper, it's because you didn't really have a `Dog` object.

Listing 18.2's program demonstrates how the `dynamic_cast` operator can be used.

### Listing 18.2 The Full Text of `listing_18_2.cpp`
```C++
#include <iostream>

class Mammal
{
public:
    Mammal() : age(1) { std::cout << "Mammal constructor()." << std::endl; }
    virtual ~Mammal() { std::cout << "Mammal destructor()." << std::endl; }

    virtual void speak() const { std::cout << "Mammal speak()." << std::endl; }
protected:
    int age;
};

class Dog : public Mammal
{
public:
    Dog() { std::cout << "Dog constructor()." << std::endl; }
    ~Dog() { std::cout << "Dog destructor()." << std::endl; }

    void speak() const { std::cout << "Woof." << std::endl; }
    void growl() const { std::cout << "Grrrr." << std::endl; }
};

class Cat : public Mammal
{
public:
    Cat() { std::cout << "Cat constructor()." << std::endl; }
    ~Cat() { std::cout << "Cat destructor()." << std::endl; }

    void speak() const { std::cout << "Meow." << std::endl; }
    void purr() const { std::cout << "Purrr." << std::endl; }
};

int main()
{
    Mammal *zoo[3];
    Mammal *pMammal;
    int choice, i;

    for (i = 0; i < 2; i++)
    {
        std::cout << "(1) Dog, (2) cat: ";
        std::cin >> choice;

        switch(choice)
        {
        case 1:
            pMammal = new Dog;
            break;
        case 2:
            pMammal = new Cat;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
        }

        zoo[i] = pMammal;
    }

    std::cout << std::endl;

    for (i = 0; i < 2; i++)
    {
        zoo[i]->speak();

        Cat *pRealCat = dynamic_cast<Cat *> (zoo[i]);

        if (pRealCat)
            pRealCat->purr();
        else
            std::cout << "Not a cat." << std::endl;

        delete zoo[i];
        zoo[i] = nullptr;

        std::cout << std::endl;
    }
  
    return 0;
}
```

When compiled and run, Listing 18.2's program produces the following output:

```Console
(1) Dog, (2) cat: 1
Mammal constructor().
Dog constructor().   
(1) Dog, (2) cat: 2  
Mammal constructor().
Cat constructor().   

Woof.
Not a cat.
Dog destructor().
Mammal destructor().

Meow.
Purrr.
Cat destructor().
Mammal destructor().

```

Here, Listing 18.2's program is very similar to Listing 18.1's. One difference is that there is a new class, `Cat`, which is functionally similar to `Dog`. Another difference is that `Cat` and `Dog` implement the functions `purr()` and `growl()`, respectively. Both of these functions are specific to each class and are not common with other mammals.

On lines 36-38, variables used in the program are declared. There is an array of pointers to `Mammal` objects, a pointer to a single `Mammal` object, and integers for tracking user input and loop iteration.

On lines 40-59, a `for` loop is used to ask the user to choose an animal twice. A `switch-case` statement is used to assign a pointer to a `Mammal` object the address of either a `Dog` or `Cat` object based on the user's choice. If the user didn't choose either animals, the program ends. Afterwards, the pointer is assigned to an array of pointers to `Mammal` objects' corresponding index.

On lines 63-78, a `for` loop is used to make each object in the array call its `speak()` function. A `dynamic_cast` operator is used to cast the object in the array's corresponding index into a pointer to a `Cat` object. An `if` statement checks whether the conversion was valid. If it was, the `Cat` pointer's `purr()` member function is called; else, a statement is displayed. Afterwards, the array's corresponding index is deleted and allocated memory freed.

## Abstract Data Types

Often, you will create a hierarchy of classes together. For example, you might create a `Shape` class as a base class to derive `Rectangle` and `Circle` classes from it. `Shape` may implement a number of member functions, such as `getArea()` or `draw()`, and `Rectangle` and `Circle` may override these.

Listing 18.3's program provides a bare-bones example of how the `Shape`, `Rectangle`, and `Circle` classes can be used.

### Listing 18.3 The Full Text of `listing_18_3.cpp`
```C++
#include <iostream>

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    
    virtual float getArea() const { return -1; }
    virtual void draw() const {}
};

class Circle : public Shape
{
public:
    Circle(int newRadius) : radius(newRadius) {}
    ~Circle() {}
    
    float getArea() { return ((22 / 7) * radius * radius); }
    void draw() const { std::cout << "Circle draw()." << std::endl; }

private:
    int radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(int newWidth, int newLength) : width(newWidth), length(newLength) { }
    ~Rectangle() { }
    
    float getArea() { return (width * length); }
    void draw() const { std::cout << "Rectangle draw()." << std::endl; }

private:
    int width;
    int length;
};

int main()
{
    bool loop = true;
    int choice = 0;
    Shape *pShape = nullptr;

    do
    {
        std::cout << "(1) Circle, (2) Rectangle, (0) Quit: ";
        std::cin >> choice;

        switch(choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pShape = new Circle(3);
            break;
        case 2:
            pShape = new Rectangle(3, 3);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
        }

        if(!loop)
            break;
      
        pShape->draw();
        
        delete pShape;
        pShape = nullptr;
     
        std::cout << std::endl;

    } while (loop);
    

    return 0;
}
```

When compiled and run, Listing 18.3's program produces the following output:

```Console
(1) Circle, (2) Rectangle, (0) Quit: 1
Circle draw().

(1) Circle, (2) Rectangle, (0) Quit: 2
Rectangle draw().

(1) Circle, (2) Rectangle, (0) Quit: 0
```

Here, three classes are defined, `Shape`, `Circle` and `Rectangle`; where, `Circle` and `Rectangle` derive from `Shape`. `Shape` has a public default constructor and a virtual destructor, and two public virtual member functions, `getArea()` and `draw()`. `Circle` has a public overloaded constructor and a destructor, and two public member functions, `getArea()` and `draw()`, which override `Shape`'s implementation. `Circle` has one private member variable, `radius`. `Rectangle` has a public overloaded constructor and a destructor, and two public member functions, `getArea()` and `draw()`, which override `Shape`'s implementation. `Rectangle` has two private member variables, `width` and `length`.

On lines 42-44, the variables using in the program are defined. There is a Boolean used to check if a loop should keep iterating, an integer to track user input, and a pointer to a `Shape` object.

On lines 46-65, a `do-while` loop continuously asks the user to choose a shape. A `switch-case` statement is used to assign a pointer to a `Shape` object the address of either a `Circle` or `Rectangle` object depending on the user's choice. If the user didn't choose either shape, the program ends. Afterwards, an `if` statement checks to see if the pointer was assigned a value. If not, the loop ends and the program ends; otherwise, the program's execution continues, and the pointer's `draw()` member function is called. Lastly, the pointer is deleted and the allocated memory freed.

Here, `Shape` has been used purely as an interface for the classes derived from it. It is an abstract data type, or an ADT.

An abstract data type represents a concept, like a shape, rather than an object, like a circle. In C++, an ADT is always the base class to other classes, and it is not valid to make an instance of an ADT. Therefore, if you make an ADT, it is not possible to make an instance of a `Shape` object.

### Pure Virtual Functions

C++ supports the creation of abstract data types with pure virtual functions. A pure virtual function is a virtual function that must be overridden in the derived class. A virtual function is made pure by initialising it with the value 0. For example:

```C++
virtual void draw() = 0;
```

A class with one or more pure virtual functions is an ADT, and it is illegal to instantiate an object of a class that is an ADT. To do so causes a compile-time error. Putting a pure virtual function in your class signals two things to the clients of your class:

* Don't make an object of this class, derive from it
* Make sure to override pure virtual functions

Any class that derives from an ADT inherits the pure virtual functions as pure, so it must override every pure virtual function if it wants to instantiate objects. Therefore, if `Rectangle` inherits from `Shape`, and shape has pure virtual functions, `Rectangle` must override all of these functions; otherwise, it too will be an ADT.

Here's a rewrite of `Shape` so that it is now an ADT:

```C++
class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    
    virtual float getArea() = 0;
    virtual void draw() = 0;
};
```

If this ADT was substituted for `Shape`'s definition in Listing 18.3, it would be impossible to make an object of this type.

### Implementing Pure Virtual Functions

Typically, the pure virtual functions in an abstract base class are never implemented. Because no objects of that type are ever created, there is no reason to provide implementations, and the ADT works purely as the definition of an interface to objects that derive from it.

It is possible, however, to provide an implementation to a pure virtual function. The function can then be called by objects derived from the ADT, providing a common functionality to all the overridden functions.

Listing 18.4's program defines `Shape` as an ADT and includes an implementation for the pure virtual function `draw()`. The `Circle` and `Rectangle` classes override the `draw()` function, calling the base class's implementation of the function.

### Listing 18.4 The Full Text of `listing_18_4.cpp`
```C++
#include <iostream>

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual float getArea() = 0;
    virtual void draw() = 0;
};

void Shape::draw()
{
    std::cout << "Abstract drawing method." << std::endl;

    return;
}

class Circle : public Shape
{
public:
    Circle(int newRadius) : radius(newRadius) {}
    ~Circle() {}

    float getArea() { return ((22 / 7) * radius * radius); }
    void draw();

private:
    int radius;
};

void Circle::draw()
{
    std::cout << "Circle draw()." << std::endl;
    Shape::draw();

    return;
}

class Rectangle : public Shape
{
public:
    Rectangle(int newWidth, int newLength) : width(newWidth), length(newLength) {}
    ~Rectangle() {}

    float getArea() { return (width * length); }
    void draw();

private:
    int width;
    int length;
};

void Rectangle::draw()
{
    std::cout << "Rectangle draw()." << std::endl;
    Shape::draw();

    return;
}

int main()
{
    bool loop = true;
    int choice = 0;
    Shape *pShape = nullptr;

    do
    {
        std::cout << "(1) Circle, (2) Rectangle, (0) Quit: ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pShape = new Circle(3);
            break;
        case 2:
            pShape = new Rectangle(3, 3);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
        }

        if (!loop)
            break;

        pShape->draw();

        delete pShape;
        pShape = nullptr;

        std::cout << std::endl;

    } while (loop);

    return 0;
}
```

When compiled and run, Listing 18.4's program produces the following output:

```Console
(1) Circle, (2) Rectangle, (0) Quit: 1
Circle draw().
Abstract drawing method.

(1) Circle, (2) Rectangle, (0) Quit: 2
Rectangle draw().
Abstract drawing method.

(1) Circle, (2) Rectangle, (0) Quit: 0
```

Here, Listing 18.4's program is very similar to Listing 18.3's. One difference is that `Shape` is defined as an ADT. Another difference is that `Circle` and `Rectangle`'s `draw()` member functions call `Shape`'s implementation of `draw()`. When the program is run, it's evident that both member functions are called for each user choice.

### Complex Hierarchies of Abstraction

At times, you will receive ADTs from other ADTs. It might be that you want to make some of the derived pure virtual functions non-pure and leave others pure.

If you create an `Animal` class, you can make `eat()`, `sleep()`, and `reproduce()` pure virtual functions. Perhaps you derive `Mammal` and `Fish` from `Animal`.

On examination, you could decide that every `Mammal` will reproduce in the same way, and so you make `Mammal::reproduce()` non-pure, but leave `eat()` and `sleep()` pure virtual functions.

From `Mammal` you derive `Dog`, and `Dog` must override and implement the three remaining pure virtual functions so that you can make `Dog` objects.

What you say, as a class designer, is that no `Animal` or `Mammal` objects can be instantiated, but that all `Mammal` objects can inherit the provided `reproduce()` member function without having to override it.

Listing 18.5's program demonstrates this technique.

### Listing 18.5 The Full Text of `listing_18_5.cpp`
```C++
#include <iostream>

enum COLOR
{
    Black,
    White,
    Brown
};

class Animal
{
public:
    Animal(int newAge) : age(newAge) { std::cout << "Animal constructor()." << std::endl; }
    virtual ~Animal() { std::cout << "Animal destructor()." << std::endl; }

    virtual int getAge() const { return age; }
    virtual void setAge(int newAge) { age = newAge; }

    virtual void eat() const = 0;
    virtual void sleep() const = 0;
    virtual void reproduce() const = 0;
    virtual void speak() const = 0;

protected:
    int age;
};

class Mammal : public Animal
{
public:
    Mammal(int newAge) : Animal(newAge) { std::cout << "Mammal constructor()." << std::endl; }
    virtual ~Mammal() { std::cout << "Mammal destructor()." << std::endl; }

    virtual void reproduce() const { std::cout << "Mammal reproduce()." << std::endl; }
};

class Fish : public Animal
{
public:
    Fish(int newAge) : Animal(newAge) { std::cout << "Fish constructor()." << std::endl; }
    ~Fish() { std::cout << "Fish destructor()." << std::endl; }

    virtual void eat() const { std::cout << "Fish eat()." << std::endl; }
    virtual void sleep() const { std::cout << "Fish sleep()." << std::endl; }
    virtual void speak() const {}
    virtual void reproduce() const { std::cout << "Fish reproduce()." << std::endl; }
};

class Dog : public Mammal
{
public:
    Dog(int newAge, COLOR newColor) : Mammal(newAge), color(newColor) { std::cout << "Dog constructor()." << std::endl; }
    virtual ~Dog() { std::cout << "Dog destructor()." << std::endl; }

    virtual COLOR getColor() const { return color; }

    virtual void eat() const { std::cout << "Dog eat()." << std::endl; }
    virtual void sleep() const { std::cout << "Dog sleep()." << std::endl; }
    virtual void speak() const { std::cout << "Woof." << std::endl; }
    virtual void reproduce() const { std::cout << "Dog reproduce()." << std::endl; }

private:
    COLOR;
};

int main()
{
    bool loop = true;
    int choice = 0;
    Animal *pAnimal = nullptr;

    do
    {
        std::cout << "(1) Fish, (2) Dog, (0) Quit: ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pAnimal = new Fish(1);
            break;
        case 2:
            pAnimal = new Dog(2, Black);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
        }

        if (!loop)
            break;

        pAnimal->eat();
        pAnimal->sleep();
        pAnimal->reproduce();
        pAnimal->speak();

        delete pAnimal;
        pAnimal = nullptr;

        std::cout << std::endl;

    } while (loop);

    return 0;
}
```

When compiled and run, Listing 18.5's program produces the following output:

```Console
Animal constructor().
Fish constructor().
Fish eat().
Fish sleep().
Fish reproduce().
Fish destructor().
Animal destructor().

(1) Fish, (2) Dog, (0) Quit: 2
Animal constructor().
Mammal constructor().
Dog constructor().
Dog eat().
Dog sleep().
Dog reproduce().
Woof.
Dog destructor().
Mammal destructor().
Animal destructor().

(1) Fish, (2) Dog, (0) Quit: 0
```

Here, four classes are declared, `Animal`, `Mammal`, `Fish`, and `Dog`. `Animal` is an ADT, which `Mammal` derives from. `Fish` derives from `Animal`, and `Dog` derives from `Mammal`. `Animal` has a public overloaded constructor and virtual destructor; two virtual accessors, `getAge()` and `setAge()`; and four pure virtual member functions, `eat()`, `sleep()`, `reproduce()`, and `speak()`. The class has one protected member variable, `age`. `Mammal` has a public overloaded constructor and virtual destructor, and one virtual member function, `reproduce()`, which overrides `Animal`'s implementation. The remaining pure virtual functions are not overridden, which means `Mammal` is also an ADT. `Fish` has a public overloaded constructor and virtual destructor, and four virtual member functions, `eat()`, `sleep()`, `reproduce()`, and `speak()`, which override `Animal`'s implementation. `Dog` has a public overloaded constructor and virtual destructor; one virtual accessor, `getColor()`; and four virtual member functions, `eat()`, `sleep()`, `reproduce()`, and `speak()`, which override `Animal`'s implementation. 

Because `Fish` derives from `Animal`, the class can't take advantage of `Mammal`'s definition of `reproduce()` and must override the function; however, because `Dog` derives from `Mammal`, the class doesn't need to override the function.

In the body of the program, an `Animal` pointer is used to point to the various derived objects in turn. The virtual member functions are invoked, and the correct function is called in the derived class, based on the runtime binding of the pointer.

If `Animal` or `Mammal` objects were instantiated, a compile-time error would be generated.

### Which Types Are Abstract?

In one program, `Animal` was abstract; in another, it wasn't. What determines whether to make a class abstract?

The answer depends on the design of your program. If you are writing a program that depicts a farm or a zoo, you might want `Animal` to be abstract, but `Dog` to be a class from which you can instantiate objects.

On the other hand, if you are making an animated kennel, you might want to keep `Dog` as an abstract data type and only instantiate types of dogs. The level of abstraction is a function of how finely you need to distinguish your types.

## Summary

An abstract data type is a class that cannot be implemented as an object. Instead, it defines common member variables and functions for its derived class.

A function becomes a pure virtual function by adding = 0 to the end of its declaration. If a class contains at least one pure function, the class is an abstract data type.

The compiler will not allow objects of an abstract data type to be instantiated.

## Q & A

Q. Why is dynamic casting bad?

A. The point of virtual functions is to let the virtual table, rather than the programmer, determine the runtime type of the object.

Q. Why bother making an abstract data type? Why not just make it non-abstract and avoid creating any objects of that type?

A. The purpose of many of the conventions in C++ is to enlist the compiler in finding bugs to avoid runtime bugs in completed code. Make a class abstract by giving it pure virtual functions causes the compiler to flag any objects created of that abstract type as errors. It also means that you can share the abstract data types with other applications or programmers.

## Workshop

### Quiz

1. Is there a difference between a virtual member function and an overridden member function in the base class?

    A. Yes
    B. No
    C. Only in some cases

<!-- A. Yes, a virtual function expects to be overridden in the derived classes. An overridden function does not have to be in derived classes. -->

2. What makes an abstract data type abstract?

    A. The `abstract` keyword
    B. It has at least one pure virtual function
    C. It has all pure virtual functions

<!-- B. The base class is abstract if it has one pure virtual function. Because of this function, you cannot create a concrete example of that class and must derive a class from the abstract, with the pure functions being overridden. -->

3. Is it okay to supply base class member functions that apply only to specific derived classes?

    A. Yes
    B. No
    C. It depends

<!-- B. No, base class member functions that apply only to some classes make it much harder to use derived objects. The function only can be called after checking the data type of each object. -->

### Activities

1. Modify Listing 18.5's program to instantiate an `Animal` and a `Mammal` object. What happens?

2. Modify Listing 18.2's program to see what happens when you remove the `if` statement on lines 69-72 and call `purr()` for each object. What happens? Which objects work properly, and which fail?
