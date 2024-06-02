#include "item.h"

Item::Item(int index, string name) : Entity(index, name){
    this->index = index;
    this->name = name;
}
bool Item::operator==(const Item& other) const{
    return this->index == other.index;
}
