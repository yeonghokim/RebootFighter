//
//  Fighter.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 28..
//
//

#include "Fighter.h"

Fighter::~Fighter() {
}
Health Fighter::GetHealth(){
    return mHealty;
}
Sprite* Fighter::GetSprite(){
    return mSprite;
}
DrawStatus* Fighter::GetDrawStatus(){
    return mDrawStatus;
}
Career* Fighter::GetCareer(){
    return mCareer;
}
Status Fighter::GetStatus(){
    return mStatus;
}
bool Fighter::IsCritical(){
    return RandomHelper::random_int(0, 100) <= (8 + (int)(mStatus.mFortune*0.15));
}

bool Fighter::IsAvoidDance() {
    return RandomHelper::random_int(0, 100) <= (3 + (int)(mStatus.mFortune*0.1));
}

bool Fighter::IsKill() {
    return RandomHelper::random_int(0, 100) <= (8 + (int)(mStatus.mFortune*0.15))/2;
}

void Fighter::Reset() {
    this->RandomCareer();
    this->DivideStatus();
    mDrawStatus->ChangePentagon(mStatus);
}

void Fighter::Dead(){
    mHealty.Damaged(100000000);
    
}
void Fighter::ChangeCareer(){
    switch(mCareer->Code){
        case (int)Career::BERSERKER:
            filepath="Berserker/berserker";
            break;
            
        case (int)Career::KNIGHT:
            filepath="Sword/sword";//"Sword/sword";
            break;
            
        case (int)Career::WIZARD:
            filepath="Magician/magician";
            break;
            
        case (int)Career::PRIEST:
            filepath="Priest/priest";
            break;
            
        case (int)Career::ADVENTURER:
            filepath="Adventurer/adventurer";
            break;
            
        case (int)Career::GOBLINWARRIOR:
            filepath="goblin/goblin_w";
            break;
            
        case (int)Career::GOBLINARCHER:
            filepath="goblin/goblin_a";
            break;
            
        case (int)Career::GOBLINMAGICION:
            filepath="goblin/goblin_m";
            break;
            
        case (int)Career::GOBLINBOSS:
            filepath="goblin/goblin_b";
            break;
            
        default:
            filepath="Knight/knight";
    }
    mSprite ->setTexture(filepath+"(0).png");
    
    for(int i=0;i<2;i++){
        mAttackTexture[i] = TextureManager::CreateTexture(filepath+StringUtils::format("(%d).png",i+1));
    }
    GeneralTexture = mSprite->getTexture();
}

void Fighter::RandomCareer() {
    
    int rnd =IsMonster?RandomHelper::random_int(5, 8):RandomHelper::random_int(0, 4);
    switch (rnd) {
        case (int)Career::BERSERKER:
            mCareer = new BerserKer;
            break;
        
        case (int)Career::KNIGHT:
            mCareer = new Knight;
            break;
        
        case (int)Career::WIZARD:
            mCareer = new Wizard;
            break;
        
        case (int)Career::PRIEST:
            mCareer = new Priest;
            break;
        
        case (int)Career::ADVENTURER:
            mCareer = new Adventurer;
            break;
        
        case (int)Career::GOBLINWARRIOR:
            mCareer = new GoblinWarrior;
            break;
        
        case (int)Career::GOBLINARCHER:
            mCareer = new GoblinArcher;
            break;
        
        case (int)Career::GOBLINMAGICION:
            mCareer = new GoblinMagicion;
            break;
        
        case (int)Career::GOBLINBOSS:
            mCareer = new GoblinBoss;
            break;
        
        default:
            CCLOG("Career is Not Found.");
            break;
    }
}

void Fighter::DivideStatus() {
    mCareer->SetStatus(mStatus);
    RandomFortune();

    
    
}

void Fighter::RandomFortune() {
    int allStatus = this->GetAllStatus();
    int luckH = (int)(((500.f - (float)allStatus) / 500.f) * 100) + 25;
    int luckL = 100 - luckH + 15;
    mStatus.mFortune = RandomHelper::random_int(luckL, luckH > 100 ? 100 : luckH);
}

int Fighter::GetAllStatus() {
    return mStatus.mAttack.mPhysical + mStatus.mAttack.mMagic +
        mStatus.mDefence.mPhysical + mStatus.mDefence.mMagic;
}

void Fighter::Hit(Fighter* fighter, bool Critical ) {
    fighter->mCareer->SetStatus(fighter->mStatus);
    
    int physicalDefence = fighter->mStatus.mDefence.mPhysical * 0.125f;
    int magicDefence = fighter->mStatus.mDefence.mMagic * 0.125f;
    int damage = (Critical?mStatus.mAttack.mMagic*2:mStatus.mAttack.mMagic*(25-magicDefence)/(float)25)+(Critical?mStatus.mAttack.mPhysical*2:mStatus.mAttack.mPhysical * (25-physicalDefence)/(float)25);
    
    if(damage < 0) damage = 0;
    
    fighter->mHealty.Damaged(damage);
}

void Fighter::Init(){
    if(IsMonster){
        mDrawStatus= new DrawStatus(IsMonster);
    }else
    mDrawStatus= new DrawStatus();
    mDrawStatus->Init();
    
    
    Reset();
    mHealty.Init(mStatus.mDefence);
    InitTexture();
    
}
void Fighter::InitTexture(){

    switch(mCareer->Code){
        case (int)Career::BERSERKER:
            filepath="Berserker/berserker";
            break;
            
        case (int)Career::KNIGHT:
            filepath="Sword/sword";
            break;
            
        case (int)Career::WIZARD:
            filepath="Magician/magician";
            break;
            
        case (int)Career::PRIEST:
            filepath="Priest/priest";
            break;
            
        case (int)Career::ADVENTURER:
           filepath="Adventurer/adventurer";
            break;
            
        case (int)Career::GOBLINWARRIOR:
            filepath="goblin/goblin_w";
            break;
            
        case (int)Career::GOBLINARCHER:
            filepath="goblin/goblin_a";
            break;
            
        case (int)Career::GOBLINMAGICION:
            filepath="goblin/goblin_m";
            break;
            
        case (int)Career::GOBLINBOSS:
            filepath="goblin/goblin_b";
            break;
            
        default:
            filepath="Knight/knight";
            
            
    }
    mSprite = Sprite::create(filepath+"(0).png");
    
    for(int i=0;i<2;i++){
        mAttackTexture[i] = TextureManager::CreateTexture(filepath+StringUtils::format("(%d).png",i+1));
    }
    GeneralTexture = mSprite->getTexture();
    
}
void Fighter::DieAction(){
    
    
    
    
    
    
    
    
    
    
    
}
void Fighter::SetMonster(){
    IsMonster=true;
}
