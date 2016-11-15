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
    bool IsSpriteB;
    
    Sprite* mSpriteB;
    
    int mMaxHp;
    
    int mHp;

public:
    void Init(int maxhp);
    
    float GetPercent();
    
    void GetParents(Node* node);
    
    void SetHp(int hp);
    
    void SetPositionB(int x, int y);
    
    void SetSpriteB();
    
    void SetAnchorPointB(Point point);
    
    void SetFlipped();
};
