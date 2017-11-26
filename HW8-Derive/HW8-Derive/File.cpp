#include "File.h"

File::File()
{
}

File::File(string pathName, string text)
{
    this->_pathName = pathName;
    this->SetText(text);
}

void File::SetPathName(string pathname)
{
    this->_pathName = pathname;
}

string File::GetPathName()
{
    return this->_pathName;
}

File::~File()
{
}

void File::operator=(File const &rhs)
{
    this->_pathName = rhs._pathName;
}
