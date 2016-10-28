//
//  HealthPercent.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//
#pragma once

#include "cocos2d.h"
#include "IProperty.h"


USING_NS_CC;

class HealthPercent : public IProperty{
private:
    const float mBaseHealth;
    
    const float mChangeValue;
    
    int mPhysicalDefense;
    int mMagicDefense;



public:
    
    HealthPercent();
    
    int GetPhysicalDefense() const;
    int GetMagicDefense() const;
    
    
    void SetStatus(int physicDefence, int magicDefence);
    
    int CalculatePercent(int luck,PM damage) override;
    
    
    
};
