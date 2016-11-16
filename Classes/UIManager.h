//
//  UIManager.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//
#pragma once

#include "cocos2d.h"

USING_NS_CC;

#define Ver2 "ver2/"

class UIManager{
protected:
    Layer* mLayer;
    
    int mZorder;
    
    Sprite* mSprite;
    
    bool IsButton;
    
    Texture2D* mOnButton;
    Texture2D* mOffButton;
    
    Node* mParents;
    
protected:
    
    Texture2D* GetTexture(std::string str);
    
    
public:
    void Init(std::string str);
    
    bool onTouchBegan(Touch* touch);
    bool onTouchEnded(Touch* touch);
    
    void SetPosition(int x, int y);
    void SetAnchorPoint(Point point);
    void SetButton(std::string str);
    void SetZorder(int zorder);
    
    void GetParents(Node* node);
    void GetParents(Node* node,int Zorder);

};
