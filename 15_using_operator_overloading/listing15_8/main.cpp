#include <QCoreApplication>
#include <iostream>

class Counter
{
public:
    Counter();
    Counter(int newValue);
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    operator unsigned int();

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::Counter(int newValue) : value(newValue)
{
    return;
}

Counter::~Counter()
{
    return;
}

int Counter::getValue() const
{
    return value;
}

void Counter::setValue(int newValue)
{
    value = newValue;

    return;
}

Counter::operator unsigned int()
{
    return (value);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter count1(10);

    int count2 = count1;

    std::cout << "count1's value is: " << count2 << std::endl;
    std::cout << "count2's value is: " << count2 << std::endl;

    return a.exec();
}
