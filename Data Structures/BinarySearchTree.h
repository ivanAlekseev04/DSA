#pragma once
#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BST {
    private:
        Node* root;

        // insert() utility function
        Node* insertNode(Node* root, int val) {
            if(root == nullptr) 
                return new Node(val);
            
            if(root->val < val) 
                root->right = insertNode(root->right, val);
            else if(root->val > val)
                root->left = insertNode(root->left, val);

            return root;
        }

        // printInorder() utility function
        void printInorderUtil(Node* toPrint) {
            if(toPrint != nullptr) {
                printTree(toPrint->left);

                std::cout << toPrint->val << " ";

                printTree(toPrint->right);
            }
        }

        // remove() utility functions
        Node* getMinNode(Node* root) {
            while(root->left != nullptr) {
                root = root->left;
            }

            return root;
        }
        Node* removeNode(Node* root, int val) {
            if(root == nullptr) {
                return root;
            }

            if(root->val > val) {
                root->left = removeNode(root->left, val);
            }
            else if(root->val < val) {
                root->right = removeNode(root->right, val);
            }
            else {
                if(root->left == nullptr && root->right == nullptr) { // no child case
                    delete root;
                    root = nullptr;
                    return root;
                }
                else if(root->left == nullptr) { // one child case
                    Node* temp = root->right;
                    delete root;
                    root = nullptr;
                    return temp;
                } 
                else if(root->right == nullptr) { // one child case
                    Node* temp = root->left;
                    delete root;
                    root = nullptr;
                    return temp;
                }
                // Now will be case with 2 childs

                Node* min = getMinNode(root->right);
                root->val = min->val;
                root->right = removeNode(root->right, min->val);
            }

            return root;
        }

        // heightOfRight() && heightOfLeft() utility function
        void heightOfSide(Node* node, int curHeight, int& maxHeight) {
            if(node != nullptr) {
                if(node == root) {
                    return;
                }

                if(curHeight > maxHeight) {
                    maxHeight = curHeight;
                }

                heightOfSide(node->left, curHeight + 1, maxHeight);
                heightOfSide(node->right, curHeight + 1, maxHeight);
            }
        }

        // lowestCommonAncestor() utility function
        void getPathFromTheRoot(Node* root, int val, vector<Node*>& path) {
            if(root != nullptr) {
                if(path.empty() || path.back()->val != val) {
                    path.push_back(root);
                } else {
                    return;
                }

                if(val < root->val) {
                    getPathFromTheRoot(root->left, val, path);
                } else if(val > root->val) {
                    getPathFromTheRoot(root->right, val, path);
                } 
            }
        }

    public:
        BST() : root(nullptr) {}

        void insert(int val) {
            root = insertNode(root, val);
        }

        void printInorder() {
            printInorderUtil(root);
        }

        void remove(int val) {
            root = removeNode(root, val);
        }

        int heightOfRight() {
            int maxHeight = 0;
            heightOfSide(root->right, 1, maxHeight);

            return maxHeight;
        }

        int heightOfLeft() {
            int maxHeight = 0;
            heightOfSide(root->left, 1, maxHeight);

            return maxHeight;
        }

        Node* lowestCommonAncestor(int p, int q) {
            vector<Node*> pPath;
            vector<Node*> qPath;

            getPathFromTheRoot(root, p, pPath);
            getPathFromTheRoot(root, q, qPath);

            vector<Node*>& smaller = (pPath.size() >= qPath.size()) ? qPath : pPath;
            vector<Node*>& bigger = (pPath.size() < qPath.size()) ? qPath : pPath;

            int i = 0;
            for(; i < smaller.size(); i++) {
                if(i + 1 == smaller.size()) {
                    break; 
                } else if(smaller[i + 1]->val != bigger[i + 1]->val) {
                    break;
                }
            }

            return smaller[i];
        }
};
