//
//  GameHit.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 9..
//
//
#include "GameScene.h"
void GameScene::HitMonster(){
    
    if(mMonster->IsAvoidDance()){
        Label* Labelavoid = Label::createWithTTF("Miss!", "fonts/jungfont.ttf", 50);
        Point point = mMonster->GetSprite()->getPosition();
        point.y+=60;
        point.x+=60;
        Labelavoid->setPosition(point);
        
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        
        return;
    }else if(mFighter->IsKill()){
        mMonster->Dead();
        
        
        Label* Labelavoid = Label::createWithTTF("일격필살!", "fonts/jungfont.ttf", 50);
        
        Point point = mMonster->GetSprite()->getPosition();
        point.y+=60;
        point.x+=60;
        
        
        Labelavoid->setPosition(point);
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        
        
    }else if(mFighter->IsCritical()){
        
        
        
        Label* Labelavoid = Label::createWithTTF("크리티컬!", "fonts/jungfont.ttf", 50);
        Point point = mMonster->GetSprite()->getPosition();
        point.y+=60;
        point.x+=60;
        Labelavoid->setPosition(point);
        
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        mFighter->Hit(mMonster,true);
        
        
        
    }else mFighter->Hit(mMonster);
    
    int sizePercent=100-mMonster->GetHealth().GetPercentHealth();
    if(sizePercent>=100){
        //mMonsterBlinder->setContentSize(Size(280,50));
        //mMonsterBlinder->setPositionX(360+59);
        //끝내기
    }else{
        //mMonsterBlinder->setContentSize(Size(280*sizePercent/(float)100,50));
        //mMonsterBlinder->setPositionX(360+59+280-280*sizePercent/(float)100);
    }
}
void GameScene::HitPlayer(){
    if(mFighter->IsAvoidDance()){
        Label* Labelavoid = Label::createWithTTF("Miss!", "fonts/jungfont.ttf", 50);
        Point point = mFighter->GetSprite()->getPosition();
        point.y+=60;
        point.x-=60;
        Labelavoid->setPosition(point);
        this->addChild(Labelavoid,1000);
        
        Labelavoid->runAction(FadeOut::create(1.0f));
        
        return;
    }
    if(mMonster->IsKill()){
        //한방에 죽이기
        
    }
    if(mMonster->IsCritical()){
        Label* Labelavoid = Label::createWithTTF("크리티컬!", "fonts/jungfont.ttf", 50);
        Point point = mFighter->GetSprite()->getPosition();
        point.y+=60;
        point.x-=60;
        Labelavoid->setPosition(point);
        
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        mMonster->Hit(mFighter,true);
    }
    else
        mMonster->Hit(mFighter);
    //파티클 해주면 되고
    
    int sizePercent=100-mFighter->GetHealth().GetPercentHealth();
    if(sizePercent>=100){
        //mFighterBlinder->setContentSize(Size(280,50));
    }else{
        //mFighterBlinder->setContentSize(Size(280*sizePercent/(float)100,50));
    }
}
