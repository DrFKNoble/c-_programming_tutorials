#include <QCoreApplication>
#include <iostream>

class Drawer
{
public:
    Drawer(int rows, int cols);
    ~Drawer();

    void drawShape() const;
    void drawShape(int newRows, int newCols) const;

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

void Drawer::drawShape(int newRows, int newCols) const
{
    for (int i = 0; i < newRows; i++)
    {
        for (int j = 0; j < newCols; j++)
        {
            std::cout << "*";

        }

        std::cout << std::endl;

    }

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Drawer rect(3, 3);

    std::cout << "rect.drawShape()" << std::endl;
    rect.drawShape();

    std::cout << std::endl;

    std::cout << "rect.drawShape(5, 5)" << std::endl;
    rect.drawShape(5, 5);

    return a.exec();
}
