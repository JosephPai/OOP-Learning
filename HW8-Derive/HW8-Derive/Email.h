#ifndef EMAIL_H
#define EMAIL_H
#include "Document.h"

using namespace std;

class Email: 
	public Document
{
public:
    Email();
    Email(string sender, string recipient, string title, string text);
    void SetSender(string sender);
    void SetRecipient(string recipient);
    void SetTitle(string title);
    string GetSender();
    string GetRecipient();
    string GetTitle();
    ~Email();
    void operator= (Email const &rhs);

private:
    string _sender;
    string _recipient;
    string _title;
};
#endif
