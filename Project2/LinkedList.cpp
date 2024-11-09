#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
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
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFirst() {
        if (!head) {
            std::cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteLast() {
        if (!tail) {
            std::cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
    }

    int size() const {
        int count = 0;
        Node<T>* temp = head;
        while (temp) {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    void display() const {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> list;

    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    std::cout << "List after adding elements: ";
    list.display();

    std::cout << "Size of list: " << list.size() << std::endl;

    list.deleteFirst();
    list.deleteLast();

    std::cout << "List after deleting first and last elements: ";
    list.display();

    std::cout << "Size of list after deletion: " << list.size() << std::endl;

    return 0;
}