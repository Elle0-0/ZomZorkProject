#include "item.h"

Item::Item(int index, string name, string description) : Entity(index, name, description){}

void Item::setWeight(int userWeight) {
    weight = userWeight;
}


bool Item::operator==(const Item& other) const{
    return Entity::operator==(other);
}


