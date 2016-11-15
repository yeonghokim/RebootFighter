//
//  HpBar.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//
#include "HpBar.h"

void HpBar::Init(int* maxhp){
    std::string str(Ver2);
    UIManager::Init(str+"UI/hpbar_energy_A.png");

    //줄어들기
    
    if(*maxhp>650)
        SetSpriteB(*maxhp-650);
        //B줄어들기
    
    mMaxHp=*maxhp;
    mHp=maxhp;
    
    mHpbarEdge=GetTexture(str+"UI/hpbar_edge.png");
    mHpbarBody=GetTexture(str+"UI/hpbar_body.png");
}
//-------------Setter---------------//
void HpBar::SetHp(){
    if(IsSpriteB){
        //B 타입 줄어들기
    }else{
        //줄어들기
    }
}
void HpBar::SetSpriteB(int number){
    mSpriteB = Sprite::create("ver2/UI/hpbar_energy_B.png");
    
    
    mLayer->addChild(mSpriteB);
    
    IsSpriteB=true;
}
void HpBar::SetPosition(int x ,int y){
    mPoint=Point(x,y);
    if(mSpriteB)
        mSpriteB->setPosition(x,y-50);
}
//--------------Getter--------------//
float HpBar::GetPercent(){
    return (float)*mHp/mMaxHp;
}
void HpBar::SetAnchorPoint(Point point){
    UIManager::SetAnchorPoint(point);
    
    if(IsSpriteB)
        mSpriteB->setAnchorPoint(point);
}
void HpBar::SetFlipped(){
    mSprite->setFlippedX(true);
    if(IsSpriteB)
        mSpriteB->setFlippedX(true);
}
int HpBar::GetMaxHp(){
    return mMaxHp;
}
