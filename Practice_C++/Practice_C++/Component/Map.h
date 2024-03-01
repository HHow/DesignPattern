#pragma once
#include <string>
#include <vector>
#include <iostream>


enum eMapState
{
	eMapState_Rest,
	eMapState_Burning,
	eMapState_Final
};

class CComponent
{
	public:
		CComponent(){};
		virtual ~CComponent(){};

	public:
		virtual void Draw() = 0;
};

class CMountain : public CComponent
{
public:
	void Draw()
	{
		std::cout << "make Mountain" << std::endl;
	}
};

class CRock : public CComponent
{
public:
	void Draw()
	{
		std::cout << "make Rock" << std::endl;
	}
};

class CCompositeForm : public CComponent
{
public:
	void Draw()
	{
		for (int i = 0; i < _components.size(); i++)
		{
			_components[i]->Draw();
		}
	}

	void AddComponent(CComponent* _component)
	{
		_components.push_back(_component);
	}

	void SubComponent()
	{
		_components.pop_back();
	}

private: 
	std::vector<CComponent*> _components;
};

class CDecorator : public CComponent
{
public:
	CDecorator(CComponent* _component) : pComponent(_component){}
	~CDecorator()
	{
		if (pComponent)
			delete pComponent;
	}
	virtual void Draw()
	{
		if (pComponent)
			pComponent->Draw();
	}

private:
	CComponent* pComponent;
};

class CTriangleDecorator : public CDecorator
{
public:
	CTriangleDecorator(CComponent* _component) : CDecorator(_component) {}
	
	virtual void Draw()
	{
		CDecorator::Draw();
		TriangleDraw();
	}

private:
	void TriangleDraw()
	{
		std::cout << "make Decorator Triangle" << std::endl;
	}
};

class CCircleDecorator : public CDecorator
{
public:
	CCircleDecorator(CComponent* _component) : CDecorator(_component) {}

	virtual void Draw()
	{
		CDecorator::Draw();
		CircleDraw();
	}

private:
	void CircleDraw()
	{
		std::cout << "make Decorator Circle" << std::endl;
	}
};

class CMapState
{
public:
	virtual void UpdateMap() = 0;
};


class CRestMap : public CMapState
{
public:
	virtual ~CRestMap() {};

	static CRestMap* GetMapStateInstance()
	{
		if (!MapStateInstance)
			MapStateInstance = new CRestMap();

		return MapStateInstance;
	}

	virtual void UpdateMap()
	{
		std::cout << "Let's Rest time~" << std::endl;
		//		SetMapState(_CLoadMap, CRestMap::GetMapStateInstance());
	}

private:
	static CRestMap* MapStateInstance;
};

class CBurningMap : public CMapState
{
public:
	virtual ~CBurningMap() {};

	static CBurningMap* GetMapStateInstance()
	{
		if (!MapStateInstance)
			MapStateInstance = new CBurningMap();

		return MapStateInstance;
	}

	virtual void UpdateMap()
	{
		std::cout << "Let's Burning time~" << std::endl;
		//		SetMapState(_CLoadMap, CBurningMap::GetMapStateInstance());
	}

private:
	static CBurningMap* MapStateInstance;
};

class CFinalMap : public CMapState
{
public:
	virtual ~CFinalMap() {};

	static CFinalMap* GetMapStateInstance()
	{
		if (!MapStateInstance)
			MapStateInstance = new CFinalMap();

		return MapStateInstance;
	}

	virtual void UpdateMap()
	{
		std::cout << "Let's Final time~" << std::endl;
		//		SetMapState(_CLoadMap, CBurningMap::GetMapStateInstance());
	}

private:
	static CFinalMap* MapStateInstance;
};

class CLoad {
public:
	virtual void DrawBasicMap() = 0;
};

class CLoadMap : public CLoad {
public:
	CLoadMap()
	{
		MapState = CRestMap::GetMapStateInstance();
	}
	void DrawBasicMap()
	{
		std::cout << "Load map start" << std::endl;
	}

	void SetMapState(eMapState _eMapState)
	{
		switch (_eMapState)
		{
		case eMapState_Rest:
			MapState = CRestMap::GetMapStateInstance();
		case eMapState_Burning:
			MapState = CBurningMap::GetMapStateInstance();
		case eMapState_Final:
			MapState = CFinalMap::GetMapStateInstance();
		default:
			break;
		}
	}

	void UpdateMap()
	{
		MapState->UpdateMap();
	}

private:
	CMapState* MapState;
};

class CLoadMapProxy : public CLoad {
public:
	CLoadMapProxy() :LoadMap(NULL){}
	~CLoadMapProxy() 
	{ 
		if (LoadMap) 
			delete LoadMap; 
	}

	void DrawBasicMap()
	{
		if (!LoadMap)
		{
			LoadMap = new CLoadMap;
			std::cout << "Load map~" << std::endl;
		}
		LoadMap->DrawBasicMap();
	}

	void DrawPlayMap()
	{
		LoadMap->UpdateMap();
	}

	void SetMapState(eMapState _eMapState)
	{
		LoadMap->SetMapState(_eMapState);
	}

private:
	CLoadMap* LoadMap;
};
