/***
* Class: Exchange Student
* ID：106012046
* Name: Bai Zechen
* HW number: 7
* Date: 10/23/106
* Purpose: RPG GAEM #1
***/
#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <time.h>
#include "Character.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	const int MAIN_MENU_CREAT = 1, MAIN_MENU_FIGHT = 2, MAIN_MENU_LIST = 3, MAIN_MENU_EXIT = 4;
    const int CREAT_NAME = 0, CREAT_POINT = 1, CREAT_INFO = 2;
	Character ENEMY[4];
	ENEMY[0] = Character("哥布林", 1, 6, 1);
	ENEMY[1] = Character("史莱姆", 1, 1, 6);
	ENEMY[2] = Character("兽人", 6, 1, 1);
	ENEMY[3] = Character("大青蛙", 3, 2, 3);
	const std::regex NUM_PATTERN("^[1-9]\\d*|0$");			// regular expression
	const std::regex NAME_PATTERN("[\\\\/:*?\"<>|]");		// regular expression

    int mainMenuState, creatState;
    bool init;
    init = true;
    Character chaObj [6];
	int objCounter = 1;
	int fightPointer1,fightPointer2;
	string mainMenuSel, pointSel, fightSel;
    string name;
    int strTemp = 1, dexTemp = 1, conTemp = 1, pointTemp = 5;

    while (init)
    {
        cout << "1.创建角色 \n2.角色作战\n3.列出所有角色\n4.离开" << endl;
		getline(cin,mainMenuSel);	// 检查
		if (mainMenuSel.compare("1")==0 || mainMenuSel.compare("2") == 0 || mainMenuSel.compare("3") == 0 || mainMenuSel.compare("4") == 0)
		{
			if (mainMenuSel.find(" ")==0 || mainMenuSel.empty())
			{
				cout << "指令错误001，请重新输入。\n" << endl;
			}
			else
			{
				mainMenuState = atoi(mainMenuSel.c_str());
			}
			
		}
		else
		{
			cout << "指令错误，请重新输入。\n" << endl;
		}
        

        if (mainMenuState == MAIN_MENU_CREAT)
        {
            if (objCounter > 5)
            {
                cout << "角色数量已达上限！\n" << endl;
				continue;
            }
			strTemp = dexTemp = conTemp = 1;
            creatState = CREAT_NAME;

            while (creatState == CREAT_NAME)
            {
                cout << "请输入角色名称：" ;
				while (true)
				{
					getline(cin, name);
					if (std::regex_search(name, NAME_PATTERN) || name.find(" ") == 0 || name.empty())	
						// 假设找到了非法字符  注意空白  还需完善
					{
						cout << "名称不合规定，请重新输入：";
						continue;
					}
					else
					{
						creatState = CREAT_POINT;
						pointTemp = 5;
						break;
					}
				}                  
            }

            while (creatState == CREAT_POINT)
            {
                cout << "\n1.目前STR : " << strTemp << endl;
                cout << "2.目前DEX : " << dexTemp << endl;
                cout << "3.目前CON : " << conTemp << endl;
                cout << "目前剩余点数 : " << pointTemp << endl;
                cout << "请选择欲增加之属性 : ";
				getline(cin,pointSel);	// 还需完善
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
					cout << "指令错误，请重新输入。" << endl;
                    pointTemp++;
                    continue;
                }

                if (pointTemp == 0)
                {
                    chaObj[objCounter] = Character(name, strTemp, dexTemp, conTemp);
                    cout << "创建成功！\n" << endl;
                    creatState = CREAT_INFO;
                }
            }

            if (creatState == CREAT_INFO)
            {
				chaObj[objCounter++].GetInformation();
            }
        }

        if (mainMenuState == MAIN_MENU_FIGHT)
        {
			if (objCounter == 1)
			{
				cout << "没有角色可供选择！\n" << endl;
				continue;
			}
			int i;
			for (i = 1;i < objCounter;i++)
				cout << i << ". " << chaObj[i].GetName() << endl;
			while (true)
			{
				cout << "请选择角色进行作战：";
				getline(cin,fightSel);		// 还需完善
				if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0
					|| fightSel.compare("4") == 0 || fightSel.compare("5") == 0)
				{	
					if (fightSel.find(" ") == 0 || fightSel.empty())
					{
						cout << "指令错误，请重新输入。" << endl;
						continue;
					}
					fightPointer1 = atoi(fightSel.c_str());
					if (fightPointer1 >= objCounter)
					{
						cout << "不存在该角色，请重新选择。\n" << endl;
						continue;
					}
					else
					{
						fightPointer2 = (rand() % 4);
						chaObj[fightPointer1].Fight(ENEMY[fightPointer2]);
						break;
					}
				}
				else
				{
					cout << "指令错误，请重新输入。" << endl;
				}
			}			
        }

        if (mainMenuState == MAIN_MENU_LIST)
        {
			if (objCounter == 1)
			{
				cout << "没有角色可供选择！\n" << endl;
				continue;
			}
			int i;
			for (i = 1;i < objCounter;i++)
				chaObj[i].GetInformation();
        }

        if (mainMenuState == MAIN_MENU_EXIT)
        {
			return 0;
        }
    }

    return 0;

}