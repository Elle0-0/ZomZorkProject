#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

class room
{

private:
    string description;
    int roomIndex;
    room* exits[4];

public:
    room(string description, int roomIndex);
    void setExits(room *north, room *south, room *east, room *west);
    room* getExit(int index);
    int getRoomIndex();
};

#endif // ROOM_H
