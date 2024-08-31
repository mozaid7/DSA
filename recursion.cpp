#include<bits/stdc++.h>
using namespace std;
int cnt =0;

// Print 1 to n
void print () {
    if(cnt == 3) return;
    cout<<cnt<<endl;

    cnt++;
    print();
}

void print2(int i, int n){
    if(i>n) return;
    cout << i << " ";
    print2(i+1,n);
}

// N to 1 without backtracking
void print3(int n, int i){
    if(n<i) return;
    cout << n << " ";
    print3(n-1,i);
}

// Backtracking
void print4(int i, int n) {
    if(i>n) return;
    print4(i+1,n);
    cout << i << " ";
}
// int main(){
//     int n = 4;
//     print4(1,n);
//     return 0;
// }

// Sum of n numbers
int print5(int n) {
   if(n == 0) return 0;
   return n + print5(n-1);
}

// Factorial
int print6(int n) {
   if(n == 0) return 1;
   return n * print5(n-1);
}

void reverse(int i, int arr[], int n) {
    if(i>= n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverse(i+1, arr, n);
}
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0; i<n; i++) cin >> arr[i];
//     reverse(0, arr, n);
//     for(int i=0; i<n; i++) cout << arr[i] << " ";
//     return 0;
// }

bool palindrome(int i, string &s) {
    if(i >= s.size() / 2) return true;
    if(s[i] != s[s.size() - i - 1]) return false;
    return palindrome(i+1, s);
}
// int main(){
//     string s ="madam";
//     cout << palindrome(0, s);
//     return 0;
// }

// Palindrome Code with No spaces and No Uppercase
// class Solution {
// public:
// bool isPalindrome(string s) {
//     string pal = "";
//     for (char i : s) {
//         i = tolower(i);
//         if (isalpha(i) || isdigit(i)) pal.push_back(i);
//     }

//     int n = pal.size(), left = 0, right = n - 1;
//     if (n == 0 || n == 1) return true;
//     while (left <= right) {
//         if (pal[left] == pal[right]) {
//             left++;
//             right--;
//         } else return false;
//     }
//     return true;
// }
// };

// Fibonacci Number
int fib(int n) {
        if(n<=1) return n;
        int ans = fib(n-1) + fib(n-2);
        return ans;
}

int main(){
    int n = 10;
    cout << fib(n);
}