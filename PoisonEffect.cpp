#include "PoisonEffect.h"
#include "Character.h" 

PoisonEffect::PoisonEffect(int dmg, int dur): StatusEffect("Poison", dur), damagePerTurn(dmg) {}

void PoisonEffect::onTurnStart(Character& target) 
{
    target.takeDamage(damagePerTurn);
    cout << target.getName() << " takes " << damagePerTurn << " poison damage! (" << duration << " turns left)" << endl;
    reduceDuration();
}

void PoisonEffect::onExpire(Character& target) 
{
    cout << target.getName() << " is no longer poisoned." << endl;
}
