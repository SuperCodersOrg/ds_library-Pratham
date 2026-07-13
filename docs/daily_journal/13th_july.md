## Specific Issue

While extending the Hash Map, I realized the hashing logic was duplicated for every primitive type. I also needed a design that supports strings and user-defined data types while producing well-distributed hash values. Additionally, the Dynamic Array lacked direct indexing support required by the Hash Map.

---

## Failed Attempt

Initially, I implemented `hashBytes()` inside the Hash Map, which required rewriting similar code for multiple data types. I also used a simple hash combination formula, but it was not robust enough for better hash distribution, so I replaced it with a standard hash-combining technique.
plus i needed to make a a change for [] operator in dynamic arrays.
---

## Memory Diagram

                    HashMap
                       │
                       │
                  hashKey()
                       │
                       ▼
          HashAlgorithm<Key>::hash()
                 │              │
                 │              │
         Primitive         User-defined
             │                  │
             ▼                  ▼
         hashBytes()     combineHash(member1)
                          combineHash(member2)
                          combineHash(member3)
                                 │
                                 ▼
                        HashAlgorithm<MemberType>
                                 │
                          (recursive)

---

##  Code Reference
~~~cpp
//operator []
template<typename T>
T& DynamicArray<T>::operator[](int index){
    if(index < 0 || index >= currentSize){
        throw std::out_of_range("Invalid Index");
    }

    return arr[index];
}

template <typename T>
    void combineHash(size_t& currentHash, const T& value){
        currentHash = currentHash * 31 + HashAlgorithm<T>::hash(value);
    }

```


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

---

## Section 5 – Learning Reflection

so i learned the importance of separating reusable components from container implementations.
Plus i have also learned to keep the code open for updation like i updated dynamic arrays i needed not to  make multiple changes just added a method .
also learned that its needed to manage use defined data types too and also use the already built data structures in code isntead of creating them again.

