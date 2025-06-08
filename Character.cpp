#include "Character.h"
#include <iostream>

Character::Character(my_str n, int h, int m, int atk, int def)
    : name(n), health(h), maxHealth(h), mana(m), maxMana(m),
    attackPower(atk), defense(def) {
}

Character::~Character()
{
    // Delete items and status effects later
}

void Character::addItem(Item* item)
{
    inventory.push(item);
    cout << "Added " << item->getName() << " to inventory!" << endl;
}

void Character::useItem(int index)
{
    if (index < 0 || index >= inventory.size())
    {
        cout << "Invalid item slot!" << endl; //replace with exception
        return;
    }
    inventory[index]->use();
    delete inventory[index];
    inventory.delete_at(index);
}

void Character::showInventory()
{
    cout << endl;
    cout << "=== " << name << "'s Inventory ===" << endl;
    if (inventory.empty())
    {
        cout << "Inventory is empty!" << endl; //replace with exception
        return;
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << i << ". " << inventory[i]->getName() << " - " << inventory[i]->getDesc() << endl;
    }
}

void Character::showStatus()
{
    // Implementation to be added
}

void Character::attack(Character& target)
{
    int damage = attackPower - (target.getDefense() / 2);
    if (damage < 1) damage = 1;
    cout << name << " attacks " << target.getName() << " for " << damage << " damage!" << endl;
    target.takeDamage(damage);
}

void Character::takeDamage(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        health = 0;
        cout << name << " has been defeated!" << endl;
    }
    else
    {
        cout << name << " now has " << health << "/" << maxHealth << " HP." << endl;
    }
}

my_str Character::getName() const { return name; }
int Character::getHealth() const { return health; }
int Character::getMana() const { return mana; }
int Character::getDefense() const { return defense; }
bool Character::isAlive() const { return health > 0; }

void Character::addStatusEffect(StatusEffect* effect)
{
    activeEffects.push(effect);
    cout << name << " gained " << effect->getName() << " effect!\n";
}

void Character::processStatusEffects()
{
    int i = 0;
    while (i < activeEffects.size())
    {
        activeEffects[i]->applyEffect(*this);

        if (activeEffects[i]->isExpired())
        {
            cout << name << "'s " << activeEffects[i]->getName() << " effect wore off!" << endl;
            delete activeEffects[i];
            activeEffects.delete_at(i);
        }
        else
        {
            i++;
        }
    }
}

