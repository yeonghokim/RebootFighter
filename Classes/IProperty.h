//
//  IProperty.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//

#ifndef IProperty_h
#define IProperty_h

struct PM {
    int mPhysical;
    int mMagic;
};

class IProperty 
{
    virtual int CalculatePercent(int luck,PM pm) = 0;
    
};


#endif 
