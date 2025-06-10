#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "my_str.h"
#include "vector.h"

class Item
{
protected:
	my_str name;
	my_str description;
public:
	Item(my_str n, my_str desc);
	virtual ~Item() {}
	virtual void use(Character& user) = 0;
	my_str getName() const;
	my_str getDesc() const;
};


#endif !ITEM_H

