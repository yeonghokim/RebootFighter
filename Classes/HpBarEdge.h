//
//  HpBarEdge.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 16..
//
//
#pragma once

#ifndef HPBAREDGE
#define HPBAREDGE

#include "UIManager.h"
#include "HpBar.h"

class HpBarEdge : public UIManager{
private:
    Sprite* mEdge;
    
    bool IsFlip;
    
    Sprite* mBody;
    
    Sprite* mFinalEdge;
    
public:
    void AutoSetting(HpBar* hpbar, bool fliped=true);
    
    void ChangeSetting(HpBar* hpbar);
};

#endif
