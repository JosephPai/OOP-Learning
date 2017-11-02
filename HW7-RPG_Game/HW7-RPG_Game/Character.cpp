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

string Character::getName()
{
	return this->_name;
}

void Character::setName(string name)
{
	this->_name = name;
}

int Character::getLevel()
{
	return this->_level;
}

void Character::setLevel(int level)
{
	this->_level = level;
}

int Character::getStr() 
{
	return this->_str;
}

void Character::setStr(int str)
{
	this->_str = str;
}

int Character::getDex()
{
	return this->_dex;
}

void Character::setDex(int dex)
{
	this->_dex = dex;
}

int Character::getCon()
{
	return this->_con;
}

void Character::setCon(int con)
{
	this->_con = con;
}

int Character::getExp()
{
	return this->_exp;
}

void Character::setExp(int exp)
{
	this->_exp = exp;
}

int Character::getTotalFightTimes()
{
	return this->_totalFightTimes;
}

void Character::setTotalFightTimes(int times)
{
	this->_totalFightTimes = times;
}

int Character::getFailFightTimes()
{
	return this->_failFighttTimes;
}

void Character::setFailFightTimes(int times)
{
	this->_failFighttTimes = times;
}

bool Character::Fight(Character &monster)
{
	int hp1, hp2;
	bool attackOrderFlag;
	hp1 = this->getDex() * 3;
	hp2 = monster.getDex() * 3;
	cout << "\n系统选择了[" << monster.getName() << "]作为敌人。" << endl;
	cout << this->getName() << "的DEX为" << this->getDex() << ",";
	cout << monster.getName() << "的DEX为" << monster.getDex() << ",由";
	attackOrderFlag = this->getDex() >= monster.getDex();
	cout << (attackOrderFlag ? this->getName() : monster.getName()) << "先进行攻击。\n" << endl;

	while (true)
	{
		if (attackOrderFlag)
		{
			cout << this->getName() << "发动攻击！对"
				<< monster.getName() << "造成" << this->getStr() << "点伤害。" << endl;
			cout << monster.getName() << "的HP从" << hp2 << "变为";
			if (hp2 > this->getStr())
			{
				hp2 = hp2 - this->getStr();
				cout << hp2 << "\n" << endl;
				attackOrderFlag = false;
			}
			else
			{
				hp2 = 0;
				cout << hp2 << "\n" << endl;
				cout << monster.getName() << "倒下了！获胜的是 ：" << this->getName() << endl;
				this->setTotalFightTimes(this->getTotalFightTimes() + 1);
				this->setExp(monster.getExp() + 100);
				return true;
			}
		}
		else
		{
			cout << monster.getName() << "发动攻击！对"
				<< this->getName() << "造成" << monster.getStr() << "点伤害。" << endl;
			cout << this->getName() << "的HP从" << hp1 << "变为";
			if (hp1 > monster.getStr())
			{
				hp1 = hp1 - monster.getStr();
				cout << hp1 << "\n" << endl;
				attackOrderFlag = true;
			}
			else
			{
				hp1 = 0;
				cout << hp1 << "\n" << endl;
				cout << this->getName() << "倒下了！获胜的是 ：" << monster.getName() << "\n" << endl;
				this->setTotalFightTimes(this->getTotalFightTimes() + 1);
				this->setFailFightTimes(this->getFailFightTimes() + 1);
				return false;
			}
		}
	}

}

void Character::getInformation()
{
	cout << "\n角色名称 ：" << this->getName() << endl;
	cout << "目前等级 ：" << this->getLevel() << endl;
	cout << "目前经验值 ：" << this->getExp() << endl;
	cout << "STR : " << this->getStr() << endl;
	cout << "DEX : " << this->getDex() << endl;
	cout << "CON : " << this->getCon() << endl;
	cout << "总战斗场数 ：" << this->getTotalFightTimes() << endl;
	cout << "战斗失败场数 ：" << this->getFailFightTimes() << "\n" << endl;
}

