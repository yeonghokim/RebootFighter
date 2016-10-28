//
//  HealthPercent.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//

#include "HealthPercent.h"

HealthPercent::HealthPercent()
: mBaseHealth(100)
, mChangeValue(1.0f){
    
}

int HealthPercent::GetPhysicalDefense() const{
    return mPhysicalDefense;
}
int HealthPercent::GetMagicDefense() const{
    return mMagicDefense;
}

void HealthPercent::SetStatus(int physicDefence, int magicDefence){
    
    mPhysicalDefense=physicDefence;
    mMagicDefense=magicDefence;

}
int HealthPercent::CalculatePercent(int luck, PM damage){
    //구현 아직 안함
    return 0;
}

