#include "collections-library\include\dynamic_array.h"
#include <cstdlib>      // so that we can use malloc, free
#include <new>          // for using placement new
#include <stdexcept>     // to handle exceptions


//default constructor
template<typename T>
DynamicArray<T>::DynamicArray(){
    currentSize = 0;
    currentCapacity = 4;

    arr = (T*)malloc(sizeof(T) * currentCapacity);

    if(arr == nullptr){
        throw std::bad_alloc();
    }
}

//parameterized constructor with user defined capacity
template<typename T>
DynamicArray<T>::DynamicArray(int initialCapacity){
    if(initialCapacity <= 0){
        throw std::invalid_argument("Invalid Capacity");
    }
    currentSize = 0;
    currentCapacity = initialCapacity;

    arr = (T*)malloc(sizeof(T) * currentCapacity);

    if(arr == nullptr){
        throw std::bad_alloc();
    }
}


// destructor
template<typename T>
DynamicArray<T>::~DynamicArray(){
    for(int i = 0; i < currentSize; i++){
        arr[i].~T();
    }

    free(arr);
    arr = nullptr;

    currentSize = 0;
    currentCapacity = 0;
}

//copy constructor 
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other){
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;
    arr = (T*)malloc(sizeof(T) * currentCapacity);
    if(arr == nullptr){
        throw std::bad_alloc();
    }
    for(int i = 0; i < currentSize; i++){
        new(&arr[i]) T(other.arr[i]);
    }
}

// assignment operator overloading 
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other){
    if(this == &other){
        return *this;
    }
    for(int i = 0; i < currentSize; i++){
        arr[i].~T();
    }
    free(arr);
    arr = nullptr;
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;
    arr = (T*)malloc(sizeof(T) * currentCapacity);
    if(arr == nullptr){
        throw std::bad_alloc();
    }
    for(int i = 0; i < currentSize; i++){
        new(&arr[i]) T(other.arr[i]);
    }
    return *this;
}

//resize 
template<typename T>
void DynamicArray<T>::resize(){
    int newCapacity = currentCapacity * 2;
    T* newArr = (T*)malloc(sizeof(T) * newCapacity);
    if(newArr == nullptr){
        throw std::bad_alloc();
    }
    // Copy existing objects to new memory
    for(int i = 0; i < currentSize; i++){
        new(&newArr[i]) T(arr[i]);
    }
    // Destroy old objects
    for(int i = 0; i < currentSize; i++){
        arr[i].~T();
    }

    // Free old memory
    free(arr);
    arr = nullptr;

    // Update pointer and capacity
    arr = newArr;
    currentCapacity = newCapacity;
}

//append at end 
template<typename T>
void DynamicArray<T>::push(T value){
    if(currentSize == currentCapacity){
        resize();
    }
    new(&arr[currentSize]) T(value);
    currentSize++;
}

//insert at index
template<typename T>
void DynamicArray<T>::insert(int index, T value){
    if(index < 0 || index > currentSize){
        throw std::out_of_range("Invalid Index");
    }
    if(currentSize == currentCapacity){
        resize();
    }
    for(int i = currentSize; i > index; i--){
        new(&arr[i]) T(arr[i - 1]);
        arr[i - 1].~T();
    }
    new(&arr[index]) T(value);
    currentSize++;
}

//remove 
template<typename T>
void DynamicArray<T>::remove(int index){
    if(index < 0 || index >= currentSize){
        throw std::out_of_range("Invalid Index");
    }

    arr[index].~T();

    for(int i = index; i < currentSize - 1; i++){
        new(&arr[i]) T(arr[i + 1]);
        arr[i + 1].~T();
        //desctructor sirf object lieftime khtm krega memory abhi bhi rhegi 
    }
    currentSize--;
}

//get
template<typename T>
T DynamicArray<T>::get(int index){
    if(index < 0 || index >= currentSize){
        throw std::out_of_range("Invalid Index");
    }
    return arr[index];
}

//size
template<typename T>
int DynamicArray<T>::size(){
    return currentSize;
}

//capacity
template<typename T>
int DynamicArray<T>::capacity(){
    return currentCapacity;
}

//isempty
template<typename T>
bool DynamicArray<T>::isEmpty(){
    return currentSize == 0;
}

//clear-- array ko clear krenge bass memory deallocate nahi krenge 
template<typename T>
void DynamicArray<T>::clear(){
    for(int i = 0; i < currentSize; i++){
        arr[i].~T();
    }
    currentSize = 0;
}


