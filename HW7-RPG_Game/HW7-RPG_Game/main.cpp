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
	ENEMY[0] = Character("�粼��", 1, 6, 1);
	ENEMY[1] = Character("ʷ��ķ", 1, 1, 6);
	ENEMY[2] = Character("����", 6, 1, 1);
	ENEMY[3] = Character("������", 3, 2, 3);
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
        cout << "1.������ɫ(Creating Character) \n2.��ɫ��ս(Fight)\n3.�г����н�ɫ(List all the characters)\n4.�뿪(Exit)" << endl;
		getline(cin,mainMenuSel);	
		if (mainMenuSel.compare("1")==0 || mainMenuSel.compare("2") == 0 || mainMenuSel.compare("3") == 0 || mainMenuSel.compare("4") == 0)
		{
			if (mainMenuSel.find(" ")==0 || mainMenuSel.empty())
			{
				cout << "ָ��������������롣(Invalid input, please input again.)\n" << endl;
			}
			else
			{
				mainMenuState = atoi(mainMenuSel.c_str());
			}			
		}
		else
		{
			cout << "ָ��������������롣(Invalid input, please input again.)\n" << endl;
		}
        

        if (mainMenuState == MAIN_MENU_CREAT)		// creating character branch
        {
            if (objCounter > 5)
            {
                cout << "��ɫ�����Ѵ����ޣ�(The number of characters has reached the limit!)\n" << endl;
				continue;
            }
			strTemp = dexTemp = conTemp = 1;
            creatState = CREAT_NAME;				// switch game state

            while (creatState == CREAT_NAME)
            {
                cout << "�������ɫ���ƣ��ɽ��ܿո�(Please input the name of the character��containing space is accepted:)" ;
				while (true)
				{
					getline(cin, name);
					if (std::regex_search(name, NAME_PATTERN) || name.find(" ") == 0 || name.empty())		// Check for illegal symbols
					{
						cout << "���Ʋ��Ϲ涨�����������룺(Name is not acceptable format, please input again.";
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
                cout << "\n1.ĿǰSTR :(Current STR) " << strTemp << endl;
                cout << "2.ĿǰDEX : (Current DEX)" << dexTemp << endl;
                cout << "3.ĿǰCON : (Current CON)" << conTemp << endl;
                cout << "Ŀǰʣ����� : (Current remaining points)" << pointTemp << endl;
                cout << "��ѡ��������֮���� : (Please choose to increase the attributes)";
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
					cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
                    pointTemp++;
                    continue;
                }

                if (pointTemp == 0)
                {
                    chaObj[objCounter] = Character(name, strTemp, dexTemp, conTemp);		// construct instance
                    cout << "�����ɹ���(Created successfully)\n" << endl;
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
				cout << "û�н�ɫ�ɹ�ѡ��(No character to choose from)\n" << endl;
				continue;
			}
			int i;
			for (i = 1;i < objCounter;i++)
				cout << i << ". " << chaObj[i].GetName() << endl;
			while (true)
			{
				cout << "��ѡ���ɫ������ս��(Please choose a character to fight)";
				getline(cin,fightSel);	
				if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0
					|| fightSel.compare("4") == 0 || fightSel.compare("5") == 0)
				{	
					if (fightSel.find(" ") == 0 || fightSel.empty())
					{
						cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
						continue;
					}
					fightPointer1 = atoi(fightSel.c_str());
					if (fightPointer1 >= objCounter)		// Determine whether the character exists
					{
						cout << "�����ڸý�ɫ��������ѡ��(This character does not exist, please select again.)\n" << endl;
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
					cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
				}
			}			
        }

        if (mainMenuState == MAIN_MENU_LIST)		// list branch
        {
			if (objCounter == 1)
			{
				cout << "û�н�ɫ�ɹ�ѡ��(No character to choose from)\n" << endl;
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
