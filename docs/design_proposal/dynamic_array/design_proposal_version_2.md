# Project 1 – SuperCoders Collection Library

## Objective

The objective of this project is to design and implement a reusable **Collections Library** consisting of the following data structures:

- Dynamic Array
- Linked List
- Hash Map
- Redis Lite

Each data structure will be implemented from scratch with proper memory management, documentation, testing, and complexity analysis.

---

# Phase 0 – Design Proposal for Dynamic Arrays

---

# Dynamic Arrays

A dynamic array is a flexible list that automatically grows or shrinks in size as you add or remove data.
Unlike standard fixed arrays, when it runs out of space, it automatically allocates a larger block of memory and copies the data over.
It gives the freedom of a flexible size and the fast speed of index-based searching.

---

# Section 1 – Public API

The Dynamic Array will be implemented as a **generic template class** so that it can store **primitive data types** (`int`, `char`, `float`, `double`, etc.) as well as **user-defined data types** without changing the implementation.

```cpp
template <typename T>
class DynamicArray
{
    ...
};
```

## Constructor

```cpp
Default: DynamicArray();
```

- Creates an empty Dynamic Array with an initial capacity.

```cpp
Parameterized: DynamicArray(int initialCapacity);
```

- Creates a Dynamic Array with a user-defined initial capacity.

## Public Methods

```cpp
void push(T value);
```

- Inserts a value at the end of the array.
- Return Type: `void`
- Parameter: `T`

```cpp
void remove(int index);
```

- Removes the element at the specified index.
- Return Type: `void`
- Parameter: `int`

```cpp
T get(int index);
```

- Returns the element stored at the given index.
- Handles invalid index appropriately.
- Return Type: `T`
- Parameter: `int`

```cpp
void insert(int index, T value);
```

- Inserts a value at the specified index.
- Return Type: `void`
- Parameters: `int`, `T`

```cpp
int size();
```

- Returns the current number of elements stored in the array.
- Return Type: `int`
- Parameter: No parameters

```cpp
int capacity();
```

- Returns the current capacity of the array.
- Return Type: `int`
- Parameter: No parameters

```cpp
void resize();
```

- Called automatically whenever at the start of insertion `size == capacity`.
- Creates a larger array.
- Copies all existing elements.
- Deletes the old array.
- Updates the internal pointer.
- Return Type: `void`
- Parameter: No parameters

**Resize Factor:** `2`

- Resize factor is the number by which the array's capacity is increased when it becomes full.

- Array capacity is doubled (2×) after every resize. This provides a balance between frequent resizing operations and memory utilization while maintaining amortized **O(1)** insertion complexity.

```cpp
bool isEmpty();
```

- Returns `true` if the array contains no elements.
- Otherwise returns `false`.
- Return Type: `bool`
- Parameter: No parameters

---

## Exception Handling

Instead of returning status values for invalid operations, the Dynamic Array will use **C++ Exception Handling**.

Operations such as `get()`, `insert()`, `remove()`, and the parameterized constructor may throw exceptions when invalid arguments are supplied.

The implementation will use the **try–throw–catch** mechanism to detect and handle errors gracefully. This approach separates normal program execution from error handling and provides meaningful error messages without causing undefined behavior.

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

<img width="1180" height="1333" alt="image" src="https://github.com/user-attachments/assets/01e9f722-1727-48ca-ad55-d5b83100f80e" />


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

---

## 1. Contiguous Memory Allocation

### Decision

The Dynamic Array will use a contiguous block of dynamically allocated memory to store all elements. This design allows direct index-based access using pointer arithmetic, resulting in **O(1)** random access time.

### Alternative Considered

A **Linked List** was considered because it supports efficient insertion and deletion without shifting elements.

### Reason for Rejection

A Linked List does not provide constant-time random access since elements must be traversed sequentially. As one of the primary objectives of this project is fast index-based access, contiguous memory was considered a better choice.

