//
//  ActionManager.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//
#include "TextureManager.h"
void TextureManager::StartAttack(){
    mStep=0;
}

void TextureManager::ChangeTexture(){
    if(mStep!=NoChange&&mStep<2)
       mSprite->setTexture(mAttackTexture[mStep++]);

    else{
        mSprite->setTexture(GeneralTexture);
        mStep=NoChange;
    }
}
Texture2D* TextureManager::CreateTexture(std::string filepath)
{
    
    Image* image = new Image;//이미지를 만듬
    image->initWithImageFile(filepath);
    
    Texture2D* texture =new Texture2D;//이미지로 Texture2D를 만듬
    texture->initWithImage(image);
    
    return texture;
    
}
