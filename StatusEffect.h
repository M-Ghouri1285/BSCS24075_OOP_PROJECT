#pragma once
#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H

#include "my_str.h"
#include <iostream>

class Character;

using namespace std;

class StatusEffect
{
protected:
	my_str Name;
	int duration;

public:
	StatusEffect(my_str n, int dur);
	virtual void onTurnStart(Character& target) = 0;
	virtual void onExpire(Character& target) {}
	void reduceDuration();
	bool isExpired() const;
	my_str getName() const;
};



#endif !STATUSEFFECT_H

