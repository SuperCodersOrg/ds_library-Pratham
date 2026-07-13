date:13th july

duration: 120 minutes

goal: create a separate header and .tpp file for hashcode algorithm

problem: when i had written hashbyte() function inside hash_map i had to write it multiple times for int ,char ,float ,etc. 

what i tried :
created seprated header file hash_algorithm.h and a file hash_algorithm.tpp where i have written fnv1a algorithm at once 
and now it can be used whenever needed without actually writing it multiple times for different data types.

```cpp
#ifndef HASH_ALGORITHM_H
#define HASH_ALGORITHM_H

#include <cstddef>
#include<string>

namespace HashUtility{
    size_t hashBytes(const void* data, size_t size);

    template<typename T>
    void combineHash(size_t& currentHash, const T& value);
}

template <typename T>
struct HashAlgorithm{
    static size_t hash(const T& value);
};

template<>
struct HashAlgorithm<std::string>
{
    static size_t hash(const std::string& value);
};


#include "../src/hashmap/hash_algorithm.tpp"

#endif

```


date:13th july

duration: 120 minutes 

goal: update hash_map for user defined function by creating a version2 and using hash_algorithm.h and .tpp plus updated hash fucntion for better distribution.

problem :
previously i have written hash map supporting primitive data types but i has to be flexible to support types like defined by user like student inlcuding marks and name ,plus it also need to support string which are combinations of characters and not primitive by default.

what i did:
added specialization in hash_algorithm for strings , changed hashcode genrattion for combining hash codes of different data types 

```cpp
template<>
struct HashAlgorithm<std::string>
{
    static size_t hash(const std::string& value);
};

    template <typename T>
void combineHash(size_t& currentHash, const T& value){
    size_t newHash = HashAlgorithm<T>::hash(value);

    currentHash ^= newHash + 0x9e3779b9 + (currentHash << 6) + (currentHash >> 2);
}
```

doing xor only will give 0 in case of same values so used this 0x9e3779b9 predefined big number and used left shift 6 and right shift 2 for better distribution so bits have more difference 
why these numbers- it has been observed by makers that they settle better for combining hashcodes

in simplified version i was using this
```cpp
template <typename T>
    void combineHash(size_t& currentHash, const T& value){
     currentHash = currentHash * 31 + HashAlgorithm<T>::hash(value);
 }
 ```

 date :13th july
 duration : 50 minutes 
 
 goal: made some changes in dynamic array implementation to make it suitabe for hash map like added overloading of [] operating and added const for some fucntion to prevent them from getting modified .

 problem :
 while i was trying to use dynamic array in hash map i faced issues of accessing elements directly like arr[i] that was the main problem i didn't resolve previously 

 what i did:
```cpp
//operator []
template<typename T>
T& DynamicArray<T>::operator[](int index){
    if(index < 0 || index >= currentSize){
        throw std::out_of_range("Invalid Index");
    }

    return arr[index];
}

```
and added const keyword for function prevention from accidental modification

