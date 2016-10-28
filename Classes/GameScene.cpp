#include "GameScene.h"


USING_NS_CC;

Scene* GameScene::createScene()
{

    auto scene = Scene::create();
    
    auto layer = GameScene::create();

    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    fighter = new Fighter();
    fighter->Init();
    fighter->Reset();
    fighter->GetDrawStatus()->GetLayer()->setPosition(177,315);
    this->addChild(fighter->GetDrawStatus()->GetLayer(),(int)Zorder::Content);

    mButtonReset= (Button*)Button::create("Button/btn0.png");
    mButtonReset->Init("Button/btn0.png", "Button/btn1.png", "reboot");
    mButtonReset->setAnchorPoint(Point(0,0));
    mButtonReset->GetLabel()->setPosition(Point(180,61));
    this->addChild(mButtonReset,1);
    this->addChild(mButtonReset->GetLabel(),(int)Zorder::Button);
    
    mButtonFight= (Button*)Button::create("Button/btn0.png");
    mButtonFight->Init("Button/btn0.png", "Button/btn1.png", "fight");
    mButtonFight->setAnchorPoint(Point(1,0));
    mButtonFight->setPosition(720,0);
    mButtonFight->GetLabel()->setPosition(Point(540,61));
    this->addChild(mButtonFight,1);
    this->addChild(mButtonFight->GetLabel(),(int)Zorder::Button);
    
    auto inforback=Sprite::create("UI/status.png");
    inforback->setPosition(0,120);
    inforback->setAnchorPoint(Point(0,0));
    this->addChild(inforback,(int)Zorder::Background);
    
    auto SpriteTime=Sprite::create("TimeBar/TimeBarFull.png");
    mProgressTimer =ProgressTimer::create(SpriteTime);
    mProgressTimer->setPosition(0,600);
    mProgressTimer->setAnchorPoint(Point(0,0));
    mProgressTimer->setPercentage(100.0f);
    mProgressTimer->setType(ProgressTimer::Type::BAR);
    mProgressTimer->setMidpoint(Point(0, 0.5f));
    mProgressTimer->setBarChangeRate(Point(1, 0));
    this->addChild(mProgressTimer,(int)Zorder::Background);
    
    ProgressFromTo* TimeAction = ProgressFromTo::create(8.0, 100, 0);
    mProgressTimer->runAction(TimeAction);
    
    auto timebar=Sprite::create("TimeBar/TimeBarEmpty.png");
    timebar->setPosition(0,600);
    timebar->setAnchorPoint(Point(0,0));
    this->addChild(timebar,(int)Zorder::TimeBar);
    
    auto aTile=Sprite::create("UI/tile.png");
    aTile->setPosition(0,680);
    aTile->setAnchorPoint(Point(0,0));
    this->addChild(aTile,(int)Zorder::Background);
    
    auto HpBar = Sprite::create("UI/hpbar.png");
    HpBar->setAnchorPoint(Point(1,0.5));
    HpBar->setPosition(360-59,1210);
    this->addChild(HpBar,(int)Zorder::Background);
    HpBar = Sprite::create("UI/hpbar.png");
    HpBar->setAnchorPoint(Point(0,0.5));
    HpBar->setPosition(360+59,1210);
    HpBar->setFlippedX(true);
    this->addChild(HpBar,(int)Zorder::Background);
    
    auto vsui=Sprite::create("UI/vs.png");
    vsui->setPosition(360,1210);
    vsui->setAnchorPoint(Point(0.5,0.5));
    this->addChild(vsui,(int)Zorder::Content);
    
    listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}
bool GameScene::onTouchBegan(Touch* touch,Event* unused_event){
    mButtonReset->onTouchBegan(touch);
    mButtonFight->onTouchBegan(touch);
    return true;
}
void GameScene::onTouchMoved(Touch* touch,Event* unused_event){
    mButtonReset->onTouchMoved(touch);
    mButtonReset->onTouchMoved(touch);
}
void GameScene::onTouchEnded(Touch* touch,Event* unused_event){
    if(mButtonReset->onTouchEnded(touch))
        fighter->Reset();//reset
    if(mButtonFight->onTouchEnded(touch))
        ;
}

