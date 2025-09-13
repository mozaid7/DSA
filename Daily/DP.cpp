#include <bits/stdc++.h>
using namespace std;

// DP - Dynamic Programming

// 70. Climbing Stairs
int climbStairs(int n){
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[0] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// 746. Min Cost to Climb Stairs
int minCost(vector<int>& cost){
    int n = cost.size();
    for(int i=2; i<n; i++){
        cost[i] += min(cost[i-1], cost[i-2]);
    }
    return min(cost[n-1], cost[n-2]);
}

//198. House Robber-1
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) return nums[0];

    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[n-1];
}

// 213. House Robber 2
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) return nums[0];
    
    vector<int> skipLast(n-1);
    vector<int> skipFirst(n-1);

    for(int i=0; i<n-1; i++){
        skipLast[i] = nums[i];
        skipFirst[i] = nums[i+1];
    }

    int lootSkipLast = robHelp(skipLast);
    int lootSkipFirst = robHelp(skipFirst);

    return max(lootSkipLast, lootSkipFirst);
}

int robHelp(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) return nums[0];

    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[n-1];
}

// Coin Change - 2 
int dp[1001][10001];
int countWays(vector<int>& coins, int amount, int idx){
    if (idx == 0) {
        if (amount % coins[0] == 0) 
            return amount / coins[0];
        else 
            return 1e9;
    }

    if(dp[idx][amount] != -1) return dp[idx][amount];

    int notTake = countWays(coins, amount, idx-1);
    int take = 1e9;
    if(coins[idx] <= amount){
        take = 1 + countWays(coins, amount-coins[idx], idx);
    }

    return dp[idx][amount] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    memset(dp, -1, sizeof(dp));
    int ans = countWays(coins, amount, n - 1);
    return (ans >= 1e9) ? -1 : ans;
}

// Longest Common Subsequence
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

// Edit Distance
int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i=1; i<=n; i++){
        dp[i][0] = i;
    }
    for(int j=1; j<=m; j++){
        dp[0][j] = j;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }
    return dp[n][m];
}

// Target Sum
int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    mp[0] = 1;

    for(int num : nums){
        unordered_map<int,int> newMp;
        for(auto &[sum, count] : mp){
            newMp[sum + num] += count;
            newMp[sum - num] += count;
        }
        mp = move(newMp);
    }
    return mp.count(target) ? mp[target] : 0;
}