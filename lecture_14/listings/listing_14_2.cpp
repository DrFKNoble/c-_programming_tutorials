#include <iostream>

class Drawer
{
public:
    Drawer(int rows, int cols);
    ~Drawer();

    void drawShape() const;
    void drawShape(int newRows, int newCols, bool useCurrentValue = true) const;

private:
    int rows;
    int cols;
};

Drawer::Drawer(int newRows, int newCols)
{
    rows = newRows;
    cols = newCols;

    return;
}

Drawer::~Drawer()
{
    return;
}

void Drawer::drawShape() const
{
    drawShape(rows, cols);

    return;
}

void Drawer::drawShape(int newRows, int newCols, bool useCurrentValue) const
{

    int tempRows;
    int tempCols;

    if (useCurrentValue == true)
    {
        tempRows = rows;
        tempCols = cols;
    }
    else
    {
        tempRows = newRows;
        tempCols = newCols;
    }
    
    for (int i = 0; i < tempRows; i++)
    {
        for (int j = 0; j < tempCols; j++)
        {
            std::cout << "*";

        }

        std::cout << std::endl;

    }

    return;
}

int main()
{   
    Drawer rect(3, 3);

    std::cout << "rect.drawShape(0, 0)" << std::endl;
    rect.drawShape(0, 0);

    std::cout << std::endl;

    std::cout << "rect.drawShape(5, 5, false)" << std::endl;
    rect.drawShape(5, 5, false);

    return 0;
}