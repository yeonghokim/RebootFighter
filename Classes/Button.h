//
//  Button.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Button {
private:
    Texture2D* mUntouchedButton;
    Texture2D* mTouchedButton;
    
    Label* mLabel;
    
public:
    static bool IsSprite;
    
    Sprite* mSprite = NULL;
    
    static Button* create();
    static Button* create(std::string filepath);
    
    Label* GetLabel();
    
    Texture2D* GetUntouchedButton();

    void Init(std::string UntouchedPath,std::string TouchedPath,std::string text);
    
    void onTouchBegan(Touch* touch);
    
    void onTouchMoved(Touch* touch);
    
    bool onTouchEnded(Touch* touch);
    
    
};
