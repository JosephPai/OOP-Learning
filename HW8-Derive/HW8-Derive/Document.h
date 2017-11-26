#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>

using namespace std;

class Document
{
public:
    Document();
    Document(string text);
    void SetText(string text);
    string GetText() const;
    ~Document();
    void operator= (Document const &rhs);

private:
    string _text;
};
#endif
