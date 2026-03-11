#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

template<typename T>
class ListNode {
public:
    ListNode(const T& data, ListNode<T>* next = nullptr) : data(data), next(next) {}
    T data;
    ListNode<T>* next;
};

template<typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), len(0) {}
    ~LinkedList();

    void push_back(const T& value);
    void push_front(const T& value);
    void Print() const;

private:
    ListNode<T>* head;
    size_t len;

    void clear();
};

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void LinkedList<T>::clear() {
    ListNode<T>* current = head;
    while (current != nullptr) {
        ListNode<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    len = 0;
}

template<typename T>
void LinkedList<T>::push_back(const T& value) {
    if (head == nullptr) {
        head = new ListNode<T>(value);
    }
    else {
        ListNode<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new ListNode<T>(value);
    }
    ++len;
}

template<typename T>
void LinkedList<T>::push_front(const T& value) {
    head = new ListNode<T>(value, head);
    ++len;
}

template<typename T>
void LinkedList<T>::Print() const {
    ListNode<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Question-0. Basic function
    LinkedList<size_t> lsA, lsB;
    lsA.push_back(1);
    lsA.push_back(4);
    lsA.push_back(3);
    lsB.push_front(1);
    lsB.push_front(4);
    lsB.push_front(3);

    std::cout << "lsA: "; lsA.Print();
    std::cout << "lsB: "; lsB.Print();
    std::cout << std::endl;



    return 0;
}
