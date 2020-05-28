#include <iostream>

int main()
{
    int grade;

    std::cout << "Enter a grade (1-100): ";
    std::cin >> grade;

    if (grade >= 70)
        std::cout << "Congratulations! You passed." << std::endl;
    else
        std::cout << "I'm sorry. You failed." << std::endl;

    return 0;
}