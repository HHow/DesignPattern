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
	// ä�� ������ factory�� �ϸ� ������
	CMetiator* ChatMetiator = new CChatMetiator();

	CSubject* StatusSubject = new CStatusSubject();

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
		StatusSubject->AddObserver(userFacade);
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
	// ���� ���� ��� ������Ʈ
	std::thread th(StatusSubject->StatusUpdating, "StatusUpdate");

	// �߾�� �ѹ����� �ο�
	for (int i = 0; i < 4; i++)
	{
		ChatMetiator->Chating(vtUser[i], "���� �ٺ���");
	}


	while (1)
	{
		// ���Ӱ���

	}


	th.join();
	delete LoadMapProxy;
	return 0;
}