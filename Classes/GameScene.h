#pragma once

#include "cocos2d.h"
#include "Button.h"
#include "Fighter.h"

USING_NS_CC;


class GameScene : public Layer
{
private:
    EventListenerTouchOneByOne* listener;

    Button* mButtonReset;
    Button* mButtonFight;
    
    Fighter* fighter;
    
    ProgressTimer* mProgressTimer;
    
    enum class Zorder{
        Background,
        TimeBar,
        Button,
        Content
    };
public:
    
    bool onTouchBegan(Touch* touch,Event* unused_event);
    void onTouchMoved(Touch* touch,Event* unused_event);
    void onTouchEnded(Touch* touch,Event* unused_event);
    
    static Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);
};


