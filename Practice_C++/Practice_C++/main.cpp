#pragma once
#include <iostream>
#include <string>
#include "Factory/Factory.h"
#include "Component/Component.h"
#include "Component/Map.h"
#include "Component/Activity.h"

int main(void)
{
	// ä�� ������ factory�� �ϸ� ������
	CMetiator* ChatMetiator = new CChatMetiator();

	// Load basic map
	CLoad* LoadMapProxy = new CLoadMapProxy();
	std::vector<CFacade*> vtUser;
	// 4�ο� ����
	for(int i=0;i<4;i++)
	{
		std::string UserName, InputTribe;
		std::cout << "Input your name" << std::endl;
		std::cin >> UserName;
		std::cout << "Input 'Terran' or 'Protoss'" << std::endl;
		std::cin >> InputTribe;
		CFacade* userFacade = new CFacade(UserName, InputTribe);
		vtUser.push_back(userFacade);
		ChatMetiator->AddClient(userFacade);
	}

	// �⺻ �� ����
	LoadMapProxy->DrawBasicMap();

	// ������ �⺻����
	for(int i=0; i<4; i++)
	{
		if (vtUser[i]->GetTribe())
		{
			Unit *unit = vtUser[i]->GetTribe()->MakeUnit();

			// ���� ����
		}
		else
			continue;

		// make map
		CComponent* pRockComponent = new CCircleDecorator(new CTriangleDecorator(new CDecorator(new CRock())));
		CComponent* pMountainComponent = new CTriangleDecorator(new CCircleDecorator(new CDecorator(new CMountain())));

		vtUser[i]->AddComponent(pRockComponent);
		vtUser[i]->AddComponent(pMountainComponent);
		vtUser[i]->Draw();
	}

	// �߾�� �ѹ����� �ο�
	for (int i = 0; i < 4; i++)
	{
		ChatMetiator->Chating(vtUser[i], "���� �ٺ���");
	}

	delete LoadMapProxy;
	return 0;
}

class CFacade
{
public:
	CFacade(std::string _strUserName, std::string _strType)
	{
		ActingUser = new CActUser(_strUserName);
		MyTribe = Creator::MakeTribe(_strType);
		vtActList.push_back(new CSwearExpression());
		vtActList.push_back(new CPrivacyExpression());
	}
	~CFacade()
	{
		if (MyTribe)
			delete MyTribe;
		if (ActingUser)
			delete ActingUser;

		for (CAbstractExpression* Expression : vtActList)
			delete Expression;
	}
	void AddComponent(CComponent* _component)
	{
		CompositeMap.AddComponent(_component);
	}
	void Draw()
	{
		CompositeMap.Draw();
	}

	std::string DoingChat(std::string _strInputWord)
	{
		for (int i = 0; i < vtActList.size(); i++)
		{
			if (false == vtActList[i]->CheckWord(_strInputWord))
			{
				return;
			}
		}
		return _strInputWord;
	}

	CActUser* GetActUser()
	{
		return ActingUser;
	}
	Tribe* GetTribe()
	{
		return MyTribe;
	}
private:
	Tribe* MyTribe = NULL;
	CCompositeForm CompositeMap;
	CActUser* ActingUser = NULL;
	std::vector<CAbstractExpression*> vtActList;
};