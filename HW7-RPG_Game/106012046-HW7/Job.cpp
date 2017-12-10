#include "Job.h"

Job::Job(string name, int extraStr, int extraDex, int extraCon)
{
    this->_name = name;
    this->_extraStr = extraStr;
    this->_extraDex = extraDex;
    this->_extraCon = extraCon;
}

string Job::GetName()
{
    return this->_name;
}

int Job::GetExtraStr()
{
    return this->_extraStr;
}

int Job::GetExtraDex()
{
    return this->_extraDex;
}

int Job::GetExtraCon()
{
    return this->_extraCon;
}
