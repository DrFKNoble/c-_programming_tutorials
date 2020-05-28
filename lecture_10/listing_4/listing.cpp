#include <iostream>

int main()
{
    int localVariable = 33;
    int *pLocalVariable = &localVariable;
    int *pHeap = new int;
    
    if (pHeap == nullptr)
    {
        std::cout << "Error! No memmory for pHeap." << std::endl;
    
        return 1;
    }

    *pHeap = 29;

    std::cout << "localVariable: " << localVariable << std::endl;
    std::cout << "*pLocalVariable: " << *pLocalVariable << std::endl;
    std::cout << "*pHeap: " << *pHeap << std::endl;

    delete pHeap;

    pHeap = new int;

    if (pHeap == nullptr)
    {
        std::cout << "Error! No memmory for pHeap." << std::endl;
    
        return 1;
    }

    *pHeap = 33;
    
    std::cout << "*pHeap: " << *pHeap << std::endl;

    delete pHeap;

    return 0;
}