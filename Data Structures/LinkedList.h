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
        void erase(int start, int end) {
            if(start < 0 || start >= size || start > end) {
                return;
            } else if(end < 0 || end >= size) {
                return;
            } else if(start == end) {
                erase(start);
                return;
            }

            Node* toDelete = head;
            Node* beforeStart = nullptr;
            int pos = 0;

            while(toDelete != nullptr) {
                if(pos == start) {
                    break;
                }

                pos++;
                beforeStart = toDelete;
                toDelete = toDelete->next;
            }

            Node* temp;

            for(int i = start; i <= end; i++) { // erase the exact range [start, end]
                temp = toDelete;
                toDelete = toDelete->next;
                delete temp;
                
                size--;
            }

            if(beforeStart == nullptr && toDelete == nullptr) { // when deletion was: [head, tail] 
                head = tail = nullptr;
            } else if(beforeStart == nullptr) { // when deletion was: [head, != tail] 
                head = toDelete;
            } else if(toDelete == nullptr) { // when deletion was: [!= head, tail]
                tail = beforeStart;
                beforeStart->next = nullptr;
            } else { // when deletion was: [!= head, != tail]
                beforeStart->next = toDelete;
            }
        }
        void clear() {
            free();
        }

        // Reversing
        void reverse() {
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
        void reverse(int left, int right) {
            if(left < 0 || left > right || left >= size || left == right)
                return;
            else if(right < left || right < 0 || right >= size) 
                return;

            Node* beforeStart = nullptr;
            Node* afterEnd = nullptr;
            stack<Node*> nodes;

            Node* toTraverse = head;
            int cnt = 0;
            
            while(toTraverse != nullptr) {
                if(cnt >= left) {
                    nodes.push(toTraverse);    
                } else {
                    beforeStart = toTraverse;
                }

                toTraverse = toTraverse->next;

                if(cnt == right) {
                    afterEnd = toTraverse;
                    break;
                }

                cnt++;
            }

            if(cnt != right) {
                throw out_of_range("Invalid range for reversing LinkedList");
            }

            if(beforeStart != nullptr) {
                beforeStart->next = nodes.top();
            } else {
                head = nodes.top(); 
            }

            while(!nodes.empty()) {
                auto curNode = nodes.top();
                nodes.pop();

                if(!nodes.empty()) {
                    curNode->next = nodes.top();
                } else {
                    curNode->next = afterEnd;

                    if(afterEnd == nullptr)
                        tail = curNode;
                }
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
