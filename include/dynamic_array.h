#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
template<typename T>
class DynamicArray
{
private:
    T* arr;
    int currentSize;
    int currentCapacity;
    int initialCapacity;

    void resize();

public:
    DynamicArray();
    DynamicArray(int initialCapacity);
    DynamicArray(int size, const T& value);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    void push(const T& value);
    void remove(int index);
    void insert(int index, const T& value);

    T get(int index) const;
    
    T& operator[](int index);
    const T& operator[](int index) const;

    int size() const;
    int capacity() const;

    bool isEmpty() const;
    void clear();
};

#include "../src/dynamic_array/dynamic_array.tpp"
#endif
