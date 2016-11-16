//
//  HpBar.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//
#pragma once

#ifndef HPBAR
#define HPBAR

#include "UIManager.h"

class HpBar : public UIManager{
private:
    Sprite* mSpriteB;
    
    Point mPoint;
    
    UIManager* mEdge;
private:
    
    bool IsSpriteB;
    
    int mMaxHp;
    
    int* mHp;

public:
    void Init(int* maxhp, bool flipped =true);
    
public:
    float GetPercent();
    
    int GetMaxHp();
    
public:
    void SetMaxHp(int* maxhp);
    
    void SetHp();
    
    void SetSpriteB(int hp);
    
    void SetAnchorPoint(Point point);
    
    void SetFlipped();
    
    void SetPosition(int x ,int y);
};

#endif
