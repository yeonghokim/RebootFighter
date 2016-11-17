#include "GameScene.h"
#include "MenuScene.h"
#include "CocosMusic.h"

int GameScene::mStage=-1;

Scene* GameScene::createScene(){

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
    mGameStatus= new GameStatus();
    
    mStage++;
    
    mSequence=nullptr;
    
    IsPlayerTurn=true;
    IsTime=true;
    
//---------------------------상단--------------------------//

    CCLOG("GameSceneInit");

    //플레이어 객체
    mFighter = new Fighter();
    mFighter->Init();
    mFighter->GetDrawStatus()->GetLayer()->setPosition(190,420);
    this->addChild(mFighter->GetDrawStatus()->GetLayer(),(int)Zorder::FighterSprite);
    
    //몬스터 객체
    mMonster= new Fighter();
    mMonster->SetMonster();
    mMonster->Init();
    mMonster->GetDrawStatus()->GetLayer()->setPosition(537,420);
    this->addChild(mMonster->GetDrawStatus()->GetLayer(),(int)Zorder::MonsterSprite);
    
//---------------------------------------------------------//
    MakeHpBar();

    auto vsbar = Sprite::create("ver2/UI/hpbar_middle.png");
    vsbar->setPosition(360,1210);
    this->addChild(vsbar,(int)Zorder::VsBar);
//---------------------------------------------------------//
    
    //몬스터 이미지
    Sprite* MonsterSprite = mMonster->GetSprite();
    if(mMonster->GetCareer()->GetName()=="고블린 족장")
        MonsterSprite->setPosition(400,680);
    else
        MonsterSprite->setPosition(540,680);
    MonsterSprite->setAnchorPoint(Point(0.5,0));
    this->addChild(MonsterSprite,(int)Zorder::MonsterSprite);

    //플레이어 이미지
    Sprite* FighterSprite = mFighter->GetSprite();
    FighterSprite->setPosition(180,700);
    FighterSprite->setAnchorPoint(Point(0.5,0));
    this->addChild(FighterSprite,(int)Zorder::FighterSprite);
//---------------------------------------------------------//
    
    //배경 이미지
    auto bg = Sprite::create("UI/bg.png");
    bg->setPosition(0, 680);
    bg->setAnchorPoint(Point(0,0));
    this->addChild(bg,(int)Zorder::Background);

//-------------------------------중간----------------------------------------//
    CCLOG("Init Medle");
    TimeTexture[0]=TextureManager::CreateTexture("ver2/UI/timebar_energy.png");
    TimeTexture[1]=TextureManager::CreateTexture("TimeBar/TimeBarFullRed.png");
    
    //시간바
    MakeProgressTimer();
    
    MakeCareerText();
    
    //스테이터스 배경 이미지
    mStatusBack=Sprite::create("ver2/rebootUI/layout_ability-graph.png");
    mStatusBack->setPosition(0,242);
    mStatusBack->setAnchorPoint(Point(0,0));
    this->addChild(mStatusBack,(int)Zorder::Background);
//--------------------------------하단---------------------------------------//
    CCLOG("Init Bottom");
    
    //버튼 두개
    mButtonReset= Button::create();
    mButtonFight= Button::create();
    
    mButtonArray.push_back(mButtonReset);
    mButtonArray.push_back(mButtonFight);
    
    mButtonReset->Init("UI/Button/btn_un.png", "UI/Button/btn_touch.png", "Reboot");
    mButtonFight->Init("UI/Button/btn_un.png", "UI/Button/btn_touch.png", "Fight");
    
    Point buttonposition[2] ={Point(180,61),Point(540,61)};
    int tmp=0;
    for(Button* button : mButtonArray){
        button->mSprite->setAnchorPoint(Point(tmp,0));
        button->GetLabel()->setPosition(buttonposition[tmp++]);
        this->addChild(button->mSprite,1);
        this->addChild(button->GetLabel(),(int)Zorder::Button);
    }
    mButtonFight->mSprite->setPosition(720,0);
    
//--------------------------------listener---------------------------------//
    listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->schedule(schedule_selector(GameScene::SetBattle), 1.0f);
    this->schedule(schedule_selector(GameScene::TextureSchedule), 0.3f);
    
    this->schedule(schedule_selector(GameScene::update), 0.1f);
    
    CCLOG("GameSceneInitClear");
    
    return true;
}

