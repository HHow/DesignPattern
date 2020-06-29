#pragma once
#include <iostream>
#include <string>
#include "Factory/Factory.h"
#include "Component/Component.h"
#include "Component/Map.h"
#include "Component/Activity.h"

int main(void)
{
	// Load basic map
	CLoad* LoadMapProxy = new CLoadMapProxy();
	
	std::string UserName, InputTribe;
	// make unit
	while (1)
	{
		std::cout << "Input your name" << std::endl;
		std::cin >> UserName;
		std::cout << "Input 'Terran' or 'Protoss'" << std::endl;
		std::cin >> InputTribe;
		CFacade userFacade(UserName, InputTribe);
		LoadMapProxy->DrawBasicMap();
		if (userFacade.MyTribe)
		{
			Unit *unit = userFacade.MyTribe->MakeUnit();


		}
		else
			continue;

		// make map
		CComponent* pRockComponent = new CCircleDecorator(new CTriangleDecorator(new CDecorator(new CRock())));
		CComponent* pMountainComponent = new CTriangleDecorator(new CCircleDecorator(new CDecorator(new CMountain())));

		userFacade.AddComponent(pRockComponent);
		userFacade.AddComponent(pMountainComponent);
		userFacade.Draw();

		userFacade.DoingChat("너 정말 바보같이 못하구나");
		userFacade.DoingChat("너 주소 어디야");
		userFacade.DoingChat("좋은 게임이였습니다^^");

		delete LoadMapProxy;
	}
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

	void DoingChat(std::string _strInputWord)
	{
		for (int i = 0; i < vtActList.size(); i++)
		{
			if (false == vtActList[i]->CheckWord(_strInputWord))
			{
				return;
			}
		}
		std::cout << _strInputWord << std::endl;
	}

	Tribe* MyTribe = NULL;
	CCompositeForm CompositeMap;
	CActUser* ActingUser = NULL;
	std::vector<CAbstractExpression*> vtActList;
};