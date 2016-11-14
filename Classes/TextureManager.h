//
//  ActionManager.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//
#pragma once

#include "cocos2d.h"

USING_NS_CC;

#define NoChange -1

class TextureManager{
protected:
    Sprite* mSprite;
    
    Texture2D* mAttackTexture[3];
    
    Texture2D* GeneralTexture;
    
    int mStep= -1;
    
public:
    static Texture2D* CreateTexture(std::string filepath);
    
    virtual void InitTexture() = 0 ;
    
    void StartAttack();
    
    void ChangeTexture();
    
    virtual void DieAction() = 0;
};
