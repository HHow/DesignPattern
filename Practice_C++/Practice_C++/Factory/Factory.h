#ifndef _HEADER_FACTORY_H_
#define _HEADER_FACTORY_H_

#include <vector>
#include "../Type/type.h"

class Unit;

class Tribe
{
public:
	Tribe() {};
	virtual ~Tribe() {};

	virtual void MakeUnit(const eUnitType _eUnitType) = 0;

protected:
	void SetUnit(Unit* _Unit);

private:
	std::vector<Unit*> m_vtUnit;
};

class Terran : public Tribe
{
public:
	Terran();
	virtual ~Terran();

	virtual void MakeUnit(const eUnitType _eUnitType) override;
};

class Protoss : public Tribe
{
public:
	Protoss();
	virtual ~Protoss();
	
	virtual void MakeUnit(const eUnitType _eUnitType) override;
};

class Zerg : public Tribe
{
public:
	Zerg();
	virtual ~Zerg();
	
	virtual void MakeUnit(const eUnitType _eUnitType) override;
};

// 팩토리 패턴
class TribeCreator
{
public:
	static Tribe* MakeTribe(const eTribeType _eTribeType);
};

#endif