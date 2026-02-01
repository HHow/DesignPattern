#ifndef _HEADER_FACADE_H_
#define _HEADER_FACADE_H_

#include <iostream>
#include <vector>

class CActUser;
class CAbstractExpression;
class CActuser;
class Tribe;
class CComponent;
class MapConposite;

class CFacade
{
public:
	CFacade(std::string _strUserName, std::string _strType);
	~CFacade();
	void AddComponent(CComponent* _component);
	void Draw();

	std::string DoingChat(std::string _strInputWord);

	CActUser* GetActUser();
	Tribe* GetTribe();
private:
	Tribe* MyTribe = NULL;
	MapConposite* m_pCMapComposite;
	CActUser* ActingUser = NULL;
	std::vector<CAbstractExpression*> vtActList;
};

#endif