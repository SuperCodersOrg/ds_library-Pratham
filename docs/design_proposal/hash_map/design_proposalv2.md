# Project 1 – SuperCoders Collection Library

## Objective

The objective of this project is to design and implement a reusable Collections Library consisting of the following data structures:

- Dynamic Array
- Linked List
- Hash Map
- Redis Lite

Each data structure will be implemented from scratch with proper memory management, documentation, testing, and complexity analysis.

---

# Phase 0 – Design Proposal for Hash Map

## Hash Map

A Hash Map is a key-value based associative data structure that stores elements using a hashing technique. Instead of storing data sequentially, every key is transformed into an integer hash value using a hash function. This hash value is then mapped to a bucket within the hash table, allowing elements to be inserted, searched, and removed efficiently.

Since multiple keys may produce the same bucket index, the Hash Map must implement an appropriate collision resolution strategy. The proposed implementation will dynamically grow by rehashing whenever the load factor exceeds a predefined threshold, ensuring efficient average-case performance.

---

# Section 1 – Public API

The Hash Map will be implemented as a generic template class so that it can store both primitive and user-defined data types as keys and values without changing the implementation.

```cpp

template <typename Key, typename Value>
class HashMap
{
private:

    struct Node
    {
        Key key;
        Value value;

        Node(const Key& key, const Value& value): key(key), value(value){}
        Node(const Key& key): key(key){}  
        bool operator==(const Node& other) const{
            return key == other.key;
        }
    };

    // Default Configuration
    static constexpr int DEFAULT_BUCKET_COUNT = 8;
    static constexpr float DEFAULT_MAX_LOAD_FACTOR = 0.75f;

    // Data Members
    DynamicArray< LinkedList<Node> > buckets; 

    int bucketCount;
    int currentSize;
    float maxLoadFactor;

    // Hash Functions
    size_t hashKey(const Key& key) const;
    

    // Helper Functions
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
```

The `Node` structure is nested inside the `HashMap` because it is an internal implementation detail and should not be accessible outside the class. The Node structure stores only the key and its associated value. Collision chain management is delegated to the custom LinkedList class, whose internal nodes maintain the links between successive elements. The Node structure also overloads the equality operator so that two nodes are considered equal when their keys are identical. This allows the HashMap to reuse the searching and deletion operations already implemented by the LinkedList.

The Hash Map maintains the following private data members:

- `DynamicArray<LinkedList<Node>> buckets`

Stores the bucket table.
Each element of the Dynamic Array represents one bucket.
Instead of storing raw pointers, every bucket owns an independent LinkedList<Node> that stores all key-value pairs mapped to that bucket.

This design reuses the previously implemented Dynamic Array and Linked List data structures while keeping collision management encapsulated inside the Linked List implementation.


- `int bucketCount`
  Stores the total number of buckets currently allocated in the hash table.

- `int currentSize`
  Stores the total number of key-value pairs currently present in the Hash Map.

- `float maxLoadFactor`
  Stores the maximum allowable load factor. Once the current load factor exceeds this threshold, the Hash Map automatically resizes and rehashes all existing elements.

---

## Constructors

### Default Constructor

```cpp
HashMap();
```

Creates an empty Hash Map.

- Allocates the default number of buckets.
- Initializes every bucket with an empty LinkedList<Node> object.
- Sets the current size to `0`.
- Sets the default maximum load factor.

### Parameterized Constructor

```cpp
HashMap(int initialBucketCount);
```

Creates an empty Hash Map with the specified initial bucket count.

- Allocates the specified number of buckets.
- Initializes every bucket with an empty LinkedList<Node> object.
- Sets the current size to `0`.
- Sets the default maximum load factor.

---

## Public Methods

### void insert(const Key& key, const Value& value);

Inserts a key-value pair into the Hash Map.

If the key already exists, its associated value is updated.

Return Type: `void`

Parameters:

- `const Key&`
- `const Value&`

---

