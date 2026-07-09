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
        Node* next;
    };

    Node** buckets;              // Dynamic array of bucket pointers
    int bucketCount;             // Total number of buckets
    int currentSize;             // Number of key-value pairs stored
    float maxLoadFactor;         // Load factor threshold before rehashing

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

    // const Value& -" I promise the caller cannot change the data I return".
    // const Key& key- " I promise not to change the key you handed me ".
    // const (at the end) - " I promise not to change the container itself while looking up the item."

    
    void remove(const Key& key);
    void clear();

    // Capacity Information
    int size() const;
    int capacity() const;
    bool isEmpty() const;
    float loadFactor() const;
};
```

The `Node` structure is nested inside the `HashMap` because it is an internal implementation detail and should not be accessible outside the class. Each node stores a key-value pair and a pointer to the next node, enabling separate chaining for collision resolution.

The Hash Map maintains the following private data members:

- `Node** buckets`
  Stores the dynamically allocated bucket array. Each element of the array points to the head of a linked list representing a collision chain.

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
- Initializes every bucket to `nullptr`.
- Sets the current size to `0`.
- Sets the default maximum load factor.

### Parameterized Constructor

```cpp
HashMap(int initialBucketCount);
```

Creates an empty Hash Map with the specified initial bucket count.

- Allocates the specified number of buckets.
- Initializes every bucket to `nullptr`.
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

Returns `true` if the key is removed successfully and `false` if the key does not exist.

Return Type: `bool`

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

Since the Hash Map allocates memory dynamically for both the bucket array and collision chains, it follows the Rule of Three.

### Destructor

```cpp
~HashMap();
```

Traverses every bucket.

Releases every dynamically allocated node.

Deallocates the bucket array.

Prevents memory leaks.

---

### Copy Constructor

```cpp
HashMap(const HashMap& other);
```

Creates a deep copy of another Hash Map.

Allocates a new bucket array.

Copies every key-value pair into newly allocated nodes while preserving the collision chains.

Ensures both Hash Map objects own independent memory.

---

### Copy Assignment Operator

```cpp
HashMap& operator=(const HashMap& other);
```

Performs a deep copy of another Hash Map.

Checks for self-assignment.

Releases the existing resources.

Allocates a new bucket array.

Copies every key-value pair into newly allocated nodes.

Returns a reference to the current object.

Prevents shallow copies, dangling pointers, memory leaks, and double deletion.


## Exception Handling

The Hash Map uses exception handling to report invalid operations instead of relying on return values. This approach keeps the public interface simple while allowing errors to be handled explicitly by the caller.

Some of the conditions are as follows:

- Calling `get()` with a key that does not exist in the Hash Map.
- Calling `remove()` with a key that does not exist in the Hash Map.
- Attempting to create a Hash Map with an invalid initial bucket count (zero or negative).
- Memory allocation failure during bucket allocation, node creation, or rehashing.
- Any other operation that violates the preconditions defined by the Hash Map implementation.

# Section 2 – Internal Representation

The proposed `HashMap` is implemented using a **bucket array** and **Separate Chaining** for collision resolution.

The HashMap object itself resides on the **stack** and stores metadata such as the current number of elements, the total number of buckets, the maximum load factor, and a pointer to the dynamically allocated bucket array.

The bucket array is allocated on the **heap**. Each element of the bucket array is a pointer to the head of a linked list (collision chain). Every node within a collision chain stores a key-value pair along with a pointer to the next node in the chain.

When a key is inserted, the hash function computes its hash value, which is then converted into a bucket index using the modulo operation with the current bucket count. If the target bucket is empty, the new node becomes the first node of that bucket. Otherwise, the node is inserted into the corresponding collision chain.

As more elements are inserted, the load factor of the hash table increases. Once the load factor exceeds the predefined threshold, a larger bucket array is allocated and all existing key-value pairs are rehashed and inserted into the new bucket array. The previous bucket array is then deallocated.

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

Each bucket stores a pointer to the head of a linked list. Whenever multiple keys map to the same bucket, they are stored as nodes within that linked list.

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

## 4.3 Dynamic Bucket Array

The bucket table is implemented as a dynamically allocated array of bucket pointers.

Each bucket points to the head of a collision chain.

### Reason for Selection

A dynamic bucket array allows the HashMap to grow automatically as more elements are inserted.

The bucket array size can be increased through rehashing without changing the public interface.

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

### 4.8 Memory Allocation Strategy

The implementation uses different allocation strategies for the bucket array and the collision chain nodes.

The bucket array is allocated using `calloc()`. Since every bucket stores a pointer to the head of a collision chain, all bucket pointers must initially contain `nullptr`. Using `calloc()` automatically initializes the allocated memory to zero which most of the compilers does to represent nullptr, eliminating the need for an explicit initialization loop and reducing the possibility of uninitialized pointer errors.

Individual collision chain nodes are allocated using `malloc()`. Each newly allocated node is immediately initialized with the supplied key and value; therefore, zero-initializing the entire node using `calloc()` would provide no practical benefit. For template types that require object construction, placement `new` is used after allocation to correctly construct the `Key` and `Value` objects in the allocated memory.


