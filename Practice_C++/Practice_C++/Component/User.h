#ifndef _HEADER_USER_H_
#define _HEADER_USER_H_

#include "../Type/type.h"

class Tribe;

class User
{
public:
    User() = delete;
    User(const eTribeType _eTribeType);
    virtual ~User() {};
    
    User(const User& _User) = default;
    User& operator=(const User& _User) = default;

    void MakeUnit(const eUnitType _eUnitType);

private:
    eTribeType m_eTribeType;
    Tribe* m_Tribe;
};

#endif