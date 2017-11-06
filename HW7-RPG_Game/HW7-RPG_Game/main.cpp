/***
* Class: Exchange Student
* ID��106012046
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
	ENEMY[0] = Character("�粼��", 1, 6, 1);
	ENEMY[1] = Character("ʷ��ķ", 1, 1, 6);
	ENEMY[2] = Character("����", 6, 1, 1);
	ENEMY[3] = Character("������", 3, 2, 3);
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
        cout << "1.������ɫ \n2.��ɫ��ս\n3.�г����н�ɫ\n4.�뿪" << endl;
		getline(cin,mainMenuSel);	// ���
		if (mainMenuSel.compare("1")==0 || mainMenuSel.compare("2") == 0 || mainMenuSel.compare("3") == 0 || mainMenuSel.compare("4") == 0)
		{
			if (mainMenuSel.find(" ")==0 || mainMenuSel.empty())
			{
				cout << "ָ�����001�����������롣\n" << endl;
			}
			else
			{
				mainMenuState = atoi(mainMenuSel.c_str());
			}
			
		}
		else
		{
			cout << "ָ��������������롣\n" << endl;
		}
        

        if (mainMenuState == MAIN_MENU_CREAT)
        {
            if (objCounter > 5)
            {
                cout << "��ɫ�����Ѵ����ޣ�\n" << endl;
				continue;
            }
			strTemp = dexTemp = conTemp = 1;
            creatState = CREAT_NAME;

            while (creatState == CREAT_NAME)
            {
                cout << "�������ɫ���ƣ�" ;
				while (true)
				{
					getline(cin, name);
					if (std::regex_search(name, NAME_PATTERN) || name.find(" ") == 0 || name.empty())	
						// �����ҵ��˷Ƿ��ַ�  ע��հ�  ��������
					{
						cout << "���Ʋ��Ϲ涨�����������룺";
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
                cout << "\n1.ĿǰSTR : " << strTemp << endl;
                cout << "2.ĿǰDEX : " << dexTemp << endl;
                cout << "3.ĿǰCON : " << conTemp << endl;
                cout << "Ŀǰʣ����� : " << pointTemp << endl;
                cout << "��ѡ��������֮���� : ";
				getline(cin,pointSel);	// ��������
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
					cout << "ָ��������������롣" << endl;
                    pointTemp++;
                    continue;
                }

                if (pointTemp == 0)
                {
                    chaObj[objCounter] = Character(name, strTemp, dexTemp, conTemp);
                    cout << "�����ɹ���\n" << endl;
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
				cout << "û�н�ɫ�ɹ�ѡ��\n" << endl;
				continue;
			}
			int i;
			for (i = 1;i < objCounter;i++)
				cout << i << ". " << chaObj[i].GetName() << endl;
			while (true)
			{
				cout << "��ѡ���ɫ������ս��";
				getline(cin,fightSel);		// ��������
				if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0
					|| fightSel.compare("4") == 0 || fightSel.compare("5") == 0)
				{	
					if (fightSel.find(" ") == 0 || fightSel.empty())
					{
						cout << "ָ��������������롣" << endl;
						continue;
					}
					fightPointer1 = atoi(fightSel.c_str());
					if (fightPointer1 >= objCounter)
					{
						cout << "�����ڸý�ɫ��������ѡ��\n" << endl;
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
					cout << "ָ��������������롣" << endl;
				}
			}			
        }

        if (mainMenuState == MAIN_MENU_LIST)
        {
			if (objCounter == 1)
			{
				cout << "û�н�ɫ�ɹ�ѡ��\n" << endl;
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