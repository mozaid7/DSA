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