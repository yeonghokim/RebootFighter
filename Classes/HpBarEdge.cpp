//
//  HpBarEdge.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 11. 16..
//
//
#include "HpBarEdge.h"

void HpBarEdge::AutoSetting(HpBar* hpbar,bool fliped,bool isBtype){
    mLayer=Layer::create();
    
    IsBtype=isBtype;
    IsFlip=fliped;
    
    int maxhp = hpbar->GetMaxHp();
    if(maxhp>650&&!isBtype){
        maxhp=650;
    }else if(maxhp>650&&isBtype){
        maxhp-=650;
    }
    
    mEdge = Sprite::create("ver2/UI/hpbar_edge.png");
    mEdge->setAnchorPoint(Point(fliped?1:0,0.5));
    mEdge->setPositionX(fliped?19:-19);
    mEdge->setFlippedX(fliped);
    mLayer->addChild(mEdge);
    
    mBody = Sprite::create("ver2/UI/hpbar_body.png");
    mBody->setAnchorPoint(Point(fliped?1:0,0.5));
    mLayer->addChild(mBody);
    
    mFinalEdge = Sprite::createWithTexture(mEdge->getTexture());
    mFinalEdge->setFlippedX(!fliped);
    mLayer->addChild(mFinalEdge);

    if(isBtype) SetBtype();
    
    ChangeSetting(hpbar);
}

void HpBarEdge::ChangeSetting(HpBar *hpbar){
    
    int maxhp = hpbar->GetMaxHp();
    if(maxhp>650&&!IsBtype){
        maxhp=650;
    }else if(maxhp>650&&IsBtype){
        maxhp-=650;
    }else if(IsBtype){
        maxhp=0;
    }
    
    
    mBody->setScaleX(ceil(maxhp/50+1));
    mFinalEdge->setPosition(ceil(maxhp/50+1)*21,0);
    if(IsFlip) mFinalEdge->setPositionX(mFinalEdge->getPositionX()*(-1));
    
}
void HpBarEdge::SetBtype(){
    IsBtype=true;
    mLayer->setPosition(mLayer->getPosition()+Point(IsFlip?-50:50,-50));
}
void HpBarEdge::SetVisible(bool visible){
    mEdge->setVisible(visible);
    mBody->setVisible(visible);
    mFinalEdge->setVisible(visible);
}
