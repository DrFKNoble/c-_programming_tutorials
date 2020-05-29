#include <QCoreApplication>
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


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    return a.exec();
}
