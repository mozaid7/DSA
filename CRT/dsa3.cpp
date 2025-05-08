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

void levelOrder(Node* root){
    queue<Node*> q;
    if(root == NULL) q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size; i++){
            Node* top = q.front();
            q.pop();
            cout<<top->data<<" ";
            if(top->left != NULL) q.push(top->left);
            if(top->right != NULL) q.push(top->right);
        }
        cout<<endl;
    }
}