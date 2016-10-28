//
//  DamagePercent.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//

#include "DamagePercent.h"
DamagePercent::DamagePercent() : mChangeValue( 1.0f ){

}
int DamagePercent::GetPhysicalDamage() const{
    return mPM.mPhysical;
}
int DamagePercent::GetMagicDamage() const{
    return mPM.mMagic;
}

void DamagePercent::SetStatus(int physicDamage, int magicDamage){
    
    mPM.mPhysical=physicDamage;
    mPM.mMagic=magicDamage;
    
}

int Clamp(int value, int min, int max){
    return (value< min) ? min :(value>max)? max:value;
}

int DamagePercent::CalculatePercent(int luck,PM defence){
    //
    return (CalculateDamage(mPM.mPhysical, luck)+CalculateDamage(mPM.mMagic, luck))*mChangeValue;
}

int DamagePercent::CalculateDamage(int damage, int luck)
{
    int percent = random(-40, 40) + ((40 * random(0, luck)) / 100);
    Clamp(percent, -40, 40);
    return damage + (damage * percent) / 100;
}

