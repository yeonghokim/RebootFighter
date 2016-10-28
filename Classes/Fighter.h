//
//  Fighter.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//
#pragma once

#include "cocos2d.h"
#include "Property.h"
#include "DrawStatus.h"

USING_NS_CC;


class Fighter{
private:
    Sprite* mSprite;
    
    Attribute mAttribute;
    
    Property mProperty;

    DrawStatus* mDrawStatus;
    
private:
    bool IsCritical();
    
public:
    DrawStatus* GetDrawStatus();
    
    void Init();
    
    void Reset();
    
    
    
    
    
};
