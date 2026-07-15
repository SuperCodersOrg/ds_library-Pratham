# Project 1 – SuperCoders Collection Library

## Objective

The objective of this project is to design and implement a reusable **Collections Library** consisting of the following data structures:

- Dynamic Array
- Linked List
- Hash Map
- Redis Lite

Each data structure will be implemented from scratch with proper memory management, documentation, testing, and complexity analysis.

---

# Phase 0 – Design Proposal for Redis Lite

---

# Redis Lite

Redis Lite is a lightweight, in-memory key-value database that provides a simple command-line interface for storing and retrieving data. Unlike the real Redis database, Redis Lite is designed as a single-user, single-session application that stores all data in memory and loses its contents when the program terminates.

Redis Lite is not responsible for implementing the storage mechanism itself. Instead, it uses the previously implemented **HashMap** as its underlying storage engine. The application reads commands from the terminal, validates them, and performs the corresponding operations on the HashMap.

---

# Section 1 – Public API

Redis Lite will be implemented as a **command-line application** that internally uses the previously implemented **HashMap<std::string, std::string>** to store all key-value pairs.

```cpp
class RedisCLI
{
public:
    RedisCLI();
    void run();

private:
    HashMap<std::string, std::string> store;

    void handleSet(const std::string& key,
                   const std::string& value);

    void handleGet(const std::string& key);

    void handleDel(const std::string& key);

    void handleExists(const std::string& key);

    void handleCount();

    void handleClear();

    void printHelp();
};
```

## Constructor

```cpp
RedisCLI();
```

- Creates an empty Redis Lite database.
- Initializes an empty `HashMap<std::string, std::string>`.
- No user data is stored initially.

---

## Public Methods

```cpp
void run();
```

- Starts the Redis Lite command-line interface.
- Continuously accepts commands from the user until the `EXIT` command is entered.
- Parses the entered command and invokes the appropriate handler function.
- Return Type: `void`
- Parameter: No parameters

---

## Private Handler Methods

```cpp
void handleSet(const std::string& key,
               const std::string& value);
```

- Stores the specified key-value pair in the database.
- If the key already exists, its value is overwritten.
- Return Type: `void`
- Parameters: `std::string`, `std::string`

---

```cpp
void handleGet(const std::string& key);
```

- Retrieves the value associated with the specified key.
- Displays the stored value if the key exists.
- Displays an appropriate message if the key is not found.
- Return Type: `void`
- Parameter: `std::string`

---

```cpp
void handleDel(const std::string& key);
```

- Removes the specified key-value pair from the database.
- If the key does not exist, no deletion is performed.
- Return Type: `void`
- Parameter: `std::string`

---

```cpp
void handleExists(const std::string& key);
```

- Checks whether the specified key exists in the database.
- Displays `true` if the key exists.
- Displays `false` otherwise.
- Return Type: `void`
- Parameter: `std::string`

---

```cpp
void handleCount();
```

- Displays the total number of key-value pairs currently stored in the database.
- Return Type: `void`
- Parameter: No parameters

---

```cpp
void handleClear();
```

- Removes all key-value pairs from the database.
- Restores the database to an empty state.
- Return Type: `void`
- Parameter: No parameters

---

```cpp
void printHelp();
```

- Displays the list of supported Redis Lite commands along with their usage.
- Helps users interact with the application correctly.
- Return Type: `void`
- Parameter: No parameters

---

# Section 2 – Internal Representation

Redis Lite will be implemented as a **command-line application** that internally uses the previously implemented **HashMap** as its storage engine.

Unlike the other data structures in the Collections Library, Redis Lite does not directly allocate or manage memory for storing key-value pairs. Instead, it delegates all storage operations to the underlying `HashMap<std::string, std::string>`.

The application is responsible for reading commands from the user, validating them, parsing them, and invoking the corresponding HashMap operations.

---

## Private Data Members

```cpp
HashMap<std::string, std::string> store;
```

### Description

- **store**
  - Stores all key-value pairs entered by the user.
  - Implemented using the previously developed `HashMap`.
  - Uses `std::string` as both the key and value type.
  - Performs all insertion, retrieval, deletion, and lookup operations.
  - Since the HashMap is implemented as a template, Redis Lite simply instantiates it as `HashMap<std::string, std::string>`.

---

## Internal Workflow

Redis Lite processes commands through a continuous command loop.

1. The user enters a command through the terminal.
2. The `run()` function reads the complete input line using `getline()`.
3. The input is parsed into the command and its arguments using `std::stringstream`.
4. The appropriate handler function is invoked.
5. The handler performs the corresponding operation on the underlying `HashMap`.
6. The result is displayed back to the user.

This process continues until the user enters the `EXIT` command, which terminates the command-processing loop.

---

## Object Relationship

```text
                User
                  │
                  ▼
           Command Line
                  │
                  ▼
             RedisCLI
                  │
                  ▼
HashMap<std::string, std::string>
                  │
                  ▼
      Bucket Array + Collision Chains
```

The `RedisCLI` object owns a single instance of `HashMap<std::string, std::string>`. All key-value pairs entered during the session are stored inside this HashMap. The internal bucket array, collision chains, resizing mechanism, and memory management are handled entirely by the HashMap implementation.

---

## Memory Ownership

Redis Lite itself does not perform any explicit dynamic memory allocation for storing user data.

All dynamic memory allocation and deallocation are delegated to the underlying `HashMap`, which internally manages bucket allocation, collision handling, resizing, and cleanup.

