#pragma once
#ifndef GAMESYS_H
#define GAMESYS_H
#include <vector>
#include "Character.h"
class GameSystem
{
public:
	GameSystem();
	void Start();
	int PrintMenu();
	bool Create();
	void Fight();
	void List();
	void Delete();
	~GameSystem();

private:
	vector<Character> _charactersList;
	vector<Character> _monsterList;
};

#endif

