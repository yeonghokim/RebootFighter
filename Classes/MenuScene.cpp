//
//  MenuScene.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//

#include "MenuScene.h"
#include "GameScene.h"
#include "CocosMusic.h"
Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

MenuScene::~MenuScene(){
    Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
}

bool MenuScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }

    GameScene::mStage=UserDefault::getInstance()->getIntegerForKey("Level")-1;
    
    //이미지 만들기
    auto Logo=Sprite::create("UI/logo.png");
    Logo->setPosition(360,975);
    this->addChild(Logo);

    StatusGraph=Sprite::create("UI/statusgraph.png");
    StatusGraph->setPosition(360,600);
    this->addChild(StatusGraph);
    
    auto Knight=Sprite::create("Character/Knight/knight(0).png");
    Knight->setPosition(360,590);
    this->addChild(Knight);

    mStart= Button::create();
    mStart->Init("UI/Button/btn_un.png", "UI/Button/btn_touch.png", "Start");
    mStart->mSprite->setPosition(360,350);
    mStart->GetLabel()->setPosition(Point(360,350));
    this->addChild(mStart->mSprite,1);
    this->addChild(mStart->GetLabel(),1);
    
    Label* indiegameweekend =Label::createWithTTF("2016 Indiegame weekend", "fonts/jungfont.ttf", 40);
    indiegameweekend->setPosition(360,50);
    this->addChild(indiegameweekend);
    
    //리스너 추가
    listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(MenuScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(MenuScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(MenuScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    listener->setSwallowTouches(true);
    this->schedule(schedule_selector(MenuScene::ScaleCalculate), 0.15f);
    
    return true;
}

void MenuScene::ScaleCalculate(float dt){
    if(StatusGraph->getScale()==1)//커지다 작아지다를 반복
        StatusGraph->setScale(1.2);
    else
        StatusGraph->setScale(1);
}

bool MenuScene::onTouchBegan(Touch* touch,Event* unused_event){
    mStart->onTouchBegan(touch);
    return true;
}

void MenuScene::onTouchMoved(Touch* touch,Event* unused_event){
    mStart->onTouchMoved(touch);
}

void MenuScene::onTouchEnded(Touch* touch,Event* unused_event){
    if(mStart->onTouchEnded(touch)){
        
        Button::IsSprite=false;
        
        Director::getInstance()->replaceScene(GameScene::createScene());
        
        CocosMusic::PlayBGM01();
        
    }
}

