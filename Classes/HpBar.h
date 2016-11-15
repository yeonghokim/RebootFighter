//
//  HpBar.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//
#pragma once

#include "cocos2d.h"
#include "UIManager.h"

USING_NS_CC;

class HpBar : public UIManager{
private:
    Sprite* mSpriteB;
    
    Texture2D* mHpbarBody;
    
    Texture2D* mHpbarEdge;
    
    Point mPoint;
private:
    
    bool IsSpriteB;
    
    int mMaxHp;
    
    int* mHp;

public:
    void Init(int* maxhp);
    
public:
    float GetPercent();
    
    int GetMaxHp();
    
public:
    void SetHp();
    
    void SetSpriteB(int number);
    
    void SetAnchorPoint(Point point);
    
    void SetFlipped();
    
    void SetPosition(int x ,int y);
};
