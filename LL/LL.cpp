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

// Odd even linked list to be done
Node* oddEven(Node* head) {
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

// Merging two Sorted LL
Node* mergeLL(Node* list1, Node* list2){
    Node* t1 = list1;
    Node* t2 = list2;
    Node* dNode = new Node(-1);
    Node* temp = dNode;
    while(t1 != NULL && t2 != NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dNode->next;
}

// Sorting the LL (with MergeSort)
Node* findMiddle(Node* head){ // finding middle with Tortoise & Hare method
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sortLL(Node* head){ // putting the middle in the MergeSort snippet for sorting.
    if(head == NULL || head->next == NULL) return head;

    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;

    left = sortLL(left);
    right = sortLL(right);
    return mergeLL(left, right); // merging two sorted LL code written above
}

// Remove Nth node from the end
Node* removeNth(Node* head, int k){
    Node* slow = head;
    Node* fast = head;
    for(int i=0; i<k; i++){
        fast = fast->next;
    }
    if(fast == NULL) return head->next;
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete(delNode);
    return head;
}

// Intersection of two LL
Node* intersection(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
        if(t1 == t2) return t1;
        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
    }
    return t1;
}

// Choosing common elements in two LL & creating a new LL from them in Asc. Order
Node* intersect_ll(Node* L1, Node *L2){
    Node* head = NULL;
    Node* tail = NULL;
    while(L1 != NULL && L2 != NULL){
        if(L1->data == L2->data){
            Node* newNode = new Node(L1->data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            L1 = L1->next;
            L2 = L2->next;
        }
        else if(L1->data < L2->data) {
            L1 = L1->next;
        }
        else {
            L2 = L2->next;
        }
    }
    return head;
}

// Delete the Middle of a LL
Node* deleteMid(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next; // this will place the slow pointer one step behind the fast pointer
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete(middle);
    return head;
}

// Add one to the Data of the LL and change the LL ex. 1->5->9 + 1 == 1->6->0
int addHelper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    int carry = addHelper(temp->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;

}
Node* addOne(Node* head){
    int carry = addHelper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

// Add two numbers in a LL
Node* addTwo(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;

    while(t1 != NULL || t2 != NULL){
        int sum = carry;
        if (t1) sum = sum + t1->data;
        if (t2) sum = sum + t2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;
        
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

// Rotate a LL by K times
Node* findNthNode(Node* temp, int k){
    int cnt = 1;
    while(temp != NULL) {
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node* rotate(Node* head, int k){
    if(head == NULL || k == 0) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        tail = tail->next;
        len += 1;
    }
    if(k % len == 0) return head;
    k = k % len;

    tail->next = head;
    Node* newLastNode = findNthNode(head, len - k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}

// Flattening a LL
Node* merge2Lists(Node* list1, Node* list2){
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            // res->child = list1;
            res = list1;
            // list1 = list1->child;
        }
        else {
            // res->child = list2;
            res = list2;
            // list2 = list2->child;
        }
        res->next = NULL;
    }
    // if(list1) res->child = list1;
    // else res->child = list2;
    // if(dummy->child) dummy->child->next = NULL;
    // return dummy->child;
}

Node* flatten(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mergeHead = flatten(head->next);
    head =  merge2Lists(head, mergeHead);
    return head;
}

// Reverse LL in groups of K
Node* reverseLinkedList(Node *head){
   Node* temp = head;  
   Node* prev = NULL;  
   while(temp != NULL){  
       Node* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front; 
   }
   return prev;  
}

// Function to get the Kth node from
Node* getKthNode(Node* temp, int k){
    k -= 1; 
    while(temp != NULL && k > 0){
        k--; 
        temp = temp -> next; 
    }
    return temp; 
}

// Function to reverse nodes in groups of K
Node* kReverse(Node* head, int k){
    Node* temp = head; 
    Node* prevLast = NULL; 
    while(temp != NULL){
        Node* kThNode = getKthNode(temp, k); 
        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp; 
            }
            break; 
        }
        Node* nextNode = kThNode -> next; 
        kThNode -> next = NULL; 
        reverseLinkedList(temp); 
        if(temp == head){
            head = kThNode;
        }else{
            prevLast -> next = kThNode; 
        }
        prevLast = temp; 
        temp = nextNode; 
    }
    return head; 
}