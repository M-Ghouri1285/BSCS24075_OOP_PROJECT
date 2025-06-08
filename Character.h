#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "my_str.h"
#include "vector.h"

class Item;
class StatusEffect;
class Character;

class Character
{
protected:
    my_str name;
    int health;
    int maxHealth;
    int mana;
    int maxMana;
    int attackPower;
    int defense;
    Dynamic_array<Item*> inventory;
    Dynamic_array<StatusEffect*> activeEffects;

public:
    Character(my_str n, int h, int m, int atk, int def);
    virtual ~Character();

    void addItem(Item* item);
    void useItem(int index);
    void showInventory();
    void showStatus();
    virtual void attack(Character& target);
    void takeDamage(int damage);
    virtual void specialAbility(Character& target) = 0;

    my_str getName() const;
    int getHealth() const;
    int getMana() const;
    int getDefense() const;
    bool isAlive() const;

    void addStatusEffect(StatusEffect* effect);
    void processStatusEffects();
};

#endif !CHARACTER_H 