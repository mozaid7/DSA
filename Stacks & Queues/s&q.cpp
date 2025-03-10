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
int findTotal(vector<int> &arr){
    int n = arr.size();
    int lMax, rMax, total = 0;
    int l = arr[0]; int r = arr[n - 1];
    while(l < r){
        if(arr[l] <= arr[r]){
            if(lMax > arr[l]) {
                total += lMax - arr[l];
            } else {
                lMax = arr[l];
            }
            l = l+1;
        } else {
            if(rMax > arr[r]){
                total += rMax - arr[r];
            } else {
                rMax = arr[r];
            }
            r = r - 1;
        }
    }
    return total;
}
