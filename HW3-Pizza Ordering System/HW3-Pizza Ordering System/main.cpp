#include <iostream>
#include <string>
#include "Pizza.h"

int main()
{
    bool init = false;		
    string temp;		// get the input temporarily
    int type,size,topping;
    int state = 0;		// Different state of ordering
    Pizza pizza;		// Instantiation of class Pizza
    init = true;		// Initialization

    while (init)
    {	
        if (state == 0)		// state0: chossing type
        {
            cout << "Chosse pizza's type : " << endl;
            cout << "1. Deep dish" << endl;
            cout << "2. Hand tossed" << endl;
            cout << "3. Pan" << endl;

            while (true)
            {
                getline(cin, temp);

                if (temp.compare("-1") == 0)
                {
                    exit(1);		// when input is -1, end the program
                }
                else if (temp.compare("1") == 0 || temp.compare("2") == 0 || temp.compare("3") == 0)
                {
                    state = 1;
                    type = temp[0] - '0';
                    pizza.SetType(type);
                    break;
                }
                else
                {
                    cout << "\nInvalid input. Please input again :" << endl;
                }
            }

            cout << "\n";
        }

        if (state == 1)		// state1: chossing size
        {
            cout << "Chosse pizza's size : " << endl;
            cout << "1. Small" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Large" << endl;

            while (true)
            {
                getline(cin, temp);

                if (temp.compare("-1") == 0)
                {
                    exit(1);		// when input is -1, end the program
                }
                else if (temp.compare("1") == 0 || temp.compare("2") == 0 || temp.compare("3") == 0)
                {
                    state = 2;
                    size = temp[0] - '0';
                    pizza.SetSize(size);
                    break;
                }
                else
                {
                    cout << "\nInvalid input. Please input again :" << endl;
                }
            }

            cout << "\n";
        }

        if (state == 2)		// state2: chossing toppings
        {
            cout << "Choose pizza's toppings :" << endl;
            cout << "1. Pepperoni" << endl;
            cout << "2. Pepperoni(NY Style)" << endl;
            cout << "3. Asiago" << endl;
            cout << "4. Bocconcini" << endl;
            cout << "5. Cheddar" << endl;
            cout << "6. Feta" << endl;
            cout << "7. Goat Cheese" << endl;
            cout << "8. Mozzarella" << endl;
            cout << "9. Parmesan" << endl;

            while (true)		// customer can choose multiple toppings
            {
                getline(cin, temp);

                if (temp.compare("-1") == 0)
                {
                    exit(1);
                }
                else if (temp.length() == 1 && temp[0] - '0' >= 1 && temp[0] - '0' <= 9)
                {
                    topping = temp[0] - '0';

                    if (pizza.GetToppings(topping) == true)
                    {
                        cout << "\nYou alreayd choose this topping. Please choose again :" << endl;
                    }
                    else
                    {
                        pizza.SetToppings(topping);
                        break;
                    }
                }
                else if (temp.compare("0") == 0)
                {
                    pizza.OutputDesrciption();		// when input is 0, end the order, output the info
                    state = 0;						// get back to the start state
                    break;
                }
                else
                {
                    cout << "\nInvalid input. Please input again :" << endl;
                }
            }

            cout << "\n";
        }
    }

    return 0;
}
