#ifndef _HEADER_TYPE_H_
#define _HEADER_TYPE_H_

enum eTribeType
{
	eTribe_None = 0,
	eTribe_Terran,
	eTribe_Protoss,
	eTribe_Zerg,
	eTribe_Max
};

enum eStaminaType
{
	eStamina_None = 0,
	eStamina_Blood,
	eStamina_Shield,
	eStamina_Reroll,
	eStamina_Max
};

enum eUnitType
{
    eUnit_None = 0,
    eUnit_Worker,
    eUnit_Attacker,
    eUnit_Deffenser,
    eUnit_Max
};

enum eMapState
{
	eMapState_None = 0,
	eMapState_Rest,
	eMapState_Burning,
	eMapState_Final,
	eMapState_Max
};

enum eMapProtoType
{
	eMapProto_None = 0,
	eMapProto_Type1,
	eMapProto_Type2,
	eMapProto_Max
};

#endif