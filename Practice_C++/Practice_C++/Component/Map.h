#pragma once
#include <string>
#include <vector>
#include <iostream>

class CComponent
{
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

class CLoad {
public:
	virtual void DrawBasicMap() = 0;
};

class CLoadMap : public CLoad {
public:
	void DrawBasicMap()
	{
		std::cout << "Load map start" << std::endl;
	}
};

class CLoadMapProxy : public CLoad {
public:
	CLoadMapProxy() :LoadMap(NULL) {}
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
private:
	CLoadMap* LoadMap;
};
