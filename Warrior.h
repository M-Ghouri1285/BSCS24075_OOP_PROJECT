#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include "Character.h"

using namespace std;

class Warrior :public Character
{
public:
	Warrior(my_str name);
	void specialAbility(Character& target) override;
};

#endif !WARRIOR_H

