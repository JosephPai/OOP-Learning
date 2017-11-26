#include <iostream>
#include <string>
#include "Document.h"
#include "Email.h"
#include "File.h"

using namespace std;

bool ContainsKeyword(const Document& docObject, string keyword)
{
    if (docObject.GetText().find(keyword) != string::npos)
        return true;

    return false;
}

int main()
{
    Email em1("bai","sasa","title","I'm learing c++"), em2("Tom", "Jack", "Machine", "how are you");
    File f1("root","this is the root dir"), f2("son", "this is the son dir of the root");
    cout << "1." << ContainsKeyword(em1, "c++") << endl;
    cout << "2." << ContainsKeyword(em2, "c++") << endl;
    cout << "3." << ContainsKeyword(f1, "hei") << endl;
    cout << "4." << ContainsKeyword(f2, "son") << endl;
    return 0;
}

