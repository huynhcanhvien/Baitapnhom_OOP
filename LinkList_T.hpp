#ifndef LinkList_T_hpp
#define LinkList_T_hpp

#include <iostream>

using namespace std;

template <typename U>
class LinkList;

template <typename T>
class Node {
private:
    T value;
    Node* next;
    friend class LinkList<T>;
public:
    Node(T value, Node* ptr = nullptr) {
        this->value = value;
        this->next = ptr;
    }

    T getValue() {
        return value;
    }
    
    void setValue(T x) {
        this->value = x;
    }
    
    Node* getNext() {
        return this->next;
    }
    
    void setNext(Node* next) {
        this->next = next;
    }
};

template <typename U>
class LinkList{
private:
    Node<U>* head;
    Node<U>* tail;

public:
    LinkList();
    LinkList(const LinkList<U>&);
    ~LinkList();

    void insertAfter(U target, U value);
    void push(U value);
    U pop();
    void lpush(U value);
    U lpop();
    void remove(U value);
    void sort(bool reverse = false);

    bool operator ()(U value) const;
    template <typename V>
    friend ostream& operator<<(ostream& out, const LinkList<V>&);
    
};
#include "Linklist_T.tpp"
#endif /* LinkList_template_hpp */
