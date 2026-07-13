
## Specific Issue
previously i was writing the code for clearing memory again and again in destructor and assignemnt operator overloading ,
plus i was confused about why templates are separated into .h and .tpp files, how object lifetime works during insert() and remove(), and why insertion starts from currentSize.
---

## Failed Attempt
Initially, I kept the complete cleanup logic inside the destructor and even considered calling the destructor directly from the copy assignment operator. This worked but duplicated code and made the implementation harder to maintain.

---

## Code Reference
implemented Version 1 of both the Dynamic Array and Linked List. Added a reusable clear() method for the Linked List, updated the destructor to call it, and correctly implemented insertion and removal logic in the Dynamic Array after understanding object lifetime and currentSize

---

## Learning Reflection

Today I gained a better understanding of template implementation, header organization, object lifetime during element shifting, and reusable memory management. Completing both data structures reinforced the importance of writing maintainable and modular C++ code.

---