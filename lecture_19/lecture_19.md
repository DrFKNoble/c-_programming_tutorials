# Lecture 19: Storing Information in Linked Lists

## What You'll Learn in This Lecture

* What a linked list is
* How to create a linked list
* How to encapsulate functionality through inheritance

## Linked Lists and Other Structures

Arrays are like boxes for mailing items. They are useful containers, but each are a fixed size. If you pick too big a box, you end up wasting space. If you pick one too small, you can't fit your item in it.

In programming, it's useful to have a container that's exactly the right size for the data it contains. One way to achieve this is by using a linked list.

A linked list is a data structure that consists of small containers that connect together. Containers in this context are classes that contain the objects to be held in this list. The idea is to write a class that holds one object of your data and shows how to point to the next container in the list. You create one container for each object and link them together.

These linked containers are called nodes. The first node is called the head. The last node is called the tail.

Lists come in three, fundamental forms. From the simplest form to the most complex, they are:

* Singly linked
* Doubly linked
* Trees

In a singly linked list, each node points to the next one, head to tail. To find a particular node, you start at the head and work your way through to the tail. In a doubly linked list, each node points to both the previous node and the following one. In a tree, each node points to the previous node and one or more following nodes. 

## Linked List Case Study

Here, we examine a linked list as a case study into how to use inheritance, polymorphism, and encapsulation to manage large projects. It's also an opportunity to see how to create complex structures in C++.

### Delegation of Responsibility

A fundamental premise of object-orientated programming is that each object does one thing very well and delegates to other objects anything that is not part of its mission.

A car is a good example. Its engine produces power. Distributing the power is not part of the engine's job; that's up to the transmission. 

A well-designed machine has lots of small, well-understood parts, each doing their own job, working together to accomplish the machine's purpose. A well-designed program is much the same: each class performs its own job, but together create a functioning program.

### Component Parts

The linked list will consist of nodes. The node class itself will be abstract and we'll use three sub-types to accomplish the work. There will be head and tail nodes to manage those parts of the list, and zero or more internal nodes. The internal nodes will keep track of the list's actual data.

Note that the data and the list are quite distinct. You can save any type of data in a linked list. It isn't the data that's linked together, it's the node that holds the data that is.

A program doesn't actually know about the nodes, it only works with the list. The list does little work, delegating tasks to the nodes.

Listing 19.1's program demonstrates an object-orientated approach to linked lists. The program has three main classes: `Data`, `Node`, and `LinkedList`. When the program is run, it asks the user for a series of values, storing each as a `Data` object. These objects are inserted into a `LinkedList` object and displayed in numerical order.

The `LinkedList` class uses the `HeadNode`, `TailNode`, and `InternalNode` implementations of the abstract `Node` class. Only `InternalNode` objects hold data.

### Listing 19.1 The Full Text of `listing_19_1.cpp`
```C++
#include <iostream>

enum COMPARE
{
    lessThan,
    equal,
    greaterThan
};

class Data
{
public:
    Data(int newValue) : value(newValue) {}
    ~Data() {}

    int compare(const Data &rCompareData);
    void show() { std::cout << value << std::endl; }

private:
    int value;
};

int Data::compare(const Data &rCompareData)
{
    if (value < rCompareData.value)
        return lessThan;
    else if (value > rCompareData.value)
        return greaterThan;
    else
        return equal;
}

class Node
{
public:
    Node() {}
    virtual ~Node() {}

    virtual Node *insert(Data *pNewData) = 0;
    virtual void show() = 0;

private:
};

class InternalNode : public Node
{
public:
    InternalNode(Data *pNewData, Node *pNewNext) : pData(pNewData), pNext(pNewNext) {}
    virtual ~InternalNode()
    {
        delete pData;
        delete pNext;
    }

    virtual Node *insert(Data *pNewData);
    virtual void show()
    {
        pData->show();
        pNext->show();
    }

private:
    Data *pData;
    Node *pNext;
};

Node *InternalNode::insert(Data *pNewData)
{
    int result = pData->compare(*pNewData);

    switch (result)
    {
    case equal:
    case greaterThan:
    {
        InternalNode *newDataNode = new InternalNode(pNewData, this);
        return newDataNode;
    }
    case lessThan:
        pNext = pNext->insert(pNewData);
        return this;
    }

    return this;
}

class TailNode : public Node
{
public:
    TailNode() {}
    virtual ~TailNode() {}

    virtual Node *insert(Data *pNewData);
    virtual void show() { };

private:
};

Node *TailNode::insert(Data *pNewData)
{
    InternalNode *newDataNode = new InternalNode(pNewData, this);

    return newDataNode;
}

class HeadNode : public Node
{
public:
    HeadNode() { pNext = new TailNode; }
    virtual ~HeadNode() { delete pNext; }

    virtual Node *insert(Data *pNewData);
    virtual void show() { pNext->show(); }

private:
    Node *pNext;
};

Node *HeadNode::insert(Data *pNewData)
{
    pNext = pNext->insert(pNewData);

    return this;
}

class LinkedList
{
public:
    LinkedList() { pHead = new HeadNode; }
    ~LinkedList() { delete pHead; }

    void insert(Data *pNewData);
    void showAll() { pHead->show(); }

private:
    HeadNode *pHead;
};

void LinkedList::insert(Data *pNewData)
{
    pHead->insert(pNewData);

    return;
}

int main()
{
    Data *pData;
    int value;
    LinkedList list;

    std::cout << "Enter a valid value (1-9), Quit (0)." << std::endl;
    while (true)
    {   
        std::cout << "Value: ";
        std::cin >> value;

        if (!value)
            break;

        pData = new Data(value);

        list.insert(pData);

    }

    list.showAll();


    return 0;
}
```

