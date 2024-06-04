#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <iostream>

class Inventory
{
public:
    Inventory();
    void addItemToInventory(Entity* item);
    void removeItemFromInventory(Entity* item);

private:
    Entity* inventory[3];
};

#endif // INVENTORY_H
