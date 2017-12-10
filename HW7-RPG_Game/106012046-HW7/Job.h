#pragma once
#ifndef JOB_H
#define JOB_H
#include <string>
using namespace std;
class Job
{
public:
    Job(string name, int extraStr, int extraDex, int extraCon);
    string GetName();
    int GetExtraStr();
    int GetExtraDex();
    int GetExtraCon();
private:
    string _name;
    int _extraStr;
    int _extraDex;
    int _extraCon;
};
#endif

