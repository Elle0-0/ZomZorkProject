#include "room.h"

room::room(string description, int roomIndex) {
    this->description = description;
    this->roomIndex = roomIndex;
    for (int i = 0; i < 4; i++) {
        exits[i] = nullptr;
    }
}

void room::setExits(room *north, room *south, room *east, room *west) {
    if (north != nullptr)
        exits[0] = north;
    if (south != nullptr)
        exits[1] = south;
    if (east != nullptr)
        exits[2] = east;
    if (west != nullptr)
        exits[3] = west;
}

room* room::getExit(int index) {
    if (exits[index])
        return exits[index];
    else
        return nullptr;
}

int room::getRoomIndex() {
    return this->roomIndex;
}

