#include "Email.h"

Email::Email()
{
}

Email::Email(string sender, string recipient, string title, string text)
{
    this->_sender = sender;
    this->_recipient = recipient;
    this->_title = title;
    SetText(text);
}

void Email::SetSender(string sender)
{
    this->_sender = sender;
}

void Email::SetRecipient(string recipient)
{
    this->_recipient = recipient;
}

void Email::SetTitle(string title)
{
    this->_title = title;
}

string Email::GetSender()
{
    return this->_sender;
}

string Email::GetRecipient()
{
    return this->_recipient;
}

string Email::GetTitle()
{
    return this->_title;
}

Email::~Email()
{
}

void Email::operator= (Email const &rhs)
{
    this->_sender = rhs._sender;
    this->_recipient = rhs._recipient;
    this->_title = rhs._title;
}
