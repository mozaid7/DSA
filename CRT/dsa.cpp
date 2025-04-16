#include<bits/stdc++.h>
using namespace std;

// Add Digits
int addDigits(int num) {
    if(num >= 0 && num <= 9) return num;
    int sum = 0;
    while(num > 0){
        sum = sum + num % 10;
        num = num/10;
    }
    return addDigits(sum);
}

// Reverse a Number
int reverse(int x) {
    int revNum = 0;
    while (x != 0) {
        int lastDig = x % 10;
        revNum = revNum * 10 + lastDig;
        x = x / 10;
    }
    return revNum;
}

// Remover Duplicates from a Sorted Array 
// Approach 1 -- less optimized
int removeDuplicates(vector<int>& nums) {
    set<int> myset; //set only holds unique values
    for(int val : nums){
        myset.insert(val);
    }
    int i = 0;
    for(int val : myset){
        nums[i++] = val;
    }
    return myset.size();
}

// Approach 2 -- more optimized
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    for(int j =1; j<n; j++) {
        if(nums[i] != nums[j]) {
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
}

// Two Sum
// Approach 1 - optimized
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mpp;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        int num = nums[i];
        int moreNeeded = target - num;
        if(mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

// Approach 2 - not optimised
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((target - nums[i]) == nums[j]){
                return {i,j};
            }
        }
    }
    return{-1,-1};
}

// 3 Sum is to be done in HomeWork


// Fibonacci Number
void Fibonacci(int num) {
    int a = 0, b = 1;
    for(int i = 0; i < num; i++) {
        cout<< a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
}

// By Recursion
int fib(int n){
    if(n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}

// By using DP -- Important -- Less Time Complexity
int Fibo(int n) {
    int dp[31] = {0};
    if(dp[n] != 0) return dp[n];
    if(n == 0 || n == 1) return n;
    int curr = Fibo(n-1) + Fibo(n-2);
    dp[n] = curr;
    return curr;
}

// Factorial
int Fact(int n){
    if(n == 1) return 1;
    return n * Fact(n-1);
}

// Climbing Stairs
int dp[46] = {0};
int climbStairs(int n) {
    if(dp[n] != 0) return dp[n];
    if(n == 1 || n == 2) return n;
    int ways = climbStairs(n-1) + climbStairs(n-2);
    dp[n] = ways;
    return ways;
}

// #35 #121 #11 #167 #283 #125 #1137 #746


// Maximum Sub-Array Sum -- Brute Force
int maxSubArray(vector<int>& nums){
    int n = nums.size();
    int sum = INT_MIN;
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=i; j<n; j++){
            temp += nums[j];
        } 
        if(temp > sum){
            sum = temp;
        }
    }
    return sum;
}

// Optimized Solution -- KADANE'S ALGO
int maxSubArray(vector<int>& nums) {
    int n =nums.size();
    long long sum = 0, maxi = LONG_MIN;
    for(int i = 0; i<n; i++) {
        sum += nums[i];

        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}