//
//  HpBar.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//
#include "HpBar.h"

void HpBar::Init(int maxhp){
    std::string str(Ver2);
    UIManager::Init(str+"UI/hpbar_energy_A.png");

    IsSpriteB=false;
    
    mMaxHp=maxhp;
    mHp=mMaxHp;
}
//-------------Setter---------------//
void HpBar::SetPositionB(int x, int y){
    if(IsSpriteB)
        mSpriteB->setPosition(x,y);
}
void HpBar::SetHp(int hp){
    mHp=hp;
    if(IsSpriteB){
        //B 타입 줄어들기
        
        
    }else{
        mSprite->setScaleX(GetPercent());
    }
}
void HpBar::SetSpriteB(){
    mSpriteB = Sprite::create("ver2/UI/hpbar_energy_B.png");
    IsSpriteB=true;
}
//--------------Getter--------------//
float HpBar::GetPercent(){
    return (float)mHp/mMaxHp;
}
void HpBar::GetParents(Node* node){
    UIManager::GetParents(node);
    if(IsSpriteB)
        node->addChild(mSpriteB,mZorder);
}
void HpBar::SetAnchorPointB(Point point){
    if(IsSpriteB)
        mSpriteB->setAnchorPoint(point);
}
void HpBar::SetFlipped(){
    mSprite->setFlippedX(true);
    if(IsSpriteB)
        mSpriteB->setFlippedX(true);
}