bool GameScene::onTouchBegan(Touch* touch,Event* unused_event){
    
    //-----------------------게임오버-------------------------------//
    if(mGameStatus->GetStatus()==(int)GameStatus::nStatus::NEXTSCENE){
        mButtonRestart->onTouchBegan(touch);
        mButtonMain->onTouchBegan(touch);
        return true;
    }
    
    //------------------------파워업 버튼 ---------------------------//
    if(mGameStatus->GetStatus()==(int)GameStatus::nStatus::FIGHT){
        mButtonPowerup->onTouchBegan(touch);
        return true;
    }
    
    //-----------------------리부트, 파이트 버튼 --------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::TIMEACTION)){
        mButtonReset->onTouchBegan(touch);
        mButtonFight->onTouchBegan(touch);
    }
    
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIRSTATTACK)){
        mFirstChanceButton->onTouchBegan(touch);
    }
    return true;
}

void GameScene::onTouchMoved(Touch* touch,Event* unused_event){
    
    //-----------------------게임오버-------------------------------//
    if(mGameStatus->GetStatus()==(int)GameStatus::nStatus::NEXTSCENE){
        mButtonRestart->onTouchMoved(touch);
        mButtonMain->onTouchMoved(touch);
        return;
    }
    
    //------------------------파워업 버튼 ---------------------------//
    if(mGameStatus->GetStatus()==(int)GameStatus::nStatus::FIGHT){
        mButtonPowerup->onTouchMoved(touch);
        return;
    }
    
    //-----------------------리부트, 파이트 버튼 --------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::TIMEACTION)){
        mButtonReset->onTouchMoved(touch);
        mButtonFight->onTouchMoved(touch);
    }
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIRSTATTACK)){
        mFirstChanceButton->onTouchMoved(touch);
    }
}

