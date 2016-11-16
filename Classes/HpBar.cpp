//
//  HpBar.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//
#include "HpBar.h"
#include "HpBarEdge.h"

//처음에 만들때 쓰는 메소드
void HpBar::Init(int* maxhp,bool flipped){
    std::string str(Ver2);
    UIManager::Init(str+"UI/hpbar_energy_A.png");

    mMaxHp=*maxhp;
    mHp=maxhp;
    
    mEdge= new HpBarEdge();
    ((HpBarEdge*)mEdge)->AutoSetting(this,flipped);
    mEdge->GetParents(mLayer,-1);
    
    if(flipped)
        SetFlipped();

    SetHp();
}
//-------------Setter---------------//

//최대 체력 구해주고 바꿔주는 메소드
void HpBar::SetMaxHp(int* maxhp){
    mMaxHp=*maxhp;
    mHp=maxhp;
    ((HpBarEdge*)mEdge)->ChangeSetting(this);
    SetHp();
}

//체력 구해주는 메소드, 텍스쳐도 바꿔줌
void HpBar::SetHp(){
    if(IsSpriteB){
        if(*mHp>650){
            mSprite->setTextureRect(Rect(0,0,278,53));
        }
        else{
            mSpriteB->setScale(0);
            mSprite->setTextureRect(Rect(0,0,278*(float)(*mHp)/650.0f,53));
        }
    }else{
        mSprite->setTextureRect(Rect(0,0,278*(float)(*mHp)/650.0f,53));
    }
}

//BType 만듬
void HpBar::SetSpriteB(int hp){
    //구현 아직 X
    
    
    
    
    IsSpriteB=true;
}

//포지션 정해주는 메소드(오버라이드)
void HpBar::SetPosition(int x ,int y){
    
    mLayer->setPosition(x,y);
    if(mSpriteB)
        mSpriteB->setPosition(x,y-50);
}

//--------------Getter--------------//
//퍼센트 구해주는 메소드
float HpBar::GetPercent(){
    return (float)*mHp/mMaxHp;
}

//앵커포인트 설정(오버라이드)
void HpBar::SetAnchorPoint(Point point){
    UIManager::SetAnchorPoint(point);
    
    if(IsSpriteB)
        mSpriteB->setAnchorPoint(point);
}

//뒤집어 주는 메소드
void HpBar::SetFlipped(){
    mSprite->setFlippedX(true);
    if(IsSpriteB)
        mSpriteB->setFlippedX(true);
}

//최대체력 주는 메소드
int HpBar::GetMaxHp(){
    return mMaxHp;
}
