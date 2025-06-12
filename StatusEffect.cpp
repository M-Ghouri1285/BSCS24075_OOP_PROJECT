#include "StatusEffect.h"

StatusEffect::StatusEffect(my_str n, int dur):Name(n), duration(dur) {}
void StatusEffect::reduceDuration() { duration--; }
bool StatusEffect::isExpired() const { return duration <= 0; }
my_str StatusEffect::getName() const { return Name; }