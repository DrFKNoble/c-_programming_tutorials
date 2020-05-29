#include <QCoreApplication>
#include <iostream>

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual float getArea() = 0;
    virtual void draw() = 0;
};

void Shape::draw()
{
    std::cout << "Abstract drawing method." << std::endl;

    return;
}

class Circle : public Shape
{
public:
    Circle(int newRadius) : radius(newRadius) {}
    ~Circle() {}

    float getArea() { return ((22 / 7) * radius * radius); }
    void draw();

private:
    int radius;
};

void Circle::draw()
{
    std::cout << "Circle draw()." << std::endl;
    Shape::draw();

    return;
}

class Rectangle : public Shape
{
public:
    Rectangle(int newWidth, int newLength) : width(newWidth), length(newLength) {}
    ~Rectangle() {}

    float getArea() { return (width * length); }
    void draw();

private:
    int width;
    int length;
};

void Rectangle::draw()
{
    std::cout << "Rectangle draw()." << std::endl;
    Shape::draw();

    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool loop = true;
    int choice = 0;
    Shape *pShape = nullptr;

    do
    {
        std::cout << "(1) Circle, (2) Rectangle, (0) Quit: ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            loop = false;
            break;
        case 1:
            pShape = new Circle(3);
            break;
        case 2:
            pShape = new Rectangle(3, 3);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
        }

        if (!loop)
            break;

        pShape->draw();

        delete pShape;
        pShape = nullptr;

        std::cout << std::endl;

    } while (loop);

    return a.exec();
}
