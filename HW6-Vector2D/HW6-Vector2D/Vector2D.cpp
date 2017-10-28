#include "Vector2D.h"
#include <iostream>

using namespace std;

Vector2D::Vector2D()
{
}

void Vector2D::setX(int x)
{
    this->_x = x;
}

void Vector2D::setY(int y)
{
    this->_y = y;
}

int Vector2D::getX()
{
    return this->_x;
}

int Vector2D::getY()
{
    return this->_y;
}

Vector2D::Vector2D(int x,int y)
{
    this->setX(x);
    this->setY(y);
}

int operator * (Vector2D lhs, Vector2D rhs)		// operator overload
{
    return (lhs.getX()*rhs.getX() + lhs.getY()*rhs.getY());
}


