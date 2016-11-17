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
#include "HealthPercent.h"

class HpBar : public UIManager{
private:
    float mTextureMax;
    float mTextureBMax;
    
    bool IsBType;
    bool IsFlipped;
    
    Sprite* mSpriteB;
    
    Point mPoint;
    
    UIManager* mEdge;
    
    UIManager* mEdgeB;
private:
    
    int mMaxHp;
    
    int* mHp;

public:
    void Init(Health* maxhp, bool flipped =true);
    
public:
    float GetPercent();
    
    int GetMaxHp();
    
public:
    void SetMaxHp(int* maxhp);
    
    void SetHp();
    
    void SetSpriteB();
    
    void SetAnchorPoint(Point point);
    
    void SetFlipped();
    
    void SetPosition(int x ,int y);
};

#endif
