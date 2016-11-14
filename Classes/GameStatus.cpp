//
//  GameStatus.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 31..
//
//
#include "GameStatus.h"

GameStatus::GameStatus(){
    mStatus=(int)nStatus::TEXT;
    mDelay=mDelayNumber[mStatus];
}
void GameStatus::NextStage(){
    mStatus++;
    mDelay=mDelayNumber[mStatus];
}
void GameStatus::SetStage(nStatus status){
    mStatus= (int)status;
    mDelay=mDelayNumber[mStatus];
}
int GameStatus::GetStatus(){
    return mStatus;
}
bool GameStatus::IsAction(){
    return mDelay!=0;
}
void GameStatus::StartAction(){
    mDelay = mDelayNumber[mStatus];
}
void GameStatus::Update(){
    if(mDelay>0)
        mDelay--;
    else
        mDelay=0;
}
bool GameStatus::IsStatus(nStatus status){
    return (mDelay==0)&&(mStatus==(int)status);
}
