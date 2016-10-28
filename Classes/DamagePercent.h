//
//  DamgePercent.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//
#pragma once

#include "cocos2d.h"
#include "IProperty.h"



USING_NS_CC;

class DamagePercent : public IProperty{
private:
    PM mPM;
    
    const float mChangeValue;
private:
    
    int CalculateDamage(int damage, int luck);

public:
    DamagePercent();
    
    int GetPhysicalDamage() const;
    int GetMagicDamage() const;
    
    
    void SetStatus(int physicDamage, int magicDamage);
    
    int CalculatePercent(int luck, PM defence) override;
    
    
};
