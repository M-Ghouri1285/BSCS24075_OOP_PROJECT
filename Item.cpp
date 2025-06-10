#include "Item.h"

Item::Item(my_str n, my_str desc) : name(n), description(desc) {}

my_str Item::getName() const 
{
    return name;
}

my_str Item::getDesc() const
{
    return description;
}