### const Value& get(const Key& key) const;

Returns the value associated with the specified key.

Throws an exception if the key is not present.

Return Type: `const Value&`

Parameter:

- `const Key&`

---

### bool contains(const Key& key) const;

Determines whether the specified key exists in the Hash Map.

Returns `true` if the key exists and `false` otherwise.

Return Type: `bool`

Parameter:

- `const Key&`

---

### void remove(const Key& key);

Removes the specified key-value pair from the Hash Map.

Removes the specified key-value pair from the HashMap. If the key does not exist, an exception is thrown.
Return Type: `void`

Parameter:

- `const Key&`

---

### void clear();

Removes all key-value pairs from the Hash Map while preserving the object for future insertions.

Return Type: `void`

Parameter:

No parameters.

---

### int size() const;

Returns the number of key-value pairs currently stored.

Return Type: `int`

Parameter:

No parameters.

---

### int capacity() const;

Returns the current number of buckets allocated.

Return Type: `int`

Parameter:

No parameters.

---

### bool isEmpty() const;

Returns `true` if the Hash Map contains no elements.

Return Type: `bool`

Parameter:

No parameters.

---

### float loadFactor() const;

Returns the current load factor of the Hash Map.

Return Type: `float`

Parameter:

No parameters.

---

## Rule of Three

Since the HashMap owns a dynamically allocated Dynamic Array containing Linked Lists, it follows the Rule of Three to ensure proper ownership, deep copying, and resource management.

### Destructor

```cpp
~HashMap();
```

Invokes the helper function freeMemory(), which clears every Linked List stored in the bucket table. The Dynamic Array then releases the bucket table automatically through its destructor.

Prevents memory leaks.

---

### Copy Constructor

```cpp
HashMap(const HashMap& other);
```

Creates a deep copy of another Hash Map.

Allocates a new bucket array.

Creates a deep copy of the Dynamic Array. Each LinkedList<Node> is copied using the Linked List copy constructor, resulting in an independent copy of every collision chain.
---

### Copy Assignment Operator

```cpp
HashMap& operator=(const HashMap& other);
```

Performs a deep copy of another Hash Map.

Checks for self-assignment.

Releases the existing resources.

Releases the existing bucket table, creates a new Dynamic Array, and copies every bucket using the Linked List copy assignment operator.

Returns a reference to the current object.

Prevents shallow copies, dangling pointers, memory leaks, and double deletion.


## Exception Handling

The Hash Map uses exception handling to report invalid operations instead of relying on return values. This approach keeps the public interface simple while allowing errors to be handled explicitly by the caller.

Some of the conditions are as follows:

- Calling `get()` with a key that does not exist in the Hash Map.
- Calling `remove()` with a key that does not exist in the Hash Map.
- Attempting to create a Hash Map with an invalid initial bucket count (zero or negative).
- Memory allocation failure during construction of the Dynamic Array, Linked Lists, or while inserting elements.
- Any other operation that violates the preconditions defined by the Hash Map implementation.

# Section 2 – Internal Representation

The proposed HashMap is implemented using a Dynamic Array of Linked Lists.

The HashMap object itself resides on the stack and stores metadata including the current number of stored key-value pairs, the bucket count, the maximum load factor, and the Dynamic Array representing the bucket table.

The Dynamic Array is allocated on the heap. Each element of the Dynamic Array represents one bucket and contains an independent LinkedList<Node> object. Each Linked List internally manages its own nodes and collision chain.

Whenever multiple keys map to the same bucket, they are inserted into the corresponding Linked List.

When the load factor exceeds the predefined threshold, a larger Dynamic Array is allocated. Every bucket is traversed using the Linked List iterator, and each stored key-value pair is rehashed and inserted into its new bucket in the resized table.

This design separates bucket management from collision management by reusing the previously implemented Dynamic Array and Linked List classes instead of manually maintaining linked-list pointers inside the HashMap

