#include <iostream>
#include <string>
#include "Pizza.h"
using namespace std;

static const int SMALL = 1, MEDIUM = 2, LARGE = 3;
static const int DEEP_DISH = 1, HAND_TOSSED = 2, PAN = 3;
const string TOPPINGS[9] =
{
    "Pepperoni", "Pepperoni(NY Style)", "Asiago", "Bocconcini",
    "Cheddar", "Feta", "Goat Cheese", "Mozzarella", "Parmesan"
};

Pizza::Pizza()
{
    for (int i = 0; i < 9; i++)
    {
        this->toppings[i] = 0;
    }
}

void Pizza::SetType(int type)
{
    this->type = type;
}

void Pizza::SetSize(int size)
{
    this->size = size;
}

bool Pizza::GetToppings(int topping)
{
    if (toppings[topping - 1] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Pizza::SetToppings(int topping)
{
    toppings[topping - 1] = 1;
}

int Pizza::GetNumOfToppings()
{
    int count=0;

    for (int i = 0; i < 9; i++)
    {
        if (toppings[i] == 1)
        {
            count++;
        }
    }

    return count;
}

double Pizza::ComputePrice()
{
    double price;
    int num;
    num = GetNumOfToppings();

    switch (this->size)
    {
    case SMALL:
        price = 10 + 2 * num;

    case MEDIUM:
        price = 14 + 2 * num;

    case LARGE:
        price = 17 + 2 * num;

    default:
        break;
    }

    return price;
}

void Pizza::OutputDesrciption()
{
    cout << "\nYour order : \n" << "Type : ";

    switch (this->type)
    {
    case DEEP_DISH:
        cout << "Deep dish" << endl;
        break;

    case HAND_TOSSED:
        cout << "Hand tossed" << endl;
        break;

    case PAN:
        cout << "Pan" << endl;
        break;

    default:
        break;
    }

    cout << "Size : ";

    switch (size)
    {
    case SMALL:
        cout << "Small" << endl;
        break;

    case MEDIUM:
        cout << "Medium" << endl;
        break;

    case LARGE:
        cout << "Large" << endl;
        break;

    default:
        break;
    }

    cout << "Toppings : ";

    if (GetNumOfToppings() == 0)
    {
        cout << "None";
    }
    else
    {
        int andControlFlag = 0;

        for (int i = 0; i < 9; i++)
        {
            if (toppings[i] == 1)
            {
                if (andControlFlag == 0)
                {
                    cout << TOPPINGS[i];
                    andControlFlag = 1;
                }
                else
                {
                    cout << " & " << TOPPINGS[i];
                }
            }
        }
    }

    cout << "\n\nYour pizza's price : $" << ComputePrice() << endl;
    cout << "Thank you for your coming!" << endl;

    for (int i = 0; i < 9; i++)		// after output, get back to the init state
    {
        this->toppings[i] = 0;
    }
}