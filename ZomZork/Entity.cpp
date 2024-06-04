#include "Entity.h"

Entity::Entity(int index, string name, string description) : index(index), description(description){
    this->name = name;
}
string Entity::getName() const{
    return name;
}
int Entity::getIndex() const {
    return index;
}

string Entity::getDescription() const{
    return description;
}

bool Entity::operator==(const Entity& other) const {
    return index == other.index && name == other.name;
}
