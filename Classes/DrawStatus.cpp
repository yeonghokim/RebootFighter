//
//  DrawStat.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//
#include "DrawStatus.h"

DrawStatus::DrawStatus()
: mRadius(100)
, mFillColor(Color4F(1,1,1, 0.5))
, mColorLine(Color4F::BLACK){
}

DrawStatus::DrawStatus(bool IsMonster)
: mRadius(100)
, mFillColor(Color4F(1,1,1,0.5))
, mColorLine(Color4F::BLACK){
}

Layer* DrawStatus::GetLayer(){
    return mLayer;
}
void DrawStatus::Init(){
    drawnode =DrawNode::create();
    drawnode->setOpacity(122);
    
    mLayer=Layer::create();
    mLayer->addChild(drawnode);
}
void DrawStatus::ChangePentagon(Status stat){
    Point Circle[5];
    
    int array[5] = {stat.mFortune,
                    stat.mAttack.mPhysical,
                    stat.mDefence.mPhysical,
                    stat.mDefence.mMagic,
                    stat.mAttack.mMagic};
    
    
    for(int i=0;i<5;i++){
        array[i] = array[i]>100?100:array[i];
        array[i] = array[i]<0?0:array[i];
        
        float Angle = CC_DEGREES_TO_RADIANS(i*(-72));//최대치
        
        Circle[i]=Point(array[i]*CalculateSin(Angle),array[i]*CalculateCos(Angle));
    }
    drawnode->clear();
    drawnode->drawPolygon(Circle, 5, mFillColor, 0, mColorLine);
}
float DrawStatus::CalculateSin(float Angle){
    return mRadius*sinf(Angle)/100;
}
float DrawStatus::CalculateCos(float Angle){
    return mRadius*cosf(Angle)/100;
}
