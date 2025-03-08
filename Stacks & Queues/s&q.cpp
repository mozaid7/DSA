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