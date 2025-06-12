#pragma once
#ifndef POISONEFFECT_H
#define POISONEFFECT_H

#include "StatusEffect.h"
#include <iostream>

using namespace std;

class PoisonEffect : public StatusEffect 
{
    int damagePerTurn;
public:
    PoisonEffect(int dmg, int dur);
    void onTurnStart(Character& target) override;
    void onExpire(Character& target) override;
};

#endif !POISONEFFECT
