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