//
//  Fighter.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//

#include "Fighter.h"

DrawStatus* Fighter::GetDrawStatus(){
    return mDrawStatus;
}
void Fighter::Reset(){
    mAttribute = (Attribute)RandomHelper::random_int(0, 3);
    mProperty.DivideStatus(mAttribute);
    mDrawStatus->ChangePentagon(mProperty);
}
bool Fighter::IsCritical(){
    return RandomHelper::random_int(0, 1);
}

void Fighter::Init(){
    mDrawStatus= new DrawStatus();
    mDrawStatus->Init();
    
}
