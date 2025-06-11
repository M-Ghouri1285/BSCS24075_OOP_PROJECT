#pragma once
#ifndef FROSTSWORD_H
#define FROSTSWORD_H

#include "Item.h"
#include "Character.h"
#include "FreezeEffect.h"

class FrostSword : public Item
{
public:
    FrostSword();
    void use(Character& target) override;
};

#endif
