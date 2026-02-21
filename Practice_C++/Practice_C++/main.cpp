#include <iostream>
#include <string>
#include <thread>
#include "Factory/Factory.h"
#include "Component/MapProxy.h"

int main(void)
{
	CLoadMapProxy* LoadMapProxy = new CLoadMapProxy();

	// mapcomponent 담을 변수
	std::unique_ptr<CMapComposite> myMap = std::make_unique<CMapComposite>();

	std::unique_ptr<CMapComponentLand> Land = std::make_unique<CMapComponentLand>();
	std::unique_ptr<CMapComponentWater> Water = std::make_unique<CMapComponentWater>();
	
	std::unique_ptr<CMapDecoratorFadeOut> FadeLand = std::make_unique<CMapDecoratorFadeOut>(std::move(Land));
	std::unique_ptr<CMapDecoratorFadeOut> fadeWater = std::make_unique<CMapDecoratorFadeOut>(std::move(Water));

	LoadMapProxy->AddMapComponent(std::move(FadeLand));
	LoadMapProxy->AddMapComponent(std::move(fadeWater));
	
	LoadMapProxy->DisplayMap();

	/*
	std::cout<<"main"<<std::endl;
	
	CMetiator *ChatMetiator = new CChatMetiator();

	CSubject *StatusSubject = new CStatusSubject();

	// Load basic map
	CLoad *LoadMapProxy = new CLoadMapProxy();
	std::vector<CFacade *> vtUser;
	// 4�ο� ����
	for (int i = 0; i < 4; i++)
	{
		std::string UserName, InputTribe;
		std::cout << "Input your name" << std::endl;
		std::cin >> UserName;
		std::cout << "Input 'Terran' or 'Protoss'" << std::endl;
		std::cin >> InputTribe;
		CFacade *userFacade = new CFacade(UserName, InputTribe);
		vtUser.push_back(userFacade);
		ChatMetiator->AddClient(userFacade);
		StatusSubject->AddObserver(userFacade);
	}

	// �⺻ �� ����
	LoadMapProxy->DrawBasicMap();

	// ������ �⺻����
	for (int i = 0; i < 4; i++)
	{
		if (vtUser[i]->GetTribe())
		{
			Unit *unit = vtUser[i]->GetTribe()->MakeUnit();

			// ���� ����
		}
		else
			continue;

		// make map
		CComponent *pRockComponent = new CCircleDecorator(new CTriangleDecorator(new CDecorator(new CRock())));
		CComponent *pMountainComponent = new CTriangleDecorator(new CCircleDecorator(new CDecorator(new CMountain())));

		vtUser[i]->AddComponent(pRockComponent);
		vtUser[i]->AddComponent(pMountainComponent);
		vtUser[i]->Draw();
	}
	// ���� ���� ��� ������Ʈ
	//	std::thread threadStatus = std::thread{ &CSubject::StatusUpdating, &StatusSubject };
	//	std::thread threadStatus = std::thread(StatusSubject->StatusUpdating);
	//	std::thread threadStatus([&](CSubject* _StatusSubject) { _StatusSubject->StatusUpdating(); }, &StatusSubject);

	// �߾�� �ѹ����� �ο�
	for (int i = 0; i < 4; i++)
	{
		ChatMetiator->Chating(vtUser[i], "���� �ٺ���");
	}

	while (1)
	{
		// ���Ӱ���
	}

	//	threadStatus.join();
	delete LoadMapProxy;
	*/
	return 0;
}
