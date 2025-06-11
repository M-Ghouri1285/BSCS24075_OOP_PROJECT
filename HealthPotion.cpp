#include "HealthPotion.h"
#include <iostream>

using namespace std;

HealthPotion::HealthPotion(): Item("Health Potion", "Restores 30 HP"), healAmount(30) {}

void HealthPotion::use(Character& target)
{
    cout << "You drink the Health Potion and restore " << healAmount << " HP!" << endl;
    target.restoreHealth(healAmount);
}
