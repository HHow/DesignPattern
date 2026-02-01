#ifndef _HEADER_COMPONENT_H_
#define _HEADER_COMPONENT_H_

#include "../Type/type.h"

class Tribe;

class CombineUnit
{
public:
	CombineUnit() = delete;
	CombineUnit(const eTribeType _eTribeType);
	virtual ~CombineUnit() {};

	CombineUnit(const CombineUnit& _CombineUnit) = default;
	CombineUnit& operator=(const CombineUnit& _CombineUnit) = default;

	void MakeUnit(const eUnitType _eUnitType);

};

#endif