The following hand-drawn memory diagram illustrates the internal memory layout of the HashMap, including the stack object, dynamically allocated bucket array, collision chains, and the relationship between them.

![alt text](image.png)

                 hash(T)

                    │
        ┌───────────┴───────────┐
        │                       │
  Primitive Type?          User-defined?
        │                       │
       Yes                     Yes
        │                       │
 Primitive Hash          hashFields()/specialization
        │                       │
        │                  hashCombine(...)
        │                       │
        └───────────┬───────────┘
                    │
           Recursively hash each field
                    │
            Combine individual hashes
                    │
               Return final hash

# Section 3 – Complexity Analysis
I assume that the HashMap uses **Separate Chaining** for collision resolution and maintains an appropriate load factor through periodic rehashing.

---

## insert(const Key& key, const Value& value)

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The computed bucket is empty, allowing the new node to be inserted directly without any traversal. |
| Average Case | **O(1)** | A good hash function distributes keys uniformly across buckets, resulting in very short collision chains. Therefore, only a few nodes need to be examined before insertion or update. |
| Worst Case | **O(n)** | If all keys hash to the same bucket, the entire collision chain must be traversed before inserting or updating the key. Rehashing, when triggered, also requires visiting every stored element. |

---

## get(const Key& key)

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The key hashes to an empty bucket or is found as the first node in the collision chain. |
| Average Case | **O(1)** | Uniform distribution of keys keeps collision chains short, allowing fast lookup. |
| Worst Case | **O(n)** | If all keys belong to a single collision chain, the entire chain must be searched before locating the key or determining that it does not exist. |

---

## contains(const Key& key)

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The bucket is empty or the key is found immediately at the beginning of the chain. |
| Average Case | **O(1)** | On average, only a small portion of a collision chain is traversed because keys are uniformly distributed. |
| Worst Case | **O(n)** | Every stored element may need to be examined when all keys collide into the same bucket. |

---

## remove(const Key& key)

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The key is located as the first node of the collision chain and can be removed immediately. |
| Average Case | **O(1)** | Collision chains remain short under a good hash function, requiring only a few comparisons before deletion. |
| Worst Case | **O(n)** | The key is the last node in a collision chain containing all stored elements, requiring traversal of the complete chain before removal. |

---

## clear()

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The HashMap is already empty, so no nodes need to be deallocated. |
| Average Case | **O(n)** | Every allocated node must be visited and released to free the dynamically allocated memory. |
| Worst Case | **O(n)** | All stored nodes across every collision chain must be traversed and deallocated before releasing the bucket array. |

---

## size()

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The current number of stored elements is maintained as a member variable and returned directly. |
| Average Case | **O(1)** | No traversal or computation is required. |
| Worst Case | **O(1)** | Accessing a stored member variable always requires constant time. |

---

## capacity()

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The current bucket count is stored as a member variable and returned directly. |
| Average Case | **O(1)** | No additional computation is performed. |
| Worst Case | **O(1)** | Accessing the stored bucket count always takes constant time. |

---

## isEmpty()

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The method simply compares the current size with zero. |
| Average Case | **O(1)** | Only a single comparison is performed. |
| Worst Case | **O(1)** | The comparison always executes in constant time regardless of the number of stored elements. |

---

## loadFactor()

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | The load factor is computed using two stored member variables (`currentSize` and `bucketCount`). |
| Average Case | **O(1)** | Only one division operation is required. |
| Worst Case | **O(1)** | The calculation remains constant regardless of the number of elements stored. |

---

## HashMap()

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(b)** | Memory is allocated for the bucket array and every bucket is initialized to `nullptr`, where **b** is the initial bucket count. |
| Average Case | **O(b)** | Every bucket must be initialized before the HashMap can be used. |
| Worst Case | **O(b)** | Initialization always requires visiting each bucket exactly once. |

---

