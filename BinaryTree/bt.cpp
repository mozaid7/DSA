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

// Level Order Traversal
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i<size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

//Left side view i.e. left most node of each level
vector<int> rightSideView(Node* root) {
    if(root == NULL) return {};
    queue<Node*>q;
    vector<int> ans;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 1; i<=size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            if(i == size) ans.push_back(node->data);
        }
    }
    return ans;
}


// Given the root of a binary tree, return the leftmost value in the last row of the tree.
int findBottomLeftValue(Node* root) {
    if(root == NULL) return {};
    queue<Node*>q;
    vector<int> ans;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 1; i<=size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            if(i == 1) ans.push_back(node->data);
        }
    }
    return ans.back();
}

// Top View of a Binary Tree
vector<int> topView(Node *root) {
    vector<int> ans;
    map<int, Node*> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        Node* top = q.front().first;
        int vl = q.front().second;
        q.pop();
        if(mp.find(vl) == mp.end()){
            mp[vl] = top;
        }
        if(top->left != NULL) q.push({top->left, vl-1});
        if(top->right != NULL) q.push({top->right, vl+1});
    }
    for(auto it : mp){
        ans.push_back(it.second->data);
    }
    return ans;
    
}

// Bottom View of a Binary Tree
vector<int> topView(Node *root) {
    vector<int> ans;
    map<int, Node*> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        Node* top = q.front().first;
        int vl = q.front().second;
        q.pop();
        mp[vl] = top;
        if(top->left != NULL) q.push({top->left, vl-1});
        if(top->right != NULL) q.push({top->right, vl+1});
    }
    for(auto it : mp){
        ans.push_back(it.second->data);
    }
    return ans;
    
}