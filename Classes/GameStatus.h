//
//  GameStatus.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 31..
//
//
#pragma once

#include "cocos2d.h"

USING_NS_CC;

#define DelayTEXT 0
#define DelayBEFORTIME 1
#define DelayTIMEACTION 0
#define DelayBEFORFIGHT 1
#define DelayFIGHT 1
#define DelayRESULT 1
#define DelayNEXTSCENE 0

#define DelayFrame 10

class GameStatus{
private:
    int mDelayNumber[7] ={DelayTEXT*DelayFrame
                         ,DelayBEFORTIME*DelayFrame
                         ,DelayTIMEACTION*DelayFrame
                         ,DelayBEFORFIGHT
                         ,DelayFIGHT*DelayFrame
                         ,DelayRESULT*DelayFrame
                         ,DelayNEXTSCENE*DelayFrame};
    
    int mStatus;
    
    int mDelay;
    
public:
    void Update();
    
    enum class nStatus{
        TEXT=0,BEFORTIME,TIMEACTION,BEFORFIGHT,FIGHT,RESULT,NEXTSCENE
    };
    /*
     enum class nStatus{
     TEXT=0,BEFORTIME,TIMEACTION,BEFORFIRSTATTACK,FIRSTATTACK,BEFORFIGHT,FIGHT,RESULT,NEXTSCENE
     };
     시작 -> 스탯 선택 -> 선공 잡기 -> 스킬 사용 및 탭핑 -> 승리 또는 패배
     */
    
    GameStatus();
    
    void NextStage();
    void SetStage(nStatus status);
    
    int GetStatus();
    
    bool IsAction();
    
    void StartAction();
    
    bool IsStatus(nStatus status);
    
};
