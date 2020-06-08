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

//동적모형 객체
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


