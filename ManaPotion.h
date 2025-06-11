#pragma once
#ifndef MANAPOTION_H
#define MANAPOTION_H

#include "Item.h"
#include "Character.h"

class ManaPotion : public Item 
{
private:
    int manaAmount;
public:
    ManaPotion();
    void use(Character& target) override;
};

#endif
