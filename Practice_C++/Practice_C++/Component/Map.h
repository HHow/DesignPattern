#ifndef _HEADER_MAP_H_
#define _HEADER_MAP_H_

#include <iostream>
#include <list>
#include <unordered_map>
#include "../Type/type.h"

namespace Map
{
class Component
{
public:
	Component():m_pParentComponent(nullptr) {}
	virtual ~Component(){}
	void SetParent(Component* _pComponent);
	Component* GetComponent() const;
	virtual void AddComponent(Component* _pComponent) {}
	virtual void RemoveComponent(Component* _pComponent) {}
	virtual bool IsComposite() const
	{
		return false;
	}

	virtual void Realize() = 0;

	bool operator == (const Component& _pComponent)
	{
		return this == &_pComponent;
	}
protected:
	Component* m_pParentComponent;
};

class Mountain : public Component
{
public:
	virtual void Realize();
};

class Rock : public Component
{
public:
	virtual void Realize();
};

class MapComposite: public Component
{
public:
	virtual void AddComponent(Component* _pComponent) override;
	virtual void RemoveComponent(Component* _pComponent) override; 

	virtual bool IsComposite() const
	{
		return true;
	}

	virtual void Realize() override;

protected:
	std::list<Component*> ltChildComponent;
};

class MapDecorator: public Component
{
public:
	MapDecorator(Component* _pComponent)
	:pComponent(_pComponent)
	{	
	}

	virtual void Realize() override
	{
		this->pComponent->Realize();
	}

protected:
	Component *pComponent;
};

class ConcreteMapDecorator : public MapDecorator
{
public:
	ConcreteMapDecorator(Component* _pComponent)
	:MapDecorator(_pComponent)
	{
	}

	virtual void Realize() override
	{
		MapDecorator::Realize();
		std::cout<<"Concreate deco"<<std::endl;
	}
};

class MapProtoType
{
public:
	MapProtoType() {}
	MapProtoType(std::string _strName)
	:m_strName(_strName) {}
	virtual ~MapProtoType() {}
	virtual MapProtoType* Clone() const = 0;

private:
	std::string m_strName;
};

class ConcreteMapProtoType1 : public MapProtoType
{
public:
	ConcreteMapProtoType1() {}
	ConcreteMapProtoType1(std::string _strName)
	:MapProtoType(_strName) {}

	MapProtoType *Clone() const override
	{
		return new ConcreteMapProtoType1(*this);
	}
};

class ConcreteMapProtoType2 : public MapProtoType
{
public:
	ConcreteMapProtoType2() {}
	ConcreteMapProtoType2(std::string _strName)
	:MapProtoType(_strName) {}

	MapProtoType *Clone() const override
	{
		return new ConcreteMapProtoType2(*this);
	}
};

class MapProtoTypeFactory
{
private:
	std::unordered_map<eMapProtoType, MapProtoType*, std::hash<int> > m_mapProtoType;

public:
MapProtoTypeFactory()
{
	m_mapProtoType[eMapProto_Type1] = new ConcreteMapProtoType1("ProtoType1");
	m_mapProtoType[eMapProto_Type2] = new ConcreteMapProtoType2("ProtoType2");
}

~MapProtoTypeFactory()
{
	delete m_mapProtoType[eMapProto_Type1];
	delete m_mapProtoType[eMapProto_Type2];
}

MapProtoType* CreateMapProtoType(eMapProtoType _eMapProtoType)
{
	return m_mapProtoType[_eMapProtoType]->Clone();
}
};

}

#endif
/*
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
*/

