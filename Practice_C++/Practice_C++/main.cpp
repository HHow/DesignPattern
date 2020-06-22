#pragma once
#include <iostream>
#include <string>
#include "Factory/Factory.h"
#include "Component/Component.h"
#include "Component/Map.h"

int main(void)
{
	// Load basic map
	CLoad* LoadMapProxy = new CLoadMapProxy();
	
	

	std::string input;
	// make unit
	while (1)
	{
		std::cout << "Input 'Terran' or 'Protoss'";
		std::cin >> input;
		CFacade userFacade(input);
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

		delete LoadMapProxy;
	}
	return 0;
}

class CFacade
{
public:
	CFacade(std::string _strType)
	{
		MyTribe = Creator::MakeTribe(_strType);
	}
	~CFacade()
	{
		if (MyTribe)
			delete MyTribe;
	}
	void AddComponent(CComponent* _component)
	{
		CompositeMap.AddComponent(_component);
	}
	void Draw()
	{
		CompositeMap.Draw();
	}

	Tribe* MyTribe = NULL;
	CCompositeForm CompositeMap;
};