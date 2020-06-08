#pragma once
#include <iostream>
#include <string>
#include "Factory/Factory.h"
#include ""

int main(void)
{
	Tribe* MyTribe = NULL;

	std::string input;
	while (1)
	{
		std::cout << "Input 'Terran' or 'Protoss'";
		std::cin >> input;
		MyTribe = Creator::MakeTribe(input);

		if (MyTribe)
		{
			// 생성된 종족으로 유닛,건물 생성 수행
			UnitGroup* BossUnit = MyTribe->MakeUnit();
			UnitGroup* JYUnit = MyTribe->MakeUnit();
			UnitGroup* House = MyTribe->MakeUnit();

			BossUnit->AddUnion(JYUnit);
			House->AddUnion(BossUnit);



			delete MyTribe;
		}

	}
	return 0;
}
