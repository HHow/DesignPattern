#ifndef _HEADER_CHATMANAGER_H_
#define _HEADER_CHATMANAGER_H_

#include <iostream>

class CCheckChatMessage
{
public:
	virtual bool CheckWord(std::string _strInputWord) = 0;
};

class CCheckChatMessageSwear : public CCheckChatMessage
{
public:
	virtual bool CheckWord(std::string _strInputWord);
};

class CCheckChatMessagePrivacy : public CCheckChatMessage
{
public:
	virtual bool CheckWord(std::string _strInputWord);
};

class CMetiator
{
public:
	virtual ~CMetiator() {}
	virtual void AddClient(CFacade* _CFacade) = 0;
	virtual void Chating(CFacade* _User, std::string _message) = 0;
};

class CChatMetiator : public CMetiator
{
public:
	virtual ~CChatMetiator();

	virtual void AddClient(CFacade* _CFacade);
	virtual void Chating(CFacade* _User, std::string _message);

private:
	std::vector<CFacade*> vtUsers;
};

class CSubject
{
public:
	CSubject() {}
	~CSubject() {}
	void AddObserver(CFacade* _CFacade);
	void DeleteObserver(CFacade* _CFacade);

	virtual void StatusUpdating() = 0;

protected:
	void Notify();

private:
	std::vector<CFacade*> vtUsers;
};

class CStatusSubject : public CSubject
{
public:
	CStatusSubject() {}
	~CStatusSubject() {}

	virtual void StatusUpdating();
};

#endif