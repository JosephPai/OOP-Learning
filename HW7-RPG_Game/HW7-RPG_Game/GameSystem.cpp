#include "GameSystem.h"
#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <time.h>

using namespace std;

GameSystem::GameSystem()
{
	_monsterList.push_back(Character("�粼��(Goblin)", 1, 6, 1));
	_monsterList.push_back(Character("ʷ��ķ(Slime)", 1, 1, 6));
	_monsterList.push_back(Character("����(Orc)", 6, 1, 1));
	_monsterList.push_back(Character("������(Frog)", 3, 2, 3));			// init the enemy
}

void GameSystem::Start()
{
	const int MAIN_ERROR = -1, MAIN_MENU_CREAT = 1, MAIN_MENU_FIGHT = 2, MAIN_MENU_LIST = 3, MINA_MENU_DELELTE = 4, MAIN_MENU_EXIT = 5;	// different states of game
	int mainMenuState;
	bool init;
	init = true;
	while (init)
	{
		mainMenuState = PrintMenu();
		if (mainMenuState == MAIN_ERROR)
		{
			continue;
		}
		if (mainMenuState == MAIN_MENU_CREAT)		// creating character branch
		{
			Create();
		}

		if (mainMenuState == MAIN_MENU_FIGHT)		// fight branch
		{
			Fight();
		}

		if (mainMenuState == MAIN_MENU_LIST)		// list branch
		{
			List();
		}

		if (mainMenuState == MINA_MENU_DELELTE)		// list branch
		{
			Delete();
		}

		if (mainMenuState == MAIN_MENU_EXIT)		// Exit branch
		{
			exit(0);
		}
	}
}

int GameSystem::PrintMenu()		// print the main game menu
{
	int mainMenuState;
	string mainMenuSel;
	cout << "1.������ɫ(Creating Character) \n2.��ɫ��ս(Fight)\n3.�г����н�ɫ(List all characters)\n4.ɾ����ɫ(Delete Character)\n5.�뿪(Exit)" << endl;
	getline(cin, mainMenuSel);
	if (mainMenuSel.compare("1") == 0 || mainMenuSel.compare("2") == 0 ||
		mainMenuSel.compare("3") == 0 || mainMenuSel.compare("4") == 0 || mainMenuSel.compare("5") == 0)
	{
		if (mainMenuSel.find(" ") == 0 || mainMenuSel.empty())
		{
			cout << "ָ��������������롣(Invalid input, please input again.)\n" << endl;
			return -1;
		}
		else
		{
			mainMenuState = atoi(mainMenuSel.c_str());
			return mainMenuState;
		}
	}
	else
	{
		cout << "ָ��������������롣(Invalid input, please input again.)\n" << endl;
		return -1;
	}
}

bool GameSystem::Create()
{
	const std::regex NAME_PATTERN("[\\\\/:*?\"<>|]");		// regular expression for name
	int strTemp, dexTemp, conTemp, pointTemp;
	int creatState;
	const int CREAT_NAME = 0, CREAT_POINT = 1, CREAT_INFO = 2;
	string name, pointSel;
	if (_charactersList.size() >= 5)
	{
		cout << "��ɫ�����Ѵ����ޣ�(The number of characters has reached the limit!)\n" << endl;
		return false;
	}

	strTemp = dexTemp = conTemp = 1;
	creatState = CREAT_NAME;				// switch game state

	while (creatState == CREAT_NAME)
	{
		cout << "�������ɫ���ƣ��ɽ��ܿո�(Please input the name of the character��containing space is accepted:)";
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

	while (creatState == CREAT_POINT)		// distribute the points
	{
		cout << "\n1.ĿǰSTR :(Current STR) " << strTemp << endl;
		cout << "2.ĿǰDEX : (Current DEX)" << dexTemp << endl;
		cout << "3.ĿǰCON : (Current CON)" << conTemp << endl;
		cout << "Ŀǰʣ����� : (Current remaining points)" << pointTemp << endl;
		cout << "��ѡ��������֮���� : (Please choose to increase the attributes)";
		getline(cin, pointSel);
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
			_charactersList.push_back(Character(name, strTemp, dexTemp, conTemp));		// construct instance
			cout << "�����ɹ���(Created successfully)\n" << endl;
			creatState = CREAT_INFO;					// switch game state
		}
	}

	if (creatState == CREAT_INFO)
	{
		_charactersList.back().GetInformation();		// output the information of the character
	}
	return true;
}

