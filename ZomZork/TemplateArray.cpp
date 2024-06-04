#include "TemplateArray.h"

template<typename T>

TemplateArray<T>::TemplateArray(int size) : size(size){
    array = new T[size];
    std::cout << "array using the template class created!" << std::endl;
}

template<typename T>
TemplateArray<T>::~TemplateArray() {
    delete[] array;
    std::cout << "array using template class deleted :o" << std::endl;
}

template<typename T>
void TemplateArray<T>::addToArray(const T& value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == T()) {
            array[i] = value;
            break;
        }
    }
}

template<typename T>
void TemplateArray<T>::printArray() {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
