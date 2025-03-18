#include<bits/stdc++.h>
using namespace std;

// Balanced Paranthesis
class MyStack {
    private:
        stack<char> st;
    public:
        MyStack() {}

        bool isBalanced(string s){
            for(char ch : s){
                if(ch == '(' || ch == '{' || ch == '['){
                    st.push(ch);
                } else {
                    if(st.empty()) return false;

                    char top = st.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {
                            st.pop();
                    } else {
                        return false;
                    }
                }
            }
            return st.empty();
        }
};

// GetMin function in Stack
class MyStack{
private:
    stack<pair<int,int>> st;
public:
    MyStack(){}

    void push(int val){
        if(st.empty()){
            st.push({val,val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }

    int getMin(){
        return st.top().second;
    }

    int top() {
        return st.top().first;
    }

};

// Next Greater Element-I
list<int> findNGE(vector<int> &arr){
    int n = arr.size();
    vector<int> nge(n,-1);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()) nge[i] = st.top();
        else nge[i] = -1;
        st.push(arr[i]);
    }
    //return nge;
}

// Next Greater Element-II
list<int> findNGE(vector<int> &arr){
    int n = arr.size();
    vector<int> nge(n,-1);
    stack<int> st;
    for(int i = 2*n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i%n]){  // arr[i%n] -> original element from the array rather then doubled one
            st.pop();
        }
        if(i<n){
            nge[i] = st.empty()? -1 : st.top();
        }
        st.push(arr[i%n]);
    }
    //return nge;
}

// Trapping Rainwater
int trapWater(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int l = 0, r = n - 1;
    int lMax = arr[l], rMax = arr[r]; 
    int total = 0;

    while (l < r) {
        if (arr[l] <= arr[r]) {
            if (arr[l] < lMax) {
                total += lMax - arr[l]; 
            } 
            lMax = max(lMax, arr[l]);
            l++;  
        } else {
            if (arr[r] < rMax) {
                total += rMax - arr[r];  
            }
            rMax = max(rMax, arr[r]);  
            r--;  
        }
    }
    return total;
}

//Sum of Subarray Minimums //Hard to understand
class Solution {
    public:
        vector<int> NextSmaller(const vector<int>& arr){
            int n = arr.size();
            vector<int> nextSmall(n);
            stack<int> stk;
            for (int i = n - 1; i >= 0; i-- ) {
                while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                    stk.pop(); // Remove processed element              
                }
                nextSmall[i] = stk.empty() ? n: stk.top();
                stk.push(i);
            }
        return nextSmall;
        }
        vector<int> PrevSmaller(const vector<int>& arr){
            int n = arr.size();
            vector<int> prevSmall(n);
            stack<int> stk;
            for (int i = 0; i < n ; i++) {
                while (!stk.empty() && arr[i] < arr[stk.top()]) {
                    stk.pop(); // Remove processed element
                }
                prevSmall[i]=stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
        return prevSmall;
        }
        int sumSubarrayMins(vector<int>& arr) {
            vector<int> pse = PrevSmaller(arr);
            vector<int> nse = NextSmaller(arr);
            int total=0, mod = (int)(1e9 + 7);
            for(int i=0;i<arr.size();i++){
                int left = i-pse[i];
                int right = nse[i]-i;
                total=(total+(left * right * 1LL * arr[i]) % mod) % mod;
            }
            return total;
        }
};

// Sum of Subarray Ranges
long long subArrayRanges(vector<int>& A) {
    long long res = 0;
    for (int i = 0; i < A.size(); i++) {
        int largest = A[i], smallest = A[i];
        for (int j = i; j < A.size(); j++) {
            largest = max(largest, A[j]);
            smallest = min(smallest, A[j]);
            res += largest - smallest;
        }
    }
    return res;
}

// Asteroid Collision
list<int> asteroid(vector<int> &arr){
    list<int> st;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) st.push_back(arr[i]);
        else {
            while(!st.empty() && st.back() > 0 && st.back() < abs(arr[i])){
                st.pop_back();
            }
            if(!st.empty() && st.back() == abs(arr[i])){
                st.pop_back();
            }
            else {
                if(st.empty() || st.back() < 0){
                    st.push_back(arr[i]);
                }
            }
        }
    }
    return st;
};

//Sliding Window Maximum
vector<int> maxWindow(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> lst;
    deque<int> dq;
    for(int i = 0; i<n; i++){
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1) lst.push_back(arr[dq.front()]);
    }
    return lst;
}

// LRU Cache
class LRUCache {
    public:
        class Node{
            public: 
                int key;
                int val;
                Node* prev;
                Node* next;
    
                Node(int key, int val){
                    this->key = key;
                    this->val = val;
                }
        };
    
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
    
        int cap;
        unordered_map<int, Node*> m;
    
        LRUCache(int capacity) {
            cap = capacity;
            head -> next = tail;
            tail -> prev = head;
        }
    
        void addNode(Node* newnode){
            Node* temp = head -> next;
    
            newnode -> next = temp;
            newnode -> prev = head;
    
            head -> next = newnode;
            temp -> prev = newnode;
        }
    
        void deleteNode(Node* delnode){
            Node* prevv = delnode -> prev;
            Node* nextt = delnode -> next;
    
            prevv -> next = nextt;
            nextt -> prev = prevv;
        }
        
        int get(int key) {
            if(m.find(key) != m.end()){
                Node* resNode = m[key];
                int ans = resNode -> val;
    
                m.erase(key);
                deleteNode(resNode);
                addNode(resNode);
    
                m[key] = head -> next;
                return ans;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if(m.find(key) != m.end()){
                Node* curr = m[key];
                m.erase(key);
                deleteNode(curr);
            }
    
            if(m.size() == cap){
                m.erase(tail -> prev -> key);
                deleteNode(tail -> prev);
            }
    
            addNode(new Node(key, value));
            m[key] = head -> next;
        }
};


// LRU Revised