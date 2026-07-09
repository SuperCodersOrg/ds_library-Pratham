#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
template<typename T>
class DynamicArray
{
private:
    T* arr;
    int currentSize;
    int currentCapacity;

    void resize();

public:
    DynamicArray();
    DynamicArray(int initialCapacity);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    void push(T value);
    void remove(int index);
    void insert(int index, T value);

    T get(int index);

    int size();
    int capacity();

    bool isEmpty();
    void clear();
};

#include "collections-library\src\dynamic_array\dynamic_array.tpp"
#endif