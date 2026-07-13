#ifndef HASH_ALGORITHM_H
#define HASH_ALGORITHM_H

#include <cstddef>

namespace HashUtility{
    size_t hashBytes(const void* data, size_t size);
}

template <typename T>
struct HashAlgorithm{
    static size_t hash(const T& value);
};


#include "../src/hashmap/hash_algorithm.tpp"

#endif