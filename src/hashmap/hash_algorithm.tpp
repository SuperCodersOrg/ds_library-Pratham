#ifndef HASH_ALGORITHM_TPP
#define HASH_ALGORITHM_TPP

#include <cstddef>
namespace HashUtility{
    size_t hashBytes(const void* data, size_t size){
        const size_t FNV_OFFSET_BASIS = 14695981039346656037ULL;
        const size_t FNV_PRIME = 1099511628211ULL;

        size_t hash = FNV_OFFSET_BASIS;
        const unsigned char* bytes = (const unsigned char*)data;

        for (size_t i = 0; i < size; i++){
            hash ^= bytes[i];
            hash *= FNV_PRIME;
        }

        return hash;
    }
}

template <typename T>
size_t HashAlgorithm<T>::hash(const T& value){
    return HashUtility::hashBytes(&value, sizeof(T));
}
#endif