void GameScene::onTouchEnded(Touch* touch,Event* unused_event){
    
    //TEXT=0,BEFORTIME,TIMEACTION,BEFORFIRSTATTACK,FIRSTATTACK,BEFORFIGHT,FIGHT,RESULT,NEXTSCENE
    //-----------------------리부트, 파이트 버튼 --------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::TIMEACTION)&&mButtonReset->onTouchEnded(touch)){//Reboot 눌러지면
        mFighter->Reset();//reset
        mFighter->ChangeCareer();
        mFighterHpBar->SetMaxHp(mFighter->GetHealth().GetHealthPointer());
        mCareerLabel->setString(mFighter->GetCareer()->GetName());
    }
    if(mGameStatus->IsStatus(GameStatus::nStatus::TIMEACTION)&&mButtonFight->onTouchEnded(touch)){//Fight 눌러지면
        mProgressTimer->stopAllActions();
        mGameStatus->NextStage();
    }
    
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIRSTATTACK)){
        if(mFirstChanceButton->onTouchEnded(touch))
            mFirstChance->onTouchEnded(touch);
    }
    
    //------------------------파워업 버튼 ---------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIGHT)){
        if(mButtonPowerup->onTouchEnded(touch)){
            //power 버튼 눌리면
        }
        return;
    }
    
    //-----------------------게임오버-------------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::NEXTSCENE)&&Button::IsSprite){
        if(mButtonRestart->onTouchEnded(touch)){
            Button::IsSprite=false;
            Director::getInstance()->replaceScene(GameScene::createScene());
            mGameStatus->NextStage();
        }
        if(mButtonMain->onTouchEnded(touch)){
            Button::IsSprite=false;
            Director::getInstance()->replaceScene(MenuScene::createScene());
            mGameStatus->NextStage();
        }
        return;
    }
}
void GameScene::update(float dt){
    mGameStatus->Update();
    
    //------------------- 50퍼 이하일때 색바꾸기 -------------------------------//
    if(mProgressTimer->getPercentage()<=50&&mGameStatus->IsStatus(GameStatus::nStatus::TIMEACTION)){
        if(!this->isScheduled(schedule_selector(GameScene::NoTimeTexture)))
            this->schedule(schedule_selector(GameScene::NoTimeTexture), 0.3f);
    }
    
    
    //---------------------- 처음 -------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::TEXT)){
        CCLOG("update start");
        mStartLabel=Label::createWithTTF(StringUtils::format("%d Stage\n 도전",mStage+1), "fonts/jungfont.ttf", 60);
        mStartLabel->setAlignment(TextHAlignment::CENTER);
        mStartLabel->setPosition(0,900);
        
        this->addChild(mStartLabel,1000);
        
        MoveBy *action = MoveBy::create( 1.0, Vec2( 360, 0 ) );
        
        // easing action\
        
        Sequence* sequence = Sequence::create(EaseBackOut::create( action ),DelayTime::create(1.0f),FadeOut::create(0.01f),NULL);
        mStartLabel->runAction( sequence );
        
        
        mGameStatus->NextStage();
        return;
    }
    
    //--------------------- 두번째 -------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::BEFORTIME)){
        auto action = ProgressFromTo::create(8, 100, 0);
        mProgressTimer->runAction(action);
        mGameStatus->NextStage();
    }
    
    //----------------------세번째--------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::TIMEACTION)&&mProgressTimer->getPercentage()==0){
        //죽이고 게임 종료
        
        mGameStatus->SetStage(GameStatus::nStatus::NEXTSCENE);
        
        GameOver();
        //게임 오버
        return;
    }
    
    //----------------------네번째--------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::BEFORFIRSTATTACK)){
        RemoveForParent(mFighter->GetDrawStatus()->GetLayer());
        RemoveForParent(mMonster->GetDrawStatus()->GetLayer());
        RemoveForParent(mCareerLabel);
        RemoveForParent(mMonsterCareerLabel);
        RemoveForParent(mStatusBack);
        RemoveForParent(mButtonFight->GetLabel());
        RemoveForParent(mButtonReset->GetLabel());
        RemoveForParent(mButtonFight->mSprite);
        RemoveForParent(mButtonReset->mSprite);
        
        mFirstChance= new FirstChance();
        mFirstChance->Init();
        mFirstChance->GetParents(this,(int)Zorder::Background);
        this->addChild(mFirstChance->GetLayout(),(int)Zorder::Background);
        this->schedule(schedule_selector(GameScene::UpdateFirstChance), 0.1f);
        
        auto mFirstChanceLabel = Label::createWithTTF("선공정하기", "fonts/jungfont.ttf", 60);
        mFirstChanceLabel->setAlignment(TextHAlignment::CENTER);
        mFirstChanceLabel->setPosition(360,900);
        Spawn* spawn =Spawn::create(FadeOut::create(0.5f),MoveBy::create(0.5f, Point(0,50)), NULL);
        
        mSequence = Sequence::create(DelayTime::create(1.0f),spawn, NULL);
        mFirstChanceLabel->runAction(mSequence);
        
        mFirstChanceButton=Button::create("ver2/SelectAttackUI/power-up.png");
        mFirstChanceButton->Init("ver2/SelectAttackUI/power-up.png","ver2/SelectAttackUI/power-up(off).png","");
        mFirstChanceButton->mSprite->setAnchorPoint(Point(0,0));
        this->addChild(mFirstChanceButton->mSprite,(int)Zorder::Button);
        
        mGameStatus->NextStage();
    }
        
    //----------------------다섯번째--------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIRSTATTACK)){
        if(mFirstChance->IsPlayerWin()||mFirstChance->IsMonsterWin()){
            MakePowerUpButton();
        }
        
        if(mFirstChance->IsMonsterWin()){

            IsPlayerTurn=false;
            mGameStatus->NextStage();
        }else if(mFirstChance->IsPlayerWin()){
            
            IsPlayerTurn=true;
            mGameStatus->NextStage();
        }
    }
    
    //----------------------네번째--------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::BEFORFIGHT)){
        Label* startlabel = Label::createWithTTF("FIGHT", "fonts/jungfont.ttf", 80);
        startlabel->setColor(Color3B::WHITE);
        startlabel->setPosition(360,1000);
        this->addChild(startlabel,(int)Zorder::Content);
        
        Spawn* spawn =Spawn::create(FadeOut::create(0.5f),MoveBy::create(0.5f, Point(0,50)), NULL);
    
        mSequence = Sequence::create(DelayTime::create(1.0f),spawn, NULL);
        
        startlabel->runAction(mSequence);
        mGameStatus->NextStage();
        return;
    }
    
    //----------------파이터가 죽었는지 확인-----------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIGHT)&&mFighter->GetHealth().IsDie()){
        mGameStatus->SetStage(GameStatus::nStatus::NEXTSCENE);
        mFighter->DieAction();
        GameOver();
        
    
    }else//-----------------------몬스터가 죽었는지 확인----------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIGHT)&&mMonster->GetHealth().IsDie()){
        mGameStatus->NextStage();
        mMonster->DieAction();
    }
    
    //----------------------몬스터가 죽고 씬바꾸기-----------------------------//
    if(mGameStatus->IsStatus(GameStatus::nStatus::RESULT)&&mMonster->GetHealth().IsDie()&&Button::IsSprite){
        Button::IsSprite=false;
        auto scene =TransitionFade::create(1.0f, GameScene::createScene());
        Director::getInstance()->replaceScene(scene);
        mGameStatus->SetStage(GameStatus::nStatus::NEXTSCENE);
        mGameStatus->NextStage();
    }

}
void GameScene::TextureSchedule(float dt){
    if(!mFighter->GetHealth().IsDie())
        mFighter->ChangeTexture();
    if(!mMonster->GetHealth().IsDie())
        mMonster->ChangeTexture();
}
void GameScene::SetBattle(float dt){
    
    if(mGameStatus->GetStatus()==(int)GameStatus::nStatus::RESULT) return;
    
    
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIGHT)){
        //자동 배틀 시스템(수정 아직X)
        if(IsPlayerTurn) {
            mFighter->StartAttack();
            
            this->reorderChild(mFighter->GetSprite(),(int)Zorder::Content-1);
            this->reorderChild(mMonster->GetSprite(),(int)Zorder::Content-2);
            
            if(mFighter->GetCareer()->GetName()!="마법사"&&mFighter->GetCareer()->GetName()!="성직자"){
            
                MoveBy* move = MoveBy::create(0.1, Point(260,0));
                DelayTime* delay =DelayTime::create(0.4);
                DelayTime* delay2 =DelayTime::create(0.3);
                auto Hitaction = CallFunc::create( CC_CALLBACK_0(GameScene::HitMonster, this) );
                MoveBy* move2 =MoveBy::create(0.2, Point(-260,0));
                
                Sequence* sequence = Sequence::create(move,delay,Hitaction,delay2,move2, NULL);
                
                    
                mFighter->GetSprite()->runAction(sequence);
            }else{
                if(mFighter->GetCareer()->GetName()=="마법사"){
                    Sprite* magic = Sprite::create("Character/Magician/magic.png");
                    Point position =mFighter->GetSprite()->getPosition();
                    position.x+=100;
                    position.y+=100;
                    magic->setPosition(position);
                    this->addChild(magic,1000);
                    
                    magic->runAction(Sequence::create(MoveBy::create(0.5f, Point(250,0)),FadeOut::create(0.001f),NULL));
                    
                }
                DelayTime* delay =DelayTime::create(0.5);
                DelayTime* delay2 =DelayTime::create(0.5);
                auto Hitaction = CallFunc::create( CC_CALLBACK_0(GameScene::HitMonster, this) );
                
                Sequence* sequence = Sequence::create(delay,Hitaction,delay2, NULL);
                
                
                mFighter->GetSprite()->runAction(sequence);
            }
            //텍스쳐도 바꾸기
            IsPlayerTurn=false;
        }else{
            mMonster->StartAttack();
            //텍스쳐도 바꾸기
            
            this->reorderChild(mFighter->GetSprite(),(int)Zorder::Content-2);
            this->reorderChild(mMonster->GetSprite(),(int)Zorder::Content-1);

            if(mMonster->GetCareer()->GetName()=="고블린 전사"){
                MoveBy* move = MoveBy::create(0.1, Point(-260,0));
                DelayTime* delay =DelayTime::create(0.4);
                DelayTime* delay2 =DelayTime::create(0.3);
                auto Hitaction = CallFunc::create( CC_CALLBACK_0(GameScene::HitPlayer, this) );
                MoveBy* move2 =MoveBy::create(0.2, Point(260,0));
                
                Sequence* sequence = Sequence::create(move,delay,Hitaction,delay2,move2, NULL);
                
                mMonster->GetSprite()->runAction(sequence);
            }else{
                DelayTime* delay =DelayTime::create(0.5);
                DelayTime* delay2 =DelayTime::create(0.5);
                auto Hitaction = CallFunc::create( CC_CALLBACK_0(GameScene::HitPlayer, this) );
                
                Sequence* sequence = Sequence::create(delay,Hitaction,delay2, NULL);
                
                mMonster->GetSprite()->runAction(sequence);
            }
            CCLOG("Fighter Damaged");
            IsPlayerTurn=true;
        }
    }
}


