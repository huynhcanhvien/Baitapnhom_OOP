#include "Linklist_T.hpp"

template <typename T>
LinkList<T>::LinkList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkList<T>::LinkList(const LinkList<T>& list) : head(nullptr), tail(nullptr) {
    Node<T>* current = list.head;
    while (current != nullptr) {
        push(current->getValue());
        current = current->getNext();
    }
}

template <typename T>
LinkList<T>::~LinkList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkList<T>::lpush(T value) {
    Node<T>* newnode = new Node<T>(value);
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

template <typename T>
void LinkList<T>::push(T value) {
    Node<T>* newnode = new Node<T>(value);
    if (tail == nullptr) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

template <typename T>
T LinkList<T>::pop() {
    if (head == nullptr) {
        throw runtime_error("List is empty");
    } else if (head == tail) {
        T res = head->value;
        delete head;
        head = tail = nullptr;
        return res;
    }
    Node<T>* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    T res = tail->value;
    delete tail;
    tail = temp;
    tail->next = nullptr;
    return res;
}

template <typename T>
T LinkList<T>::lpop() {
    if (head == nullptr) throw runtime_error("List is empty");
    T res = head->value;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    return res;
}

template <typename T>
void LinkList<T>::insertAfter(T target, T x) {
    Node<T>* current = head;
    while (current != nullptr && current->getValue() != target) {
        current = current->getNext();
    }
    if (current != nullptr) {
        Node<T>* newNode = new Node<T>(x);
        newNode->next = current->next;
        current->next = newNode;
        if (current == tail) {
            tail = newNode;
        }
    }
}

template <typename T>
void LinkList<T>::remove(T target) {
    Node<T>* current = head;
    if (current == nullptr) return;
    if (target == head->value) {
        lpop();
        return;
    }
    while (current->next != nullptr && current->next->value != target) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node<T>* temp = current->next;
        current->next = temp->next;
        if (temp == tail) {
            tail = current;
        }
        delete temp;
    }
}

template <typename T>
void LinkList<T>::sort(bool reverse) {
    if (head == nullptr || head->next == nullptr) return;

    auto functionPtr = reverse ? [](T a, T b) { return a < b; }
                               : [](T a, T b) { return a > b; };

    Node<T>* i = head;
    while (i != nullptr) {
        Node<T>* j = i->next;
        while (j != nullptr) {
            if (functionPtr(i->value, j->value)) {
                swap(i->value, j->value);
            }
            j = j->next;
        }
        i = i->next;
    }
}

template <typename T>
ostream& operator<<(ostream& out, const LinkList<T>& list) {
    Node<T>* current = list.head;
    while (current != nullptr) {
        out << current->getValue() << " ";
        current = current->getNext();
    }
    out << endl;
    return out;
}
template <typename T>
bool LinkList<T>::operator ()(T value) const{
    Node<T>* current = this->head;
    while (current != nullptr) {
        if(current->getValue() == value) return true;
        current = current->getNext();
    }
    return false;
}
