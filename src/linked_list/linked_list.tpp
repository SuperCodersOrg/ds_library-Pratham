#include "collections-library\include\linked_list.h"
#include <cstdlib>     
#include <stdexcept>
#include <new>

// default constructor
template<typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

//parameterized constructor
template<typename T>
LinkedList<T>::LinkedList(T value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == nullptr){
        throw "Memory allocation failed.";
    }
    new (newNode) Node(value);
    head = newNode;
    tail = newNode;
    currentSize = 1;
}

// destructor
template<typename T>
LinkedList<T>::~LinkedList(){
    clear();
}



// copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
    Node* current = other.head;

    while(current != nullptr){
        Node* newNode = (Node*) malloc(sizeof(Node));
        if(newNode == nullptr){
            throw "Memory allocation failed.";
        }
        new (newNode) Node(current->data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        currentSize++;
        current = current->next;
    }
}

//Assignment operator overloading
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
    if(this == &other){
        return *this;
    }
    clear();
    Node* current = other.head;
    while(current != nullptr){
        Node* newNode = (Node*) malloc(sizeof(Node));
        if(newNode == nullptr){
            throw "Memory allocation failed.";
        }
        new (newNode) Node(current->data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        currentSize++;
        current = current->next;
    }
    return *this;
}

//insertfront
template<typename T>
void LinkedList<T>::insertFront(T value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == nullptr){
        throw "Memory allocation failed.";
    }
    new (newNode) Node(value);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    currentSize++;
}

// deleteFront(T value)
template<typename T>
void LinkedList<T>::deleteFront(){
    if(head == nullptr){
        throw "Linked List is empty.";
    }
    Node* temp = head;
    head = head->next;
    temp->~Node();
    free(temp);
    currentSize--;

    if(head == nullptr){
        tail = nullptr;
    }
}

//insert
template<typename T>
void LinkedList<T>::insert(int index, T value){
    if(index < 0 || index > currentSize){
        throw "Invalid index.";
    }
    if(index == 0){
        insertFront(value);
        return;
    }
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == nullptr){
        throw "Memory allocation failed.";
    }
    new (newNode) Node(value);
    Node* current = head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    if(newNode->next == nullptr){
        tail = newNode;
    }
    currentSize++;
}

//insert(int index, T value)
template<typename T>
bool LinkedList<T>::search(T value) const{
    Node* current = head;
    while(current != nullptr){
        if(current->data == value){
            return true;
        }
        current = current->next;
    }
    return false;
}
// search
template<typename T>
int LinkedList<T>::size() const{
    return currentSize;
}

//size
template<typename T>
bool LinkedList<T>::isEmpty() const{
    return currentSize == 0;
}

//print
template<typename T>
void LinkedList<T>::print() const{
    Node* current = head;
    while(current != nullptr){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

//clear
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


