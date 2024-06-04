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
    void addWeight(Item object);

private:
    Entity* inventory[3];
    int inventoryWeight = 0;
};

#endif // INVENTORY_H
