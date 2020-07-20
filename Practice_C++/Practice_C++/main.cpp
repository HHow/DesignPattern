#pragma once
#include <iostream>
#include <string>
#include <thread>
#include "Factory/Factory.h"
#include "Component/Component.h"
#include "Component/Map.h"
#include "Component/Activity.h"
#include "Component/Facade.h"

int main(void)
{
	// 채팅 관리용 factory로 하면 좋을듯
	CMetiator* ChatMetiator = new CChatMetiator();

	CSubject* StatusSubject = new CStatusSubject();

	// Load basic map
	CLoad* LoadMapProxy = new CLoadMapProxy();
	std::vector<CFacade*> vtUser;
	// 4인용 게임
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
		StatusSubject->AddObserver(userFacade);
	}

	// 기본 맵 생성
	LoadMapProxy->DrawBasicMap();

	// 유저들 기본세팅
	for(int i=0; i<4; i++)
	{
		if (vtUser[i]->GetTribe())
		{
			Unit *unit = vtUser[i]->GetTribe()->MakeUnit();

			// 유닛 생성
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
	// 유저 상태 계속 업데이트
	std::thread th(StatusSubject->StatusUpdating, "StatusUpdate");

	// 발언권 한번씩만 부여
	for (int i = 0; i < 4; i++)
	{
		ChatMetiator->Chating(vtUser[i], "너흰 바보야");
	}


	while (1)
	{
		// 게임공간

	}


	th.join();
	delete LoadMapProxy;
	return 0;
}