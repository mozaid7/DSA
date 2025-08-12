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