void GameScene::GameOver(){
    mGameOverLayer =LayerColor::create(Color4B(Color4F(0,73/(float)255,170/(float)255,0.7)));
    this->addChild(mGameOverLayer,(int)Zorder::GameOverLayer);
    
    mButtonRestart= (Button*)Button::create("Button/btn_un.png");
    mButtonRestart->Init("Button/btn_un.png", "Button/btn_touch.png", "restart");
    mButtonRestart->mSprite->setPosition(Point(360,500));
    mButtonRestart->GetLabel()->setPosition(Point(360,500));
    mGameOverLayer->addChild(mButtonRestart->mSprite,1);
    mGameOverLayer->addChild(mButtonRestart->GetLabel(),1);
    
    IsTexture=true;
    
    mGameOver=Sprite::create("UI/gameover(0).png");
    mGameOver->setPosition(360,900);
    mGameOverTexture[0]=mGameOver->getTexture();
    mGameOverTexture[1]=Sprite::create("UI/gameover(1).png")->getTexture();
    mGameOverLayer->addChild(mGameOver,1);
    this->schedule(schedule_selector(GameScene::GameOverTexture), 0.3f);
    
    mButtonMain= (Button*)Button::create("Button/btn_un.png");
    mButtonMain->Init("Button/btn_un.png", "Button/btn_touch.png", "Main menu");
    mButtonMain->mSprite->setPosition(Point(360,370));
    mButtonMain->GetLabel()->setPosition(Point(360,370));
    mGameOverLayer->addChild(mButtonMain->mSprite,1);
    mGameOverLayer->addChild(mButtonMain->GetLabel(),1);
}

void GameScene::GameOverTexture(float dt){
    if(IsTexture)
        mGameOver->setTexture(mGameOverTexture[0]);
    else
        mGameOver->setTexture(mGameOverTexture[1]);
    IsTexture=(!IsTexture);
    
}
void GameScene::NoTimeTexture(float dt){
    if(mGameStatus->GetStatus()>(int)GameStatus::nStatus::TIMEACTION) return;
    
    if(IsTime)
        mProgressTimer->getSprite()->setTexture(TimeTexture[1]);
    else
        mProgressTimer->getSprite()->setTexture(TimeTexture[0]);
    
    IsTime=!IsTime;
}

void GameScene::UpdateFirstChance(float dt){
    if(mGameStatus->IsStatus(GameStatus::nStatus::FIRSTATTACK))
    mFirstChance->Update(dt);
}
void GameScene::RemoveForParent(Node* node){
    node->setVisible(false);
    node->getParent()->removeChild(node);
}
