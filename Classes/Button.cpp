//
//  Button.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//

#include "Button.h"
#define FontSize 40

#define TTFPath "fonts/jungfont.ttf"

void Button::onTouchBegan(Touch* touch){
    Point position =touch->getLocation();
    if(getBoundingBox().containsPoint(touch->getLocation())){
        setTexture(mTouchedButton);
    }
}

void Button::onTouchMoved(Touch* touch){
    if(!getBoundingBox().containsPoint(touch->getLocation())){
        setTexture(mUntouchedButton);
    }
}

bool Button::onTouchEnded(Touch* touch){
    setTexture(mUntouchedButton);
    
    return getBoundingBox().containsPoint(touch->getLocation());
}

void Button::Init(std::string UntouchedPath,std::string TouchedPath,std::string text){
    
    Image* image =new Image();
    image->initWithImageFile(UntouchedPath);
    
    mUntouchedButton=new Texture2D();
    mUntouchedButton->initWithImage(image);
    
    image =new Image();
    image->initWithImageFile(TouchedPath);
    
    mTouchedButton = new Texture2D();
    mTouchedButton->initWithImage(image);
    
    mLabel= Label::createWithTTF(text, TTFPath, FontSize);
    mLabel->setPosition(getPosition());
    mLabel->setColor(Color3B::WHITE);
    
    
}
Label* Button::GetLabel(){
    return mLabel;
}
Texture2D* Button::GetUntouchedButton(){
    return mUntouchedButton;
}
