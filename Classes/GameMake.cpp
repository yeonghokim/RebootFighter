//
//  GameMake.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 18..
//
//
#include "GameScene.h"

void GameScene::MakeHpBar(){
    //체력 바 클래스 구현 (11월 16일 오전 12시 32분)
    mFighterHpBar = new HpBar();
    mFighterHpBar->Init(mFighter->GetHealthPointer());
    mFighterHpBar->SetPosition(300, 1210);
    mFighterHpBar->SetAnchorPoint(Point(1,0.5));
    mFighterHpBar->SetZorder((int)Zorder::Content);
    mFighterHpBar->GetParents(this);
    
    mMonsterHpBar = new HpBar();
    mMonsterHpBar->Init(mMonster->GetHealthPointer(),false);
    mMonsterHpBar->SetPosition(420, 1210);
    mMonsterHpBar->SetAnchorPoint(Point(0,0.5));
    mMonsterHpBar->SetZorder((int)Zorder::Content);
    mMonsterHpBar->GetParents(this);
}
void GameScene::MakeProgressTimer(){
    mProgressTimer =ProgressTimer::create(Sprite::createWithTexture(TimeTexture[0]));
    mProgressTimer->setPosition(20,615);
    mProgressTimer->setAnchorPoint(Point(0,0));
    mProgressTimer->setPercentage(100.0f);
    mProgressTimer->setType(ProgressTimer::Type::BAR);
    mProgressTimer->setMidpoint(Point(0, 0.5f));
    mProgressTimer->setBarChangeRate(Point(1, 0));
    mProgressTimer->runAction(ProgressFromTo::create(100, 101, 100));
    this->addChild(mProgressTimer,(int)Zorder::TimeBar);
    
    //시간바 틀
    auto timebar=Sprite::create("ver2/UI/timebar_layout.png");
    timebar->setPosition(0,600);
    timebar->setAnchorPoint(Point(0,0));
    this->addChild(timebar,(int)Zorder::TimeBar-1);
}
void GameScene::MakeCareerText(){
    //플레이어 직업 텍스트
    mCareerLabel=Label::createWithTTF(mFighter->GetCareer()->GetName(), "fonts/jungfont.ttf", 40);
    mCareerLabel->setPosition(180,560);
    this->addChild(mCareerLabel,(int)Zorder::Content);
    
    //몬스터 직업 텍스트
    mMonsterCareerLabel=Label::createWithTTF(mMonster->GetCareer()->GetName(), "fonts/jungfont.ttf", 40);
    mMonsterCareerLabel->setPosition(540,560);
    this->addChild(mMonsterCareerLabel,(int)Zorder::Content);
}
void GameScene::MakePowerUpButton(){
    mButtonPowerup = Button::create("ver2/battleUI/btn_power_on.png");
    mButtonPowerup->Init("ver2/battleUI/btn_power_on.png", "ver2/battleUI/btn_power_off.png", "");
    mButtonPowerup->mSprite->setAnchorPoint(Point(0.5,0));
    mButtonPowerup->mSprite->setPosition(360,0);
    this->addChild(mButtonPowerup->mSprite,(int)Zorder::PowerButton);
}
