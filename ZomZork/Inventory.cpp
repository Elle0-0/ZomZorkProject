#include "Inventory.h"

Inventory::Inventory() {
    for (int i = 0; i < 3; ++i) {
        inventory[i] = nullptr;
    }
}

void Inventory::addItemToInventory(Entity* item) {
    for (int i = 0; i < 3; i++) {
        if (inventory[i] == nullptr) {
            inventory[i] = item;
            break;
        }
    }
}

void Inventory::removeItemFromInventory(Entity* item) {
    for (int i = 0; i < 3; ++i) {
        if (inventory[i] != nullptr && *inventory[i] == *item) {
            inventory[i] = nullptr;
            break;
        }
    }
}

void Inventory::addWeight(Item object) {
    if (object.weight != 0) {
        inventoryWeight += object.weight;
    }
}
