//
//  HealthPercent.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//

#include "HealthPercent.h"

float Health::GetPercentHealth(){
    return mHealth/(float)mMaxHealth*100;
}
void Health::Damaged(int damage){
    mHealth-=damage;
}
void Health::Init(Element defence){
    
    int baseHp=150;
    
    mHealth=baseHp+3*(defence.mMagic+defence.mPhysical);
    mMaxHealth=mHealth;
    
}
bool Health::IsDie(){
    return mHealth<=0;
}