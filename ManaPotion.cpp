#include "ManaPotion.h"
#include <iostream>
using namespace std;

ManaPotion::ManaPotion(): Item("Mana Potion", "Restores 20 MP"), manaAmount(20) {}

void ManaPotion::use(Character& target)
{
    cout << "You drink the Mana Potion and restore " << manaAmount << " MP!" << endl;
    target.restoreMana(manaAmount);
}
