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
		if (_strInputWord.find("��") >= 0)
			std::cout << "������ ��ȯ��� ���ؿ�" << std::endl;
		else if (_strInputWord.find("�ٺ�") >= 0)
			std::cout << "������ ��ȯ��� ���ؿ�" << std::endl;
		else if (_strInputWord.find("��û��") >= 0)
			std::cout << "������ ��ȯ��� ���ؿ�" << std::endl;
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
		if (_strInputWord.find("����") >= 0)
			std::cout << "������ ��ȯ��� ���������� ������ �ʾƿ�" << std::endl;
		else if (_strInputWord.find("��ȭ") >= 0)
			std::cout << "������ ��ȯ��� ���������� ������ �ʾƿ�" << std::endl;
		else if (_strInputWord.find("�ּ�") >= 0)
			std::cout << "������ ��ȯ��� ���������� ������ �ʾƿ�" << std::endl;
		else
			return true;
		return false;
	}
};