## Copy Constructor

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(b)** | The source HashMap is empty. Only the bucket array needs to be allocated and initialized. |
| Average Case | **O(n + b)** | A new bucket array is allocated, and every stored key-value pair is copied into newly allocated nodes. |
| Worst Case | **O(n + b)** | Every bucket and every node in every collision chain must be copied to create an independent deep copy. |

---

## Copy Assignment Operator

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(1)** | Self-assignment is detected immediately, and no further work is required. |
| Average Case | **O(n + b)** | Existing memory is released, a new bucket array is allocated, and all key-value pairs are copied into the destination HashMap. |
| Worst Case | **O(n + b)** | Every existing node must be destroyed, and every node from the source HashMap must be recreated in the destination object. |

---

## Destructor

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(b)** | The HashMap contains no elements. Only the bucket array needs to be released after checking each bucket. |
| Average Case | **O(n + b)** | Every node in every collision chain must be deallocated before releasing the bucket array. |
| Worst Case | **O(n + b)** | All dynamically allocated nodes and the bucket array must be traversed and released to prevent memory leaks. |

---

## Rehashing (Internal Operation)

| Case | Complexity | Reason |
|------|------------|--------|
| Best Case | **O(n)** | Every stored key-value pair must be rehashed and inserted into the newly allocated bucket array exactly once. |
| Average Case | **O(n)** | Each element is visited once and placed into its new bucket after recomputing its bucket index. |
| Worst Case | **O(n)** | Regardless of the collision pattern, every element must be processed during rehashing, making the operation linear in the number of stored elements. 


---

# Section 4 – Design Decisions

The following design decisions were made while designing the HashMap. Each decision was selected after considering alternative approaches and evaluating their impact on performance, maintainability, memory management, and implementation complexity.

---

## 4.1 Generic Template Design

The HashMap is implemented as a generic template class.

```cpp
template<typename Key, typename Value>
class HashMap;
```

### Reason for Selection

Using templates allows the same implementation to support primitive data types (`int`, `char`, `float`, etc.) as well as user-defined data types without modifying the underlying implementation.

This improves code reusability, type safety, and extensibility while avoiding duplicate implementations for different data types.

### Alternative Considered

Implementing separate HashMap classes for different data types was considered.

This approach was rejected because it introduces significant code duplication, increases maintenance effort, and limits the flexibility of the library.

---

## 4.2 Collision Resolution Strategy

The proposed implementation uses **Separate Chaining** to resolve hash collisions.

Each bucket is represented by an independent LinkedList<Node> stored inside the Dynamic Array. The Linked List internally manages collision chains and provides insertion, searching, removal, and traversal operations that are reused by the HashMap implementation.

### Reason for Selection

Separate Chaining provides a simple and reliable collision resolution mechanism.

Its advantages include:

- Simple insertion and deletion.
- Straightforward implementation.
- Easy memory management.
- Unlimited collisions per bucket.
- Simplified rehashing.
- Easier debugging and visualization.

Since this project emphasizes understanding of memory management and dynamic allocation, Separate Chaining provides a cleaner implementation than probe-based methods.

### Alternative Considered

Open Addressing (Linear Probing) was considered.

Although it offers better cache locality and lower memory overhead, deletion becomes significantly more complicated because deleted positions must be marked using tombstones. Probe sequences also become longer as the table fills, increasing implementation complexity.

For these reasons, Open Addressing was rejected.

---

## 4.3 Dynamic Array of Buckets

The bucket table is implemented using the custom `DynamicArray<LinkedList<Node>>`. Each position in the Dynamic Array stores one Linked List representing a collision chain.

### Reason for Selection

A dynamic array of buckets  allows the HashMap to grow automatically as more elements are inserted.

The bucket size can be increased through rehashing without changing the public interface.

This approach also separates bucket management from collision management, improving modularity.

### Alternative Considered

Using a fixed-size bucket array was considered.

This approach was rejected because it limits the maximum number of elements that can be stored efficiently and results in excessive collisions once the table becomes full.

---

