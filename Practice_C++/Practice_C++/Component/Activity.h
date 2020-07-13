#pragma once
#include <string>
#include <iostream>

class CActUser
{
public:
	CActUser(std::string _stUserName) : stUserName(_stUserName) {}

	std::string GetUserName()
	{
		return stUserName;
	}

	void ReceiveMessage(std::string _message)
	{
		std::cout << _message << std::endl;
	}

private:
	std::string stUserName;
};


class CAbstractExpression
{
public:
	virtual bool CheckWord(std::string _strInputWord) = 0;
};

class CSwearExpression : public CAbstractExpression
{
public:
	virtual bool CheckWord(std::string _strInputWord)
	{
		if (_strInputWord.find("ㅗ") >= 0)
			std::cout << "건전한 소환사는 착해요" << std::endl;
		else if (_strInputWord.find("바보") >= 0)
			std::cout << "건전한 소환사는 착해요" << std::endl;
		else if (_strInputWord.find("멍청이") >= 0)
			std::cout << "건전한 소환사는 착해요" << std::endl;
		else
			return true;
		return false;
	}
};

class CPrivacyExpression : public CAbstractExpression
{
public:
	virtual bool CheckWord(std::string _strInputWord)
	{
		if (_strInputWord.find("계좌") >= 0)
			std::cout << "건전한 소환사는 개인정보를 말하지 않아요" << std::endl;
		else if (_strInputWord.find("전화") >= 0)
			std::cout << "건전한 소환사는 개인정보를 말하지 않아요" << std::endl;
		else if (_strInputWord.find("주소") >= 0)
			std::cout << "건전한 소환사는 개인정보를 말하지 않아요" << std::endl;
		else
			return true;
		return false;
	}
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
	virtual ~CChatMetiator()
	{
		for (CFacade* User : vtUsers)
			delete User;
	}

public:
	virtual void AddClient(CFacade* _CFacade)
	{
		vtUsers.push_back(_CFacade);
	}
	virtual void Chating(CFacade* _User, std::string _message)
	{
		for (int i = 0; i < vtUsers.size(); i++)
		{
			if (_User->GetActUser()->GetUserName() != vtUsers[i]->GetActUser()->GetUserName())
			{
				std::string strUsername = _User->GetActUser()->GetUserName();
				std::string strUserSendMessage = _User->DoingChat(_message);
				vtUsers[i]->GetActUser()->ReceiveMessage(strUsername + "님 : " + strUserSendMessage);
			}
		}
	}

private:
	std::vector<CFacade*> vtUsers;
};

