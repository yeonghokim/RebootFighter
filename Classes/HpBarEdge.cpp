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
    
    if(maxhp>650) maxhp=650;
    
    auto edge = Sprite::create("ver2/UI/hpbar_edge.png");
    edge->setAnchorPoint(Point(fliped?1:0,0.5));
    edge->setPositionX(fliped?19:-19);
    edge->setFlippedX(fliped);
    mLayer->addChild(edge);
    
    auto body = Sprite::create("ver2/UI/hpbar_body.png");
    body->setScaleX(maxhp/50);
    body->setAnchorPoint(Point(fliped?1:0,0.5));
    mLayer->addChild(body);
    
    auto finaledge = Sprite::createWithTexture(edge->getTexture());
    finaledge->setFlippedX(!fliped);
    finaledge->setPosition((maxhp/50)*21,0);
    if(fliped) finaledge->setPositionX(finaledge->getPositionX()*(-1));
    mLayer->addChild(finaledge);

}
