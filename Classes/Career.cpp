//
//  Career.cpp
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//

#include "Career.h"

std::array<int, 4> ArrayRandomMinMax() {
    std::array<int, 4> array;
    array[0] = RandomHelper::random_int(40, 100); // 최고
    array[3] = RandomHelper::random_int(0, (int)(array[0] * 0.25)); // 최저
    array[1] = RandomHelper::random_int((int)(array[3] * 1.5), (int)(array[0] * 0.9));
    array[2] = RandomHelper::random_int((int)(array[3] * 1.5), (int)(array[0] * 0.9));
    return array;
}

std::string BerserKer::GetName(){
    return "광전사";
}
std::string Knight::GetName(){
    return "기사";
}
std::string Wizard::GetName(){
    return "마법사";
}
std::string Priest::GetName(){
    return "성직자";
}
std::string Adventurer::GetName(){
    return "모험가";
}
std::string GoblinArcher::GetName(){
    return "고블린 궁수";
}
std::string GoblinWarrior::GetName(){
    return "고블린 전사";
}
std::string GoblinMagicion::GetName(){
    return "고블린 마법사";
}
std::string GoblinBoss::GetName(){
    return "고블린 족장";
}
void BerserKer::SetStatus(Status& stat) {
    Code=BERSERKER;
    std::array<int, 4> array = ArrayRandomMinMax();
    stat.mAttack.mPhysical=array[0];
    stat.mDefence.mPhysical=array[2];
    stat.mAttack.mMagic=array[1];
    stat.mDefence.mMagic=array[3];
}

void Knight::SetStatus(Status& stat) {
    Code=KNIGHT;
    std::array<int, 4> array = ArrayRandomMinMax();
    stat.mAttack.mPhysical=array[1];
    stat.mDefence.mPhysical=array[0];
    stat.mAttack.mMagic=array[3];
    stat.mDefence.mMagic=array[2];
}

void Wizard::SetStatus(Status &stat) {
    Code = WIZARD;
    std::array<int, 4> array = ArrayRandomMinMax();
    stat.mAttack.mPhysical=array[2];
    stat.mDefence.mPhysical=array[3];
    stat.mAttack.mMagic=array[0];
    stat.mDefence.mMagic=array[1];
}

int Max(int value, int max) {
    return value > max ? max : value;
}

void Priest::SetStatus(Status &stat) {
    Code=PRIEST;
    std::array<int, 4> array = ArrayRandomMinMax();
    stat.mAttack.mPhysical= Max(array[3] * 2.f, 100);
    stat.mDefence.mPhysical= array[2];
    stat.mAttack.mMagic= Max(array[1] * 2.f, 100);
    stat.mDefence.mMagic= array[0];
}

void Adventurer::SetStatus(Status &stat) {
    Code=ADVENTURER;
    
    stat.mAttack.mPhysical=RandomHelper::random_int(30, 75);
    stat.mDefence.mPhysical=RandomHelper::random_int(30, 75);
    stat.mAttack.mMagic=RandomHelper::random_int(30, 75);
    stat.mDefence.mMagic=RandomHelper::random_int(30, 75);
}
void GoblinArcher::SetStatus(Status &stat){
    //스탯
    Code=GOBLINARCHER;
    stat.mAttack.mPhysical=RandomHelper::random_int(40, 100);
    stat.mDefence.mPhysical=RandomHelper::random_int(10 * (int)(mLevel*0.001f), (int)(stat.mAttack.mPhysical*0.5));
    stat.mDefence.mMagic=RandomHelper::random_int(10 * (int)(mLevel*0.001f), (int)(stat.mAttack.mPhysical*0.5));
    stat.mAttack.mMagic=RandomHelper::random_int(stat.mDefence.mMagic, stat.mAttack.mPhysical);
}
void GoblinWarrior::SetStatus(Status& stat){
    Code=GOBLINWARRIOR;
    stat.mDefence.mPhysical=RandomHelper::random_int(40, 100);
    stat.mAttack.mMagic=RandomHelper::random_int( 10 * (int)(mLevel*0.001f), (int)(stat.mDefence.mPhysical*0.5));
    stat.mDefence.mMagic=RandomHelper::random_int(stat.mAttack.mMagic, stat.mDefence.mPhysical);
    stat.mAttack.mPhysical=RandomHelper::random_int(stat.mDefence.mMagic, stat.mDefence.mPhysical);

}
void GoblinMagicion::SetStatus(Status& stat){
    Code=GOBLINMAGICION;
    stat.mAttack.mMagic=RandomHelper::random_int(40, 100);
    stat.mAttack.mPhysical=RandomHelper::random_int(10 * (int)(mLevel*0.001f), 60);
    stat.mDefence.mPhysical=RandomHelper::random_int(10 * (int)(mLevel*0.001f), 60);
    stat.mDefence.mMagic=RandomHelper::random_int(stat.mAttack.mPhysical, stat.mAttack.mMagic);
}

void GoblinBoss::SetStatus(Status& stat){
    Code = GOBLINBOSS;
    stat.mAttack.mMagic=RandomHelper::random_int(50 * (int)(mLevel*0.001f), 100);
    stat.mAttack.mPhysical=RandomHelper::random_int(30 * (int)(mLevel*0.001f), 70);
    stat.mDefence.mPhysical=RandomHelper::random_int(60 * (int)(mLevel*0.001f), 100);
    stat.mDefence.mMagic=RandomHelper::random_int(30 + (int)(mLevel*0.001f), 70);
}


