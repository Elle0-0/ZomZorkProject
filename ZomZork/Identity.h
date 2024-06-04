#ifndef IDENTITY_H
#define IDENTITY_H

class Identity
{
public:
    Identity() = default;
    virtual ~Identity() = default;
    virtual int getIndex() const = 0; //the const 0 specifies thats the function is a "pure" virtual function
};

#endif // IDENTITY_H