## 4.4 Hash Function Design

The HashMap computes hash values using a recursive generic hashing mechanism (using variadic template).

Primitive data types are hashed directly using specialized hash functions.

For user-defined data types, hashing is performed recursively by hashing each selected member in their primitive form individually and combining the resulting hash values into a single hash code.

### Reason for Selection

This approach provides flexibility while maintaining a single generic hashing framework.

Since user-defined objects are ultimately composed of primitive data types, recursively hashing individual members allows complex objects to be hashed without duplicating hashing logic.

The recursive design also naturally supports nested user-defined objects.

### Alternative Considered

Hashing the raw memory occupied by an object was considered.

This approach was rejected because object layouts may contain compiler-dependent padding bytes, internal pointers, or other implementation-specific details that should not influence the hash value.

Similarly, hashing only the memory address of an object was rejected because two objects containing identical data would produce different hash values solely because they occupy different memory locations.

---

## 4.5 Load Factor

The HashMap maintains a maximum load factor threshold. I have choosen .75

Load factor= currsize/total table capacity

Whenever the load factor exceeds this threshold, the hash table automatically performs rehashing.

### Reason for Selection

Maintaining an upper bound on the load factor minimizes collision chain lengths and preserves average-case constant-time performance for insertion, lookup, and deletion.

Automatic resizing also prevents the performance degradation associated with heavily loaded hash tables.

### Alternative Considered

I have also considered 1.0 as 1 assumes uniform distribution but i might not have it so that is why i am going with 0.75 which also benefits for faster lookups

---

## 4.6 Rehashing Strategy

Whenever the load factor exceeds the predefined threshold i am considerind 0.75, a new bucket array with larger capacity is allocated.

All existing elements are then rehashed and inserted into the new bucket array.

### Reason for Selection

Rehashing redistributes elements across a larger number of buckets, reducing collisions and restoring efficient average-case performance.

Although rehashing requires linear time, it occurs infrequently, resulting in an amortized insertion complexity of **O(1)**.

### Alternative Considered

Keeping the bucket array size fixed throughout the lifetime of the HashMap was considered.

This approach was rejected because collision chains would continue to grow indefinitely as additional elements were inserted, significantly reducing lookup performance.

---


## 4.7 Exception Handling

The proposed implementation uses exception handling to report invalid operations such as attempting to access or remove a key that does not exist.

### Reason for Selection

Exceptions separate normal program flow from error handling, resulting in a cleaner and more expressive interface. They also eliminate the need for special return values that may conflict with valid data.

### Alternative Considered

Returning error codes or sentinel values was considered.

This approach was rejected because it complicates the interface and makes it difficult to distinguish between an actual stored value and an error condition.

## 4.8 Memory Allocation Strategy

The HashMap implementation delegates memory management to the previously implemented data structures.

The bucket table is managed by the custom DynamicArray class, while collision chains are managed by the custom LinkedList class.

Whenever a new bucket table is required during construction or rehashing, a new DynamicArray<LinkedList<Node>> is created. Each bucket is initialized as an empty Linked List.

Individual collision chain nodes are allocated internally by the Linked List using malloc() together with placement new, following the memory management strategy already established in the Linked List implementation.

This design avoids duplicating memory management logic inside the HashMap, improves modularity, and promotes code reuse while preserving proper ownership and deep-copy semantics.

## 4.9 Reuse of Existing Data Structures

Rather than implementing collision chains manually using raw pointers, the HashMap reuses the previously developed DynamicArray and LinkedList classes.

### Reason for Selection
Promotes code reuse.
Avoids duplicate implementations.
Reduces maintenance effort.
Keeps collision management encapsulated inside the Linked List.
Simplifies memory management and the Rule of Three.

### Alternative Considered
Implementing collision chains manually using Node* next pointers inside the HashMap.

This approach was rejected because it duplicates functionality already available in the custom Linked List implementation, resulting in additional code complexity and maintenance overhead.
