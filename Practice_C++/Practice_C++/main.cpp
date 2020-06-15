#pragma once
#include <iostream>
#include <string>
#include "Factory/Factory.h"
#include "Component/Component.h"
#include "Component/Map.h"

int main(void)
{
	Tribe* MyTribe = NULL;

	std::string input;
	// make unit
	while (1)
	{
		std::cout << "Input 'Terran' or 'Protoss'";
		std::cin >> input;
		MyTribe = Creator::MakeTribe(input);

		if (MyTribe)
		{
			/**/


		}

	}

	// make map
	CComponent* pRockComponent = new CCircleDecorator(new CTriangleDecorator(new CDecorator(new CRock())));
	CComponent* pMountainComponent = new CTriangleDecorator(new CCircleDecorator(new CDecorator(new CMountain())));

	CCompositeForm CompositeMap;
	CompositeMap.AddComponent(pRockComponent);
	CompositeMap.AddComponent(pMountainComponent);
	CompositeMap.Draw();

	delete MyTribe;

	return 0;
}
