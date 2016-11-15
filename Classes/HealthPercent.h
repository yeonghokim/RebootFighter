//
//  HealthPercent.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//
#pragma once

#include "cocos2d.h"
#include "Status.h"

USING_NS_CC;

class Health {
private:
    int mHealth;
    int mMaxHealth;

public:
    void Damaged(int damage);
    
    void Init(Element defence);
    
    float GetPercentHealth();
    
    int* GetHealthPointer();
    
    bool IsDie();
};
