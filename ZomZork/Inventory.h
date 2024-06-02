#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <iostream>

class Inventory
{
public:
    Inventory();
    void addItemToInventory(Item* item);
    void removeItemFromInventory(Item* item);

private:
    Item* inventory[3];
};

#endif // INVENTORY_H
