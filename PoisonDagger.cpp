#include "PoisonDagger.h"
#include <iostream>
using namespace std;

PoisonDagger::PoisonDagger() : Item("Poison Dagger", "Poisons enemy (5 dmg/turn, 2 turns)") {}

void PoisonDagger::use(Character& target) 
{
    target.addStatusEffect(new PoisonEffect(5, 2));
    cout << target.getName() << " was poisoned!" << endl;
}
