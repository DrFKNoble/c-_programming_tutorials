#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

class Point
{
public:
    Point();
    Point(int newX, int newY);
    ~Point();

    void setX(int newX);
    void setY(int newY);
    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

class Rectangle
{
public:
    Rectangle();
    Rectangle(Point newTopLeft, Point newBottomRight);
    ~Rectangle();

    void setTopLeft(Point newTopLeft);
    void setBottomRight(Point newBottomRight);
    Point getTopLeft() const;
    Point getBottomRight() const;
    void display() const;

private:
    Point topLeft;
    Point bottomRight;
};

#endif // MAIN_HPP
