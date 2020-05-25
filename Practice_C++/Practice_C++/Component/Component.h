#pragma once
#include <string>

enum eStaminaType
{
	eNone = 0,
	eBlood,
	eShield,
	eReroll
};

class CombineUnit
{
public:
	int iCombineCount;

public:
	CombineUnit() {}
	int PlusStamina(int _stamina)
	{
		return 2 * _stamina;
	}

	void CombineGenerateBody()
	{
		std::cout << "combine unit body" << std::endl;

	}
};

class Unit
{
public:
	std::string sUnitName;
	eStaminaType StaminaType;
	int iStamina;
public:
	Unit() {}
	Unit(std::string _sUnitName, eStaminaType _StaminaType)
	{
		std::cout << "make unit" << std::endl;
		this->sUnitName = _sUnitName;
		this->StaminaType = _StaminaType;
	}

	virtual void GenerateBody()
	{
		return;
	}
};

class TerranUnit : public Unit, public CombineUnit
{
public:
	TerranUnit() {}
	TerranUnit(std::string _sUnitName, eStaminaType _StaminaType, int _iStamina)
	{
		std::cout << "make Terran unit" << std::endl;
		this->sUnitName = _sUnitName;
		this->StaminaType = _StaminaType;
		this->iStamina = _iStamina;
	}
	TerranUnit(std::string _sUnitName, eStaminaType _StaminaType, int _iStamina, bool _bCheckCombine)
	{
		std::cout << "make Terran Combine unit" << std::endl;
		this->sUnitName = _sUnitName;
		this->StaminaType = _StaminaType;
		if (_bCheckCombine)
			this->iStamina = PlusStamina(_iStamina);
		else
			this->iStamina = _iStamina;
	}
	virtual void GenerateBody()
	{
		StaminaType = eBlood;
		CombineGenerateBody();
	}
};

class ProtossUnit : public Unit
{
public:
	virtual void GenerateBody()
	{
		StaminaType = eShield;
	}
};

class ZergUnit : public Unit
{
public:
	virtual void GenerateBody()
	{
		StaminaType = eReroll;
	}
};

class Building
{

};

class TerranBuilding : public Building
{

};

class ProtossBuilding : public Building
{

};

class ZergBuilding : public Building
{

};