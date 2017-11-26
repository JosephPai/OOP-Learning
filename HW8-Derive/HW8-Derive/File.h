#ifndef FILE_h
#define FILE_H
#include "Document.h"

using namespace std;

class File :
    public Document
{
public:
    File();
    File(string pathName, string text);
    void SetPathName(string pathname);
    string GetPathName();
    ~File();
    void operator= (File const &rhs);

private:
    string _pathName;
};
#endif