When compiled and run, Listing 19.1's program produces the following output:

```Console
Enter a valid value (1-9), Quit (0).
Value: 2
Value: 1
Value: 6
Value: 3
Value: 0
1
2
3
4
6
```

Here, an `enum` named COMPARE is defined and used to indicate if a value is less than, equal to, or greater than another. `Data` and `InternalNode` use this enum. `Data` defines the `compare()` function, which compares the class's data member `value`'s value with its parameter's value. The function returns one of the enum's named values. `InternalNode` uses the returned named value to decide whether to insert data before a node or after it.

The `Data` class is defined on lines 10-21. It has a public overloaded constructor and a public destructor, and two pubic member functions, `compare()` and `show()`. It has one private data member, an `int` named `value`. The constructor initialises `value` with its parameter's value. The destructor does nothing. `compare()` is defined on lines 23-31 and determines if `value` is less than, equal to, or greater than the function's parameter's value. `show()` displays `value`'s value.

The `Node` class is defined on lines 33-43. It has a public default constructor and a public virtual destructor, and two public, pure virtual member functions, `insert()` and `show()`. Because the class has pure virtual member functions, `Node` is an abstract data type. Therefore, `insert()` and `show()`'s definition is left to the derived classes to define.

The `LinkedList` class is defined on lines 126-137. It has a public default constructor and a public destructor, and two public member functions, `insert()` and `showAll()`. It has one private data member, a pointer to a `HeadNode` named `pHead`.  The constructor assigns the address of a new `HeadNode` object to `pHead`. The destructor deletes `pHead`. `insert()` is defined on lines 139-144 and calls `pHead`'s `insert()` function, passing it a pointer to a `Data` object. `showAll()` calls `pHead`'s `show()` function.

The `HeadNode` class is defined on lines 106-117 and derives from the `Node` class. It has a public constructor and a public virtual destructor, and has two public virtual member functions, `insert()` and `show()`. The class has one private data member, a pointer to a `Node` object. The constructor assigns the address of a new `TailNode` object to `pNext`. The destructor deletes `pNext`. Because `Node`'s `insert()` and `show()` were declared as pure virtual functions, it is required that `HeadNode` define these; otherwise, `HeadNode` becomes another abstract data type. `HeadNode`'s `insert()` is defined on lines 119-124 and calls `pNext`'s insert function, passing it a pointer to a `Data` member; `pNext` is then assigned the value returned from the function. Afterwards, `insert()` returns a pointer to the current object. `show()` calls `pNext`'s `show()` function.

The `TailNode` class is defined on lines 87-97 and derives from the `Node` class. It has a public constructor and a public virtual destructor, and has two public virtual member functions, `insert()` and `show()`. The constructor and destructor do nothing. As with the `HeadNode` class, `TailNode` must define `insert()` and `show()`; otherwise, it will be an abstract data type. `TailNode`'s `insert()` is defined on lines 99-104 a pointer to an `InternalNode` object is created and assigned the address of a new `InternalNode` object. Afterwards, the object is returned from the function. `show()` does nothing.

The `InternalNode` class is defined on lines 45-65 and derives from the `Node` class. It has a public overloaded constructor and a public virtual destructor, and two public virtual member functions, `insert()` and `show()`. It has two private data members, a pointer to a `Data` object named `pData` and a pointer to a `Node` object named `pNext`. The constructor initialises `pData` and `pNext` with its parameters' values. The destructor deletes `pData` and `pNext`. As with the `TailNode` and `HeadNode` classes, `InternalNode` must define `insert()` and `show()`; otherwise, it will be an abstract data type. `insert()` is defined on lines 67-85 and calls `pData`'s `compare()` function to check if the function's parameter is less than, equal to, or great than `pData`'s value. A `switch-case` statement determines if the new data should be inserted before the current node or after it. Afterwards, a pointer to the current object is returned.

On lines 148-150, a pointer to a `Data` object, an `int` variable, and a `Linkedlist` object are declared. These are used throughout the program.

