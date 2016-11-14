//
//  Career.h
//  RebootFighter
//
//  Created by 김영호 on 2016. 10. 29..
//
//
#pragma once

#include "cocos2d.h"

USING_NS_CC;

#include "Status.h"

#include <array>

using namespace std;

class Career
{
public:
    enum { BERSERKER, KNIGHT, WIZARD, PRIEST, ADVENTURER,GOBLINWARRIOR,GOBLINARCHER,GOBLINMAGICION,GOBLINBOSS, LENGTH };
    
    int Code;
    int mLevel = 1;
public:
    virtual void SetStatus(Status& stat) = 0;
    virtual std::string GetName() = 0;
};

class BerserKer : public Career {
public:
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};

class Knight : public Career {
public:
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};

class Wizard : public Career {
public:
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};

class Priest : public Career {
public:
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};

class Adventurer : public Career {
public:
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};
class GoblinArcher : public Career{
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};
class GoblinWarrior : public Career{
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};
class GoblinMagicion : public Career{
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};
class GoblinBoss: public Career{
    void SetStatus(Status& stat) override;
    virtual std::string GetName() override;
};
