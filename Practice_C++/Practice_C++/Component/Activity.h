#ifndef _HEADER_ACTIVITY_H_
#define _HEADER_ACTIVITY_H_

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <vector>
#include <string>

class CFacade;

class CActUser
{
public:
	CActUser(std::string _stUserName) : stUserName(_stUserName)
	{
		KillUserCount = 0;
		stTitle = std::string();
	}

	std::string GetUserName();
	void ReceiveMessage(std::string _message);
	void PlusKillCount();
	void Update();

private:
	std::string stUserName;
	std::string stTitle;
	int KillUserCount;

};

class CAbstractExpression
{
public:
	virtual bool CheckWord(std::string _strInputWord) = 0;
};

class CSwearExpression : public CAbstractExpression
{
public:
	virtual bool CheckWord(std::string _strInputWord);
};

class CPrivacyExpression : public CAbstractExpression
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