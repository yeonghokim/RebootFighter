//
//  UIManager.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 15..
//
//

#include "UIManager.h"

void UIManager::Init(std::string str){
    mSprite= Sprite::create(str);
    IsButton=false;
    mZorder=0;
}

//-------------------Touch-------------------//
bool UIManager::onTouchBegan(Touch* touch){
    if(mSprite->getBoundingBox().containsPoint(touch->getLocation())){
        if(IsButton)
            mSprite->setTexture(mOnButton);
        
        return true;
    }
    
    return false;
}
bool UIManager::onTouchEnded(Touch* touch){
    if(IsButton)
        mSprite->setTexture(mOffButton);
    return false;
}

//-------------------Setter-------------------//
void UIManager::SetButton(std::string str){
    IsButton=true;
    mOnButton = GetTexture(str);
    mOffButton = GetTexture(str);
}
void UIManager::SetAnchorPoint(Point point){
    mSprite->setAnchorPoint(point);
}
void UIManager::SetPosition(int x, int y){
    mSprite->setPosition(x,y);
}
void UIManager::SetZorder(int zorder){
    mZorder=zorder;
}
//--------------------Getter------------------//
Texture2D* UIManager::GetTexture(std::string str){
    
    Image* image = new Image();
    image->initWithImageFile(str);
    
    Texture2D* texture =  new Texture2D();
    texture->initWithImage(image);
    
    return texture;
    
}
void UIManager::GetParents(Node* node){
    mParents=node;
    mParents->addChild(mSprite,mZorder);
}