When the `RedisCLI` object is destroyed, the destructor of the contained `HashMap` is automatically invoked, ensuring that all dynamically allocated memory is released correctly without memory leaks.

---

## Rule of Three

The `RedisCLI` class does not directly own dynamically allocated memory. Therefore, it does not require a custom destructor, copy constructor, or copy assignment operator.

Memory management responsibilities are delegated entirely to the underlying `HashMap`, which already implements the Rule of Three.

---

## Memory Layout

![alt text](image.png)

---

# Section 3 – Complexity Analysis

| Operation | Best Case | Average Case | Worst Case | Reason |
| :-------- | :-------: | :----------: | :--------: | :----- |
| **SET** | O(1) | O(1) | O(n) | The key is hashed to determine its bucket. In the best and average cases, insertion or updating occurs directly within the bucket. In the worst case, excessive collisions or a rehash operation may require traversing a collision chain or reinserting all existing key-value pairs. |
| **GET** | O(1) | O(1) | O(n) | The hash value directly identifies the bucket containing the key. Under normal conditions only a few elements are searched. In the worst case, all keys may collide into a single bucket, requiring traversal of the entire collision chain. |
| **DEL** | O(1) | O(1) | O(n) | After hashing the key, the corresponding bucket is searched and the node is removed. Worst-case performance occurs when every key hashes to the same bucket, requiring traversal of the complete collision chain before deletion. |
| **EXISTS** | O(1) | O(1) | O(n) | Performs a lookup operation identical to `GET` without returning the stored value. The complexity depends entirely on the collision behavior of the underlying HashMap. |
| **COUNT** | O(1) | O(1) | O(1) | Returns the stored number of key-value pairs maintained by the HashMap without traversing any buckets. |
| **CLEAR** | O(n) | O(n) | O(n) | Every stored key-value pair must be removed and its dynamically allocated memory released. Therefore, all buckets and collision chains are traversed exactly once. |
| **HELP** | O(1) | O(1) | O(1) | Displays a predefined list of supported commands. The amount of output is fixed and independent of the number of stored key-value pairs. |
| **EXIT** | O(1) | O(1) | O(1) | Terminates the command-processing loop by breaking out of the `run()` function. No HashMap operations are performed. |

The complexity of Redis Lite is determined entirely by the complexity of the underlying `HashMap`. Redis Lite itself performs only command parsing and dispatching before invoking the corresponding HashMap operation.

---

# Section 4 – Design Decisions

The following design decisions were made while designing Redis Lite.

---

## 1. String-Based Key-Value Storage

### Decision

Redis Lite stores both keys and values as `std::string`.

```cpp
HashMap<std::string, std::string>
```

### Alternative Considered

Allowing multiple data types such as `int`, `float`, or `double`.

### Reason for Rejection

All commands entered through the terminal are received as text. Storing both keys and values as strings avoids unnecessary type conversion, simplifies command parsing, and matches the behavior of the original Redis, which stores values as strings by default. The underlying HashMap remains generic through templates, while Redis Lite simply chooses to instantiate it using string types.

---

## 2. Using `getline()` for Input

### Decision

Commands are read using `getline()`.

### Alternative Considered

Using the extraction operator (`cin >>`).

### Reason for Rejection

`getline()` reads the complete command entered by the user, making command parsing more reliable and allowing the application to process the entire input line consistently. It also provides better flexibility for future extensions if commands require more complex input.

---

## 3. Command Parsing Using `std::stringstream`

### Decision

The command entered by the user is parsed using `std::stringstream`.

### Alternative Considered

Manually parsing the input string using loops and character-by-character processing.

### Reason for Rejection

Manual parsing increases implementation complexity and is more prone to errors while handling whitespace and command arguments. `std::stringstream` provides a simpler, cleaner, and more reliable solution for extracting the command and its parameters.

---

## 4. Overwriting Existing Keys

### Decision

The `SET` command overwrites the existing value if the specified key already exists.

Example:

```text
SET name Arun
SET name Vikram
```

After execution,

```text
GET name
```

returns

```text
Vikram
```

### Alternative Considered

Rejecting duplicate keys or storing multiple values for the same key.

### Reason for Rejection

A key-value database maintains unique keys. Allowing duplicate keys would complicate retrieval and violate the expected behavior of the `GET` command. Overwriting existing values keeps the implementation simple while maintaining predictable behavior.

---

## 5. EXIT as a Control Command

### Decision

The `EXIT` command is implemented directly inside the `run()` method instead of creating a separate `handleExit()` function.

### Alternative Considered

Implementing a dedicated `handleExit()` method.

### Reason for Rejection

`EXIT` does not perform any operation on the underlying HashMap. Its sole purpose is to terminate the command-processing loop. Handling it directly inside the `run()` function simplifies the implementation and avoids introducing an unnecessary handler.

---

## Trade-offs

### Advantages

- Efficient average-case **O(1)** insertion, lookup, and deletion through the HashMap.
- Simple command-line interface for interacting with the database.
- Reuses the previously implemented generic HashMap without modification.
- Fast in-memory storage with minimal overhead.
- Straightforward architecture that is easy to understand, test, and extend.

### Limitations

- Data is stored only in memory and is lost when the application terminates.
- Supports only a single user and a single session.
- Does not support persistence, networking, or concurrent clients.
- Stores all values as strings; applications requiring other data types must perform their own conversions.