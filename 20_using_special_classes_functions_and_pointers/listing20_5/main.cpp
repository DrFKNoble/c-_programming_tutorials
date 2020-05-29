#include <QCoreApplication>
#include <iostream>

void square(int &, int &);
void cube(int &, int &);
void swap(int &, int &);
void getVals(int &, int &);
void printVals(int, int);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void (*pFunc)(int &, int &);
    bool loop = true;

    int val1 = 1, val2 = 2;
    int choice;

    while (loop)
    {
        std::cout << "(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap." << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pFunc = getVals;
            break;
        case 2:
            pFunc = square;
            break;
        case 3:
            pFunc = cube;
            break;
        case 4:
            pFunc = swap;
            break;
        }

        if (!loop)
            break;

        printVals(val1, val2);
        pFunc(val1, val2);
        printVals(val1, val2);
    }

    return a.exec();
}


void square(int &rVal1, int &rVal2)
{
    rVal1 *= rVal1;
    rVal2 *= rVal2;

    return;
}

void cube(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    rVal1 *= rVal1;
    rVal1 *= temp1;

    int temp2 = rVal2;
    rVal2 *= rVal2;
    rVal2 *= temp2;

    return;
}

void swap(int &rVal1, int &rVal2)
{
    int temp1 = rVal1;
    int temp2 = rVal2;

    rVal2 = temp1;
    rVal1 = temp2;

    return;
}

void getVals(int &rVal1, int &rVal2)
{
    std::cout << "Value 1: ";
    std::cin >> rVal1;

    std::cout << "Value 2: ";
    std::cin >> rVal2;

    return;
}

void printVals(int val1, int val2)
{
    std::cout << "Value 1: " << val1 << " , Value 2: " << val2 << "." << std::endl;

    return;
}
