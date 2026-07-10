# Project 1 – SuperCoders Collection Library

## Objective

The objective of this project is to design and implement a reusable **Collections Library** consisting of the following data structures:

- Dynamic Array
- Linked List
- Hash Map
- Redis Lite

Each data structure will be implemented from scratch with proper memory management, documentation, testing, and complexity analysis.

---

# Phase 0 – Design Proposal for Linked List

---

# Linked List

A Linked List is a linear data structure in which elements are stored as separate nodes connected using pointers. Unlike arrays, the elements of a linked list are not stored in contiguous memory locations. Instead, each node is dynamically allocated on the heap and contains the data along with a pointer to the next node in the sequence.

Since memory is allocated only when a new node is inserted, a Linked List can grow dynamically without requiring resizing or copying of existing elements. This makes it particularly suitable for applications where the number of elements is not known in advance and frequent insertions or deletions are required.

---

# Section 1 – Public API

The Linked List will be implemented as a **generic template class** so that it can store **primitive data types** (`int`, `char`, `float`, `double`, etc.) as well as **user-defined data types** without changing the implementation.

```cpp
template <typename T>
class LinkedList
{
    ...
};
```

## Constructor

```cpp
Default: LinkedList();
```

- Creates an empty Linked List.
- Initializes the head pointer to `nullptr`.
- Initializes the current size to `0`.

---

```cpp
Parameterized: LinkedList(T value);
```

- Creates a Linked List containing a single node.
- Allocates memory for one node.
- Stores the given value in the node.
- Makes the newly created node both the head and the tail of the Linked List.
- Initializes the current size to `1`.
- although its not necessarily needed as insertFront() will itself handle first insertion

---

## Public Methods

```cpp
void insertFront(T value);
```

- Inserts a new node at the beginning of the list.
- The newly created node becomes the head of the Linked List.
- Return Type: `void`
- Parameter: `T`

```cpp
void deleteFront();
```

- Removes the first node from the Linked List.
- Updates the head pointer to the next node.
- If the list is empty, no deletion is performed.
- Return Type: `void`
- Parameter: No parameters

```cpp
void insert(int index, T value);
```

- Inserts a new node at the specified index.
- Existing nodes are shifted logically by updating pointers.
- Return Type: `void`
- Parameters: `int`, `T`

```cpp
bool search(T value);
```

- Searches the Linked List for the specified value.
- Returns `true` if the value is found.
- Returns `false` otherwise.
- Return Type: `bool`
- Parameter: `T`

```cpp
int size();
```

- Returns the current number of nodes stored in the Linked List.
- Return Type: `int`
- Parameter: No parameters

```cpp
void print();
```

- Traverses the Linked List from head to tail.
- Displays all stored elements in sequence.
- Return Type: `void`
- Parameter: No parameters

---

---

## Iterator Operator Overloading

To support traversal similar to the array the Linked List iterator will overload the following operators.

### Dereference Operator

```cpp
T& operator*();
```

- Returns the data stored in the current node.
- Allows direct access to the value of the node currently pointed to by the iterator.

---

### Prefix Increment Operator

```cpp
Iterator& operator++();
```

- Advances the iterator to the next node.
- Returns the updated iterator.
- Executes in **O(1)** time.



---

## Rule of Three

Since the Linked List allocates memory dynamically on the heap, it follows the **Rule of Three**.

### Destructor

```cpp
~LinkedList();
```

- Traverses the complete Linked List.
- Frees every dynamically allocated node.
- Prevents memory leaks.

---

### Copy Constructor

```cpp
LinkedList(const LinkedList& other);
```

- Creates a deep copy of another Linked List.
- Traverses the source Linked List from head to tail.
- Dynamically allocates a separate node for every node in the source list.
- Copies each node individually while preserving the order of elements.
- Updates both the head and tail pointers of the newly created list.
- Prevents shallow copy problems by ensuring both Linked List objects own independent memory.
---

### Copy Assignment Operator

```cpp
LinkedList& operator=(const LinkedList& other);
```

- Traverses the source Linked List.
- Allocates new memory for every node.
- Updates both the head and tail pointers.
- Performs a deep copy of all nodes.
- Prevents memory leaks, shallow copies, dangling pointers, and double deletion.

---

# Section 2 – Internal Representation

The Linked List will be implemented as a **Singly Linked List**.

Each element in the list will be represented by a **Node**. Unlike a Dynamic Array, the nodes are **not stored in contiguous memory**. Instead, every node is allocated independently on the heap and connected to the next node using a pointer.

The Linked List class will contain the following private data members:

## Node Structure

```cpp
template <typename T>
struct Node
{
  T data;
  Node<T>*next;
};
```

---

## Private Data Members

```cpp
Node<T>* head;
Node<T>* tail;
int currentSize;
```

### Description

- **head**
  - Pointer to the first node of the Linked List.
  - Stores the address of the first node.
  - If the list is empty, it stores `nullptr`.

