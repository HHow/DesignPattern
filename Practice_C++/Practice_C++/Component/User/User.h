#ifndef _HEADER_USER_H_
#define _HEADER_USER_H_

#include <iostream>
#include <string>

class CUser
{
public:
	CUser(std::string _stUserName) : stUserName(_stUserName)
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

#endif