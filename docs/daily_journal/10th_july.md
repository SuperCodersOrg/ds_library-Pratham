## Specific Issue

While implementing the Hash Map, I had to design a generic hashing mechanism that works for all primitive data types. I also faced design decisions regarding bucket allocation, rehashing without recursion, safe node deletion from collision chains, and reusable memory management. Later, I encountered a compilation error caused by a missing header file.

---

## Failed Attempt

Initially, I considered recreating nodes during rehashing and keeping memory cleanup inside multiple functions, which would have duplicated logic. I also spent time debugging the hashing functions before discovering that the real issue was the missing `<cstddef>` header required for `size_t`.

---

##  Code Reference
![alt text](image-1.png)

Implemented both constructors, `insert()`, `remove()`, `get()`, `contains()`, `findNode()`, `rehash()`, `clear()`, `freeMemory()`, and `copyFrom()`. Also implemented FNV-1a hashing using separate `hashKey()` and `hashBytes()` functions and fixed a compilation issue by including `<cstddef>`.

---

## Section 5 – Learning Reflection

so i learned about including header file and always check for that as that could cost me so much time ,secondly i learned about the code reusability using fucntions which can used in multiple other methods like copyfrom() used in assignment operator overloading as well as copy constructor .

