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
    bool IsBtype;
    
    Sprite* mEdge;
    
    bool IsFlip;
    
    Sprite* mBody;
    
    Sprite* mFinalEdge;
    
public:
    void AutoSetting(HpBar* hpbar, bool fliped=true,bool isBtype=false);
    
    void ChangeSetting(HpBar* hpbar);
    
    void SetBtype();
    
    void SetVisible(bool visible);
};

#endif
