#include "../FactoryUnit.h"
#include "Component/Unit/Unit.h"

void TerranUnitFactory::MakeUnit(const eUnitType _eUnitType)
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

    Set(pTerranUnit);
}

void ProtossUnitFactory::MakeUnit(const eUnitType _eUnitType)
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

    Set(pProtossUnit);
}

void ZergUnitFactory::MakeUnit(const eUnitType _eUnitType)
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

    Set(pZergUnit);
}

UnitFactory* UnitFactoryCreator::MakeUnitFactory(const eTribeType _eTribeType)
{
    UnitFactory* pRetUnitFactory = nullptr;

    switch (_eTribeType)
    {
    case eTribe_Terran:
        pRetUnitFactory = new TerranUnitFactory;
        break;
    case eTribe_Protoss:
        pRetUnitFactory = new ProtossUnitFactory;
        break;
    case eTribe_Zerg:
        pRetUnitFactory = new ZergUnitFactory;
        break;
    default:
        break;
    }

    return pRetUnitFactory;
}

