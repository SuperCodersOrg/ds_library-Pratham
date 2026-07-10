#include<collections-library\include\hash_map.h>
#include <cstddef>
#include<cstdlib>
#include <stdexcept>
#include<new>

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