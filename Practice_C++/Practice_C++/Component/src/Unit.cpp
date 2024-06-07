#include "../Unit.h"

Unit::Unit(const std::string& _strUnitName)
    :m_strUnitName(_strUnitName)
{
    std::cout << "Crate Unit " << _strUnitName << std::endl;
}

void Unit::SetStaminaType(const eStaminaType _eStaminaType)
{
    m_eStaminaType = _eStaminaType;
}

TerranUnit::TerranUnit(const std::string & _strUnitName)
: Unit(_strUnitName)
{
}

void TerranUnit::GenerateBody()
{
    SetStaminaType(eStamina_Blood); 
}

ProtossUnit::ProtossUnit(const std::string & _strUnitName)
: Unit(_strUnitName)
{
}

void ProtossUnit::GenerateBody()
{
    SetStaminaType(eStamina_Shield);
}

void InfestTerranUnit::GenerateBody()
	{
		if(nullptr != m_pInfestAdaptee)
		{
            m_pInfestAdaptee->InfestGenerateBody();
            SetStaminaType(eStamina_Reroll);
		}
		else
		{
			std::cout<<"fail to make infest terran"<<std::endl;
		}
	}