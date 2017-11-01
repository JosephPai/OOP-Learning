#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;
class Character
{
public:
	Character();
	Character(string name, int str, int dex, int con);
	string getName();
	void setName(string name);
	int getLevel();
	void setLevel(int levle);
	int getStr();
	void setStr(int str);
	int getDex();
	void setDex(int dex);
	int getCon();
	void setCon(int con);
	int getExp();
	void setExp(int exp);
	int getTotalFightTimes();
	void setTotalFightTimes(int times);
	int getFailFightTimes();
	void setFailFightTimes(int time);
	bool Fight(Character &monster);
	void getInformation();

private:
	string _name;
	int _level;
	int _str;
	int _dex;
	int _con;
	int _exp;
	int _totalFightTimes;
	int _failFighttTimes;
};
#endif
