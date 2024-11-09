#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }


    void insertAtFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }


    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void deleteFirst() {
        if (head == nullptr) {
            std::cout << "List is empty, nothing to delete\n";
            return;
        }
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }


    void deleteLast() {
        if (tail == nullptr) {
            std::cout << "List is empty, nothing to delete\n";
            return;
        }
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }


    int size() {
        int s = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            s++;
            temp = temp->next;
        }
        return s;
    }


    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> list;


    list.insertAtFront(10);
    list.insertAtEnd(20);
    list.insertAtFront(5);
    list.insertAtEnd(30);


    std::cout << "List elements: ";
    list.display();


    list.deleteFirst();
    list.deleteLast();


    std::cout << "List elements after deletions: ";
    list.display();


    std::cout << "List size: " << list.size() << std::endl;

    return 0;
}