---

## 2. Separate Size and Capacity Variables

### Decision

The implementation maintains two separate variables:

- **currentSize** – stores the number of valid elements currently present.
- **currentCapacity** – stores the total allocated memory available.

Maintaining these values separately allows the program to determine immediately whether resizing is required without traversing the array.

### Alternative Considered

Determining the current size by traversing the array whenever required.

### Reason for Rejection

Traversing the array every time the size is required would increase the complexity of operations such as `size()` from **O(1)** to **O(n)** and introduce unnecessary overhead.

---

## 3. Dynamic Resizing Strategy

### Decision

The array will resize only when `currentSize == currentCapacity`.

The capacity will be increased using a **resize factor of 2**.

This strategy provides **amortized O(1)** insertion while keeping the number of resize operations low.

### Alternatives Considered

**Resize Factor = 1**

Increasing the capacity by only one element whenever the array becomes full.

**Reason for Rejection**

This would require allocating new memory and copying all existing elements after almost every insertion once the array becomes full, leading to poor insertion performance.

---

**Resize Factor = 1.8**

A resize factor of **1.8** reduces memory wastage because the newly allocated array is smaller.

**Reason for Rejection**

Although memory utilization improves, resizing becomes more frequent, increasing the total number of copy operations.

---

**Resize Factor = 2.2**

A resize factor of **2.2** reduces the frequency of resizing operations.

**Reason for Rejection**

The larger growth factor leaves significantly more unused memory after each resize, resulting in poor memory utilization.

---

A resize factor of **2** provides the best balance between memory usage and insertion performance.

---

## 4. Deep Copy Instead of Shallow Copy

### Decision

The Dynamic Array follows the **Rule of Three** by implementing a destructor, copy constructor, and copy assignment operator.

Each copied object owns its own dynamically allocated memory through **deep copying**.

### Alternative Considered

Using the compiler-generated copy constructor and assignment operator (shallow copy).

### Reason for Rejection

A shallow copy causes multiple objects to point to the same memory location, leading to dangling pointers, double deletion, memory corruption, and undefined behaviour.

---


## 5. Generic Programming Using Templates

### Decision

The Dynamic Array will be implemented using **C++ templates**.

This allows the same implementation to store primitive data types (`int`, `char`, `float`, `double`) as well as user-defined data types without modifying the code.

### Alternative Considered

Implementing the Dynamic Array using a fixed data type such as `int`.

### Reason for Rejection

Using a fixed data type restricts the implementation to integers only. Any change in data type would require rewriting the class. Templates make the implementation reusable and type-independent.

---

## 6. Exception Handling

### Decision

Invalid operations such as accessing, inserting, or removing an element using an invalid index will be handled using **C++ exception handling** (`try`, `throw`, and `catch`).

### Alternative Considered

Returning boolean values (`true` or `false`) to indicate success or failure.

### Reason for Rejection
A boolean value only indicates whether an operation succeeded or failed but does not provide the reason for failure. Exception handling provides meaningful error information while keeping the API cleaner and separating normal execution from error handling.

---
## 7. memory allocation using malloc 

Decision: Use malloc() for dynamic memory allocation.

Alternative Considered: calloc().

Reason for Rejection: A Dynamic Array only accesses the first currentSize elements, so initializing the remaining allocated memory to zero provides no benefit. Using malloc() avoids this unnecessary initialization overhead while still allocating the required memory.

---

## Trade-offs

### Advantages

- O(1) random access.
- Amortized O(1) insertion at the end.
- Efficient use of dynamic memory.
- Generic implementation using templates.
- Cleaner error handling using exceptions.

### Limitations

- Inserting or removing elements from the middle requires shifting elements, resulting in **O(n)** time complexity.
- Resizing temporarily requires additional memory and copying of existing elements.
- A resize factor of 2 may leave some unused memory immediately after resizing, although it significantly reduces the number of future reallocations.
