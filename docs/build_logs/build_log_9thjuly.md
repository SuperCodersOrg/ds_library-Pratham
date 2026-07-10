Date:july 9

Duration:120 minutes

Goal: Write the version 1 implementation of Dynamic Array

Problem Encountered: 
why use include.h and .tpp as separate files to include 
how remove and insert function move elements to fill gap and object liftime 
why i go from index to currentsize and not currentsize+1 while insertion

What i tried:
-researched why to create two deparate files .h and .tpp 
-why use header guard 
-researched that while moving elements in insert and remove only object lifetime is over

Outcome:
- .h is used to instantiate all the public methods and only show the method names and hide their implementation
- while filling the gap or creating one only object lifecycle is over and memory space is not deallocated that is by it does not show undefined behaviour
- currentsize means the next available position so i should go from index to currsize in insert() && also if currsize==capacity this will give error i cannot access that without resizing.
- completed the first implementation of dynamic array.


Date:july 9

Duration:120 minutes

Goal:write the version 1 implementation of Linked list 

Problem Encountered:
- Before
```cpp
   template<typename T>
LinkedList<T>::~LinkedList(){
    Node* current = head;
    while(current != nullptr){
        Node* nextNode = current->next;
        current->~Node();
        free(current);
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}
```


What i tried:
written a different reusable clear method for clearing the complete linked list

- After
```cpp
template<typename T>
void LinkedList<T>::clear(){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        temp->~Node();
        free(temp);
    }

    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

template<typename T>
LinkedList<T>::~LinkedList(){
    clear();
}
```
outcome:
completed first implementation of linked list 







