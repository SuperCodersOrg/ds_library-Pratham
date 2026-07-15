#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <new>

#include "../include/hash_map.h"

//default constructor
template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(){
    bucketCount = DEFAULT_BUCKET_COUNT;
    currentSize = 0;
    maxLoadFactor = DEFAULT_MAX_LOAD_FACTOR;
    buckets = DynamicArray< LinkedList<Node> >(bucketCount);

    for(int i = 0; i < bucketCount; i++){
        buckets.push(LinkedList<Node>());
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
    buckets = DynamicArray< LinkedList<Node> >(bucketCount);

    for(int i = 0; i < bucketCount; i++){
        buckets.push(LinkedList<Node>());
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


//hashkey
template <typename Key, typename Value>
size_t HashMap<Key, Value>::hashKey(const Key& key) const{
    return HashAlgorithm<Key>::hash(key);  // this is changed for now 
}


//contains 
template <typename Key, typename Value>
bool HashMap<Key, Value>::contains(const Key& key) const{
    size_t hash = hashKey(key);
    int bucketIndex = hash % bucketCount;
    Node temp(key);
    return buckets[bucketIndex].find(temp) != nullptr;
}

//get 
template <typename Key, typename Value>
const Value& HashMap<Key, Value>::get(const Key& key) const{
    size_t hash = hashKey(key);
    int bucketIndex = hash % bucketCount;
    Node temp(key);
    const Node* node = buckets[bucketIndex].find(temp);
    if(node == nullptr){
        throw std::out_of_range("Key not found.");
    }
    return node->value;
}
//insert
template <typename Key, typename Value>
void HashMap<Key, Value>::insert(const Key& key, const Value& value){
    size_t hash = hashKey(key);
    int bucketIndex = hash % bucketCount;
    Node temp(key);
    Node* existing = buckets[bucketIndex].find(temp);
    if(existing != nullptr){
        existing->value = value;
        return;
    }

    if((static_cast<float>(currentSize + 1) / bucketCount)
            > maxLoadFactor){
        rehash(bucketCount * 2);
        hash = hashKey(key);
        bucketIndex = hash % bucketCount;
    }
    buckets[bucketIndex].insertFront(Node(key,value));
    currentSize++;
}

//rehash
template <typename Key, typename Value>
void HashMap<Key, Value>::rehash(int newBucketCount){
    DynamicArray< LinkedList<Node> > newBuckets(newBucketCount);
    for(int i = 0; i < newBucketCount; i++){
        newBuckets.push(LinkedList<Node>());
    }
    for(int i = 0; i < bucketCount; i++){
        for(auto it = buckets[i].begin();
            it != buckets[i].end();
            ++it){
            Node node = *it;
            int bucketIndex =
                hashKey(node.key) % newBucketCount;
            newBuckets[bucketIndex].insertFront(node);
        }
    }
    buckets = newBuckets;
    bucketCount = newBucketCount;
}

//remove
template <typename Key, typename Value>
void HashMap<Key, Value>::remove(const Key& key){
    size_t hash = hashKey(key);
    int bucketIndex = hash % bucketCount;
    Node temp(key);
    bool removed = buckets[bucketIndex].remove(temp);
    if(!removed){
        throw std::out_of_range("Key not found.");
    }
    currentSize--;
}

// freememory
template<typename Key, typename Value>
void HashMap<Key, Value>::freeMemory(){
    for(int i=0;i<bucketCount;i++){
        buckets[i].clear();
    }
    currentSize = 0;
}

//clear
template <typename Key, typename Value>
void HashMap<Key, Value>::clear(){
    freeMemory();
}

//destructor
template <typename Key, typename Value>
HashMap<Key, Value>::~HashMap(){
    freeMemory();
}

//copy from
template<typename Key, typename Value>
void HashMap<Key, Value>::copyFrom(
    const HashMap& other){
    bucketCount = other.bucketCount;
    currentSize = other.currentSize;
    maxLoadFactor = other.maxLoadFactor;
    buckets =DynamicArray< LinkedList<Node> >(bucketCount);
    for(int i=0;i<bucketCount;i++){
        buckets.push(other.buckets[i]);
    }
}


//copy constructor
template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(const HashMap& other){
    copyFrom(other);
}

// assignment operator overload
template <typename Key, typename Value>
HashMap<Key, Value>& HashMap<Key, Value>::operator=(const HashMap& other){
    if (this != &other){
        freeMemory();
        copyFrom(other);
    }

    return *this;
}