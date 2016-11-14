//
//  CocosMusic.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 30..
//
//
#include "CocosMusic.h"


void CocosMusic::PlayBGM01(){
    SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/bgm_01.mp3", false);
}
unsigned int CocosMusic::playEffectHit(){
    SimpleAudioEngine::getInstance()->playEffect("Music/hit_m_001.mp3", false);
}
