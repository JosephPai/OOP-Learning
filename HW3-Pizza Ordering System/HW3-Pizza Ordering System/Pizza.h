#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>

using namespace std;

class Pizza
{
public:
    Pizza();	// Constructor function
    void SetType(int type);	
    void SetSize(int size);
    void SetToppings(int topping);
    bool GetToppings(int topping);
    int GetNumOfToppings();
    double ComputePrice();
    void OutputDesrciption();

private:
    int type;
    int size;
    int toppings[9];
};
#endif