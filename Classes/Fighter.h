//
//  Fighter.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//
#pragma once

#include "cocos2d.h"
#include "TextureManager.h"
#include "DrawStatus.h"

#include "Career.h"


#include <array>

USING_NS_CC;

class Fighter : public TextureManager{
private:
    std::string filepath;
    DrawStatus* mDrawStatus;
    
    Career* mCareer;
    
    bool IsMonster=false;
    bool IsBoss=false;
    
protected:
    Status mStatus;
    Health mHealty;
    
private:
    void DivideStatus();
    
    void RandomCareer();
    
    void RandomFortune();
    int GetAllStatus();
    
public:
    void ChangeCareer();
    
    void Dead();
    
    void SetMonster();
    
    Health GetHealth();
    
    Sprite* GetSprite();
    
    void Hit(Fighter* fighter, bool Critical = false);
    
    virtual void InitTexture() override;
    
    virtual void DieAction() override;
    
    Career* GetCareer();
    
    ~Fighter();
    
    Status GetStatus();
    
    DrawStatus* GetDrawStatus();
    
    void Init();
    
    void Reset();
    
    bool IsCritical();//크리티컬인지
    bool IsAvoidDance();//회피인지
    bool IsKill();//원킬인지
};