void GameSystem::Fight()
{
	srand((unsigned)time(NULL));							// random seed
	string fightSel;
	int fightPointer1, fightPointer2;
	if (_charactersList.empty())
	{
		cout << "û�н�ɫ�ɹ�ѡ��(No character to choose from)\n" << endl;
		//continue;
		return;
	}
	int i;
	for (i = 0;i < _charactersList.size();i++)
		cout << i + 1 << ". " << _charactersList[i].GetName() << endl;
	while (true)
	{
		cout << "��ѡ���ɫ������ս��(Please choose a character to fight)";
		getline(cin, fightSel);
		if (fightSel == "0")
		{
			cout << "\n������ս�������ز˵���(Not fight, jump back to the menu)\n" << endl;
			break;
		}
		if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0
			|| fightSel.compare("4") == 0 || fightSel.compare("5") == 0)
		{
			if (fightSel.find(" ") == 0 || fightSel.empty())
			{
				cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
				continue;
			}
			fightPointer1 = atoi(fightSel.c_str()) - 1;
			if (fightPointer1 >= _charactersList.size())		// Determine whether the character exists
			{
				cout << "�����ڸý�ɫ��������ѡ��(This character does not exist, please select again.)\n" << endl;
				continue;
			}
			else
			{
				fightPointer2 = (rand() % 4);				// Choose enemies randomly
				_charactersList[fightPointer1].Fight(_monsterList[fightPointer2]);
				break;
			}
		}
		else
		{
			cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
		}
	}
}

void GameSystem::List()
{
	if (_charactersList.empty())
	{
		cout << "û�н�ɫ�ɹ�ѡ��(No character to choose from)\n" << endl;
		//continue;
		return;
	}
	int i;
	for (i = 0;i < _charactersList.size();i++)
		_charactersList[i].GetInformation();		// output the information for each character one by one
}

void GameSystem::Delete()
{
	string deleteSel;
	int deletePointer;
	if (_charactersList.empty())
	{
		cout << "û�н�ɫ�ɹ�ѡ��(No character to choose from)\n" << endl;
		//continue;
		return;
	}
	int i;
	for (i = 0;i < _charactersList.size();i++)
		cout << i + 1 << ". " << _charactersList[i].GetName() << endl;
	while (true)
	{
		cout << "��������ɾ���Ľ�ɫ��(Please enter the character you want to delete)\n";
		getline(cin, deleteSel);
		if (deleteSel == "0")
		{
			cout << "\n��ɾ����ɫ�����ز˵���(Not delete the character, jump back to the menu)\n" << endl;
			break;
		}
		if (deleteSel.compare("1") == 0 || deleteSel.compare("2") == 0 || deleteSel.compare("3") == 0
			|| deleteSel.compare("4") == 0 || deleteSel.compare("5") == 0)
		{
			if (deleteSel.find(" ") == 0 || deleteSel.empty())
			{
				cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
				continue;
			}
			deletePointer = atoi(deleteSel.c_str())-1;
			if (deletePointer >= _charactersList.size())		// Determine whether the character exists
			{
				cout << "�����ڸý�ɫ��������ѡ��(This character does not exist, please select again.)\n" << endl;
				continue;
			}
			else
			{
				cout << "��ɾ����ɫ��(Character deleted:)" << _charactersList[deletePointer].GetName() << "��\n" << endl;
				_charactersList.erase(_charactersList.begin() + deletePointer);
				break;
			}
		}
		else
		{
			cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
		}
	}
}

GameSystem::~GameSystem()
{
	_charactersList.clear();
	_monsterList.clear();
	vector <Character>().swap(_charactersList);		// clear the vector
	vector <Character>().swap(_monsterList);
}