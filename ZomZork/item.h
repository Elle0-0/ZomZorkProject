#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Entity.h"

using namespace std;
class Item : public Entity
{
public:
    Item(int index, string name);
    bool operator==(const Item& other) const;

private:
    int index;
    string name;
};

#endif // ITEM_H
