#pragma once       
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
    Node() : val(0), next(nullptr) {}
};

class LinkedList {
    private:
        void free() {
            Node* toDelete = head;

            while(head != nullptr) {
                toDelete = head;
                head = head->next;
                delete toDelete;
            }

            head = tail = nullptr;
        }

        Node* head = nullptr;
        Node* tail = nullptr;
        size_t size = 0;

    public:
        LinkedList() {}
        LinkedList(const LinkedList& list) {
            Node* toCopy = list.head;

            while(toCopy != nullptr) {
                pushBack(toCopy->val);
                toCopy = toCopy->next;
            }
        }
        ~LinkedList() { free(); }

        // Add element
        void pushFront(int val) {
            Node* temp = head;
            head = new Node(val);
            head->next = temp;
            
            if(tail == nullptr) {
                tail = head;
            } else if(head == tail) {    
                tail = temp;
            }

            size++;
        }
        void pushBack(int val) {
            if(tail == nullptr) {
                head = new Node(val);
                tail = head;
            } else {
                tail->next = new Node(val);
                tail = tail->next;
            }

            size++;
        }
        void insert(int val, int index) {
            if(index < 0 || index > size) {
                throw out_of_range("Invalid insertion index");
            } else if(index == 0) {
                pushFront(val);
                return;
            } else if(index == size) {
                pushBack(val);
                return;
            }

            int counter = 0;

            Node* cur = head;
            Node* prev;

            while(cur != nullptr) {
                if(counter == index) {
                    prev->next = new Node(val);
                    prev->next->next = cur;
                    size++;

                    break;
                } else {
                    prev = cur;
                    cur = cur->next;
                    counter++;
                }
            }
        }

        // Remove a node
        void popFront() {
            if(head == nullptr) {
                return;
            }

            if(head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
                toDelete = nullptr;
            }

            size--;
        }
        void popBack() {
            if(head == nullptr) {
                return;
            } else if(head == tail) {
                delete head;
                head = tail = nullptr;
                size = 0;

                return;
            }

            Node* cur = head;
            Node* prev;

            while(cur->next != nullptr) {
                prev = cur;
                cur = cur->next;
            }

            delete cur;
            prev->next = nullptr;
            tail = prev;
        }
        void erase(int index) {
            if(index < 0 || index >= size) {
                throw out_of_range("Invalid deletion index");
            } else if(index == 0) {
                popFront(); 
                return;
            } else if(index == size - 1) {
                popBack(); 
                return;
            }

            Node* cur = head;
            Node* prev;
            int counter = 0;

            while(cur != nullptr) {
                if(counter == index) {
                    prev->next = cur->next;
                    delete cur;
                    size--;

                    break;
                } else {
                    counter++;
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
        void clear() {
            free();
        }

        // Reversing
        void reverseWithPointers() {
            if(head == tail) {
                return;
            }

            Node* prev = nullptr;
            Node* cur = head;
            Node* next = cur->next;
            
            tail = cur;

            while(cur != nullptr) {
                cur->next = prev;
                
                prev = cur;
                cur = next;

                if(next != nullptr) 
                    next = next->next;
                else
                    head = prev; // "prev" at this moment will be exactly the last element from non-reversed LinkedList
            }
        }
        void reverseWithArray() {
            if(head == nullptr)
                return;

            vector<int> vals;

            Node* temp = head;
            while(temp != nullptr) {
                vals.push_back(temp->val);
                temp = temp->next;
            }

            reverse(vals.begin(), vals.end());

            temp = head;
            for(auto it : vals) {
                temp->val = it;
                temp = temp->next;
            }
        }

        // Palindrom check
        bool isPalindrom() {
            if(head == tail) {
                return true;
            }

            stack<int> toCompare;
            Node* toTraverse = head;

            for(int i = 0; i < (size / 2); i++) {
                toCompare.push(toTraverse->val);
                toTraverse = toTraverse->next;
            }

            if(size % 2 != 0) {
                toTraverse = toTraverse->next;
            }

            while(!toCompare.empty()) {
                if(toCompare.top() != toTraverse->val) {
                    return false;
                }

                toCompare.pop();
                toTraverse = toTraverse->next;
            }

            return true;
        }

        // Other
        size_t getSize() const { return size; }
        void print() {
            Node* temp = head;

            while(temp != nullptr) {
                cout << temp->val << " ";
                temp = temp->next;
            }

            cout << '\n';
        }
};
