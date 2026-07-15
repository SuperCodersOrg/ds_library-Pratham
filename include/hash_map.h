#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "linked_list.h"
#include "dynamic_array.h" // for da
#include "hash_algorithm.h"
#include <cstddef>

template <typename Key, typename Value>
class HashMap
{
private:

    struct Node
    {
        Key key;
        Value value;
        // Node* next;

        Node(const Key& key, const Value& value): key(key), value(value){}
        Node(const Key& key): key(key){} // thoda dekhna iska edge case hai value provide nahi ki 
        bool operator==(const Node& other) const{
            return key == other.key;
        }
    };

    // Default Configuration
    static constexpr int DEFAULT_BUCKET_COUNT = 8;
    static constexpr float DEFAULT_MAX_LOAD_FACTOR = 0.75f;

    // Data Members
    // Node** buckets; //remove it for da 
    // DynamicArray<Node*> buckets; // add it for da //remove for LL
    DynamicArray< LinkedList<Node> > buckets; //add for DA and LL

    int bucketCount;
    int currentSize;
    float maxLoadFactor;

    // Hash Functions
    size_t hashKey(const Key& key) const;
    // size_t hashBytes(const void* data, size_t size) const;
    

    // Helper Functions
    // Node* findNode(const Key& key) const; // removed coz of LL
    void rehash(int newBucketCount);
    void freeMemory();
    void copyFrom(const HashMap& other);

public:

    // Constructors
    HashMap();
    HashMap(int initialBucketCount);

    // Rule of Three
    ~HashMap();
    HashMap(const HashMap& other);
    HashMap& operator=(const HashMap& other);

    // Core Operations
    void insert(const Key& key, const Value& value);
    const Value& get(const Key& key) const;
    bool contains(const Key& key) const;
    void remove(const Key& key);
    void clear();

    // Capacity
    int size() const;
    int capacity() const;
    bool isEmpty() const;
    float loadFactor() const;
};


// #include "../src/hashmap/hash_map_v2.tpp"
// #include "../src/hashmap/hash_map.tpp"
#include "../src/hashmap/hash_map_v3.tpp"

#endif