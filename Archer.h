#ifndef ARCHER_H
#define ARCHER_H

#include "character.h"  
#include <iostream>

using namespace std;

class Archer : public Character 
{
public:
    Archer(my_str name);
    void specialAbility(Character& target) override;
};

#endif !ARCHER_H