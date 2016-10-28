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
, mFillColor(Color4F(0,0,1,0.5))
, mColorLine(Color4F::BLACK){
}
Layer* DrawStatus::GetLayer(){
    return mLayer;
}
void DrawStatus::Init(){
    mLayer=Layer::create();
    drawnode =DrawNode::create();
    drawnode->setOpacity(122);
    Point Circle[5]={Point(0,0)};
    
    mLayer->addChild(drawnode);
}
void DrawStatus::ChangePentagon(Property property){
    
    Point Circle[5];
    int array[5] = {property.mFortune,property.mDamage.GetPhysicalDamage(),property.mHealth.GetPhysicalDefense(),property.mHealth.GetMagicDefense(),property.mDamage.GetMagicDamage()};
    
    for(int i=0;i<5;i++){
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
