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

// Delete in a BST
Node* deleteBST(Node* root, int key){
    if(root == NULL) return NULL;
    if(root->data == key) return helper(root);

    Node* dummy = root;
    while(root != NULL){
        if(root->data > key){
            if(root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if(root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}
Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    } 
    else if(root->right == NULL){
        return root->left;
    }
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
Node* findLastRight(Node* root){
    if(root == NULL) return root;
    return findLastRight(root->right);
}