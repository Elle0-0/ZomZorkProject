#ifndef ENTITY_H
#define ENTITY_H

#include <string>
using namespace std;

class Entity
{
private:
    string name;
    string description;
    int index;
public:
    Entity(int index, string name);
    virtual void setDescription(string description);
    virtual string getDescription();
    virtual string getName();
    virtual int getIndex();
};

#endif // ENTITY_H
