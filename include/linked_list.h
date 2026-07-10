#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
    void deleteFront();
    void insert(int index, T value);
    bool search(T value) const;
    int size() const;
    bool isEmpty() const;
    void print() const;
    void clear();

};

#endif