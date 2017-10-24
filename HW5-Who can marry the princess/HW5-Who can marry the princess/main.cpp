#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

int main()
{
    vector<int> theVector;              // declare the vector
    int n, index = 0, winner;
    string input;
    const std::regex PATTERN("^[0-9]*[1-9][0-9]*$");		// regular expression
    cout << "How many suitors are there? " << endl;

    while (true)
    {
        getline(cin, input);

        if (std::regex_match(input, PATTERN))
        {
            n = (int)atof(input.c_str());

            for (int i = 0; i<n; i++)
            {
                theVector.push_back(i + 1);			// Initialize the vector object, and then insert i + 1 into the tail
            }

            while (theVector.size())             // When the number of elements in the vector more than one
            {
                index = (index + 3 -1) % theVector.size();     // Calculate the remove position
                winner = theVector[index];
                theVector.erase(theVector.begin() + index); // Remove this element from the vector
            }

            cout << "\nThe lucky winner is ... Number " << winner << " !\n" << endl;
            cout << "How many suitors are there? " << endl;
        }
        else if (input.compare("0") == 0)
        {
            exit(0);		// Exit the program without system pause when input is 0
        }
        else
        {
            cout << "Wrong input. Please input again:" << endl;
        }
    }

    return 0;
}
