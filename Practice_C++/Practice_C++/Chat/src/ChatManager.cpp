#include "../ChatManager.h"

bool CCheckChatMessageSwear::CheckWord(std::string _strInputWord)
{
	if (_strInputWord.find("die") >= 0)
		std::cout << "dont chat swear" << std::endl;
	else if (_strInputWord.find("fuck") >= 0)
		std::cout << "dont chat swear" << std::endl;
	else if (_strInputWord.find("go to hell") >= 0)
		std::cout << "dont chat swear" << std::endl;
	else
		return true;
	return false;
}


bool CCheckChatMessagePrivacy::CheckWord(std::string _strInputWord)
{
	if (_strInputWord.find("name") >= 0)
		std::cout << "dont chat privacy info" << std::endl;
	else if (_strInputWord.find("addr") >= 0)
		std::cout << "dont chat privacy info" << std::endl;
	else if (_strInputWord.find("�tele") >= 0)
		std::cout << "dont chat privacy info" << std::endl;
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