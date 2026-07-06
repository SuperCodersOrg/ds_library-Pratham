

# Phase 0 – Design Proposal for Dynamic Arrays

---

# Section 1 – Public API

The Dynamic Array will provide the following public methods:

## Constructor

```cpp
Default: DynamicArray();
```

- Creates an empty Dynamic Array with an initial capacity.

## Public Methods

```cpp
void push(int value);
```

- Inserts a value at the end of the array.

```cpp
bool remove(int index);
```

- Removes the element at the specified index.
- Returns `true` if the operation is successful.
- Returns `false` if the index is invalid.

```cpp
int get(int index);
```

- Returns the element stored at the given index.
- Handles invalid index appropriately.

```cpp
bool insert(int index, int value);
```

- Inserts a value at the specified index.
- Returns `true` if insertion is successful.
- Returns `false` if the index is invalid.

```cpp
int size();
```

- Returns the current number of elements stored in the array.

```cpp
int capacity();
```

- Returns the current capacity of the array.

```cpp
void resize();
```

- Called automatically whenever `size == capacity`.
- Creates a larger array.
- Copies all existing elements.
- Deletes the old array.
- Updates the internal pointer.

**Resize Factor:** `2`

```cpp
bool isEmpty();
```

- Returns `true` if the array contains no elements.
- Otherwise returns `false`.

---

## Rule of Three

Since the Dynamic Array allocates memory dynamically on the heap, it follows the **Rule of Three**.

### Destructor

```cpp
~DynamicArray();
```

- Frees the dynamically allocated memory.
- Prevents memory leaks.

### Copy Constructor

```cpp
DynamicArray(const DynamicArray& other);
```

- Creates a deep copy of another Dynamic Array.
- Allocates new memory.
- Copies every element individually.
- Prevents shallow copy problems.

### Copy Assignment Operator

```cpp
DynamicArray& operator=(const DynamicArray& other);
```

- Frees previously allocated memory.
- Allocates new memory.
- Performs a deep copy.
- Prevents memory leaks, shallow copies, dangling pointers, and double deletion.

---

# Section 2 – Internal Representation

The Dynamic Array will be implemented using a contiguous block of dynamically allocated memory.

The class will contain the following private data members:

```cpp
int* data;
int currentSize;
int currentCapacity;
```

### Description

- **data**
  - Pointer to the dynamically allocated array on the heap.

- **currentSize**
  - Number of valid elements currently stored.

- **currentCapacity**
  - Total number of elements the array can store before resizing.



---

# Section 3 – Complexity Analysis

## push()

| Case | Complexity | Reason |
|------|------------|--------|
| Best | O(1) | Inserts directly at the end when free space is available. |
| Average | O(1) *(Amortized)* | Resizing happens infrequently, so average insertion remains constant. |
| Worst | O(n) | A resize is required, so all existing elements must be copied into a larger array. |

---

## remove()

| Case | Complexity | Reason |
|------|------------|--------|
| Best | O(1) | Removing the last element only decreases the size. |
| Average | O(n) | Approximately half the remaining elements must be shifted. |
| Worst | O(n) | Removing the first element shifts every remaining element. |

---

## get()

| Case | Complexity | Reason |
|------|------------|--------|
| Best | O(1) | Direct index calculation using pointer arithmetic. |
| Average | O(1) | Every index can be accessed directly. |
| Worst | O(1) | No traversal is ever required. |

---

## insert()

| Case | Complexity | Reason |
|------|------------|--------|
| Best | O(1) | Inserting at the end with available space is equivalent to push(). |
| Average | O(n) | Elements after the insertion point must be shifted one position to the right. |
| Worst | O(n) | Resizing and shifting may both be required. |

---

## size()

| Case | Complexity | Reason |
|------|------------|--------|
| Best | O(1) | Returns the stored size variable. |
| Average | O(1) | No traversal or computation is required. |
| Worst | O(1) | Direct variable access. |

The `currentSize` variable is updated whenever an element is inserted or removed.

---

## capacity()

| Case | Complexity | Reason |
|------|------------|--------|
| Best | O(1) | Returns the stored capacity variable. |
| Average | O(1) | Constant-time member access. |
| Worst | O(1) | Constant-time member access. |

---

## resize()

| Case | Complexity | Reason |
|------|------------|--------|
| Best | O(n) | Every existing element must be copied into the new array. |
| Average | O(n) | Allocation and copying are required during every resize. |
| Worst | O(n) | All elements are copied before replacing the old array. |

---

# Section 4 – Design Decisions

The following design decisions were made while designing the Dynamic Array.

## 1. Contiguous Memory Allocation

The Dynamic Array will use a contiguous block of dynamically allocated memory to store all elements. This design was chosen because contiguous memory allows direct index-based access using pointer arithmetic, resulting in constant-time random access (O(1)). Although resizing requires copying all elements to a new memory block, the benefit of fast element access outweighs this occasional cost.

---

## 2. Separate Size and Capacity Variables

The implementation maintains two separate variables:

- **currentSize** – stores the number of valid elements currently present in the array.
- **currentCapacity** – stores the total allocated memory available.

Keeping these values separate allows the program to determine instantly whether resizing is required without traversing the array. It also makes the implementation simpler and improves efficiency.

---

## 3. Dynamic Resizing Strategy

The array will be resized only when the current size becomes equal to the capacity. Instead of increasing the capacity by a fixed amount, the capacity will be doubled (2×) whenever resizing occurs.

The doubling strategy reduces the number of expensive resize operations and provides an amortized insertion time of O(1). Although it temporarily leaves some unused memory after each resize, it significantly improves overall performance for large numbers of insertions.

---

## 4. Deep Copy Instead of Shallow Copy

Since the Dynamic Array allocates memory dynamically on the heap, the default copy constructor and assignment operator would perform a shallow copy, causing multiple objects to share the same memory.

To avoid problems such as memory leaks, dangling pointers, and double deletion, the Dynamic Array will implement the Rule of Three by providing a destructor, copy constructor, and copy assignment operator. Every copied object will own its own independent memory.

---

## 5. Error Handling

Operations such as `get()`, `insert()`, and `remove()` require a valid index. If an invalid index is provided, the operation will fail safely instead of accessing invalid memory.

Methods that modify the array (`insert()` and `remove()`) return a boolean value indicating whether the operation was successful.

---

## Alternatives Considered

### Fixed-Size Array

A fixed-size array was considered but rejected because its capacity cannot grow once it becomes full. This makes it unsuitable for applications where the number of elements is not known in advance.

---

### Increasing Capacity by One

Another possible approach was to increase the capacity by only one element whenever the array became full.

This approach was rejected because every insertion after the array becomes full would require allocating a new array and copying all existing elements, resulting in poor insertion performance.


---

### resize factor 1.8 or 2.2 

if resize factor is choosen 1.8  then resizes would be little more frequent then 2 but will save memmory from wastage 
similary resize factor 2.2 will cause less frequent resizes but will memory 
so 2 resize factor maintains a balance between the two .

---

## Trade-offs

The chosen design provides several advantages:

- O(1) random access.
- Amortized O(1) insertion at the end.
- Efficient memory usage through dynamic allocation.
- Simpler implementation compared to linked structures.

 the design also has limitations:

- Inserting or removing elements from the middle requires shifting elements, resulting in O(n) time complexity.
- Resizing temporarily requires additional memory and copying of all existing elements.

