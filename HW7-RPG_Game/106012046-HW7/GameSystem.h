#pragma once
#ifndef GAMESYS_H
#define GAMESYS_H
#include <vector>
#include "Character.h"
#include "Job.h"
class GameSystem
{
public:
    GameSystem();
    void Start();
    int PrintMenu();
    bool Create();
    void Fight();
    void List();
    void DeleteCharacter();
    void NewJob();
    void DeleteJob();
    void ListJobs();
    ~GameSystem();

private:
    vector<Character> _charactersList;
    vector<Character> _monsterList;
    vector<Job> _jobList;
};

#endif

