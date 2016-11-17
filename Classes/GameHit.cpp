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
        //회피
        
        Label* Labelavoid = Label::createWithTTF("Miss!", "fonts/jungfont.ttf", 50);
        Point point = mMonster->GetSprite()->getPosition();
        point += Point(60,60);
        Labelavoid->setPosition(point);
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        
        return;
    }else if(mFighter->IsKill()){
        //일격필살
        
        mMonster->Dead();
        
        
        Label* Labelavoid = Label::createWithTTF("일격필살!", "fonts/jungfont.ttf", 50);
        Point point = mMonster->GetSprite()->getPosition();
        point += Point(60,60);
        Labelavoid->setPosition(point);
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        
        
    }else if(mFighter->IsCritical()){
        //크리티컬
        
        
        Label* Labelavoid = Label::createWithTTF("크리티컬!", "fonts/jungfont.ttf", 50);
        Point point = mMonster->GetSprite()->getPosition();
        point += Point(60,60);
        Labelavoid->setPosition(point);
        
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        mFighter->Hit(mMonster,true);
        
        
        
    }else mFighter->Hit(mMonster);
    
    mMonsterHpBar->SetHp();
}
void GameScene::HitPlayer(){
    if(mFighter->IsAvoidDance()){
        //회피
        
        Label* Labelavoid = Label::createWithTTF("Miss!", "fonts/jungfont.ttf", 50);
        Point point = mFighter->GetSprite()->getPosition();
        point += Point(60,-60);
        Labelavoid->setPosition(point);
        this->addChild(Labelavoid,1000);
        
        Labelavoid->runAction(FadeOut::create(1.0f));
        
        return;
    }
    if(mMonster->IsKill()){
        //한방에 죽이기
        
    }
    if(mMonster->IsCritical()){
        //크리티컬
        
        Label* Labelavoid = Label::createWithTTF("크리티컬!", "fonts/jungfont.ttf", 50);
        Point point = mFighter->GetSprite()->getPosition();
        point += Point(60,-60);
        Labelavoid->setPosition(point);
        
        Labelavoid->runAction(FadeOut::create(1.0f));
        this->addChild(Labelavoid,1000);
        mMonster->Hit(mFighter,true);
    }
    else
        mMonster->Hit(mFighter);
    //파티클 해주면 되고
    
    mFighterHpBar->SetHp();
}
