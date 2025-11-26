/*
Name: Bani
Roll No: 102403190
Question 3: BST Insert, Delete, Maximum Depth, Minimum Depth
*/

#include <iostream>
#include <algorithm>
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

// (a) Insert element
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

// Find minimum node
Node* findMinNode(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// (b) Delete element
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        // Case 2: One child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Two children
        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// (c) Maximum depth
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + max(leftDepth, rightDepth);
}

// (d) Minimum depth
int minDepth(Node* root) {
    if (root == NULL) return 0;
    
    if (root->left == NULL && root->right == NULL) return 1;
    
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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
    
    cout << "In-order: ";
    inOrder(root);
    cout << endl;
    
    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;
    
    root = deleteNode(root, 30);
    cout << "After deleting 30: ";
    inOrder(root);
    cout << endl;
    
    return 0;
}
