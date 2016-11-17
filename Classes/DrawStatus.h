//
//  DrawStatus.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//
#pragma once

#include "cocos2d.h"
#include "HealthPercent.h"

USING_NS_CC;

class DrawStatus{
private:
    Layer* mLayer;
    
    DrawNode *drawnode;
    
    const Color4F mColorLine;
    
    const Color4F mFillColor;
    
    const int mRadius;
    
    Point mStatusPoint[5];
    
public:
    DrawStatus();
    
    DrawStatus(bool IsMonster);
    
    
    void Init();
    
    void ChangePentagon(Status status);
    
    float CalculateSin(float Angle);
    float CalculateCos(float Angle);
    
    Layer* GetLayer();
};
