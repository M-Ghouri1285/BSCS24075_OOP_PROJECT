#pragma once
#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Item.h"
#include "Character.h" 

class HealthPotion : public Item
{
private:
    int healAmount;
public:
    HealthPotion();
    void use(Character& target) override; 
};

#endif

