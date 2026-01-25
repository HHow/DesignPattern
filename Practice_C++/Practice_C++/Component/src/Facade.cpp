#include "../Facade.h"
#include "../Activity.h"
#include "../../Factory/Factory.h"
#include "../Map.h"
//#include "../Component.h"

Creator* Creator::creator = NULL;


CFacade::CFacade(std::string _strUserName, std::string _strType)
{
	ActingUser = new CActUser(_strUserName);
	TribeCreator::MakeTribe(_strType);
	MyTribe = Creator::MakeTribe(_strType);
	vtActList.push_back(new CSwearExpression());
	vtActList.push_back(new CPrivacyExpression());
}
CFacade::~CFacade()
{
	if (MyTribe)
		delete MyTribe;
	if (ActingUser)
		delete ActingUser;

	for (CAbstractExpression* Expression : vtActList)
		delete Expression;
}
void CFacade::AddComponent(CComponent* _component)
{
	CompositeMap->AddComponent(_component);
}
void CFacade::Draw()
{
	CompositeMap->Draw();
}

std::string CFacade::DoingChat(std::string _strInputWord)
{
	for (int i = 0; i < vtActList.size(); i++)
	{
		if (false == vtActList[i]->CheckWord(_strInputWord))
		{
			return _strInputWord;
		}
	}
	return _strInputWord;
}

CActUser* CFacade::GetActUser()
{
	return ActingUser;
}
Tribe* CFacade::GetTribe()
{
	return MyTribe;
}
