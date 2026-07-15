#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>
template <typename T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node(T value){
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int currentSize;

public:

    LinkedList();
    LinkedList(T value);

    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    void insertFront(T value);
    void insertBack(T value);
    void deleteFront();
    void insert(int index, T value);
    bool search(T value) const;
    bool remove(const T& value);
    T* find(const T& value);
    const T* find(const T& value) const;
    int size() const;
    bool isEmpty() const;
    void print() const;
    void clear();

};
#include "../src/linked_list/linked_list.tpp"

#endif