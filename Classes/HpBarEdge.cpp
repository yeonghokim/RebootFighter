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
    
    IsFlip=fliped;
    
    int maxhp = hpbar->GetMaxHp();
    
    if(maxhp>650) maxhp=650;
    
    mEdge = Sprite::create("ver2/UI/hpbar_edge.png");
    mEdge->setAnchorPoint(Point(fliped?1:0,0.5));
    mEdge->setPositionX(fliped?19:-19);
    mEdge->setFlippedX(fliped);
    mLayer->addChild(mEdge);
    
    mBody = Sprite::create("ver2/UI/hpbar_body.png");
    mBody->setAnchorPoint(Point(fliped?1:0,0.5));
    mLayer->addChild(mBody);
    
    mFinalEdge = Sprite::createWithTexture(mEdge->getTexture());
    mFinalEdge->setFlippedX(!fliped);
    mLayer->addChild(mFinalEdge);
    
    ChangeSetting(hpbar);
}

void HpBarEdge::ChangeSetting(HpBar *hpbar){
    
    int maxhp = hpbar->GetMaxHp();
    
    if(maxhp>650) maxhp=650;
    
    mBody->setScaleX(ceil(maxhp/50+1));
    mFinalEdge->setPosition(ceil(maxhp/50+1)*21,0);
    if(IsFlip) mFinalEdge->setPositionX(mFinalEdge->getPositionX()*(-1));
    
}
