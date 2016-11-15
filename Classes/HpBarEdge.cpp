//
//  HpBarEdge.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 16..
//
//
#include "HpBarEdge.h"

void HpBarEdge::AutoSetting(HpBar* hpbar,bool fliped){
    mLayer=Layer::create();
    
    int maxhp = hpbar->GetMaxHp();
    
    auto sprite = Sprite::create("ver2/UI/hpbar_edge.png");
    if(fliped){
        sprite->setAnchorPoint(Point(1,0.5));
        sprite->setFlippedX(true);
    }
    else
        sprite->setAnchorPoint(Point(0,0.5));
    
    
    
}
