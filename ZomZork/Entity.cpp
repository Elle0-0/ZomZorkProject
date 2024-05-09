#include "Entity.h"

Entity::Entity(string name) {
    this->name = name;
}

string Entity::getName() {
    return name;
}

void Entity::setDescription(string description) {
    this->description = description;
}

string Entity::getDescription() {
    return description;
}
