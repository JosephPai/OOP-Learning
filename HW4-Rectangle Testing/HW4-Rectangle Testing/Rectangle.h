#ifndef RECTANGLE
#define RECTANGLE
#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
public:
    Rectangle();
    Rectangle(bool init);
    Rectangle(double width, double height);
    void SetWidth(double width);
    void SetHeight(double height);
    void Area();
private:
    double width;
    double height;
};
#endif