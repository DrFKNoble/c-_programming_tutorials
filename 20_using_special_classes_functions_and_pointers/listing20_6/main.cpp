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

    int val1 = 1, val2 = 2;
    int choice, i;

    const int maxArray = 3;
    void (*pFuncArray[maxArray]) (int&, int&);

    for (i = 0; i < maxArray; i++)
    {
        std::cout << "(0) Quit, (1) Change Values, (2) Square Values, (3) Cube Values, or (4) Swap." << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            pFuncArray[i] = 0;
            break;
        case 1:
            pFuncArray[i] = getVals;
            break;
        case 2:
            pFuncArray[i] = square;
            break;
        case 3:
            pFuncArray[i] = cube;
            break;
        case 4:
            pFuncArray[i] = swap;
            break;
        }

    }

    for(auto i : pFuncArray)
    {
        i(val1, val2);
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
