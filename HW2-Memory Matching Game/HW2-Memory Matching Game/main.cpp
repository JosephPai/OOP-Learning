#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <regex>
#include <string>

using namespace std;

void Shuffles(int Matrix[4][4])
{
    int row, col;
    srand((unsigned)time(NULL));	// random seed

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= 8; )
        {
            row = rand() % 4;
            col = rand() % 4;

            if (Matrix[row][col] == 0)  // tow loops form 1 to 8, if the random location of Matrix is not assigned,then assign it.
            {
                Matrix[row][col] = j;
                j++;
            }
        }
    }
}

int main()
{
    int arrangeMatrix[4][4] = { 0 };		// 2D Matrix of the game board
    int downOrUpMartrix[4][4] = { 0 };		// The Matrix for controller of face up or face down
    std::string location1, location2;		// use sting to get location info
    const std::regex PATTERN( "^\\([1-4],[1-4]\\)$" );		// regular expression
    int row1, col1; // first coordinate info
    int row2, col2; // second coordinate info
    int currentState = 0; 	//Different game state£¬0 is the coordinate input state£¬1 is the judgment of match or not£¬2 is output current board
    int lastState = 0;	// 0:match£»1:no match
    bool init = false;		// initialization
    bool winFlag = false;	// the flag for winning
    Shuffles(arrangeMatrix);
    init = true;

    while (init)
    {
        if (currentState == 0)
        {
            cout << "Please enter the coordinate1 : ";
            getline(cin,location1);

            if (std::regex_match(location1, PATTERN))  		// use regex to judge is the location1's format right
            {
                row1 = location1[1] - '0';
                col1 = location1[3] - '0';
            }
            else
            {
                cout << "Invalid input! Please input again from the coordinate1.\n" << endl;
                continue;
            }

            cout << "Please enter the coordinate2 : ";
            getline(cin, location2);

            if (std::regex_match(location2, PATTERN))  		// use regex to judge is the location2's format right
            {
                row2 = location2[1] - '0';
                col2 = location2[3] - '0';
            }
            else
            {
                cout << "Invalid input! Please input again from the coordinate1.\n" << endl;
                continue;
            }

            cout << "\n";
            currentState = 1;

            if (lastState == 1)  		// lastState not match£¬Output 50 blank lines to clean up the screen
            {
                for (int i = 0; i < 50; i++)
                {
                    cout << "\n";
                }
            }
        }

        if (currentState == 1)
        {
            if (arrangeMatrix[row1 - 1][col1 - 1] == arrangeMatrix[row2 - 1][col2 - 1])
            {
                cout << "(" << row1 << "," << col1 << ")" << "(" << row2 << "," << col2 << ")" << " is Match!!\n" << endl;
                downOrUpMartrix[row1 - 1][col1 - 1] = 1;
                downOrUpMartrix[row2 - 1][col2 - 1] = 1;
                lastState = 0;
            }
            else
            {
                cout << "(" << row1 << "," << col1 << ")" << "(" << row2 << "," << col2 << ")" << " is Not Match!!\n" << endl;
                lastState = 1;
            }

            currentState = 2;
        }

        if (currentState == 2)
        {
            cout << "       [1]    [2]    [3]    [4]" << endl;

            for (int i = 1; i <= 4; i++)
            {
                cout << "[" << i << "]     ";

                for (int j = 1; j <= 4; j++)
                {
                    if (downOrUpMartrix[i - 1][j - 1] == 1 || (i == row1 && j == col1) || (i == row2 && j == col2))
                    {
                        cout << arrangeMatrix[i - 1][j - 1] << "      ";
                    }
                    else
                    {
                        cout << "*      ";
                    }
                }

                cout << "\n" << endl;
            }

            currentState = 0;
        }

        winFlag = true;

        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (downOrUpMartrix[i][j] == 0)  // According to whether all the cards are turned over to determine whether the game is over
                {
                    winFlag = false;
                    break;
                }
            }
        }

        if (winFlag == true)
        {
            cout << "Congratulations!! You Win!!\n" << endl;
            init = false;
        }
    }

    return 0;
}
