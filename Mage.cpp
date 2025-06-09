#include "Mage.h"
#include "Character.h"
#include <iostream>

using namespace std;

Mage::Mage(my_str name) : Character(name, 80, 80, 10, 5) {}

void Mage::specialAbility(Character& target)
{
    if (mana < 20) 
    {
        cout << "Not enough mana!" << endl; //add error exception later
        return;
    }
    mana -= 20;
    int damage = (attackPower * 1.5) - (target.getDefense() / 2);;
    cout << name << " casts FIREBALL! (" << damage << " damage)" << endl;
    target.takeDamage(damage);
}