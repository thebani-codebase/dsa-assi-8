/*
Name: Bani
Roll No: 102403190
Question 2: BST Search (Recursive & Non-Recursive), Min, Max, Successor, Predecessor
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    
    return root;
}


bool searchRecursive(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    
    if (key < root->data) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}


bool searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return true;
        
        if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}
int findMax(Node* root) {
    if (root == NULL) return -1;
    
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}
int findMin(Node* root) {
    if (root == NULL) return -1;
    
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}
Node* inorderSuccessor(Node* root, int key) {
    Node* current = root;
    Node* successor = NULL;
    
    while (current != NULL) {
        if (key < current->data) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return successor;
}
Node* inorderPredecessor(Node* root, int key) {
    Node* current = root;
    Node* predecessor = NULL;
    
    while (current != NULL) {
        if (key > current->data) {
            predecessor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    
    return predecessor;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    cout << "Search 40 (Recursive): " << (searchRecursive(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 40 (Non-Recursive): " << (searchNonRecursive(root, 40) ? "Found" : "Not Found") << endl;
    
    cout << "Maximum: " << findMax(root) << endl;
    cout << "Minimum: " << findMin(root) << endl;
    
    Node* succ = inorderSuccessor(root, 50);
    if (succ) cout << "Successor of 50: " << succ->data << endl;
    
    Node* pred = inorderPredecessor(root, 50);
    if (pred) cout << "Predecessor of 50: " << pred->data << endl;
    
    return 0;
}
