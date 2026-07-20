#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../include/linked_list.h"
#include <cstddef>
template <typename T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node(T value): data(value), next(nullptr){}
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
    T& front();
    const T& front() const;

    class Iterator{
    private:
        Node* current;
    public:
        Iterator(Node* node)
            : current(node){}
        T& operator*(){
            return current->data;
        }
        T* operator->(){
            return &(current->data);
        }
        Iterator& operator++(){
            if(current != nullptr){
                current = current->next;
            }
            return *this;
        }
        bool operator!=(const Iterator& other) const{
            return current != other.current;
        }
    };

    Iterator begin();
    Iterator end();
};
#include "../src/linked_list/linked_list.tpp"

#endif