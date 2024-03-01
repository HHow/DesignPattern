#include "../Activity.h"
#include "../Facade.h"

std::string CActUser::GetUserName()
{
	return stUserName;
}

void CActUser::ReceiveMessage(std::string _message)
{
	std::cout << _message << std::endl;
}

void CActUser::PlusKillCount()
{
	KillUserCount++;
}

void CActUser::Update()
{
	if (KillUserCount >= 5 && KillUserCount < 10)
		stTitle = "�л���";
	else if (KillUserCount >= 10)
		stTitle = "�Ǹ�";
}


bool CSwearExpression::CheckWord(std::string _strInputWord)
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


bool CPrivacyExpression::CheckWord(std::string _strInputWord)
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



CChatMetiator::~CChatMetiator()
{
	for (CFacade* User : vtUsers)
		delete User;
}

void CChatMetiator::AddClient(CFacade* _CFacade)
{
	vtUsers.push_back(_CFacade);
}
void CChatMetiator::Chating(CFacade* _User, std::string _message)
{
	for (int i = 0; i < vtUsers.size(); i++)
	{
		if (_User->GetActUser()->GetUserName() != vtUsers[i]->GetActUser()->GetUserName())
		{
			std::string strUsername = _User->GetActUser()->GetUserName();
			std::string strUserSendMessage = _User->DoingChat(_message);
			vtUsers[i]->GetActUser()->ReceiveMessage(strUsername + "�� : " + strUserSendMessage);
		}
	}
}


void CSubject::AddObserver(CFacade* _CFacade)
{
	vtUsers.push_back(_CFacade);
}
void CSubject::DeleteObserver(CFacade* _CFacade)
{
	int vtUserSize = vtUsers.size();
	for (int i = 0; i < vtUserSize; i++)
	{
		std::vector<CFacade*>::iterator iter = vtUsers.begin();
		if (vtUsers[i]->GetActUser()->GetUserName() == _CFacade->GetActUser()->GetUserName())
		{
			vtUsers.erase(iter + i);
			break;
		}
	}
}

void CSubject::Notify()
{
	int vtUserSize = vtUsers.size();
	for (int i = 0; i < vtUserSize; i++)
	{
		vtUsers[i]->GetActUser()->Update();
	}
}


void CStatusSubject::StatusUpdating()
{
	// �ʴ���
	//int StartTime = timeGetTime() / 1000;
	// while (1)
	// {
	// 	// ���ӽð� 10000��
	// 	if (timeGetTime() / 1000 - StartTime >= 10000)
	// 		break;
	// 	Notify();
	// 	// 1�� sleep
	// 	Sleep(1000);
	// }
}