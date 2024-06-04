#ifndef TEMPLATEARRAY_H
#define TEMPLATEARRAY_H

#include <iostream>

template<typename T>
class TemplateArray
{
public:
    TemplateArray(int size);

    ~TemplateArray();

    void addToArray(const T& value);
    void printArray();

private:
    T* array;
    int size;
};

#endif // TEMPLATEARRAY_H
