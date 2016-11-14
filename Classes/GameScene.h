#pragma once

#include "cocos2d.h"
#include "Button.h"
#include "Fighter.h"

#include "DelayManager.h"
#include "GameStatus.h"
USING_NS_CC;

class GameScene : public Layer
{
private:
    GameStatus* mGameStatus;
    
    Sequence* mSequence;
    
    Label* mStartLabel;    
private:
    
    //플레이어 턴, 몬스터 턴인지,
    bool IsPlayerTurn;
    
    EventListenerTouchOneByOne* listener;

    //하단 버튼
    Button* mButtonReset;
    Button* mButtonFight;
    std::vector<Button*> mButtonArray;
    
    Button* mButtonPowerup;
    
    //파이터 두마리
    Fighter* mFighter;
    Fighter* mMonster;
    
    //타임바
    bool IsTime;
    ProgressTimer* mProgressTimer;
    Texture2D* TimeTexture[2];//타임바 색깔 텍스쳐 두개(50이하일때 번갈아 가면서)
    
    //HP 블라인더
    LayerColor* mFighterBlinder;
    LayerColor* mMonsterBlinder;
    
    //직업 텍스트 뷰어
    Label* mCareerLabel;
    Label* mMonsterCareerLabel;

    //게임 종료부분 버튼 두개
    Button* mButtonRestart;
    Button* mButtonMain;
    
    //게임 오버 텍스쳐 두개(번갈아 가면서)
    bool IsTexture;
    Sprite* mGameOver;
    Texture2D* mGameOverTexture[2];
    //게임 오버 레이어
    LayerColor* mGameOverLayer;
    
    enum class Zorder{
        Background,
        TimeBar,
        MonsterSprite,
        FighterSprite,
        Button,
        Content,
        Blinder,
        PowerButton,
        GameOverLayer,
        GameOverContent
    };
private:
    void HitMonster();
    
    void HitPlayer();
    
    void GameOver();
    
    void GameOverTexture(float dt);
    
    void NoTimeTexture(float dt);
    
public:
    static int mStage;
public:
    void update(float dt);
    
    void SetBattle(float dt);
    
    void TextureSchedule(float dt);
    
    bool onTouchBegan(Touch* touch,Event* unused_event);
    void onTouchMoved(Touch* touch,Event* unused_event);
    void onTouchEnded(Touch* touch,Event* unused_event);
    
    static Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);
};


