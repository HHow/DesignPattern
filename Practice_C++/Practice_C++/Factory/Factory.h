#include "Component.h"


class Factory
{
public:
	Factory();

	virtual Unit* MakeUnit() const
	{
		return new Unit;
	}

	virtual Building* MakeBuilding() const
	{
		return new Building;
	}
};

class TerranFactory : public Factory
{
public:
	TerranFactory();

	virtual Unit* MakeUnit() const
	{
		return new TerranUnit;
	}
	virtual Building* MakeBuilding() const
	{
		return new TerranBuilding;
	}
};

class ProtossFactory : public Factory
{
public:
	ProtossFactory();

	virtual Unit* MakeUnit() const
	{
		return new ProtossUnit;
	}
	virtual Building* MakeBuilding() const
	{
		return new ProtossBuilding;
	}
};