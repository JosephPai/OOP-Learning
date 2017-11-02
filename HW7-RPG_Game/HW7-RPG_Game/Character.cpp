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
	cout << "\nϵͳѡ����[" << monster.getName() << "]��Ϊ���ˡ�" << endl;
	cout << this->getName() << "��DEXΪ" << this->getDex() << ",";
	cout << monster.getName() << "��DEXΪ" << monster.getDex() << ",��";
	attackOrderFlag = this->getDex() >= monster.getDex();
	cout << (attackOrderFlag ? this->getName() : monster.getName()) << "�Ƚ��й�����\n" << endl;

	while (true)
	{
		if (attackOrderFlag)
		{
			cout << this->getName() << "������������"
				<< monster.getName() << "���" << this->getStr() << "���˺���" << endl;
			cout << monster.getName() << "��HP��" << hp2 << "��Ϊ";
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
				cout << monster.getName() << "�����ˣ���ʤ���� ��" << this->getName() << endl;
				this->setTotalFightTimes(this->getTotalFightTimes() + 1);
				this->setExp(monster.getExp() + 100);
				return true;
			}
		}
		else
		{
			cout << monster.getName() << "������������"
				<< this->getName() << "���" << monster.getStr() << "���˺���" << endl;
			cout << this->getName() << "��HP��" << hp1 << "��Ϊ";
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
				cout << this->getName() << "�����ˣ���ʤ���� ��" << monster.getName() << "\n" << endl;
				this->setTotalFightTimes(this->getTotalFightTimes() + 1);
				this->setFailFightTimes(this->getFailFightTimes() + 1);
				return false;
			}
		}
	}

}

void Character::getInformation()
{
	cout << "\n��ɫ���� ��" << this->getName() << endl;
	cout << "Ŀǰ�ȼ� ��" << this->getLevel() << endl;
	cout << "Ŀǰ����ֵ ��" << this->getExp() << endl;
	cout << "STR : " << this->getStr() << endl;
	cout << "DEX : " << this->getDex() << endl;
	cout << "CON : " << this->getCon() << endl;
	cout << "��ս������ ��" << this->getTotalFightTimes() << endl;
	cout << "ս��ʧ�ܳ��� ��" << this->getFailFightTimes() << "\n" << endl;
}

