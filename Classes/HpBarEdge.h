//
//  HpBarEdge.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 16..
//
//
#pragma once

#include "cocos2d.h"
#include "UIManager.h"
#include "HpBar.h"
USING_NS_CC;

class HpBarEdge : public UIManager{
private:
    
    
    
public:
    void AutoSetting(HpBar* hpbar, bool fliped=true);
    
    
};