- **currentSize**
  - Stores the number of nodes currently present in the Linked List.
  - Updated whenever a node is inserted or deleted.
  - Allows the `size()` function to execute in **O(1)** time without traversing the list.

- **tail**
    - Pointer to the last node of the Linked List.
    - Stores the address of the last node.
    - If the list is empty, it stores `nullptr`.
    - Updated whenever the last node changes.

---

## Memory Layout

<img width="1792" height="2390" alt="image" src="https://github.com/user-attachments/assets/20ca9ff0-8e42-4e6b-ab45-90542b100873" />

---


# Section 3 – Complexity Analysis

| Operation | Best Case | Average Case | Worst Case | Reason |
| :-------- | :-------: | :----------: | :--------: | :----- |
| **insertFront()** | O(1) | O(1) | O(1) | A new node is created and inserted at the beginning by updating the head pointer. No traversal is required. |
| **deleteFront()** | O(1) | O(1) | O(1) | The first node is removed by updating the head pointer. No traversal is required. |
| **insert()** | O(1) | O(n) | O(n) | Inserting at the beginning (`index == 0`) or at the end (`index == currentSize`) requires only pointer manipulation. Otherwise, traversal is required to reach the insertion position before updating pointers. |
| **search()** | O(1) | O(n) | O(n) | The best case occurs when the value is found in the first node. Otherwise, nodes are traversed sequentially until the value is found or the end of the list is reached. |
| **size()** | O(1) | O(1) | O(1) | Returns the stored `currentSize` variable without traversing the Linked List. |
| **print()** | O(n) | O(n) | O(n) | Every node must be visited sequentially to display all stored elements. |
| **Destructor** | O(n) | O(n) | O(n) | Traverses the entire Linked List and deallocates every dynamically allocated node. |
| **Copy Constructor** | O(n) | O(n) | O(n) | Traverses the source Linked List and allocates a separate node for every element while preserving their order. |
| **Copy Assignment Operator** | O(n) | O(n) | O(n) | Frees the existing nodes, traverses the source Linked List, allocates new nodes, and performs a deep copy of every element. |

The `currentSize` variable is updated whenever a node is inserted or deleted, allowing the `size()` operation to execute in **O(1)** time.

# Section 4 – Design Decisions

The following design decisions were made while designing the Linked List.

---

## 1. Separate Size Variable

### Decision

The implementation maintains a separate variable:

- **currentSize** – stores the number of nodes currently present in the Linked List.

Maintaining this value separately allows the program to determine the size immediately without traversing the entire list.

### Alternative Considered

Calculating the size by traversing the Linked List whenever `size()` is called.

### Reason for Rejection

Traversing the list every time the size is required would increase the complexity of the `size()` operation from **O(1)** to **O(n)** and introduce unnecessary overhead.

---

## 2. Singly Linked List

### Decision

The Linked List will be implemented as a **Singly Linked List**.

Each node stores only one pointer that points to the next node in the sequence. This keeps the implementation simple while supporting all required operations.

### Alternative Considered

A **Doubly Linked List**.

### Reason for Rejection

A Doubly Linked List stores both **next** and **previous** pointers in every node, increasing memory consumption.And for now i am not does not considering backward traversal so the additional pointer so i dont require previous for now.


---

## 3. Generic Programming Using Templates

### Decision

The Linked List will be implemented using **C++ templates**.

This allows the same implementation to store primitive data types (`int`, `char`, `float`, `double`) as well as user-defined data types without modifying the code.

### Alternative Considered

Implementing the Linked List using a fixed data type such as `int`.

### Reason for Rejection

Using a fixed data type restricts the implementation to integers only. Any change in the stored data type would require rewriting the class. Templates make the implementation reusable and type-independent.


---

## 4. Memory Allocation using malloc()

### Decision

Use `malloc()` for dynamic memory allocation of individual nodes.

### Alternative Considered

`calloc()`.

### Reason for Rejection

Every newly allocated node is explicitly initialized immediately after allocation. The data field is assigned the supplied value, and the `next` pointer is explicitly set to `nullptr`. Since all members are initialized manually, zero-initializing the allocated memory using `calloc()` provides no additional benefit while introducing unnecessary initialization overhead. Therefore, `malloc()` was selected as the preferred memory allocation method.

---

## Trade-offs

### Advantages

- O(1) insertion at the front of the list.
- O(1) deletion from the front of the list.
- Dynamic growth without requiring resizing.
- No requirement for contiguous memory allocation.
- Generic implementation using templates.
- Efficient insertion and deletion through pointer manipulation.

### Limitations

- Random access is not supported efficiently because nodes must be traversed sequentially.
- Searching for an element requires **O(n)** time in the worst case.
- Every node stores an additional pointer, increasing memory usage compared to arrays.
- Accessing elements by index is slower than in a Dynamic Array because traversal is required.
