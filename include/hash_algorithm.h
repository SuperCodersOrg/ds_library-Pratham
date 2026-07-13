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