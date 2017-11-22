#include "GameSystem.h"
#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <time.h>

using namespace std;

GameSystem::GameSystem()
{
	_monsterList.push_back(Character("哥布林(Goblin)", 1, 6, 1));
	_monsterList.push_back(Character("史莱姆(Slime)", 1, 1, 6));
	_monsterList.push_back(Character("兽人(Orc)", 6, 1, 1));
	_monsterList.push_back(Character("大青蛙(Frog)", 3, 2, 3));			// init the enemy
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
	cout << "1.创建角色(Creating Character) \n2.角色作战(Fight)\n3.列出所有角色(List all characters)\n4.删除角色(Delete Character)\n5.离开(Exit)" << endl;
	getline(cin, mainMenuSel);
	if (mainMenuSel.compare("1") == 0 || mainMenuSel.compare("2") == 0 ||
		mainMenuSel.compare("3") == 0 || mainMenuSel.compare("4") == 0 || mainMenuSel.compare("5") == 0)
	{
		if (mainMenuSel.find(" ") == 0 || mainMenuSel.empty())
		{
			cout << "指令错误，请重新输入。(Invalid input, please input again.)\n" << endl;
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
		cout << "指令错误，请重新输入。(Invalid input, please input again.)\n" << endl;
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
		cout << "角色数量已达上限！(The number of characters has reached the limit!)\n" << endl;
		return false;
	}

	strTemp = dexTemp = conTemp = 1;
	creatState = CREAT_NAME;				// switch game state

	while (creatState == CREAT_NAME)
	{
		cout << "请输入角色名称，可接受空格：(Please input the name of the character，containing space is accepted:)";
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

	while (creatState == CREAT_POINT)		// distribute the points
	{
		cout << "\n1.目前STR :(Current STR) " << strTemp << endl;
		cout << "2.目前DEX : (Current DEX)" << dexTemp << endl;
		cout << "3.目前CON : (Current CON)" << conTemp << endl;
		cout << "目前剩余点数 : (Current remaining points)" << pointTemp << endl;
		cout << "请选择欲增加之属性 : (Please choose to increase the attributes)";
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
			cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
			pointTemp++;
			continue;
		}

		if (pointTemp == 0)
		{
			_charactersList.push_back(Character(name, strTemp, dexTemp, conTemp));		// construct instance
			cout << "创建成功！(Created successfully)\n" << endl;
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
		cout << "没有角色可供选择！(No character to choose from)\n" << endl;
		//continue;
		return;
	}
	int i;
	for (i = 0;i < _charactersList.size();i++)
		cout << i + 1 << ". " << _charactersList[i].GetName() << endl;
	while (true)
	{
		cout << "请选择角色进行作战：(Please choose a character to fight)";
		getline(cin, fightSel);
		if (fightSel == "0")
		{
			cout << "\n不进行战斗，跳回菜单。(Not fight, jump back to the menu)\n" << endl;
			break;
		}
		if (fightSel.compare("1") == 0 || fightSel.compare("2") == 0 || fightSel.compare("3") == 0
			|| fightSel.compare("4") == 0 || fightSel.compare("5") == 0)
		{
			if (fightSel.find(" ") == 0 || fightSel.empty())
			{
				cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
				continue;
			}
			fightPointer1 = atoi(fightSel.c_str()) - 1;
			if (fightPointer1 >= _charactersList.size())		// Determine whether the character exists
			{
				cout << "不存在该角色，请重新选择。(This character does not exist, please select again.)\n" << endl;
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
			cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
		}
	}
}

void GameSystem::List()
{
	if (_charactersList.empty())
	{
		cout << "没有角色可供选择！(No character to choose from)\n" << endl;
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
		cout << "没有角色可供选择！(No character to choose from)\n" << endl;
		//continue;
		return;
	}
	int i;
	for (i = 0;i < _charactersList.size();i++)
		cout << i + 1 << ". " << _charactersList[i].GetName() << endl;
	while (true)
	{
		cout << "请输入欲删除的角色：(Please enter the character you want to delete)\n";
		getline(cin, deleteSel);
		if (deleteSel == "0")
		{
			cout << "\n不删除角色，跳回菜单。(Not delete the character, jump back to the menu)\n" << endl;
			break;
		}
		if (deleteSel.compare("1") == 0 || deleteSel.compare("2") == 0 || deleteSel.compare("3") == 0
			|| deleteSel.compare("4") == 0 || deleteSel.compare("5") == 0)
		{
			if (deleteSel.find(" ") == 0 || deleteSel.empty())
			{
				cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
				continue;
			}
			deletePointer = atoi(deleteSel.c_str())-1;
			if (deletePointer >= _charactersList.size())		// Determine whether the character exists
			{
				cout << "不存在该角色，请重新选择。(This character does not exist, please select again.)\n" << endl;
				continue;
			}
			else
			{
				cout << "已删除角色：(Character deleted:)" << _charactersList[deletePointer].GetName() << "。\n" << endl;
				_charactersList.erase(_charactersList.begin() + deletePointer);
				break;
			}
		}
		else
		{
			cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
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