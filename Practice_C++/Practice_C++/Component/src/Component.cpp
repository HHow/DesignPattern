#include <iostream>
#include "../User.h"
#include "../../Factory/Factory.h"

User::User(const eTribeType _eTribeType)
: m_eTribeType(_eTribeType)
{
    switch (_eTribeType)
    {
    case eTribe_Terran:
        std::cout<<"Make User Terran"<<std::endl;
        break;
    
    case eTribe_Protoss:
        std::cout<<"Make User Protoss"<<std::endl;
        break;
    
    case eTribe_Zerg:
        std::cout<<"Make User Zerg"<<std::endl;
        break;
    
    default:
        break;
    }

    m_Tribe = TribeCreator::MakeTribe(_eTribeType);
}

void User::MakeUnit(const eUnitType _eUnitType)
{
    m_Tribe->MakeUnit(_eUnitType);
}