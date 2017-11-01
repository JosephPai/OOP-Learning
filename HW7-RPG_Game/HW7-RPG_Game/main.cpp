/***
* Class: Exchange Student
* ID：106012046
* Name: Bai Zechen
* HW number: 6
* Date: 10/23/106
* Purpose: Vector2D and its dot product
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

    int mainMenuState, creatState;
	bool attackOrderFlag;
    bool init;
    init = true;
    Character chaObj [6];
	int objCounter = 1, hp1, hp2;
	int mainMenuSel, fightPointer1,fightPointer2;
	string pointSel, fightSel;
    string name;
    int strTemp = 1, dexTemp = 1, conTemp = 1, pointTemp = 5;

    while (init)
    {
        cout << "1.创建角色 \n2.角色作战\n3.列出所有角色\n4.离开" << endl;
        cin >> mainMenuSel;		// 还需完善
        mainMenuState = mainMenuSel;

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
				cin >> name;

                if (name.find('<') == 0)	// 假设找到了非法字符  注意空白  还需完善
                {
                    cout << "名称不合规定，请重新输入：";
                }
                else
                {
                    creatState = CREAT_POINT;
                    pointTemp = 5;
                }
            }

            while (creatState == CREAT_POINT)
            {
                cout << "\n1.目前STR : " << strTemp << endl;
                cout << "2.目前DEX : " << dexTemp << endl;
                cout << "3.目前CON : " << conTemp << endl;
                cout << "目前剩余点数 : " << pointTemp << endl;
                cout << "请选择欲增加之属性 : ";
				cin >> pointSel;	// 还需完善
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
				chaObj[objCounter++].getInformation();
            }
        }

        if (mainMenuState == MAIN_MENU_FIGHT)
        {
			int i;
			for (i = 1;i < objCounter;i++)
				cout << i << ". " << chaObj[i].getName() << endl;
			cout << "请选择角色进行作战：";
			cin >> fightSel;		// 还需完善
			if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0 || fightSel.compare("4") == 0)
			{	// 还有5
				// 判断是否大于objCounter
				fightPointer1 = atoi(fightSel.c_str());
				fightPointer2 = (rand() % 4);				
				hp1 = chaObj[fightPointer1].getDex() * 3;
				hp2 = ENEMY[fightPointer2].getDex() * 3;
				cout << "\n系统选择了[" << ENEMY[fightPointer2].getName() << "]作为敌人。" << endl;
				cout << chaObj[fightPointer1].getName() << "的DEX为" << chaObj[fightPointer1].getDex() << ",";
				cout << ENEMY[fightPointer2].getName() << "的DEX为" << ENEMY[fightPointer2].getDex() << ",由";
				attackOrderFlag = chaObj[fightPointer1].getDex() >= ENEMY[fightPointer2].getDex();
				cout << (attackOrderFlag ? chaObj[fightPointer1].getName() : ENEMY[fightPointer2].getName()) << "先进行攻击。\n" << endl;
				
				while (true)
				{
					if (attackOrderFlag)
					{
						cout << chaObj[fightPointer1].getName() << "发动攻击！对"
							<< ENEMY[fightPointer2].getName() << "造成" << chaObj[fightPointer1].getStr() << "点伤害。" << endl;
						cout << ENEMY[fightPointer2].getName() << "的HP从" << hp2 << "变为";
						if (hp2 > chaObj[fightPointer1].getStr())
						{
							hp2 = hp2 - chaObj[fightPointer1].getStr();
							cout << hp2 << "\n" << endl;
							attackOrderFlag = false;
						}
						else
						{
							hp2 = 0;
							cout << hp2 << "\n" << endl;
							cout << ENEMY[fightPointer2].getName() << "倒下了！获胜的是 ：" << chaObj[fightPointer1].getName() << endl;
							chaObj[fightPointer1].setTotalFightTimes(chaObj[fightPointer1].getTotalFightTimes() + 1);
							chaObj[fightPointer1].setExp(chaObj[fightPointer1].getExp() + 100);
							break;
						}
					}
					else
					{
						cout << ENEMY[fightPointer2].getName() << "发动攻击！对"
							<< chaObj[fightPointer1].getName() << "造成" << ENEMY[fightPointer2].getStr() << "点伤害。" << endl;
						cout << chaObj[fightPointer1].getName() << "的HP从" << hp1 << "变为";
						if (hp1 > ENEMY[fightPointer2].getStr())
						{
							hp1 = hp1 - ENEMY[fightPointer2].getStr();
							cout << hp1 << "\n" << endl;
							attackOrderFlag = true;
						}
						else
						{
							hp1 = 0;
							cout << hp1 << "\n" << endl;
							cout << chaObj[fightPointer1].getName() << "倒下了！获胜的是 ：" << ENEMY[fightPointer2].getName() << "\n" << endl;
							chaObj[fightPointer1].setTotalFightTimes(chaObj[fightPointer1].getTotalFightTimes() + 1);
							chaObj[fightPointer1].setFailFightTimes(chaObj[fightPointer1].getFailFightTimes() + 1);
							break;
						}
					}
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
				chaObj[i].getInformation();
        }

        if (mainMenuState == MAIN_MENU_EXIT)
        {
			return 0;
        }
    }

    return 0;
}