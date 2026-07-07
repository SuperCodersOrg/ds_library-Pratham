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
- Makes the newly created node the head of the list.
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

## Exception Handling

Instead of returning status values for invalid operations, the Linked List will use **C++ Exception Handling** wherever appropriate.

Operations such as `insert()` and the parameterized constructor  may throw exceptions when invalid arguments are supplied.

The implementation will use the **try–throw–catch** mechanism to detect and handle errors gracefully. This approach separates normal program execution from error handling and provides meaningful error messages without causing undefined behavior.

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
- Allocates new memory for every node.
- Copies each node individually while preserving the order of elements.
- Prevents shallow copy problems.

---

### Copy Assignment Operator

```cpp
LinkedList& operator=(const LinkedList& other);
```

- Frees previously allocated nodes.
- Allocates new memory.
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
    Node<T>* next;
};
```

---

## Private Data Members

```cpp
Node<T>* head;
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

---

## Memory Layout


---

# Section 3 – Complexity Analysis

## insertFront()

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(1) | A new node is created and inserted at the beginning by updating the head pointer. |
| Average | O(1) | No traversal is required; only pointer manipulation is performed. |
| Worst | O(1) | The operation always inserts directly at the front of the list. |

---

## deleteFront()

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(1) | The first node is removed by updating the head pointer. |
| Average | O(1) | Only the head pointer changes; no traversal is required. |
| Worst | O(1) | Removing the first node always requires constant-time pointer updates. |

---

## insert()

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(1) | Inserting at index `0` is equivalent to `insertFront()` and requires no traversal. |
| Average | O(n) | Approximately half of the list must be traversed before reaching the insertion position. |
| Worst | O(n) | Inserting near the end requires traversing almost the entire list before updating pointers. |

---

## search()

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(1) | The required value is found in the first node. |
| Average | O(n) | On average, about half of the nodes are traversed before the value is found. |
| Worst | O(n) | The value is located in the last node or does not exist, requiring traversal of the entire list. |

---

## size()

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(1) | Returns the stored `currentSize` variable. |
| Average | O(1) | No traversal or computation is required. |
| Worst | O(1) | Direct access to the stored size variable. |

The `currentSize` variable is updated whenever a node is inserted or deleted.

---

## print()

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(n) | Every node must be visited and displayed. |
| Average | O(n) | Complete traversal of the Linked List is required. |
| Worst | O(n) | Every node is traversed and printed. |

---

## Destructor

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(n) | Every dynamically allocated node must be deallocated before the object is destroyed. |
| Average | O(n) | The destructor traverses the complete list and frees each node. |
| Worst | O(n) | Every node is visited exactly once and deallocated. |

---

## Copy Constructor

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(n) | Every node from the source list is copied into newly allocated memory. |
| Average | O(n) | Deep copying requires traversal of the entire Linked List. |
| Worst | O(n) | All nodes are duplicated while preserving their order. |

---

## Copy Assignment Operator

| Case | Complexity | Reason |
| :--- | :--------: | :----- |
| Best | O(n) | Existing nodes are deleted and new nodes are allocated and copied. |
| Average | O(n) | The current list is destroyed and a deep copy of the source list is created. |
| Worst | O(n) | Every node is deallocated and recreated during the assignment operation. |


# Section 4 – Design Decisions

The following design decisions were made while designing the Linked List.

---

## 1. Linked Node Structure

### Decision

The Linked List will store elements as individually allocated nodes connected using pointers rather than storing all elements in contiguous memory.

This design allows the list to grow dynamically without requiring resizing or copying of existing elements during insertion.

### Alternative Considered

A **Dynamic Array** was considered because it provides constant-time random access to elements.

### Reason for Rejection

A Dynamic Array requires shifting elements when inserting or deleting from the beginning or middle of the structure. It also requires resizing when the allocated capacity becomes full. Since the primary objective of a Linked List is efficient insertion and deletion without moving existing elements, a linked structure was considered more suitable.

---

## 2. Separate Size Variable

### Decision

The implementation maintains a separate variable:

- **currentSize** – stores the number of nodes currently present in the Linked List.

Maintaining this value separately allows the program to determine the size immediately without traversing the entire list.

### Alternative Considered

Calculating the size by traversing the Linked List whenever `size()` is called.

### Reason for Rejection

Traversing the list every time the size is required would increase the complexity of the `size()` operation from **O(1)** to **O(n)** and introduce unnecessary overhead.

---

## 3. Singly Linked List

### Decision

The Linked List will be implemented as a **Singly Linked List**.

Each node stores only one pointer that points to the next node in the sequence. This keeps the implementation simple while supporting all required operations.

### Alternative Considered

A **Doubly Linked List**.

### Reason for Rejection

A Doubly Linked List stores both **next** and **previous** pointers in every node, increasing memory consumption. Since the proposed API does not require backward traversal, the additional pointer provides little benefit while increasing implementation complexity.

---

## 4. Deep Copy Instead of Shallow Copy

### Decision

The Linked List follows the **Rule of Three** by implementing a destructor, copy constructor, and copy assignment operator.

Each copied object owns its own dynamically allocated nodes through **deep copying**.

### Alternative Considered

Using the compiler-generated copy constructor and assignment operator (shallow copy).

### Reason for Rejection

A shallow copy causes multiple Linked List objects to point to the same nodes, leading to dangling pointers, double deletion, memory corruption, and undefined behaviour.

---

## 5. Generic Programming Using Templates

### Decision

The Linked List will be implemented using **C++ templates**.

This allows the same implementation to store primitive data types (`int`, `char`, `float`, `double`) as well as user-defined data types without modifying the code.

### Alternative Considered

Implementing the Linked List using a fixed data type such as `int`.

### Reason for Rejection

Using a fixed data type restricts the implementation to integers only. Any change in the stored data type would require rewriting the class. Templates make the implementation reusable and type-independent.

---

## 6. Exception Handling

### Decision

Invalid operations such as inserting at an invalid index will be handled using **C++ exception handling** (`try`, `throw`, and `catch`).

### Alternative Considered

Returning boolean values (`true` or `false`) to indicate success or failure.

### Reason for Rejection

A boolean value only indicates whether an operation succeeded or failed but does not explain why it failed. Exception handling provides meaningful error information while keeping the API cleaner and separating normal program execution from error handling.

---

## 7. Memory Allocation using malloc()

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
