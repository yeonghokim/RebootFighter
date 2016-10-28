//
//  Property.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//

#include "Property.h"

void Property::DivideStatus(Attribute mAttribute){
    int physicDefense = RandomHelper::random_int(0, 100), magicDefense = RandomHelper::random_int(0, 100);
    int physicDamage = RandomHelper::random_int(0, 100), magicDamage = RandomHelper::random_int(0, 100);
    
    mFortune=RandomHelper::random_int(0, 100);
    
    
    
    
    
    
    
    
    
    
    mHealth.SetStatus(physicDefense, magicDefense);
    mDamage.SetStatus(physicDamage,magicDamage);
    
}
