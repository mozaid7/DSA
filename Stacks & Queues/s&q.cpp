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

// comment