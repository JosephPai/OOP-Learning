#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

Character::Character()
{

}

Character::~Character()
{

}

Character::Character(string name, int str, int dex, int con)
{
	this->_name = name;
	this->_str = str;
	this->_dex = dex;
	this->_con = con;
	this->_level = 1;
	this->_exp = 0;
	this->_totalFightTimes = 0;
	this->_failFighttTimes = 0;
}

string Character::GetName()
{
	return this->_name;
}

void Character::GetName(string name)
{
	this->_name = name;
}

int Character::GetLevel()
{
	return this->_level;
}

void Character::SetLevel(int level)
{
	this->_level = level;
}

int Character::GetStr()
{
	return this->_str;
}

void Character::SetStr(int str)
{
	this->_str = str;
}

int Character::GetDex()
{
	return this->_dex;
}

void Character::SetDex(int dex)
{
	this->_dex = dex;
}

int Character::GetCon()
{
	return this->_con;
}

void Character::SetCon(int con)
{
	this->_con = con;
}

int Character::GetExp()
{
	return this->_exp;
}

void Character::SetExp(int exp)
{
	this->_exp = exp;
}

int Character::GetTotalFightTimes()
{
	return this->_totalFightTimes;
}

void Character::SetTotalFightTimes(int times)
{
	this->_totalFightTimes = times;
}

int Character::GetFailFightTimes()
{
	return this->_failFighttTimes;
}

void Character::SetFailFightTimes(int times)
{
	this->_failFighttTimes = times;
}

bool Character::Fight(Character &monster)
{
	int hp1, hp2;
	int monDex, monStr, monCon;
	bool attackOrderFlag;
	monDex = monster.GetDex() + (this->GetLevel() - 1);
	monStr = monster.GetStr() + (this->GetLevel() - 1);
	monCon = monster.GetCon() + (this->GetLevel() - 1);
	hp1 = this->GetDex() * 3;
	hp2 = monDex * 3;
	cout << "\n系统选择了[" << monster.GetName() << "]作为敌人。" << endl;
	cout << this->GetName() << "的DEX为" << this->GetDex() << ",";
	cout << monster.GetName() << "的DEX为" << monDex << ",由";
	attackOrderFlag = this->GetDex() >= monDex;
	cout << (attackOrderFlag ? this->GetName() : monster.GetName()) << "先进行攻击。\n" << endl;

	while (true)
	{
		if (attackOrderFlag)
		{
			cout << this->GetName() << "发动攻击！对"
				<< monster.GetName() << "造成" << this->GetStr() << "点伤害。" << endl;
			cout << monster.GetName() << "的HP从" << hp2 << "变为";
			if (hp2 > this->GetStr())
			{
				hp2 = hp2 - this->GetStr();
				cout << hp2 << "\n" << endl;
				attackOrderFlag = false;
			}
			else
			{
				hp2 = 0;
				cout << hp2 << "\n" << endl;
				cout << monster.GetName() << "倒下了！获胜的是 ：" << this->GetName() << endl;
				this->SetTotalFightTimes(this->GetTotalFightTimes() + 1);
				if (this->GetExp() < 1000)
				{
					this->SetExp(this->GetExp() + 100);
				}
				switch (this->GetExp())
				{
				case 100:	this->LevelUp(2);break;
				case 300:	this->LevelUp(3);break;
				case 600:	this->LevelUp(4);break;
				case 1000:	this->LevelUp(5);break;
				default:
					break;
				}
				return true;
			}
		}
		else
		{
			cout << monster.GetName() << "发动攻击！对"
				<< this->GetName() << "造成" << monStr << "点伤害。" << endl;
			cout << this->GetName() << "的HP从" << hp1 << "变为";
			if (hp1 > monStr)
			{
				hp1 = hp1 - monStr;
				cout << hp1 << "\n" << endl;
				attackOrderFlag = true;
			}
			else
			{
				hp1 = 0;
				cout << hp1 << "\n" << endl;
				cout << this->GetName() << "倒下了！获胜的是 ：" << monster.GetName() << endl;
				this->SetTotalFightTimes(this->GetTotalFightTimes() + 1);
				this->SetFailFightTimes(this->GetFailFightTimes() + 1);
				return false;
			}
		}
	}

}

void Character::GetInformation()
{
	cout << "\n角色名称 ：" << this->GetName() << endl;
	cout << "目前等级 ：" << this->GetLevel() << endl;
	cout << "目前经验值 ：" << this->GetExp() << endl;
	cout << "STR : " << this->GetStr() << endl;
	cout << "DEX : " << this->GetDex() << endl;
	cout << "CON : " << this->GetCon() << endl;
	cout << "总战斗场数 ：" << this->GetTotalFightTimes() << endl;
	cout << "战斗失败场数 ：" << this->GetFailFightTimes() << "\n" << endl;
}

void Character::LevelUp(int lv)
{
	this->SetLevel(lv);
	int pointTemp = 3;
	string pointSel;
	cout << "角色升级了！获得新的3点点数可以分到当前属性上：(Role upgraded! Get the new 3 points can be assigned to the current property)" << "\n" << endl;
	while (pointTemp != 0)
	{
		cout << "\n1.目前STR :(Current STR) " << this->GetStr() << endl;
		cout << "2.目前DEX : (Current DEX)" << this->GetDex() << endl;
		cout << "3.目前CON : (Current CON)" << this->GetCon() << endl;
		cout << "目前剩余点数 : (Current remaining points)" << pointTemp << endl;
		cout << "请选择欲增加之属性 : (Please choose to increase the attributes)";
		getline(cin, pointSel);
		pointTemp--;

		if (pointSel.compare("1") == 0)
		{
			this->SetStr(this->GetStr() + 1);
		}
		else if (pointSel.compare("2") == 0)
		{
			this->SetDex(this->GetDex() + 1);
		}
		else if (pointSel.compare("3") == 0)
		{
			this->SetCon(this->GetCon() + 1);
		}
		else
		{
			cout << "指令错误，请重新输入。(Invalid input, please input again.)" << endl;
			pointTemp++;
			continue;
		}
	}
	cout << "\n配点完成！(Done!)" << this->GetName() << "目前的等级达到(level reach to)" << lv << "。" << endl;
	this->GetInformation();
}