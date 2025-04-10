#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

// Search in a BST
Node* searchBST(Node* root, int val){
    while(root != NULL && root->data != val){
        root = val < root->data ? root->left : root->right;
    }
    return root;
}

// Insert in a BST
Node* insertBST(Node* root, int val){
    if(root == NULL) return new Node(val);
    Node* curr = root;
    while(true){
        if(curr->data <= val){
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new Node(val);
                break;
            }
        } else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new Node(val);
                break;
            }
        }
    }
    return root;
}