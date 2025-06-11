#include "FrostSword.h"
#include <iostream>
using namespace std;

FrostSword::FrostSword(): Item("Frost Sword", "Drains enemy MP (3/turn, 2 turns)") {}

void FrostSword::use(Character& target) 
{
    target.addStatusEffect(new FreezeEffect(3, 2));
    cout << target.getName() << "'s mana is freezing!" << endl;
}
