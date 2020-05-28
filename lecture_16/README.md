# Lecture 16: Extending Classes with Inheritance

## What You'll Learn in This Lecture:

* What inheritance is
* How to derive one class from another
* How to access base member functions from derived classes
* How to override base member functions
* What protected access is and how to use it

## What is Inheritance?

Humans seek out, recognise, and create relationships among concepts. We build hierarchies, networks, and relationships to explain the ways things interact. C++ embodies this in inheritance hierarchies, making it possible for a class to inherit from another class.

Concepts can be categorised in many ways. For example, a car can be thought of as a network of mechanical, electrical, and software systems. 

Each category can be divided further into subcategories. For example, a Toyota Corolla is a car and a car is a type of vehicle.

Here, a hierarchy is established by using an "is a" statement.

When something is described as a kind of something else, this means it is a specialisation of that thing. For example, a car is a special kind of vehicle. Cars and buses are both vehicles. They are distinguished by their specific characteristics, but share things in common with each other and other vehicles.

### Inheritance and Derivation

These relationships are conveyed by inheritance. The concept of a car inherits all the functions of a vehicle. For example, because a car is a vehicle, it has wheels; by definition, all vehicles have wheels. The concept of a car adds to that the idea of having an engine (a bicycle is a vehicle, because it has wheels, but it doesn't have an engine). A car has traits unique to cars and traits common to all vehicles.

C++ attempts to represent relationships between objects by defining classes that derive from one another. Derivation is a way of expressing the "is a" relationship. You derive a new class, `Car`, from the class `Vehicle`. You don't have to state explicitly that cars have wheels because they inherit that from `Vehicle`. Because it derives from `Vehicle`, `Car` automatically has wheels.

A class that adds new functionality to an existing class is said to derive from the original class. The original class is said to be the new class's base class.

If the `Car` class derives from `Vehicle`, `Vehicle` is a base class of `Car`. Derived classes are supersets of their base classes. `Car` adds certain member functions or data to the `Vehicle` class.

A base class can have more than one derived class. Just as bicycles and motorbikes are vehicles, their classes would all derive from the `Vehicle` class.

### The Syntax of Derivation

To create a class that inherits from another class in C++, in the `class` declaration, put a colon after the class's name and specify the access level of the class (public, protected, or private) and after that the class it derives from. For example:

```C++
class Car : public Vehicle
{
    // class declaration
};
```

This statement creates a derived class named `Car` from the base class `Vehicle`.

Listing 16.1's program demonstrates how to derive a class from a base class.

### Listing 16.1 The Full Text of `listing_16_1.cpp`
```C++
#include <iostream>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    Vehicle();
    ~Vehicle();

    int getWheels() const;
    void setWheels(int newWheels);

protected:
    int wheels;
};

class Car : public Vehicle
{
public:
    Car();
    ~Car();

    int getCC() const;
    void setCC(int newCC);

protected:
    int cc;
    MANUFACTURER make;
};

int main()
{
    return 0;
}
```

When compiled and run, the program produces no output; it consists of only declarations and no definitions.

Here, a class named `Vehicle` is declared on lines 10-21. The class has a public constructor and destructor, and two public accessors, `getWheels()` and `setWheels()`. The class has a single protected member variable, `wheels`. Because all vehicles have wheels, this is represented by `wheels` here.

Another class named `Car` is declared on lines 23-35. The class has public constructor and destructor, and six public accessors, `getMake()`, `setMake()`, `getModel()`, `setModel()`, `getCC()`, and `setCC()`. The class has three protected member variables, `cc`, `make`, and `model`. 

`Car` inherits from `Vehicle`, as indicated on line 23. Every `Car` object has four member variables, `wheels`, `cc`, `make`, and `model`. Note that the declaration of `Car` doesn't include the variable `wheels`. `Car` objects inherit this variable from the `Vehicle` class, along with all the member functions (except the constructors, copy operator, and destructor).

## Private Versus Protected

A new keyword `protected` was introduced on lines 19 and 32 of Listing 16.1's program. In previous listings, class data has been declared `private`. However, private members are not available to derived classes. You could make `wheels` public, but this isn't desirable. You don't want other classes accessing these data members directly.

What you want is to make the data visible to this class and its derived classes, which is accomplished by `protected`. Protected data members and functions are fully visible to derived classes, but otherwise private.

There are three access specifiers: `public`, `protected`, and `private`. If a function has an instance of a class, it can access all the public member data and functions of that class. The member functions of a class, however, can access all the private member data and functions of any class that they derive from.

Even if other classes are layered between a derived class and the base class, the derived class will still be able to access the protected data members of the base class, assuming that these other classes have public inheritance.

Listing 16.2's program demonstrates how to derive a class and access it and the base class's data and member functions.

### Listing 16.2 The Full Text of `listing_16_2.cpp`
```C++
#include <iostream>
#include <string>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    Vehicle();
    ~Vehicle();

    int getWheels() const;
    void setWheels(int newWheels);

protected:
    int wheels;
};

Vehicle::Vehicle() : wheels(2)
{
    return;
}

Vehicle::~Vehicle()
{
    return;
}

int Vehicle::getWheels() const
{
    return wheels;
}

void Vehicle::setWheels(int newWheels)
{
    wheels = newWheels;

    return;
}

class Car : public Vehicle
{
public:
    Car();
    ~Car();

    std::string getMake() const;
    void setMake(MANUFACTURER newMake);

    int getCC() const;
    void setCC(int newCC);

protected:
    int cc;
    MANUFACTURER make;
};

Car::Car() : cc(1000), make(Nissan)
{
    return;
}

Car::~Car()
{
    return;
}

std::string Car::getMake() const
{
    switch (make)
    {
    case 0:
        return "Nissan";
        break;
    case 1:
        return "Toyota";
        break;
    default:
        break;
    }

    return "Other";
}

void Car::setMake(MANUFACTURER newMake)
{
    make = newMake;
}

int Car::getCC() const
{
    return cc;
}

void Car::setCC(int newCC)
{
    cc = newCC;

    return;
}

int main()
{
    Car myCar;

    std::cout << "myCar is made by " << myCar.getMake();
    std::cout << ", has " << myCar.getWheels() << " wheels, and a " << myCar.getCC() << " cc sized engine." << std::endl;

    return 0;
}
```

When compiled and run, Listing 16.2's program produces the following output:

```Console
myCar is made by Nissan, has 2 wheels, and a 1000 cc sized engine.
```

Here, two classes named `Vehicle` and `Car` are declared. The `Vehicle` class has a public default constructor and destructor, and two public accessors, `getWheels()` and `setWheels()`. The class has one protected variable, `wheels`. The class's constructor is defined on lines 24-27 and initialises `wheels` with the value 2. The destructor is defined on lines 29-32 and does nothing. The accessors are defined on lines 34-44 and get and set `wheels`' value, respectively.

The `Car` class has a public default constructor and destructor, and four public accessors, `getMake()`, `setMake()`, and `getCC()`, and `setCC()`. The class has two private variables, `cc` and `make`. The class is derived from `Vehicle` and inherits the base class's member variables and functions. The class's constructor is defined on lines 63-66 and initialises `cc` and `make` with the values 1000 and `Nissan`, respectively. The destructor is defined on lines 68-71 and does nothing. The accessors are defined on lines 73-105 and get and set `cc` and `make`'s values, respectively. `getMake()` uses a `switch-case` statement to test the `make`'s value, returning a string literal correlating to common car manufacturers.

On line 109 and `Car` object named `myCar` is created. Because `Car` derives from `Vehicle`, `myCar` has access to the `Vehicle` class's `getWheels()` member function.

On lines 111-112, `main()` displays a message describing the object's make, number of wheels, and engine size.

## Constructors and Destructors

An important aspect to understand about inheritance in C++ is that more than one constructor is called when an object of a derived class is created.

`Car` objects are `Vehicle` objects. When `myCar` was created in Listing 16.2's program, its base class's constructor was called first, creating a `Vehicle` object, and then the `Car` class's constructor was called, completing the construction of the `Car` object. Because `myCar` was created with no parameters, the default constructor was called in each case.

When `myCar` is destroyed, the `Car` destructor is called first, followed by the `Vehicle` destructor. Each destructor is given an opportunity to clean up after its own part of the object. Constructors are called in the order of inheritance. Destructors are called in reverse order of inheritance.

Listing 16.3's program demonstrates how constructors and destructors are called.

### Listing 16.3 The Full Text of `listing_16_3.cpp`
```C++
#include <iostream>
#include <string>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    Vehicle();
    ~Vehicle();

    int getWheels() const;
    void setWheels(int newWheels);

protected:
    int wheels;
};

Vehicle::Vehicle() : wheels(2)
{
    std::cout << "Vehicle constructor." << std::endl;

    return;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle destructor." << std::endl;

    return;
}

int Vehicle::getWheels() const
{
    return wheels;
}

void Vehicle::setWheels(int newWheels)
{
    wheels = newWheels;

    return;
}

class Car : public Vehicle
{
public:
    Car();
    ~Car();

    std::string getMake() const;
    void setMake(MANUFACTURER newMake);

    int getCC() const;
    void setCC(int newCC);

protected:
    int cc;
    MANUFACTURER make;
};

Car::Car() : cc(1000), make(Nissan)
{
    std::cout << "Car constructor." << std::endl;

    return;
}

Car::~Car()
{
    std::cout << "Car destructor." << std::endl;

    return;
}

std::string Car::getMake() const
{
    switch (make)
    {
    case 0:
        return "Nissan";
        break;
    case 1:
        return "Toyota";
        break;
    default:
        break;
    }

    return "Other";
}

void Car::setMake(MANUFACTURER newMake)
{
    make = newMake;
}

int Car::getCC() const
{
    return cc;
}

void Car::setCC(int newCC)
{
    cc = newCC;

    return;
}

int main()
{
    Car myCar;

    std::cout << "myCar is made by " << myCar.getMake();
    std::cout << ", has " << myCar.getWheels() << " wheels and a " << myCar.getCC() << " cc sized engine." << std::endl;

    return 0;
}
```

When compiled and run, Listing 16.3's program produces the following output:

```Console
Vehicle constructor.
Car constructor.
myCar is made by Nissan, has 2 wheels and a 1000 cc sized engine.
Car destructor.
Vehicle destructor.
```

Here, the definition of the `Vehicle` and `Car` is almost identical to Listing 16.2's program. Listing 16.3's definitions just include statements that display when the class's constructors and destructors are called. When a `Car` object named `myCar` is created on line 117, it can be seen that `Vehicle`'s constructor is called, followed by `Car`'s. When the object falls out of scope, `Car`'s destructor is called, followed by `Vehicle`'s.

## Passing Arguments to Base Constructors

As you work with classes, you may want to overload the constructor of `Vehicle` to set `wheels` to a specific number and overload the constructor of `Car` to set `cc` and `make` to a specific number and value. The question is, how do you get the `wheels` parameters passed up to the right constructor in `Vehicle`?

Base class initialisation can be performed during class initialisation by writing the base class name followed by the parameters expected by the base class. 

Listing 16.4's program demonstrates how to initialise a base class.

### Listing 16.4 The Full Text of `listing_16_4.cpp`
```C++
#include <iostream>
#include <string>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    Vehicle();
    Vehicle(int initialWheels);
    ~Vehicle();

    int getWheels() const;
    void setWheels(int newWheels);

protected:
    int wheels;
};

Vehicle::Vehicle() : wheels(2)
{
    std::cout << "Vehicle constructor." << std::endl;

    return;
}

Vehicle::Vehicle(int initialWheels) : wheels(initialWheels)
{
    std::cout << "Vehicle(int) constructor." << std::endl;

    return;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle destructor." << std::endl;

    return;
}

int Vehicle::getWheels() const
{
    return wheels;
}

void Vehicle::setWheels(int newWheels)
{
    wheels = newWheels;

    return;
}

class Car : public Vehicle
{
public:
    Car();
    Car(int initialWheels);
    Car(int initialWheels, int initialCC);
    Car(int initialWheels, int initialCC, MANUFACTURER initialMake);
    ~Car();

    std::string getMake() const;
    void setMake(MANUFACTURER newMake);

    int getCC() const;
    void setCC(int newCC);

protected:
    int cc;
    MANUFACTURER make;
};

Car::Car() : Vehicle(4), cc(1000), make(Nissan)
{
    std::cout << "Car constructor." << std::endl;

    return;
}

Car::Car(int initialWheels) : Vehicle(initialWheels), cc(1000), make(Nissan)
{
    std::cout << "Car(int) constructor." << std::endl;

    return;
}

Car::Car(int initialWheels, int initialCC) : Vehicle(initialWheels), cc(initialCC), make(Nissan)
{
    std::cout << "Car(int, int) constructor." << std::endl;

    return;
}

Car::Car(int initialWheels, int initialCC, MANUFACTURER initialMake) : Vehicle(initialWheels), cc(initialCC), make(initialMake)
{
    std::cout << "Car(int, int, MANUFACTURER) constructor." << std::endl;

    return;
}

Car::~Car()
{
    std::cout << "Car destructor." << std::endl;

    return;
}

std::string Car::getMake() const
{
    switch (make)
    {
    case 0:
        return "Nissan";
        break;
    case 1:
        return "Toyota";
        break;
    default:
        break;
    }

    return "None";
}

void Car::setMake(MANUFACTURER newMake)
{
    make = newMake;
}

int Car::getCC() const
{
    return cc;
}

void Car::setCC(int newCC)
{
    cc = newCC;

    return;
}

int main()
{
    Car myCar1;
    Car myCar2(3, 1500);
    Car myCar3(4, 2000, Toyota);

    std::cout << "myCar1 is a " << myCar1.getMake(); 
    std::cout << " and it has " << myCar1.getWheels() << " wheels and a " << myCar1.getCC() << " cc sized engine." << std::endl;
    std::cout << "myCar2 is a " << myCar2.getMake(); 
    std::cout << " and it has " << myCar2.getWheels() << " wheels and a " << myCar2.getCC() << " cc sized engine." << std::endl;
    std::cout << "myCar3 is a " << myCar3.getMake();
    std::cout << " and it has " << myCar3.getWheels() << " wheels and a " << myCar3.getCC() << " cc sized engine." << std::endl;

    return 0;
}
```

When compiled and run, Listing 16.4's program produces the following output:

```Console
Vehicle(int) constructor.
Car constructor.
Vehicle(int) constructor.
Car(int, int) constructor.
Vehicle(int) constructor.
Car(int, int, MANUFACTURER) constructor.
myCar1 is a Nissan and it has 4 wheels and a 1000 cc sized engine.
myCar2 is a Nissan and it has 3 wheels and a 1500 cc sized engine.
myCar3 is a Toyota and it has 4 wheels and a 2000 cc sized engine.
Car destructor.
Vehicle destructor.
Car destructor.
Vehicle destructor.
Car destructor.
Vehicle destructor.
```

Here, the definition of the `Vehicle` and `Car` is almost identical to Listing 16.3's program. Listing 16.4's definition of `Vehicle`, however, includes an overloaded constructor, which takes one `int` parameter. The definition of `Car` incudes three overloaded constructors, which take either one `int`, two `int`s, or two `int`s and one `MANUFACTURER` value. These constructors are defined on lines 78-104. In each, the base class and `Car`'s member variables are initialised with the function's parameters. 

On line 149, a `Car` object named `myCar1` is created. Here, its default constructor is called. A message indicating that `Vehicle`'s overloaded constructor and then `Car`'s default constructor were used to create the object is displayed. Here, `myCar1` is a Nissan make, has a 1000 cc sized engine, and has 4 wheels. 

On line 150, a `Car` object named `myCar2` is created. Here, its overloaded constructor is called with two `int` parameters. A message indicating that `Vehicle`'s overloaded constructor and then `Car`'s overloaded constructor were used to create the object is displayed. Here, `myCar2` is a Nissan make, has a 1500 cc sized engine, and has 3 wheels.

On line 151, a `Car` objected named `myCar3` is created. Here, its overloaded constructor is called with two `int` parameters and one `MANUFACTURER` value. A message indicating that `Vehicle`'s overloaded constructor and then `Car`'s overloaded constructor were used to create the object is displayed. Here, `myCar3` is a Toyota make, has a 2000 cc sized engine, and has 4 wheels.

On lines 153-158, `main()` displays each object's make, number of wheels, and engine size.

As each object falls out of scope, a message indicating that `Car`'s destructor and then `Vehicles`'s destructor were called is displayed.

Here, the base class has been overloaded to allow the derived class to initialise its values when creating new objects.

##  Overriding Functions

A `Car` object has access to all the member functions in the `Vehicle` class, as well as any member function it defines, such as `getCC()`. `Car` can also override a base class function. Overriding a function means changing the base class function's implementation in the derived class. When you make an object of the derived class, the correct function is called.

When a derived class creates a member function with the same return type and signature as a member function in the base class, but a new implementation, it is said to be overriding that function.

When you override a function, it must agree in return type and in signature with the function in the base class. The signature is the function prototype without the return type: that is, the name, its parameters, and the `const` keyword, if used.

Listing 16.5's program demonstrates how to override a base class's member function.

## Listing 16.5 The Full Text of `listing_16_5.cpp`
```C++
#include <iostream>
#include <string>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    Vehicle();
    Vehicle(int initialWheels);
    ~Vehicle();

    int getWheels() const;
    void setWheels(int newWheels);

protected:
    int wheels;
};

Vehicle::Vehicle() : wheels(2)
{
    std::cout << "Vehicle constructor." << std::endl;

    return;
}

Vehicle::Vehicle(int initialWheels) : wheels(initialWheels)
{
    std::cout << "Vehicle(int) constructor." << std::endl;

    return;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle destructor." << std::endl;

    return;
}

int Vehicle::getWheels() const
{
    return wheels;
}

void Vehicle::setWheels(int newWheels)
{
    wheels = newWheels;

    return;
}

class Car : public Vehicle
{
public:
    Car();
    ~Car();

    std::string getMake() const;
    void setMake(MANUFACTURER newMake);

    int getCC() const;
    void setCC(int newCC);

    int getWheels() const;

protected:
    int cc;
    MANUFACTURER make;
};

Car::Car() : Vehicle(4), cc(1000), make(Nissan)
{
    std::cout << "Car constructor." << std::endl;

    return;
}

Car::~Car()
{
    std::cout << "Car destructor." << std::endl;

    return;
}

std::string Car::getMake() const
{
    switch (make)
    {
    case 0:
        return "Nissan";
        break;
    case 1:
        return "Toyota";
        break;
    default:
        break;
    }

    return "None";
}

void Car::setMake(MANUFACTURER newMake)
{
    make = newMake;
}

int Car::getCC() const
{
    return cc;
}

void Car::setCC(int newCC)
{
    cc = newCC;

    return;
}

int Car::getWheels() const
{
    int tempWheels = wheels;

    return ++tempWheels;
}

int main()
{
    Car myCar1;

    std::cout << "myCar1 is a " << myCar1.getMake();
    std::cout << " and it has " << myCar1.getWheels() << " wheels and a " << myCar1.getCC() << " cc sized engine." << std::endl;

    return 0;
}
```

When compiled and run, Listing 16.5's program produces the following output:

```Console
Vehicle(int) constructor.
Car constructor.
myCar1 is a Nissan and it has 5 wheels and a 1000 cc sized engine.
Car destructor.
Vehicle destructor.
```

Here, Listing 16.5's definition of `Vehicle` and `Car` is similar to Listing 16.2's definition. The only difference is that `Car` declares a `getWheels()` member function, which overrides `Vehicle`'s definition. The overridden function is defined on lines 125-130. In it, `wheel`'s value is assigned to a temporary variable, which is incremented using the prefix increment operator and then returned. Essentially, the overridden function just adds one to the number of wheels a car has.

On line 134, a `Car` object named `myCar1` is created. Here, its default constructor is called. A message indicating that `Vehicle`'s overloaded constructor and then `Car`'s default constructor were used to create the object is displayed. Here, `myCar1` is a Nissan make, has a 1000 cc sized engine, and has 4 wheels. 

On lines 136-137, `main()` displays the object's make, number of wheels, and engine size. Here, the overridden `getWheels()` function is called, which returns 5 instead of `wheel`'s initial value of 4.

As `myCar` falls out of scope, a message indicating that `Car`'s destructor and then `Vehicles`'s destructor were called is displayed.

### Overloading Versus Overriding

The terms overloading and overriding sound similar and do similar things in C++. When you overload a member function, you create more than on function with the same name, but with different signatures. When you override a member function, you create a function in a derived class with the same signature as a function in the base class.

### Hiding the Base Class Member Function

In Listing 16.5's program, the `Car` class's `getWheels()` member function hides the base class's function. This is just what is wanted; however, it can have unexpected consequences. For example, if `Vehicle` had an overloaded function named `accelerate()`, and `Car` overrides it, then `Car` hides all the `Vehicle` functions with the same name.

If `Vehicle` overrides `accelerate()` as two functions - one that takes no parameters, and one that takes one parameter - and `Car` just overrides the `accelerate()` function that takes no parameters, `Car` will not be able to access the `accelerate()` member function that takes one parameter.

Listing 16.6's program demonstrates the problem of overriding a base class's overloaded function.

### Listing 16.6 The Full Text of `listing_16_6.cpp`
```C++
#include <iostream>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    void accelerate();
    void accelerate(int acc);

protected:
    int cc;
};

void Vehicle::accelerate()
{
    std::cout << "Vehicle accelerates 1 m/s^2." << std::endl;

    return;
}

void Vehicle::accelerate(int acc)
{
    std::cout << "Vehicle accelerates " << acc << " m/s^2." << std::endl;
}

class Car : public Vehicle
{
public:
    void accelerate(); // You may receive a warning that you are hiding a function.

protected:
    MANUFACTURER make;
};

void Car::accelerate()
{
    std::cout << "Car accelerates 5 m/s^2." << std::endl;

    return;
}

int main()
{

    Vehicle myVehicle;
    
    myVehicle.accelerate();
    myVehicle.accelerate(2);

    Car myCar;

    myCar.accelerate();
    // myCar.accelerate(10);

    return 0;
}
```

When compiled and run, Listing 16.6's program produces the following output:

```Console
Vehicle accelerates 1 m/s^2.
Vehicle accelerates 2 m/s^2.
Car accelerates 5 m/s^2.
```

Here, a class named `Vehicle` is declared on lines 10-18. It has two public member functions, `accelerate()` and `accelerate(int)`. It has one protected member variable, `cc`. `accelerate()` is defined on lines 20-25. It displays a default message before ending. `accelerate(int)` is defined on lines 27-32. It takes one `int` parameter and displays its value in a message before ending.

Another class named `Car` is declared on lines 34-41. It is derived from `Vehicle`. `Car` overrides `Vehicle`'s definition of `accelerate()`. The overridden function is defined on lines 43-48. It displays a default message before ending.

On line 53, a `Vehicle` object named `myVehicle` is created. On lines 55-56, its `accelerate()` function and its `accelerate(int)` function passed the value 2 are called. Two messages are displayed.

On line 58, a `Car` object named `myCar` is created. On line 60, its `accelerate()` function is called. A message is displayed. Here, if we try to pass a value to `accelerate(int)` an error is generated.

It is a common mistake to hide a base class member function, when you intend to override it, by emitting some part of a function's signature, such as the `const` keyword. 

Some compilers will give you a warning when you hide a function. Although, you are allowed to hide a function, it's often done by mistake, which is why you may receive a warning when you do.

### Calling the Base Member Function

If you have overridden a base member function, it is still possible to call it by fully qualifying the name of the function. You do this by writing the base name, followed by two colons, and the function name. For example:

```C++
Vehicle::getWheels();
```

Line 61 of Listing 16.6 could have been rewritten using this so make it compile. For example:

```C++
myCar.Vehicle::accelerate(10);
```

This call's `Vehicle`'s `accelerate(int)` function explicitly.

Listing 16.7's program demonstrates how a base class's member function can be called explicitly.

### Listing 16.7 The Full Text of `listing_16_7.cpp`
```C++
#include <iostream>

enum MANUFACTURER
{
    Nissan,
    Toyota,
    Other
};

class Vehicle
{
public:
    void accelerate();
    void accelerate(int acc);

protected:
    int cc;
};

void Vehicle::accelerate()
{
    std::cout << "Vehicle accelerates 1 m/s^2." << std::endl;

    return;
}

void Vehicle::accelerate(int acc)
{
    std::cout << "Vehicle accelerates " << acc << " m/s^2." << std::endl;
}

class Car : public Vehicle
{
public:
    void accelerate(); // You may receive a warning that you are hiding a function.

protected:
    MANUFACTURER make;
};

void Car::accelerate()
{
    std::cout << "Car accelerates 5 m/s^2." << std::endl;

    return;
}

int main()
{

    Vehicle myVehicle;

    myVehicle.accelerate(2);

    Car myCar;

    myCar.Vehicle::accelerate(10);

    return 0;
}
```

When compiled and run, Listing 16.7's program produces the following output:

```Console
Vehicle accelerates 2 m/s^2.
Vehicle accelerates 10 m/s^2.
```

Here, Listing 16.7's program differs from Listing 16.6's in that it in line 57 it calls the base class's `accelerate(int)`'s member function explicitly.

## Summary

Here, we have discussed inheritance. You may wonder if the effort of creating base classes and derived classes is worth it. Deciding whether to put member variables and functions among a set of related classes can take some time and planning.

The reason to do this is to make your classes more powerful and reusable.

When you've designed a set of related classes well, you can extend a base class and design a new derived class much more easily. You only have to focus on the things that make the new class different from its parent.

## Q & A

Q. Are inherited members and functions passed only to subsequent generations? If `Car` derives from `Vehicle` and `Vehicle` derives from `Machine`, does `Car` inherit `Machine`'s functions and data?

A. Yes. As derivation continues, derived classes inherit the sum of all the functions and data in their base classes.

Q. Can a derived class make a public base function private?

A. Yes, and it will then remain private for all subsequent derivations.

## Workshop

### Quiz

1. What access keyword limits a member variable to an object and its derived classes?

    A. `private`
    B. `public`
    C. `protected`

<!-- C. The `protected` keyword limits access to member variables and member functions so that derived classes can use them, but no others can. -->

2. In what order are constructors called in a derived class?

    A. In order of inheritance downward
    B. In order of inheritance upward
    C. In order the classes are defined in the source code

<!-- A. The base class's constructor is called first, followed by the derived class's constructor. -->

3. Why would you want to hide a base class's member function in a derived class?

    A. To prevent it from being used
    B. To call that function
    C. There's no reason to do this

<!-- A. Sometimes the behaviour of a derived class is different from the base that some of the base member functions are not necessary. -->

### Activities

1. Modify Listing 16.6's program by uncommenting line 27. What happens? What do you need to do to make it work?

2. Modify Listing 16.2's program so that it uses a text string instead of an enumerated data type for the breed.