On line 152, `main()` displays a message, prompting the user to enter a number of values. On lines 153-165, a `while` loop loops continuous, prompting the user for a value. If the value is not zero, `pData` is assigned the address of a new `Data` object, which is created using the user's entered value; otherwise, the loop terminates. `Data`'s constructor assign's the value to the class's data member `value`. Aftwards, `list`'s insert function is called, passing `pData` as an argument. 

On line 167, `list`'s `showAll()` function is called and all of the linked list's values are displayed.

Let's step through what happens when a `LinkedList` object is created. When a new `LinkedList` object is created, its constructor assigns its data member `pHead` the address of a new `HeadNode` object. When a new `HeadNode` object is created, its constructor assigns its `pNext` data member the address of a new `TailNode` object. At this point, we have a linked list whose head node points to its tail node.

Now, let's step through when a new `Data` object is inserted into the list. When the linked list's `insert()` function is called, the pointer to the head node's `insert()` function is passed the new data. This data is then passed to the object pointed to by the head node's `pNext` data member's `insert()` function. At this point, it is the tail node. The tail node's `insert()` function creates a new `InternalNode` object, assigning the object's `pData` and `pNext` data members the new data and a pointer to the tail node, respectively. The function then returns a pointer to the new internal node. This is then assigned to the head node's `pNext` data member. Now, the head node points to the new internal node and the new internal node points to the tail node. An internal node has successfully been inserted between the head and tail nodes.

Lastly, let's step through when a second `Data` object is inserted into the list. When the linked list's `insert()` function is called, the pointer to the head node's `insert()` function is passed the new data. This data is then passed to the object pointed to by the head node's `pNext` data member's `insert()` function. At this point, it is the first internal node. The internal node's `insert()` function first compares the new data with the node's current value. If the current value is less than the new data, the new data is passed to the node pointed to by the `pNext` data member (at this point, the tail node); otherwise, if it is equal or great than the new data's value, the new data is inserted before the current node. Depending on the outcome of the comparison, either: 1) the head node points to the new node, which points to the old node, which points to the tail node; or 2) the head node points to the old node, which points to the new node, which points to the tail node. For each new `Data` object added to the linked list, it is placed in numerical order.

## Linked Lists as Objects

In object-orientated programming, each individual object is given a narrow and well-define set of responsibilities. 

In Listing 19.1's program, the linked list is responsible for maintaining the head node. The `HeadNode` immediately passes any new data on to whatever it points to, without regard for what it may be. The `TailNode`, whenever it is handed data, creates a new node and inserts it just before itself. The `InternalNode`s compare an existing object with a new object. Depending on the result, the new object is inserted or passed along the list.

Note, `InternalNode` has no idea how to do the comparison, that is a property of `Data`. All `InternalNode` knows is to ask an object to compare itself with another object. Given the result, the object is either inserted or passed along the list.

So which class is in charge? In a well-designed program, no class is in charge. Each object does its own job and the net effect is a well-running application.

The beauty of a linked list is that you can put any data type you would like in the `Data` class. In Listing 19.1's program, it was an `int` variable; however, it could be anything, such as another object.

The use of dynamic memory allows linked lists to use very little memory when small, and lots when the list grows. The important thing is it only uses enough to hold the data they contain.

## Summary

So far, the examples previously provided have been short and illustrative. This made it easy to focus on their functionality.

This example, however, is a lot more detailed; more in line with what you will end up programming in your own applications.

Listing 19.1's program consisted of six classes: `Data`, `Node`, `HeadNode`, `TailNode`, `InternalNode`, and `LinkedList`. True to object-orientated programming, each class took care of its own task and relied on the others to do theirs.

By understanding how these objects work together, you have developed a better sense of how to manage the relationships between objects.

## Q & A

Q. Why should you create a linked list if an array will work?

A. An array must be a fixed size, whereas a linked list can be sized dynamically at runtime, making efficient use of memory.

Q. Why do you separate the data object from the node?

A. This programming practice facilitates code reuse. After you get your node objects working properly, you can reuse that code for any number of objects you may want to store in a list.

Q. If you want to add other objects to the list, do you have to create a new list type and a new node type?

A. For now, yes. It is possible to implement a link list in a more generic way, such as by using templates.

## Workshop

### Quiz

1. What is the first node in a linked list called?

    A. The front
    B. The top
    C. The head

<!-- C. As the name implies, it contains the head of the linked list. It is very important to know where the list starts so it can be accessed. -->

2. What two things does a linked list's node contain?

    A. Behaviour and data
    B. Functions and variables
    C. Data and a node pointer

<!-- C. The data can be any type of object. The pointer indicates the next node in the linked list. -->

3. How many pointers are needed in a doubly linked list?

    A. One
    B. Two
    C. Two or more

<!-- B. Each node in a doubly linked list has two pointers, one for the next node and one for the previous node. -->

### Activities

1. Modify Listing 19.1's program so that its linked list stores `Bike` objects.

2. Modify Listing 19.1's program so that a function displays the number of objects in the linked list.
