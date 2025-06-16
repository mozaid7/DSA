#include<bits/stdc++.h>
using namespace std;

// 238. Product of Array Except Self
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n), suf(n);
    pre[0] = nums[0];
    suf[n-1] = nums[n-1];
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1]*nums[i];
    }
    for(int i=n-2; i>=0; i--){
        suf[i] = suf[i+1]*nums[i];
    }
    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        if(i == 0) ans[i]=suf[i+1];
        else if (i == n-1) ans[i] = pre[i-1];
        else ans[i] = pre[i-1]*suf[i+1];
    }
    return ans;
}

// 3584. Maximum Product of First and Last Elements of a Subsequence
long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> suf_max(n), suf_min(n);
        suf_max[n-1]=suf_min[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            suf_max[i] = max(suf_max[i+1],1LL*nums[i]);
            suf_min[i] = min(suf_min[i+1],1LL*nums[i]);
        }
        long long ans = LLONG_MIN;
        for(int i=0; i<n-m+1; i++){
            long long num = nums[i];
            if(m == 1){
                ans = max(ans,num*num);
            }
            else{
                if(nums[i]<0) ans = max(ans,1LL*nums[i]*suf_min[i+m-1]);
                else ans = max(ans,1LL*nums[i]*suf_max[i+m-1]);
            }
        }
        return ans;
}

// Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n,0);
        pre[0] = arr[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto& q:queries){
            int l = q[0], r= q[1];
            int res=0;
            if(l>0){
                res ^= pre[l-1];
            }
            res ^= pre[r];
            ans.push_back(res);
        }
        return ans;

    }