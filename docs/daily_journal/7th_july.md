## Section 1 – Specific Issue

The primary challenge was refining the Dynamic Array proposal by making it generic using templates and ensuring consistency across the documentation. While designing the Linked List, the main design decisions involved selecting between a singly and doubly linked list, deciding whether to maintain both `head` and `tail` pointers, designing iterator support, and justifying the use of `malloc()` over `calloc()`.

---

## Section 2 – Failed Attempt

Initially, the Dynamic Array was designed only for the `int` data type, but I later realized that implementing it as a template would make the Collections Library reusable for both primitive and user-defined data types.

While designing the Linked List, I initially considered implementing a Doubly Linked List but found that the current API did not require backward traversal. Therefore, I switched to a Singly Linked List to reduce memory usage and implementation complexity.

I also initially maintained only a `head` pointer but later decided to include a `tail` pointer as well. Although it is not required by the current API, it makes the implementation easier to extend in the future with operations such as insertion at the end.

---

## Section 3 – Memory Diagram
![alt text](<singly linked list memory diagram (2).png>)
---

## Section 4 – Code Reference

- No implementation code was written today.
- The work consisted of refining the Dynamic Array design proposal and creating the complete design proposal for the Linked List.

---

## Section 5 – Learning Reflection
 I learnt about the use of template and user defined data types why fixed data types failed along with that i also got to know that malloc doesnot work with contructor as it doesnot allocate memory to object so we have to use placement new 
 also it was the design proposal day for linked list ,chosing singly over doubly because of not opting for backward traversal and reducing memory overhead.
 