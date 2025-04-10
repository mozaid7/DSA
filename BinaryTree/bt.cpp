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

// Height of a Binary Tree
int maxDepth(Node* root){
    if(root == nullptr) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}

// Check if the height of the tree is Balanced
bool isBalanced(Node* root) {
    return maxDepth(root) != -1;
}

int maxDepth(Node* root){
    if(root == nullptr) return 0;
    int lh = maxDepth(root->left);
    if(lh == -1) return -1;
    int rh = maxDepth(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

// Level Order Traversal todo