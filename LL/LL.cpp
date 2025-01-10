#include<bits/stdc++.h>
using namespace std;

// declaring a linked list datatype
class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// int main(){
//     vector<int> arr = {2,4,3,5};
//     Node* y = new Node(arr[2],nullptr);
//     cout << y;
// }

// coverting arr to LL
// Node* convertArrToLL(vector<int> arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
//     for(int i =1; i<arr.size(); i++){
//         Node* temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = temp;
//     }
//     return head;
// }
// int main(){
//     vector<int> arr = {12,4,3,5};
//     Node* head = convertArrToLL(arr);
//     cout << head->data;
// }

// LL traversal 
// first declare the LL and print the Head then traverse
Node* convertArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// int main(){
//     vector<int> arr = {12,4,3,5};
//     Node* head = convertArrToLL(arr);
//     Node* temp = head;
//     while(temp){
//         cout << temp->data << " " ;
//         temp = temp->next;
//     }
// }

// Length of LL
int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        // cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
// int main(){
//     vector<int> arr = {12,4,3,5};
//     Node* head = convertArrToLL(arr);
//     cout << lengthOfLL(head);
// }

// Searching an element
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     cout << checkIfPresent(head, 5);
// }

// Print LL
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Deleting the Head of the LL
Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     head = deleteHead(head);
//     print(head);
// }

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp= temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     head = removeTail(head);
//     print(head);
// }

// Removing the Kth element (Positon of element)
Node* removeKth(Node* head, int k){
    if(head == NULL) return head;
    if (k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     head = removeKth(head,3);
//     print(head);
// }

// Removing the Kth element (Value of element)
Node* removeEle(Node* head, int el){
    if(head == NULL) return head;
    if (head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     head = removeEle(head,4);
//     print(head);
// }

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return head;
}
int main(){
    vector<int> arr = {12,4,3,5,8,7};
    Node* head = convertArrToLL(arr);
    head = insertHead(head,100);
    print(head);
}
