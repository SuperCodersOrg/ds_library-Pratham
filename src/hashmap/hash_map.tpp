#include "collections-library\include\hash_map.h"
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <new>

//default constructor
template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(){
    bucketCount = DEFAULT_BUCKET_COUNT;
    currentSize = 0;
    maxLoadFactor = DEFAULT_MAX_LOAD_FACTOR;
    buckets = (Node**)calloc(bucketCount, sizeof(Node*));
    if (buckets == nullptr){
        throw std::bad_alloc();
    }
}

//parameterized constructor
template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(int initialBucketCount){
    if (initialBucketCount <= 0){
        throw std::invalid_argument("Bucket count must be greater than zero.");
    }
    bucketCount = initialBucketCount;
    currentSize = 0;
    maxLoadFactor = DEFAULT_MAX_LOAD_FACTOR;
    buckets = (Node**)calloc(bucketCount, sizeof(Node*));
    if (buckets == nullptr){
        throw std::bad_alloc();
    }
}

//size
template <typename Key, typename Value>
int HashMap<Key, Value>::size() const{
    return currentSize;
}

//capacity
template <typename Key, typename Value>
int HashMap<Key, Value>::capacity() const{
    return bucketCount;
}

//isempty
template <typename Key, typename Value>
bool HashMap<Key, Value>::isEmpty() const{
    return currentSize == 0;
}

//loadfactor
template <typename Key, typename Value>
float HashMap<Key, Value>::loadFactor() const{
    return static_cast<float>(currentSize) / bucketCount;
}

//hashbyte
template <typename Key, typename Value>
size_t HashMap<Key, Value>::hashBytes(const void* data, size_t size) const{
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

template <typename Key, typename Value>
size_t HashMap<Key, Value>::hashKey(const Key& key) const{
    return hashBytes(&key, sizeof(Key));
}

//findnode
template <typename Key, typename Value>
typename HashMap<Key, Value>::Node*
HashMap<Key, Value>::findNode(const Key& key) const{
    size_t hash = hashKey(key);
    int bucketIndex = hash % bucketCount;
    Node* current = buckets[bucketIndex];
    while (current != nullptr){
        if (current->key == key){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

//contains
template <typename Key, typename Value>
bool HashMap<Key, Value>::contains(const Key& key) const{
    return findNode(key) != nullptr;
}

//get
template <typename Key, typename Value>
const Value& HashMap<Key, Value>::get(const Key& key) const{
    Node* node = findNode(key);
    if (node == nullptr){
        throw std::out_of_range("Key not found.");
    }

    return node->value;
}
