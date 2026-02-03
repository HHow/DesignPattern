#ifndef _HEADER_FACTORY_UNIT_H_
#define _HEADER_FACTORY_UNIT_H_

#include "Factory.h"

class Unit;

class UnitFactory : public Factory<Unit>
{
public:
	UnitFactory() {}
	virtual ~UnitFactory() {}

	virtual void MakeUnit(const eUnitType _eUnitType) {}
};

class TerranUnitFactory : public UnitFactory
{
public:
	TerranUnitFactory() {}
	virtual ~TerranUnitFactory() {}

	virtual void MakeUnit(const eUnitType _eUnitType) override;
};

class ProtossUnitFactory : public UnitFactory
{
public:
	ProtossUnitFactory() {}
	virtual ~ProtossUnitFactory() {}
	
	virtual void MakeUnit(const eUnitType _eUnitType) override;
};

class ZergUnitFactory : public UnitFactory
{
public:
	ZergUnitFactory() {}
	virtual ~ZergUnitFactory() {}
	
	virtual void MakeUnit(const eUnitType _eUnitType) override;
};

// 팩토리 패턴
class UnitFactoryCreator
{
public:
	static UnitFactory* MakeUnitFactory(const eTribeType _eTribeType);
};

#endif