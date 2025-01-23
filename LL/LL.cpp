#include<bits/stdc++.h>
using namespace std;

// declaring a linked list datatype
class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
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
//     cout << head->data;
// }

// LL traversal 
// first declare the LL and print the Head then traverse
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

// insert at Head
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head); // return new Node(val,head);
    return temp;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     head = insertHead(head, 132);
//     print(head);
// }

// insert at Tail
Node* insertTail(Node* head, int val){
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val, nullptr);
    return head;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     head = insertTail(head, 77);
//     print(head);
// }

// insert at a specified position i.e. K
Node* insertAtK(Node* head, int el, int k){
    if (head == NULL){ // when LL is empty
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        } 
    }
    if(k == 1){  // when inserting at the head i.e. k=1
        Node* temp = new Node(el, head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
// int main(){
//     vector<int> arr = {12,4,3,5,8,7};
//     Node* head = convertArrToLL(arr);
//     head = insertAtK(head, 69, 3);
//     print(head);
// }

// insert before the given value i.e. value from the given LL
Node* insertBeforeVal(Node* head, int el, int val){
    if (head == NULL){ // when LL is empty
        return NULL; 
    }
    if(head->data == val){  // when inserting before the head
        Node* temp = new Node(el, head);
        return temp;
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {12,4,3,5,8,7};
    Node* head = convertArrToLL(arr);
    head = insertBeforeVal(head, 89, 3);
    print(head);
}

// Deleting the given node when head is not given
Node* deleteWithoutHead(Node* node){
    Node* temp = node->next; // create a temp node which is next to the node to be deleted
    node->data = temp->data; // copy the data from the temp node
    node->next = temp->next; // remove the temp node from between
    delete temp;
}

// Reverse a LL with Iterative method
Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Reverse a LL with recursion
Node* reverseLLRecursion(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverseLLRecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// Middle of LL using Tortoise and Hare method
Node* middleOfLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    if(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Detecing a loop in a LL with Tortoise & Hare method
bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// Detecting the starting node of the loop
Node* startOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

// Detect the length of the loop in a LL
int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}
int lengthOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return findLength(slow, fast);
    }
    return 0;
}

// LL is palindrome or not
bool isPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLLRecursion(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            reverseLLRecursion(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLLRecursion(newHead);
    return true;
}