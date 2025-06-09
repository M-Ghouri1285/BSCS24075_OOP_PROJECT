#include "Archer.h"
#include <iostream>

using namespace std;

Archer::Archer(my_str name): Character(name, 90, 40, 12, 8) {}
void Archer::specialAbility(Character& target) 
{
    if (mana < 25) 
    {
        cout << "Not enough mana!" << endl; //add error exception here
        return;
    }
    mana -= 25;
    int damage = (attackPower * 1.8) - (target.getDefense() / 2);
    cout << name << " uses PRECISION SHOT! (" << damage << " damage)" << endl;
    target.takeDamage(damage);
}

