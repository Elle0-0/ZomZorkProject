#include "Inventory.h"

Inventory::Inventory() {
    for (int i = 0; i < 3; ++i) {
        inventory[i] = nullptr;
    }
}

void Inventory::addItemToInventory(Item* item) {
    if (inventory[0] == nullptr)
        inventory[0] = item;
    if (inventory[1] == nullptr)
        inventory[1] = item;
    if (inventory[2] == nullptr)
        inventory[2] = item;
}

void Inventory::removeItemFromInventory(Item* item) {
    for (int i = 0; i < 3; ++i) {
        if (inventory[i] != nullptr && *inventory[i] == *item) {
            inventory[i] = nullptr;
            break;
        }
    }
}
