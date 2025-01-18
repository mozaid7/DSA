#include<bits/stdc++.h>
using namespace std;

// declaring a doubley linked list datatype
class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrToDLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

// int main(){
//     vector<int> arr = {12,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     print(head);
//     return 0;
// }

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     head = deleteHead(head);
//     print(head);
//     return 0;
// }

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;
    delete tail;
    return head;
}
// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     head = deleteTail(head);
//     print(head);
//     return 0;
// }

Node* removeKth(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){ // DLL with one element
        return NULL;
    }
    else if(prev == NULL){ // it is the head node
        return deleteHead(head);
    }
    else if(front == NULL){ // it is the tail node
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     head = removeKth(head,3);
//     print(head);
//     return 0;
// }

void deleteNode(Node* temp){ // this will never ask you to delete the head node
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}
// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     deleteNode(head->next);
//     print(head);
//     return 0;
// }

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}
// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     head = insertBeforeHead(head,77);
//     print(head);
//     return 0;
// }

Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     head = insertBeforeTail(head,7);
//     print(head);
//     return 0;
// }

Node* insertBeforeKth(Node* head, int k, int val){
    if(k == 1){
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     head = insertBeforeKth(head,3,10);
//     print(head);
//     return 0;
// }

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

// int main(){
//     vector<int> arr = {12,34,8,4,3,5};
//     Node* head = convertArrToDLL(arr);
//     insertBeforeNode(head->next,69);
//     print(head);
//     return 0;
// }

// Reversing a DLL
Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    head = prev->back;
    return head;
}
int main(){
    vector<int> arr = {12,34,8,4,3,5};
    Node* head = convertArrToDLL(arr);
    head = reverseDLL(head);
    print(head);
    return 0;
}