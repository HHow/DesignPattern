#ifndef _HEADER_MAP_H_
#define _HEADER_MAP_H_

#include <iostream>
#include <memory>
#include <list>
#include "../Type/type.h"

class MapComponent
{
public:
	virtual ~MapComponent() = default;
	virtual void add(std::unique_ptr<MapComponent> _pMapComponent)
	{
		(void)_pMapComponent;
	}
	virtual void remove(MapComponent* _pMapComponent)
	{
		(void)_pMapComponent;
	}
	virtual void display() {}
};

class MapComposite : public MapComponent
{
public:
	virtual ~MapComposite() = default;
	virtual void add(std::unique_ptr<MapComponent> _pMapComponent) override
	{
		ltComponent.push_back(std::move(_pMapComponent));
	}
	virtual void remove(MapComponent* _pMapComponent) override
	{
		if (nullptr == _pMapComponent)
		{
			return;
		}

		for (auto it = ltComponent.begin(); it != ltComponent.end(); ++it)
		{
			if (it->get() == _pMapComponent)
			{
				ltComponent.erase(it);
				return;
			}
		}
	}
private:
	std::list<std::unique_ptr<MapComponent>> ltComponent;
};

class MapComponentLand : public MapComponent
{
public:
	virtual ~MapComponentLand() = default;
	virtual void display() override
	{
		std::cout << "draw Land" << std::endl;
	}
};


class MapComponentWater : public MapComponent
{
public:
	virtual ~MapComponentWater() = default;
	virtual void display() override
	{
		std::cout << "draw Water" << std::endl;
	}
};

class MapDecorator : public MapComponent
{
public:
	MapDecorator(std::unique_ptr<MapComponent> _pMapComponent)
	:pInner(std::move(_pMapComponent))
	{}

	virtual void display() override
	{
		pInner->display();
	}
	
private:
	std::unique_ptr<MapComponent> pInner;
};

class MapDecoratorBlingBling : public MapDecorator
{
public:
	virtual void display() override
	{
		MapDecorator::display();
		std::cout << "Decorate BlingBling" << std::endl;
	}
};

class MapDecoratorFadeOut : public MapDecorator
{
public:
	virtual void display() override
	{
		MapDecorator::display();
		std::cout << "Decorate FadeOut" << std::endl;
	}
};

/*
class MapProtoType
{
public:
	MapProtoType() {}
	MapProtoType(std::string _strName)
	:m_strName(_strName) {}S
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

#endif