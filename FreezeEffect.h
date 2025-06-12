#pragma once
#ifndef FREEZEEFFECT_H
#define FREEZEEFFECT_H

#include "StatusEffect.h"
#include <iostream>

using namespace std;

class FreezeEffect : public StatusEffect
{
    int manaDrainPerTurn;

public:
    FreezeEffect(int drain, int dur);
    void onTurnStart(Character& target) override;
    void onExpire(Character& target) override;
};

#endif !FROSTEFFECT_H
