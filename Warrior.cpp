#include "Warrior.h"
#include "Character.h"
#include <iostream>

using namespace std;

Warrior::Warrior(my_str name): Character(name, 120, 30, 15, 10) {}

void Warrior::specialAbility(Character& target)
{
    if (mana < 20)
    {
        cout << "Not enough mana!"<<endl; //might add error exception later
        return;
    }
    mana -= 20;
    int damage = (attackPower * 2) - (target.getDefense() / 2);
    cout << name << " uses CRUSHING BLOW! (" << damage << " damage)" << endl;
    target.takeDamage(damage);
 }