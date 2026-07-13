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

//hashkey
template <typename Key, typename Value>
size_t HashMap<Key, Value>::hashKey(const Key& key) const{
    return HashAlgorithm<Key>::hash(key);  // this is changed for now 
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

//insert
template <typename Key, typename Value>
void HashMap<Key, Value>::insert(const Key& key, const Value& value){
    Node* node = findNode(key);
    if (node != nullptr){
        node->value = value;
        return;
    }
    if ((static_cast<float>(currentSize + 1) / bucketCount) > maxLoadFactor){
        rehash(bucketCount * 2);
    }
    size_t hash = hashKey(key);
    int bucketIndex = hash % bucketCount;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr){
        throw std::bad_alloc();
    }
    new (newNode) Node(key, value);
    newNode->next = buckets[bucketIndex];
    buckets[bucketIndex] = newNode;
    currentSize++;
}

//rehash
template <typename Key, typename Value>
void HashMap<Key, Value>::rehash(int newBucketCount){
    Node** newBuckets = (Node**)calloc(newBucketCount, sizeof(Node*));
    if (newBuckets == nullptr){
        throw std::bad_alloc();
    }
    for (int i = 0; i < bucketCount; i++){
        Node* current = buckets[i];
        while (current != nullptr){
            Node* next = current->next;

            int bucketIndex = hashKey(current->key) % newBucketCount;

            current->next = newBuckets[bucketIndex];
            newBuckets[bucketIndex] = current;

            current = next;
        }
    }
    free(buckets);
    buckets = newBuckets;
    bucketCount = newBucketCount;
}

//remove
template <typename Key, typename Value>
void HashMap<Key, Value>::remove(const Key& key){
    size_t hash = hashKey(key);
    int bucketIndex = hash % bucketCount;

    Node* current = buckets[bucketIndex];
    Node* previous = nullptr;

    while (current != nullptr){
        if (current->key == key){
            if (previous == nullptr){
                buckets[bucketIndex] = current->next;
            }
            else{
                previous->next = current->next;
            }
            current->~Node();
            free(current);
            currentSize--;
            return;
        }

        previous = current;
        current = current->next;
    }

    throw std::out_of_range("Key not found.");
}

// freememory
template <typename Key, typename Value>
void HashMap<Key, Value>::freeMemory(){
    for (int i = 0; i < bucketCount; i++){
        Node* current = buckets[i];

        while (current != nullptr){
            Node* next = current->next;

            current->~Node();
            free(current);

            current = next;
        }

        buckets[i] = nullptr;
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
    free(buckets);
}

//copy from
template <typename Key, typename Value>
void HashMap<Key, Value>::copyFrom(const HashMap& other)
{
    bucketCount = other.bucketCount;
    currentSize = other.currentSize;
    maxLoadFactor = other.maxLoadFactor;
    buckets = (Node**)calloc(bucketCount, sizeof(Node*));
    if (buckets == nullptr){
        throw std::bad_alloc();
    }

    for (int i = 0; i < bucketCount; i++){
        Node* current = other.buckets[i];
        Node* last = nullptr;

        while (current != nullptr)
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (newNode == nullptr){
                throw std::bad_alloc();
            }
            new (newNode) Node(current->key, current->value);
            if (last == nullptr){
                buckets[i] = newNode;
            }
            else{
                last->next = newNode;
            }

            last = newNode;
            current = current->next;
        }
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
        free(buckets);

        copyFrom(other);
    }

    return *this;
}

