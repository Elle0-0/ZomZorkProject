#include "Entity.h"

Entity::Entity(int index, string name) {
    this->name = name;
    this->index = index;
}
string Entity::getName() {
    return name;
}
int Entity::getIndex() {
    return index;
}

void Entity::setDescription(string description) {
    this->description = description;
}

string Entity::getDescription() {
    return description;
}
