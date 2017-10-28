#ifndef VECTOR2D
#define VECTOR2D
#include <iostream>

using namespace std;

class Vector2D
{
public:
    friend int operator*(Vector2D lhs, Vector2D rhs);	// operator overload
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    Vector2D();
    Vector2D(int x, int y);
private:
    int _x;
    int _y;
};
#endif

