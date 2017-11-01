/***
* Class: Exchange Student
* ID��106012046
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
	ENEMY[0] = Character("�粼��", 1, 6, 1);
	ENEMY[1] = Character("ʷ��ķ", 1, 1, 6);
	ENEMY[2] = Character("����", 6, 1, 1);
	ENEMY[3] = Character("������", 3, 2, 3);

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
        cout << "1.������ɫ \n2.��ɫ��ս\n3.�г����н�ɫ\n4.�뿪" << endl;
        cin >> mainMenuSel;		// ��������
        mainMenuState = mainMenuSel;

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
				cin >> name;

                if (name.find('<') == 0)	// �����ҵ��˷Ƿ��ַ�  ע��հ�  ��������
                {
                    cout << "���Ʋ��Ϲ涨�����������룺";
                }
                else
                {
                    creatState = CREAT_POINT;
                    pointTemp = 5;
                }
            }

            while (creatState == CREAT_POINT)
            {
                cout << "\n1.ĿǰSTR : " << strTemp << endl;
                cout << "2.ĿǰDEX : " << dexTemp << endl;
                cout << "3.ĿǰCON : " << conTemp << endl;
                cout << "Ŀǰʣ����� : " << pointTemp << endl;
                cout << "��ѡ��������֮���� : ";
				cin >> pointSel;	// ��������
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
				chaObj[objCounter++].getInformation();
            }
        }

        if (mainMenuState == MAIN_MENU_FIGHT)
        {
			int i;
			for (i = 1;i < objCounter;i++)
				cout << i << ". " << chaObj[i].getName() << endl;
			cout << "��ѡ���ɫ������ս��";
			cin >> fightSel;		// ��������
			if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0 || fightSel.compare("4") == 0)
			{	// ����5
				// �ж��Ƿ����objCounter
				fightPointer1 = atoi(fightSel.c_str());
				fightPointer2 = (rand() % 4);				
				hp1 = chaObj[fightPointer1].getDex() * 3;
				hp2 = ENEMY[fightPointer2].getDex() * 3;
				cout << "\nϵͳѡ����[" << ENEMY[fightPointer2].getName() << "]��Ϊ���ˡ�" << endl;
				cout << chaObj[fightPointer1].getName() << "��DEXΪ" << chaObj[fightPointer1].getDex() << ",";
				cout << ENEMY[fightPointer2].getName() << "��DEXΪ" << ENEMY[fightPointer2].getDex() << ",��";
				attackOrderFlag = chaObj[fightPointer1].getDex() >= ENEMY[fightPointer2].getDex();
				cout << (attackOrderFlag ? chaObj[fightPointer1].getName() : ENEMY[fightPointer2].getName()) << "�Ƚ��й�����\n" << endl;
				
				while (true)
				{
					if (attackOrderFlag)
					{
						cout << chaObj[fightPointer1].getName() << "������������"
							<< ENEMY[fightPointer2].getName() << "���" << chaObj[fightPointer1].getStr() << "���˺���" << endl;
						cout << ENEMY[fightPointer2].getName() << "��HP��" << hp2 << "��Ϊ";
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
							cout << ENEMY[fightPointer2].getName() << "�����ˣ���ʤ���� ��" << chaObj[fightPointer1].getName() << endl;
							chaObj[fightPointer1].setTotalFightTimes(chaObj[fightPointer1].getTotalFightTimes() + 1);
							chaObj[fightPointer1].setExp(chaObj[fightPointer1].getExp() + 100);
							break;
						}
					}
					else
					{
						cout << ENEMY[fightPointer2].getName() << "������������"
							<< chaObj[fightPointer1].getName() << "���" << ENEMY[fightPointer2].getStr() << "���˺���" << endl;
						cout << chaObj[fightPointer1].getName() << "��HP��" << hp1 << "��Ϊ";
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
							cout << chaObj[fightPointer1].getName() << "�����ˣ���ʤ���� ��" << ENEMY[fightPointer2].getName() << "\n" << endl;
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
				cout << "û�н�ɫ�ɹ�ѡ��\n" << endl;
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