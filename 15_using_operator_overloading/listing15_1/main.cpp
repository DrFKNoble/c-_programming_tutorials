#include <QCoreApplication>
#include <iostream>

class Counter
{
public:
    Counter();
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

    Counter count;
    std::cout << "count's value is: " << count.getValue() << std::endl;

    return a.exec();
}