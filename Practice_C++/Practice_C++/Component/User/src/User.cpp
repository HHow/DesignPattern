#include "../User.h"

std::string CUser::GetUserName()
{
	return stUserName;
}

void CUser::ReceiveMessage(std::string _message)
{
	std::cout << _message << std::endl;
}

void CUser::PlusKillCount()
{
	KillUserCount++;
}

void CUser::Update()
{
	if (KillUserCount >= 5 && KillUserCount < 10)
		stTitle = "kill 5 ~ 10";
	else if (KillUserCount >= 10)
		stTitle = "kill over 10";
}