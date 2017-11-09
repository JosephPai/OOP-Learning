#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <time.h>
#include "Character.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));							// random seed
	const int MAIN_MENU_CREAT = 1, MAIN_MENU_FIGHT = 2, MAIN_MENU_LIST = 3, MAIN_MENU_EXIT = 4;		// different states of game
    const int CREAT_NAME = 0, CREAT_POINT = 1, CREAT_INFO = 2;
	Character ENEMY[4];										// default enemy characters
	ENEMY[0] = Character("哥布林", 1, 6, 1);
	ENEMY[1] = Character("史莱姆", 1, 1, 6);
	ENEMY[2] = Character("兽人", 6, 1, 1);
	ENEMY[3] = Character("大青蛙", 3, 2, 3);
	const std::regex NUM_PATTERN("^[1-9]\\d*|0$");			// regular expression for number
	const std::regex NAME_PATTERN("[\\\\/:*?\"<>|]");		// regular expression for name

	Character chaObj[6];
	int mainMenuState, creatState;
	int objCounter = 1;
	int fightPointer1,fightPointer2;
	string mainMenuSel, pointSel, fightSel;
    string name;
    int strTemp = 1, dexTemp = 1, conTemp = 1, pointTemp = 5;
	bool init;
	init = true;

    while (init)
    {
        cout << "1.创建角色(Creating Character) \n2.角色作战(Fight)\n3.列出所有角色(List all the characters)\n4.离开(Exit)" << endl;
		getline(cin,mainMenuSel);	
		if (mainMenuSel.compare("1")==0 || mainMenuSel.compare("2") == 0 || mainMenuSel.compare("3") == 0 || mainMenuSel.compare("4") == 0)
		{
			if (mainMenuSel.find(" ")==0 || mainMenuSel.empty())
			{
				cout << "指令错误，请重新输入。(Invalid input, please input again.)\n" << endl;
			}
			else
			{
				mainMenuState = atoi(mainMenuSel.c_str());
			}			
		}
		else
		{
			cout << "指令错误，请重新输入。(Invalid input, please input again.)\n" << endl;
		}
        

        if (mainMenuState == MAIN_MENU_CREAT)		// creating character branch
        {
            if (objCounter > 5)
            {
                cout << "角色数量已达上限！(The number of characters has reached the limit!)\n" << endl;
				continue;
            }
			strTemp = dexTemp = conTemp = 1;
            creatState = CREAT_NAME;				// switch game state

            while (creatState == CREAT_NAME)
            {
                cout << "请输入角色名称，可接受空格：(Please input the name of the character，containing space is accepted:)" ;
				while (true)
				{
					getline(cin, name);
					if (std::regex_search(name, NAME_PATTERN) || name.find(" ") == 0 || name.empty())		// Check for illegal symbols
					{
						cout << "名称不合规定，请重新输入：(Name is not acceptable format, please input again.";
						continue;
					}
					else
					{
						creatState = CREAT_POINT;
						pointTemp = 5;				// Temporary variable for points
						break;
					}
				}                  
            }

            while (creatState == CREAT_POINT)
            {
                cout << "\n1.目前STR :(Current STR) " << strTemp << endl;
                cout << "2.目前DEX : (Current DEX)" << dexTemp << endl;
                cout << "3.目前CON : (Current CON)" << conTemp << endl;
                cout << "目前剩余点数 : (Current remaining points)" << pointTemp << endl;
                cout << "请选择欲增加之属性 : (Please choose to increase the attributes)";
				getline(cin,pointSel);
                pointTemp--;

                if (pointSel.compare("1") == 0)
                {
                    strTemp++;
                }
                else if (pointSel.compare("2") == 0)
                {
                    dexTemp++;
                }
                else if (pointSel.compare("3") == 0)
                {
                    conTemp++;
                }
                else
                {
					cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
                    pointTemp++;
                    continue;
                }

                if (pointTemp == 0)
                {
                    chaObj[objCounter] = Character(name, strTemp, dexTemp, conTemp);		// construct instance
                    cout << "创建成功！(Created successfully)\n" << endl;
                    creatState = CREAT_INFO;					// switch game state
                }
            }

            if (creatState == CREAT_INFO)
            {
				chaObj[objCounter++].GetInformation();		// output the information of the character
            }
        }

        if (mainMenuState == MAIN_MENU_FIGHT)		// fight branch
        {
			if (objCounter == 1)
			{
				cout << "没有角色可供选择！(No character to choose from)\n" << endl;
				continue;
			}
			int i;
			for (i = 1;i < objCounter;i++)
				cout << i << ". " << chaObj[i].GetName() << endl;
			while (true)
			{
				cout << "请选择角色进行作战：(Please choose a character to fight)";
				getline(cin,fightSel);	
				if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0
					|| fightSel.compare("4") == 0 || fightSel.compare("5") == 0)
				{	
					if (fightSel.find(" ") == 0 || fightSel.empty())
					{
						cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
						continue;
					}
					fightPointer1 = atoi(fightSel.c_str());
					if (fightPointer1 >= objCounter)		// Determine whether the character exists
					{
						cout << "不存在该角色，请重新选择。(This character does not exist, please select again.)\n" << endl;
						continue;
					}
					else
					{
						fightPointer2 = (rand() % 4);				// Choose enemies randomly
						chaObj[fightPointer1].Fight(ENEMY[fightPointer2]);
						break;
					}
				}
				else
				{
					cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
				}
			}			
        }

        if (mainMenuState == MAIN_MENU_LIST)		// list branch
        {
			if (objCounter == 1)
			{
				cout << "没有角色可供选择！(No character to choose from)\n" << endl;
				continue;
			}
			int i;
			for (i = 1;i < objCounter;i++)
				chaObj[i].GetInformation();		// output the information for each character one by one
        }

        if (mainMenuState == MAIN_MENU_EXIT)		// Exit branch
        {
			return 0;
        }
    }

    return 0;

}
