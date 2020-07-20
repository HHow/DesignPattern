#pragma once
#include "../Component/Component.h"

class Tribe
{
public:
	Tribe()
	{
		std::cout << "Basic Factory" << std::endl;
	}
	~Tribe()
	{
		std::cout<<"~Basic Factory" << std::endl;
	}
	virtual Unit* MakeUnit() const
	{
		std::cout << "Basic Factory MakeUnit" << std::endl;
		return new Unit;
	}

	virtual Building* MakeBuilding() const
	{
		std::cout << "Basic Factory MakeBuilding" << std::endl;
		return new Building;
	}
};

class Terran : public Tribe
{
public:
	Terran()
	{
		std::cout << "Terran Factory" << std::endl;
	}
	~Terran()
	{
		std::cout << "~Terran Factory" << std::endl;
	}
	virtual Unit* MakeUnit() const
	{
		std::cout << "Terran Factory MakeUnit" << std::endl;
		return new TerranUnit;
	}
	virtual Building* MakeBuilding() const
	{
		std::cout << "Terran Factory MakeBuilding" << std::endl;
		return new TerranBuilding;
	}
};

class Protoss : public Tribe
{
public:
	Protoss()
	{
		std::cout << "Protoss Factory" << std::endl;
	}
	~Protoss()
	{
		std::cout << "~Protoss Factory" << std::endl;
	}
	virtual Unit* MakeUnit() const
	{
		std::cout << "Protoss Factory MakeUnit" << std::endl;
		return new ProtossUnit;
	}
	virtual Building* MakeBuilding() const
	{
		std::cout << "Protoss Factory MakeBuilding" << std::endl;
		return new ProtossBuilding;
	}
};

class Creator
{
private:
	static Creator* creator;

	static void MakeCreator()
	{
		std::cout << "make Creator" << std::endl;
		creator = new Creator;
	}

public:
	static Tribe* MakeTribe(std::string _sType)
	{
		if (!creator)
			MakeCreator();

		if (_sType == "Terran")
			return new Terran;
		else if (_sType == "Protoss")
			return new Protoss;
		else
		{
			std::cout << "make nothing" << std::endl;
			return NULL;
		}
	}
};