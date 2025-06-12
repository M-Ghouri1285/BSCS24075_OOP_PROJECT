#include "FreezeEffect.h"
#include "Character.h"

FreezeEffect::FreezeEffect(int drain, int dur): StatusEffect("Frostbite", dur), manaDrainPerTurn(drain) {}

void FreezeEffect::onTurnStart(Character& target)
{
    if (target.getMana() > 0) 
    {
        int actualDrain;
        if (manaDrainPerTurn < target.getMana())
        {
            actualDrain = manaDrainPerTurn;
        }
        else
        {
            actualDrain = target.getMana();
        }

        target.drainMana(actualDrain);

        cout << target.getName() << " loses " << actualDrain << " MP to frostbite! (" << duration << " turns left)" << endl;
    }
    reduceDuration();
}

void FreezeEffect::onExpire(Character& target) 
{
    cout << target.getName() << " thawed out." << endl;
}
