#pragma once
#ifndef POISONDAGGER_H
#define POISONDAGGER_H

#include "Item.h"
#include "Character.h"
#include "PoisonEffect.h"

class PoisonDagger : public Item
{
public:
    PoisonDagger();
    void use(Character& target) override; 
};

#endif
