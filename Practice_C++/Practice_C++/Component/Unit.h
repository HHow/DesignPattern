#ifndef _HEADER_UNIT_H_
#define _HEADER_UNIT_H_

#include <iostream>
#include <string>
#include <vector>
#include "../Type/type.h"

class Unit
{
public:
	Unit() = delete;
	Unit(const Unit& _Unit) = default;
	Unit& operator=(const Unit& _Unit) = default;
	explicit Unit(const std::string &_strUnitName);
	virtual ~Unit() {};
	virtual void GenerateBody() = 0;

	void SetStaminaType(const eStaminaType _eStaminaType);
private:
	eStaminaType m_eStaminaType;
	std::string m_strUnitName;
};

class TerranUnit : public Unit
{
public:
	TerranUnit() = delete;
	TerranUnit(const std::string &_strUnitName);

	virtual void GenerateBody() override;
};

// adaptor 패턴
class InfestAdaptee
{
public:
	void InfestGenerateBody()
	{
		std::cout<<"Im Infest Terran"<<std::endl;
	}
};

class InfestTerranUnit : public TerranUnit
{
public:
	InfestTerranUnit(const std::string &_strUnitName, InfestAdaptee* _pInfestAdaptee = nullptr)
	:TerranUnit(_strUnitName), m_pInfestAdaptee(_pInfestAdaptee)
	{
	}
	~InfestTerranUnit()
	{
		delete m_pInfestAdaptee;
	}

	virtual void GenerateBody() override;

private:
	InfestAdaptee* m_pInfestAdaptee;
};

class ProtossUnit : public Unit
{
public:
	ProtossUnit() = delete;
	ProtossUnit(const std::string &_strUnitName);

	virtual void GenerateBody() override;
};

#endif