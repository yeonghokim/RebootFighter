//
//  DelayManager.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 30..
//
//
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class DelayManager{
private:
    
    int mDelaynum;
    
public:
    void Setnum(int a){mDelaynum=a;}
    
    DelayManager(int delaynum){ mDelaynum=delaynum;}
    
    void Update(float dt){ if(mDelaynum>0) mDelaynum--;}
    
    bool IsContinue(){return mDelaynum==0;}
    
    
};
