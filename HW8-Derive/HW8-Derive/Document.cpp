#include "Document.h"

using namespace std;

Document::Document()
{
}

Document::Document(string text)
{
    this->_text = text;
}

void Document::SetText(string text)
{
    this->_text = text;
}

string Document::GetText() const
{
    return this->_text;
}

Document::~Document()
{
}

void Document::operator= (Document const &rhs)
{
    this->_text = rhs._text;
}
