#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Rectangle.h"
using namespace std;


Rectangle::Rectangle()
{
    this->width = 5;
    this->height = 5;
    cout << "Rectangle() is called.\n" << endl;
}

Rectangle::Rectangle(bool init)
{
    this->width = 5;
    this->height = 5;
}

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
    cout << "Rectangle(double, double) is called.\n" << endl;
}

void Rectangle::SetWidth(double width)
{
    this->width = width;
    cout << "SetWidth(double) is called.\n" << endl;
}

void Rectangle::SetHeight(double height)
{
    this->height = height;
    cout << "SetHeight(double) is called.\n" << endl;
}

void Rectangle::Area()
{
    double area;
    area = this->width * this->height;
    cout << "Area() is called." << endl;
    cout << "Rectangle's area is " << setiosflags(ios::fixed) << setprecision(2) << area << '\n' << endl;
}

