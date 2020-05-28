#include "listing.hpp"

Point::Point()
{
    x = 0;
    y = 0;

    return;
}

Point::Point(int newX, int newY)
{
    x = newX;
    y = newY;

    return;
}

Point::~Point()
{
    // do nothing.

    return;
}

void Point::setX(int newX)
{
    x = newX;

    return;
}

void Point::setY(int newY)
{
    y = newY;

    return;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

Rectangle::Rectangle()
{
    topLeft.setX(0);
    topLeft.setY(0);
    bottomRight.setX(0);
    bottomRight.setY(0);

    return;
}

Rectangle::Rectangle(Point newTopLeft, Point newBottomRight)
{
    topLeft = newTopLeft;
    bottomRight = newBottomRight;

    return;
}

Rectangle::~Rectangle()
{
    // do nothing

    return;
}

void Rectangle::setTopLeft(Point newTopLeft)
{
    topLeft = newTopLeft;

    return;
}

void Rectangle::setBottomRight(Point newBottomRight)
{
    bottomRight = newBottomRight;

    return;
}

Point Rectangle::getTopLeft() const
{
    return topLeft;
}

Point Rectangle::getBottomRight() const
{
    return bottomRight;
}

void Rectangle::display() const
{
    std::cout << "Rect: [(" << topLeft.getX() << "," << topLeft.getY() << ")";
    std::cout << ",(" << bottomRight.getX() << "," << bottomRight.getY() << ")]" << std::endl;

    return;
}

int main()
{

    Point topLeft(1, 1);
    Point bottomRight(10, 10);

    std::cout << "topLeft.x: " << topLeft.getX() << ", topLeft.y: " << topLeft.getY() << std::endl;
    std::cout << "bottomRight.x: " << bottomRight.getX() << ", bottomRight.y: " << bottomRight.getY() << std::endl;

    Rectangle rect(topLeft, bottomRight);

    rect.display();

    return 0;
}