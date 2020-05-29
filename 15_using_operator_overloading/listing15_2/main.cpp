#include <QCoreApplication>
#include <iostream>

class Counter
{
public:
    Counter();
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    void increment();
    const Counter& operator++();

private:
    int value;
};

Counter::Counter() : value(0)
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

void Counter::increment()
{
    ++value;

    return;
}

const Counter& Counter::operator++()
{
    ++value;

    return *this;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    count1.increment();
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    ++count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    Counter count2 = ++count1;
    std::cout << "count1's value is: " << count1.getValue();
    std::cout << ", count2's value is: " << count2.getValue() << std::endl;

    return a.exec();
}
