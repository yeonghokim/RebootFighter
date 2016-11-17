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
void HpBar::Init(Health* maxhp,bool flipped){
    UIManager::Init("ver2/UI/hpbar_energy_A.png");
    
    //A,B타입 만들고 안보이게 하는 타입
    
    IsFlipped=flipped;
    SetSpriteB();

    mMaxHp=*(maxhp->GetHealthPointer());
    mHp=maxhp->GetHealthPointer();
    
    mEdge= new HpBarEdge();
    mEdgeB= new HpBarEdge();

    ((HpBarEdge*)mEdge)->AutoSetting(this,flipped);
    ((HpBarEdge*)mEdgeB)->AutoSetting(this,flipped,true);
    
    mEdge->GetParents(mLayer,-1);
    mEdgeB->GetParents(mLayer,1);
    
    if(IsFlipped)
        SetFlipped();
    
    SetMaxHp(mHp);
    SetHp();
}
//-------------Setter---------------//

//최대 체력 구해주고 바꿔주는 메소드
void HpBar::SetMaxHp(int* maxhp){
    mMaxHp=*maxhp;
    mHp=maxhp;
    
    IsBType=mMaxHp>650;
    
    ((HpBarEdge*)mEdge)->ChangeSetting(this);
    mTextureMax = 278*(float)(*mHp)/650.0f;
    
    ((HpBarEdge*)mEdgeB)->ChangeSetting(this);
    if(IsBType)
        mTextureBMax= 236*(float)(*mHp-650)/550.0f;
    
    SetHp();
}

//체력 구해주는 메소드, 텍스쳐도 바꿔줌
void HpBar::SetHp(){
    if(IsBType){
        if(*mHp>650){
            mSprite->setTextureRect(Rect(0,0,278,53));
            mSpriteB->setTextureRect(Rect(0,0,mTextureBMax*(float)(*mHp-650)/(mMaxHp-650),53));
            ((HpBarEdge*)mEdgeB)->SetVisible(true);
        }
        else{
            mSprite->setTextureRect(Rect(0,0,mTextureMax*(float)(*mHp)/mMaxHp,53));
            ((HpBarEdge*)mEdgeB)->SetVisible(false);
            mSpriteB->setVisible(false);
        }
    }else{
        mSprite->setTextureRect(Rect(0,0,mTextureMax*(float)(*mHp)/mMaxHp,53));
        ((HpBarEdge*)mEdgeB)->SetVisible(false);
        mSpriteB->setVisible(false);
    }
}

//BType 만듬
void HpBar::SetSpriteB(){
    mSpriteB=Sprite::create("ver2/UI/hpbar_energy_B.png");
    mSpriteB->setPosition(IsFlipped?-50:50,-50);
    mLayer->addChild(mSpriteB,2);
}

//포지션 정해주는 메소드(오버라이드)
void HpBar::SetPosition(int x ,int y){
    mLayer->setPosition(x,y);
}

//--------------Getter--------------//
//퍼센트 구해주는 메소드
float HpBar::GetPercent(){
    return (float)*mHp/mMaxHp;
}

//앵커포인트 설정(오버라이드)
void HpBar::SetAnchorPoint(Point point){
    UIManager::SetAnchorPoint(point);
    if(IsBType)
        mSpriteB->setAnchorPoint(point);
}

//뒤집어 주는 메소드
void HpBar::SetFlipped(){
    mSprite->setFlippedX(true);
    if(IsBType)
        mSpriteB->setFlippedX(true);
}

//최대체력 주는 메소드
int HpBar::GetMaxHp(){
    return mMaxHp;
}
