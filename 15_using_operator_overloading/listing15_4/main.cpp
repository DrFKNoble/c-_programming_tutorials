#include <QCoreApplication>
#include <iostream>

class Counter
{
public:
    Counter();
    Counter(int initialValue);
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    const Counter operator+(const Counter&);

private:
    int value;
};

Counter::Counter() : value(0)
{
    return;
}

Counter::Counter(int initialValue) : value(initialValue)
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

const Counter Counter::operator+(const Counter& rhs)
{
    return Counter(value + rhs.getValue());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter count1(4), count2(13), count3;

    count3 = count1 + count2;

    std::cout << "count1's value is: " << count1.getValue() << std::endl;
    std::cout << "count2's value is: " << count2.getValue() << std::endl;
    std::cout << "count3's value is: " << count3.getValue() << std::endl;

    return a.exec();
}
