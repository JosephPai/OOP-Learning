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
	string GetName();
	void GetName(string name);
	int GetLevel();
	void SetLevel(int levle);
	int GetStr();
	void SetStr(int str);
	int GetDex();
	void SetDex(int dex);
	int GetCon();
	void SetCon(int con);
	int GetExp();
	void SetExp(int exp);
	int GetTotalFightTimes();
	void SetTotalFightTimes(int times);
	int GetFailFightTimes();
	void SetFailFightTimes(int time);
	bool Fight(Character &monster);
	void GetInformation();

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
