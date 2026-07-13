#ifndef HASH_ALGORITHM_TPP
#define HASH_ALGORITHM_TPP
#include<string>
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

    // template <typename T>
    // void combineHash(size_t& currentHash, const T& value){
    //     currentHash = currentHash * 31 + HashAlgorithm<T>::hash(value);
    // }

    template <typename T>
void combineHash(size_t& currentHash, const T& value){
    size_t newHash = HashAlgorithm<T>::hash(value);

    currentHash ^= newHash + 0x9e3779b9 + (currentHash << 6) + (currentHash >> 2);
}

}

template <typename T>
size_t HashAlgorithm<T>::hash(const T& value){
    return HashUtility::hashBytes(&value, sizeof(T));
}


size_t HashAlgorithm<std::string>::hash(const std::string& value){
    return HashUtility::hashBytes(value.c_str(), value.length());
}

#endif