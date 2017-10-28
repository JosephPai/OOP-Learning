#include <iostream>
#include <string>
#include <regex>
#include "Vector2D.h"

using namespace std;

int main()
{
    string input;
    Vector2D vectorA, vectorB;
    double x, y;
    const std::regex PATTERN("^\\([+-]?\\d+(\\.\\d+)?,[+-]?\\d+(\\.\\d+)?\\)$");		// regular expression
    bool init;
    bool abFlag = true, doneFlag = false;		// flag variable for vector2D A or B and for whether task done or not
    init = true;

    while (init)
    {
        if (abFlag)
        {
            cout << "Please input vectorA: ";
        }
        else
        {
            cout << "Please input vectorB: ";
        }

        getline(cin, input);

        if (input.compare("Exit")==0)		// input Exit, quit the program immediately
        {
            return 0;
        }
        else if (!std::regex_match(input, PATTERN))
        {
            cout << "Input error: Wrong Format!" << endl;		// invalid input: wrong format
        }
        else
        {
            int idx;
            idx = input.find_last_of(',');					// the split index for two dimensions

            if (input.substr(1, idx-1).find('.')!= string::npos || input.substr(idx + 1, (input.length() - 1)).find('.')!= string::npos)
            {
                // input x.0 (like 2.0) is regard as invalid input
                cout << "Input error: Wrong Number Pattern!" << endl;		// invalid input: number pattern (we need integer)
                continue;
            }

            x = atof(input.substr(1, idx-1).c_str());
            y = atof(input.substr(idx+1, input.length()-1).c_str());

            if (abs((int)x - x)>0 || abs((int)y - y)>0)
            {
                cout << "Input error: Wrong Number Pattern!" << endl;		// invalid input: number pattern (we need integer)
                continue;
            }
            else
            {
                if (abFlag)
                {
                    vectorA = Vector2D((int)x, (int)y);
                    abFlag = false;
                }
                else
                {
                    vectorB = Vector2D((int)x, (int)y);
                    abFlag = true;
                    doneFlag = true;
                }
            }
        }

        if (doneFlag == true)
        {
            cout << "\nvectorA = (" << vectorA.getX() << "," << vectorA.getY() << ") vectorB = ("	// call the getter function
                 << vectorB.getX() << "," << vectorB.getY() << ")" << endl;				// output the result
            cout << "vectorA * vectorB = " << vectorA* vectorB << "\n\n" << endl;		// call the operator overload function
            doneFlag = false;
        }
    }

    return 0;
}
