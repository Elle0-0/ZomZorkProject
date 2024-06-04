#ifndef ENTITY_H
#define ENTITY_H

#include "Identity.h"
#include "Description.h"
#include <string>
using namespace std;

class Entity : public Identity, public Description
{
private:
    string name;
    string description;
    int index;
public:
    Entity(int index, string name, string description);
    virtual string getDescription() const override;
    virtual string getName() const;
    virtual int getIndex() const override;

    bool operator==(const Entity& other) const;
};

#endif // ENTITY_H
