//
//  HpBar.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//
#include "HpBar.h"
#include "HpBarEdge.h"

void HpBar::Init(int* maxhp,bool flipped){
    
    
    
    std::string str(Ver2);
    UIManager::Init(str+"UI/hpbar_energy_A.png");
    
    mMaxHp=*maxhp;
    mHp=maxhp;
    
    HpBarEdge* mEdge= new HpBarEdge();
    mEdge->AutoSetting(this,flipped);
    mEdge->GetParents(mLayer,-1);
    if(flipped)
        SetFlipped();
    
    
    
    //줄어들기
    
    if(mMaxHp>650)
        SetSpriteB(mMaxHp-650);
        //B줄어들기
    

    
    
    
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
    mLayer->setPosition(x,y);
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
