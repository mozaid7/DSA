#include<bits/stdc++.h>
using namespace std;

// Plus One
vector<int> plusOne(vector<int>& digits) {
    // move backwards
    for (int i = digits.size() - 1; i >= 0; i--) {
        int num = digits[i] + 1;
        if (num == 10 && i != 0) {
            digits[i] = 0;
        }
        else {
            digits[i] = num;
            break;
        }
    }
    if (digits[0] == 10) {
        digits[0] = 1;
        digits.push_back(0);
    }
    return digits;
}

// Largest Number
string largestNumber(vector<int>& nums) {
    vector<string> arr;
    for(int num : nums){
        arr.push_back(to_string(num));
    }

    // VERY IMP method. revise again !!
    sort(arr.begin(), arr.end(), [](const string &a, const string &b){
        return a+b > b+a;
    });

    if(arr[0] == "0"){
        return "0";
    }

    string largest;
    for(const string &num : arr){
        largest += num;
    }
    return largest;
}

// Most Frequent Even Element
int mostFrequentEven(vector<int>& nums) {
    map<int, int>mpp;
    for(int num : nums){
        if(num%2 == 0){
            mpp[num] += 1;
        }  
    }

    map<int, int>::iterator it;
    int maxFreqNumber = -1;
    int maxFreq = 0;
    for(it = mpp.begin(); it != mpp.end(); it++){
        if(it->second > maxFreq){
            maxFreq = it->second;
            maxFreqNumber = it->first;
        } else if(it->second == maxFreq){
            maxFreqNumber = min(maxFreqNumber, it->first);
        }
    }

    return maxFreqNumber;
}

// Simplified and Compact Version
int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0, result = -1;

    for (int num : nums) {
        if (num % 2 == 0) {
            freq[num]++;
            if (freq[num] > maxFreq || 
               (freq[num] == maxFreq && num < result)) {
                maxFreq = freq[num];
                result = num;
            }
        }
    }

    return result;
}


// LINKED LIST -- STARTING FROM HERE
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

// Delete the middle of the Linked List
Node* deleteMid(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
        
    }
    prev->next = slow->next;
    return head;
}