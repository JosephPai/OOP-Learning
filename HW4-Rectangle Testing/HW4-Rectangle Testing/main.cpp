#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <iomanip>

using namespace std;

#include "Rectangle.h"

int main()
{
    string command;			// command info from console
    double width, height;
    const std::regex PATTERN_RECTANGLE("^R\\s[0-9]+\\.?[0-9]*\\s[0-9]+\\.?[0-9]*$");	// regular expression for command info
    const std::regex PATTERN_WIDTH( "^W\\s[0-9]+\\.?[0-9]*$");
    const std::regex PATTERN_HEIGHT("^H\\s[0-9]+\\.?[0-9]*$");
    bool init;
    bool hasConstructed;			// the bool flag of rectangle construction
    init = true;
    hasConstructed = false;
    Rectangle* recObj = new Rectangle(init);

    while (init)
    {
        cout << ">";
        getline(cin, command);		// get the command info from console

        if (std::regex_match(command, PATTERN_RECTANGLE))
        {
            if (hasConstructed == true)
            {
                cout << "You have been constructed a rectangle, please input Next first.\n" << endl;
            }
            else
            {
                int idx;
                idx = command.find_last_of(' ');					// index for selection
                width = atof(command.substr(2, idx).c_str());		// select the width and height from the string of command info
                height = atof(command.substr(idx, command.length()).c_str());	// from string to double

                if (width == 0 || height == 0)		// another protection of invalid input
                {
                    cout << "Wrong input format, please enter again.\n" << endl;
                    continue;
                }

                recObj = new Rectangle(width, height);
                hasConstructed = true;
            }
        }
        else if (command.compare("R") == 0)
        {
            if (hasConstructed == true)
            {
                cout << "You have been constructed a rectangle, please input Next first.\n" << endl;
            }
            else
            {
                recObj = new Rectangle();
                hasConstructed = true;
            }
        }
        else if (std::regex_match(command, PATTERN_WIDTH))
        {
            if (hasConstructed == false)
            {
                cout << "You have not constructed a rectangle.\n" << endl;
            }
            else
            {
                width = atof(command.substr(2, command.length()).c_str());

                if (width == 0)
                {
                    cout << "Wrong input format, please enter again.\n" << endl;
                    continue;
                }

                recObj->SetWidth(width);
            }
        }
        else if (std::regex_match(command, PATTERN_HEIGHT))
        {
            if (hasConstructed == false)
            {
                cout << "You have not constructed a rectangle.\n" << endl;
            }
            else
            {
                height = atof(command.substr(2, command.length()).c_str());

                if (height == 0)
                {
                    cout << "Wrong input format, please enter again.\n" << endl;
                    continue;
                }

                recObj->SetHeight(height);
            }
        }
        else if (command.compare("A") == 0)
        {
            if (hasConstructed == false)
            {
                cout << "You have not constructed a rectangle.\n" << endl;
            }
            else
            {
                recObj->Area();			// call the Area() function
            }
        }
        else if (command.compare("Next")==0)
        {
            if (hasConstructed == false)
            {
                cout << "You have not constructed a rectangle.\n" << endl;
            }
            else
            {
                delete recObj;				// Release memory, go to the next Obj
                hasConstructed = false;		// switch to none construction state
                cout << "==============================\n" << endl;
            }
        }
        else if (command.compare("End")==0)
        {
            delete recObj;						// Release memory
            init = false;						// break the loop
        }
        else
        {
            cout << "Wrong input format, please enter again.\n" << endl;	//Did not find the match, invalid input
        }
    }

    return 0;
}
