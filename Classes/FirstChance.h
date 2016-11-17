//
//  FirstChance.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 17..
//
//
#pragma once

#include "cocos2d.h"
#include "UIManager.h"

USING_NS_CC;

class FirstChance : public UIManager
{
private:
    Sprite* mRed;
    Sprite* mBlue;
    Sprite* mLayout;
    
public:
    void Init();
    
    void Update(float dt);
    
    void onTouchEnded(Touch* touch);
    
    bool IsPlayerWin();
    bool IsMonsterWin();
    
    Sprite* InitButton();
    
    Sprite* GetLayout();
};
