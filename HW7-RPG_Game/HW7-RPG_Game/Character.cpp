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
	return true;	// ��ʱд��Ϊ�˱���
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

