//
//  Button.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//

#include "Button.h"

#define FontSize 50

#define TTFPath "fonts/jungfont.ttf"

bool Button::IsSprite=false;

Button* Button::create(){
    Button* button =  new Button();
    button->mSprite=Sprite::create("Button/btn_un.png");
    return button;
}
Button* Button::create(std::string filepath){
    Button* button =  new Button();
    button->mSprite=Sprite::create(filepath);
    return button;
}
void Button::onTouchBegan(Touch* touch){
    if(!IsSprite) return;

    Point position =touch->getLocation();
    if(IsSprite&&mSprite->getBoundingBox().containsPoint(touch->getLocation())){
        
        mSprite->setTexture(mTouchedButton);
    }
}

void Button::onTouchMoved(Touch* touch){
    if(!IsSprite) return;
    
    if(IsSprite&& !mSprite->getBoundingBox().containsPoint(touch->getLocation())){
        mSprite->setTexture(mUntouchedButton);
    }
}

bool Button::onTouchEnded(Touch* touch){
    mSprite->setTexture(mUntouchedButton);
    
    if(!IsSprite) return false;
    
    return mSprite->getBoundingBox().containsPoint(touch->getLocation());
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
    
    mLabel= Label::createWithTTF(text, TTFPath, text=="Power up"?FontSize+30:FontSize);
    mLabel->setPosition(mSprite->getPosition());
    mLabel->setColor(Color3B::WHITE);
    IsSprite=true;
    
}
Label* Button::GetLabel(){
    return mLabel;
}
Texture2D* Button::GetUntouchedButton(){
    return mUntouchedButton;
}
