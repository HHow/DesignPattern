#ifndef _HEADER_MAP_H_
#define _HEADER_MAP_H_

#include <iostream>
#include <memory>
#include <list>
#include "../Type/type.h"

class CMapComponent
{
public:
	virtual ~CMapComponent() = default;
	virtual void add(std::unique_ptr<CMapComponent> _pCMapComponent)
	{
		(void)_pCMapComponent;
	}
	virtual void remove(CMapComponent* _pCMapComponent)
	{
		(void)_pCMapComponent;
	}
	virtual void display() {}
};

class CMapComposite : public CMapComponent
{
public:
	virtual ~CMapComposite() = default;
	virtual void add(std::unique_ptr<CMapComponent> _pCMapComponent) override
	{
		ltComponent.push_back(std::move(_pCMapComponent));
	}
	virtual void remove(CMapComponent* _pCMapComponent) override
	{
		if (nullptr == _pCMapComponent)
		{
			return;
		}

		for (auto it = ltComponent.begin(); it != ltComponent.end(); ++it)
		{
			if (it->get() == _pCMapComponent)
			{
				ltComponent.erase(it);
				return;
			}
		}
	}
	virtual void display() override
	{
		for (auto it = ltComponent.begin(); it != ltComponent.end(); it++)
		{
			it->get()->display();
		}
	}

private:
	std::list<std::unique_ptr<CMapComponent>> ltComponent;
};

class CMapComponentLand : public CMapComponent
{
public:
	virtual ~CMapComponentLand() = default;
	virtual void display() override
	{
		std::cout << "draw Land" << std::endl;
	}
};


class CMapComponentWater : public CMapComponent
{
public:
	virtual ~CMapComponentWater() = default;
	virtual void display() override
	{
		std::cout << "draw Water" << std::endl;
	}
};

class CMapDecorator : public CMapComponent
{
public:
	CMapDecorator(std::unique_ptr<CMapComponent> _pCMapComponent)
		:pInner(std::move(_pCMapComponent))
	{}

	virtual void display() override
	{
		pInner->display();
	}

private:
	std::unique_ptr<CMapComponent> pInner;
};

class CMapDecoratorBlingBling : public CMapDecorator
{
public:
	CMapDecoratorBlingBling(std::unique_ptr<CMapComponent> _pCMapComponent)
		:CMapDecorator(std::move(_pCMapComponent))
	{}
	virtual void display() override
	{
		CMapDecorator::display();
		std::cout << "Decorate BlingBling" << std::endl;
	}
};

class CMapDecoratorFadeOut : public CMapDecorator
{
public:
	CMapDecoratorFadeOut(std::unique_ptr<CMapComponent> _pCMapComponent)
		:CMapDecorator(std::move(_pCMapComponent))
	{}
	virtual void display() override
	{
		CMapDecorator::display();
		std::cout << "Decorate FadeOut" << std::endl;
	}
};

#endif