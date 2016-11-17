
//
//  FirstChance.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 17..
//
//
#include "FirstChance.h"

#define MaxX 720

void FirstChance::Init()
{
    mLayer=Layer::create();
    
    mRed=Sprite::create("ver2/SelectAttackUI/fch_02_red.png");
    mRed->setPosition(360,220);
    mRed->setFlippedX(true);
    mRed->setAnchorPoint(Point(0,0));
    mLayer->addChild(mRed);
    
    mBlue=Sprite::create("ver2/SelectAttackUI/fch_01_blue.png");
    mBlue->setPosition(-360,220);
    mBlue->setAnchorPoint(Point(0,0));
    mLayer->addChild(mBlue);
    
    mLayout=Sprite::create("ver2/SelectAttackUI/fch_00-layout.png");
    mLayout->setPosition(0,220);
    mLayout->setAnchorPoint(Point(0,0));
}

void FirstChance::onTouchEnded(Touch* touch)
{
    mLayer->setPositionX(mLayer->getPositionX()+10);
}

void FirstChance::Update(float dt)
{
    mLayer->setPositionX(mLayer->getPositionX()-3);
}

bool FirstChance::IsPlayerWin()
{
    if(mLayer->getPositionX()>MaxX-360)
    {
        return true;
    }
    return false;
}
bool FirstChance::IsMonsterWin()
{
    if(mLayer->getPositionX()<-360)
    {
        return true;
    }
    return false;
}
Sprite* FirstChance::GetLayout(){
    return mLayout;
}
