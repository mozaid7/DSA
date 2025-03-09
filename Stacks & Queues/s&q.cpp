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

// Next Greater Element
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