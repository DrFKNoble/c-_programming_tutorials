#include <iostream>

class Counter
{
public:
    Counter();
    ~Counter();

    int getValue() const;
    void setValue(int newValue);

    const Counter& operator++();
    const Counter operator++(int);

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

const Counter& Counter::operator++()
{
    ++value;

    return *this;
}

const Counter Counter::operator++(int)
{
    Counter temp(*this);
    ++value;
    
    return temp;
}

int main()
{
    Counter count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    count1++;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    ++count1;
    std::cout << "count1's value is: " << count1.getValue() << std::endl;

    Counter count2 = ++count1;
    std::cout << "count1's value is: " << count1.getValue();
    std::cout << ", count2's value is: " << count2.getValue() << std::endl;
    
    count2 = count1++;
    std::cout << "count1's value is: " << count1.getValue();
    std::cout << ", count2's value is: " << count2.getValue() << std::endl;
    
    return 0;
}