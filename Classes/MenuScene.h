//
//  MenuScene.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//
#pragma once

#include "cocos2d.h"
#include "Button.h"

USING_NS_CC;

class MenuScene: public Layer{
private:
    Button* mStart;
    
    Sprite* StatusGraph;
    
    EventListenerTouchOneByOne* listener;
    
public:
    ~MenuScene();
    void ScaleCalculate(float dt);
    
    bool onTouchBegan(Touch* touch,Event* unused_event);
    void onTouchMoved(Touch* touch,Event* unused_event);
    void onTouchEnded(Touch* touch,Event* unused_event);
    
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(MenuScene);
    
};
