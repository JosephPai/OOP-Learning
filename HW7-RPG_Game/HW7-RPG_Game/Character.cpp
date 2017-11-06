#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

Character::Character()
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
	bool attackOrderFlag;
	hp1 = this->GetDex() * 3;
	hp2 = monster.GetDex() * 3;
	cout << "\n系统选择了[" << monster.GetName() << "]作为敌人。" << endl;
	cout << this->GetName() << "的DEX为" << this->GetDex() << ",";
	cout << monster.GetName() << "的DEX为" << monster.GetDex() << ",由";
	attackOrderFlag = this->GetDex() >= monster.GetDex();
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
				this->SetExp(monster.GetExp() + 100);
				return true;
			}
		}
		else
		{
			cout << monster.GetName() << "发动攻击！对"
				<< this->GetName() << "造成" << monster.GetStr() << "点伤害。" << endl;
			cout << this->GetName() << "的HP从" << hp1 << "变为";
			if (hp1 > monster.GetStr())
			{
				hp1 = hp1 - monster.GetStr();
				cout << hp1 << "\n" << endl;
				attackOrderFlag = true;
			}
			else
			{
				hp1 = 0;
				cout << hp1 << "\n" << endl;
				cout << this->GetName() << "倒下了！获胜的是 ：" << monster.GetName() << "\n" << endl;
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

