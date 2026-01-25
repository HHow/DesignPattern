#include "../Factory.h"
#include "../../Component/Unit.h"

void Tribe::SetUnit(Unit * _Unit)
{
    if(nullptr != _Unit)
    {
        m_vtUnit.push_back(_Unit);
    }
}

Terran::Terran() 
{
    std::cout << "Make Terran" << std::endl;
}

Terran::~Terran()
{
    std::cout << "Delete Terran" << std::endl;
}

void Terran::MakeUnit(const eUnitType _eUnitType)
{
    std::cout << "Make Terran Unit" << std::endl;

    TerranUnit* pTerranUnit = nullptr;

    switch(_eUnitType)
    {
        case eUnit_Attacker:
            pTerranUnit = new TerranUnit("Attacker");
            break;
        case eUnit_Deffenser:
            pTerranUnit = new TerranUnit("Deffenser");
            break;
        case eUnit_Worker:
            pTerranUnit = new TerranUnit("Worker");
            break;
        default:
            break;
    }

    SetUnit(pTerranUnit);
}

Protoss::Protoss()
{
    std::cout << "Make Protoss" << std::endl;
}

Protoss::~Protoss()
{
    std::cout << "Make Protoss" << std::endl;
}

void Protoss::MakeUnit(const eUnitType _eUnitType)
{
    std::cout << "Make Protoss Unit" << std::endl;

    ProtossUnit* pProtossUnit = nullptr;

    switch(_eUnitType)
    {
        case eUnit_Attacker:
            pProtossUnit = new ProtossUnit("Attacker");
            break;
        case eUnit_Deffenser:
            pProtossUnit = new ProtossUnit("Deffenser");
            break;
        case eUnit_Worker:
            pProtossUnit = new ProtossUnit("Worker");
            break;
        default:
            break;
    }

    SetUnit(pProtossUnit);
}

Zerg::Zerg()
{
    std::cout << "Make Protoss" << std::endl;
}

Zerg::~Zerg()
{
    std::cout << "Make Protoss" << std::endl;
}

void Zerg::MakeUnit(const eUnitType _eUnitType)
{
    std::cout << "Make Protoss Unit" << std::endl;

    ZergUnit* pZergUnit = nullptr;

    switch(_eUnitType)
    {
        case eUnit_Attacker:
            pZergUnit = new ZergUnit("Attacker");
            break;
        case eUnit_Deffenser:
            pZergUnit = new ZergUnit("Deffenser");
            break;
        case eUnit_Worker:
            pZergUnit = new ZergUnit("Worker");
            break;
        default:
            break;
    }

    SetUnit(pZergUnit);
}

Tribe * TribeCreator::MakeTribe(const eTribeType _eTribeType)
{
    Tribe* pRetTribe = nullptr;

    switch (_eTribeType)
    {
    case eTribe_Terran:
        pRetTribe = new Terran;
        break;
    
    case eTribe_Protoss:
        pRetTribe = new Protoss;
        break;

    default:
        break;
    }

    return pRetTribe;
}