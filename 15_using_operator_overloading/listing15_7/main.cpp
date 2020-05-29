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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int count1 = 5;

    Counter count2 = count1;
    std::cout << "count2's value is: " << count2.getValue() << std::endl;

    return a.exec();
}
