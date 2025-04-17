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

// Container with Most Water #11
int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int maxArea = 0;
    while(left < right){
        int currArea = min(height[left], height[right]) * (right -left);
        if(currArea > maxArea) maxArea = currArea;

        if(height[left] < height[right]){
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

// Move zeroes to the end
vector<int> moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = -1;
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) {
            j = i;
            break;
        }
    }
    // no non zero numbers
    if(j == -1) return nums;

    for(int i = j+1; i<n; i++) {
        if(nums[i] != 0) {
            swap(nums[i],nums[j]);
            j++;
        }
    }
    return nums;
}

// Search insert position
int searchInsert(vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// 35 121 11 #167 283 125 1137 #746

// Buy and Sell Stock
int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for(int i = 1; i<n; i++) {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

// Valid Palindrome
bool isPalindrome(string s) {
    string pal = "";
    for (char i : s) {
        i = tolower(i);
        if (isalpha(i) || isdigit(i)) pal.push_back(i);
    }

    int n = pal.size(), left = 0, right = n - 1;
    if (n == 0 || n == 1) return true;
    while (left <= right) {
        if (pal[left] == pal[right]) {
            left++;
            right--;
        } else return false;
    }
    return true;
}

// Tribonacci
int tribonacci(int n) {
    if(n == 0 || n == 1 || n == 1) return n;
    int dp[n+1];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3; i<= n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    return dp[n];
}

// Rotate an Array
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    
}