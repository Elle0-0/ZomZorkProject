#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <string>

class Description
{
public:
    Description() = default;
    virtual ~Description() = default;
    virtual std::string getDescription() const = 0;
};

#endif // DESCRIPTION_H
