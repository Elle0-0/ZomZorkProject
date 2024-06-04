#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Entity.h"


using namespace std;
class Item : public Entity
{
public:
    Item(int index, string name, string description);
    bool operator==(const Item& other) const;
    void setWeight(int weight);

    friend class Inventory;
private:
    unsigned int weight : 6; //maximum weight of 63
};

#endif // ITEM_H
