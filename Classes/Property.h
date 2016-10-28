//
//  Property.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//
#pragma once

#include "HealthPercent.h"
#include "DamagePercent.h"

enum class Attribute : int { PhysicalDamage,MagicDamage,PhysicalDefense,MagicDefense};


struct Property{
public:
    HealthPercent mHealth;
    DamagePercent mDamage;
    int mFortune;
    
public:
    void DivideStatus(Attribute mAttribute);
};
