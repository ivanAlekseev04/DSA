#pragma once
#include <iostream>
        
template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node *next;

        Node(T data, Node* next = nullptr) : data(data) {
            this->next = next;
        }
    };
    Node* head;
    Node* tail;
    void free() {
        Node* toDelete = head;

        while(head != nullptr) {
            toDelete = head;
            head = head->next;
            delete toDelete;
        }   
    };
    size_t size;

public:
    // C-tors & d-tor
    LinkedList() {head = tail = nullptr; size = 0;};
    ~LinkedList() {free();};

    // Mutators
    void pushFront(const T& data) {
        Node* newNode = new Node(data);

        if(head == nullptr) {
            head = tail = newNode;
            newNode->next = nullptr;
            size++;
            return;
        } 

        newNode->next = head;
        head = newNode;

        size++;
    }
    void pushBack(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = nullptr;

        if(tail == nullptr) 
            head = newNode;
        else 
            tail->next = newNode;

        tail = newNode;
        size++;
    }
    void popBack() {
        if(head == tail) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        Node* next = head;
        Node* prev = head;

        while(next != tail) {
            prev = next;
            next = next->next;    
        }

        delete next;
        prev->next = nullptr;
        tail = prev;

        size--;
    }
    void popFront() {
        if(head == tail) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        Node* temp = head;
        head = head->next;

        size--;

        delete temp;
    }
    void insert(const T& data, size_t pos) {
        if(pos > size) {
            throw std::out_of_range("Invalid index");
        }
        else if(pos == 0) {
            pushFront(data);
            return;
        }
        else if(pos == size) {
            pushBack(data);
            return;
        }

        Node* prev = head;
        Node* next = head;
        size_t iter = 0;

        while(next != nullptr) {
            if(iter == pos) {
                Node* newNode = new Node(data);
                newNode->next = next;
                prev->next = newNode;
                size++;
                break;
            }

            prev = next;
            next = next->next;
            iter++;
        }
    }
    void erase(size_t pos) {
        if(pos < 0 || pos > size - 1) {
            throw std::out_of_range("Invalid index");
        }
        else if(pos == 0) {
            popFront();
            return;
        }
        else if(pos == size - 1) {
            popBack();
            return;
        }

        Node* prev = head;
        Node* next = head;
        size_t iter = 0;

        while(next != nullptr) {
            if(iter == pos) {
                prev->next = next->next;
                delete next;
                size--;
                break;
            }
            
            iter++;
            prev = next;
            next = next->next;
        }
    }
    void copy(const LinkedList& list) {
        free();
        Node* toAdd = list.head;

        while(toAdd != nullptr) {
            pushBack(toAdd->data);
            toAdd = toAdd->next;
        }
    }
    void reverse() {
        if(size <= 1) {
            return;
        }

        T buff[size];
        Node* elem = head;

        for(int i = 0; i < size && elem != nullptr; i++) {
            buff[i] = elem->data;
            elem = elem->next; 
        }

        std::reverse(buff, buff + size);
        elem = head;

        for(int i = 0; i < size && elem != nullptr; i++) {
            elem->data = buff[i];
            elem = elem->next; 
        }
    }
    void reverseWithPointers() {
            if(head == tail || head == nullptr) {
                return;
            }

            Node* prev = head;
            Node* next = head->next;
            Node* temp;

            prev->next = nullptr;
            tail = prev;

            while(next != nullptr) {
                temp = next->next;
                next->next = prev;

                prev = next;
                next = temp;
            }

            head = prev;
    }
    size_t count(const T& data) const {
        size_t counter = 0;
        Node* iter = head;

        while(iter != nullptr) {
            if(iter->data == data) {
                counter++;
            }

            iter = iter->next;
        }

        return counter;
    }
    bool isPalindrome() const {
        if(size <= 1) {
            return true;
        }

        T buffer[size];
        Node* iter = head;
        for(int i = 0; i < size && iter != nullptr; i++) {
            buffer[i] = iter->data;
            iter = iter->next;
        }

        bool check = false;
        for(int i = 0; i < (size / 2); i++) {
            if(buffer[i] == buffer[size - 1 - i]) {
                check = true;
            }
            else {
                check = false;
            }
        }

        return check;
    }
    void removeAll(const T& data) {
        Node* prev = head;
        Node* cur = head;
        Node* toDelete;

        while(cur != nullptr) {
            if(cur->data == data) {
                prev->next = cur->next;
                toDelete = cur;
                cur = prev->next;
                
                if(toDelete == head) {
                    head = prev->next;
                }

                delete toDelete;
                continue;
            }

            prev = cur;
            cur = cur->next;
        }
    }

    // Accessors
    size_t getSize() const {return size;};

    //Additional
    void print() {
        Node* iter = head;

        std::cout << "[ ";

        while(iter != nullptr) {
            std::cout << iter->data << " ";
            iter = iter->next;
        }

        std::cout << "]\n";
    }
};

