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
    LinkedList(const LinkedList& other); // Copy constructor for deep copy
    LinkedList& operator=(const LinkedList& other); // Copy assignment for deep copy
    ~LinkedList();

    void push_back(const T& value);
    void push_front(const T& value);
    void Print() const;
    ListNode<T>* getFirstPtr() const { return head; } // To print the first node pointer

private:
    ListNode<T>* head;
    size_t len;

    void clear();
    void copyNodes(const LinkedList& other);
};

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(nullptr), len(0) {
    copyNodes(other);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        copyNodes(other);
    }
    return *this;
}

template<typename T>
void LinkedList<T>::copyNodes(const LinkedList& other) {
    ListNode<T>* current = other.head;
    ListNode<T>* last = nullptr;
    while (current != nullptr) {
        ListNode<T>* newNode = new ListNode<T>(current->data);
        if (last == nullptr) {
            head = newNode;
        }
        else {
            last->next = newNode;
        }
        last = newNode;
        current = current->next;
    }
    len = other.len;
}

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

    LinkedList<size_t> ls1;
    ls1.push_back(1);
    ls1.push_back(4);
    ls1.push_back(3);
    ls1.push_back(1);

    LinkedList<size_t> ls2 = ls1;
    ls1.push_back(5);

    std::cout << "ls1: "; ls1.Print();
    std::cout << "ls2: "; ls2.Print();
    std::cout << "ls1.getFirstPtr() = " << ls1.getFirstPtr() << std::endl;
    std::cout << "ls2.getFirstPtr() = " << ls2.getFirstPtr() << std::endl;
    std::cout << std::endl;

    return 0;
}
