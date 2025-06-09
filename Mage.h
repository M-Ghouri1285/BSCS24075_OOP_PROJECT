#pragma once
#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include "Character.h"

using namespace std;

class Mage :public Character
{
public:
	Mage(my_str name);
	void specialAbility(Character& target) override;
};


#endif !MAGE_H

