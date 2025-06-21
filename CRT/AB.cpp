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


// 304. Range Sum Query 2D - Immutable
vector<vector<int>> pre;
// NumMatrix(vector<vector<int>>& matrix) {
//     int m = matrix.size(), n = matrix[0].size();
//     pre = vector<vector<int>>(m,vector<int>(n));
//     pre[0][0] = matrix[0][0];
//     for(int i=0; i<m; i++) {
//         for(int j=0; j<n; j++){
//             if(i == 0 && j==0) continue;
//             pre[i][j] = matrix[i][j];
//             if(i>0 && j>0){
//                 pre[i][j] += pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
//             }
//             else if(i>0) pre[i][j]+=pre[i-1][j];
//             else if(j>0) pre[i][j]+=pre[i][j-1];
//         }
//     }
    
// }
    
int sumRegion(int row1, int col1, int row2, int col2) {
    int ans = pre[row2][col2];
    if(row1>0) ans -= pre[row1-1][col2];
    if(col1>0) ans -= pre[row2][col1-1];
    if(row1>0 && col1>0) ans += pre[row1-1][col1-1];
    return ans;
}

// Highest Value Palindrome
string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int l = 0, r = n - 1;
    int minChanges = 0;

    
    while (l < r) {
        if (s[l] != s[r]) {
            char maxChar = max(s[l], s[r]);
            s[l] = s[r] = maxChar;
            changed[l] = changed[r] = true;
            k--;
        }
        l++;
        r--;
    }

    if (k < 0) return "-1";

    l = 0;
    r = n - 1;
    while (l <= r) {
        if (l == r) {
            if (k > 0 && s[l] != '9') {
                s[l] = '9';
                k--;
            }
        } else {
            if (s[l] != '9') {
                if (changed[l] || changed[r]) {
                    if (k >= 1) {
                        s[l] = s[r] = '9';
                        k--;
                    }
                } else {
                    if (k >= 2) {
                        s[l] = s[r] = '9';
                        k -= 2;
                    }
                }
            }
        }
        l++;
        r--;
    }

    return s;
}

// Trapping Rain Water
int trap(vector<int>& height) {
    int n = height.size();
    if(n==0) return 0;

    int l = 0; int r = n-1;
    int lmax = height[l], rMax = height[r];
    int total = 0;

    while(l < r){
        if(height[l] <= height[r]){
            if(height[l] < lmax){
                total += lmax - height[l];
            }
            lmax = max(lmax, height[l]);
            l++;
        } else {
            if(height[r] < rMax){
                total += rMax - height[r];
            }
            rMax = max(rMax, height[r]);
            r--;
        }
    }
    return total;
};

// 1446. Consecutive Characters
int maxPower(string s) {
    int n = s.size();
    int cnt = 1;
    int maxCount = 0;

    for(int i=1; i<=n; i++){
        if(s[i] == s[i-1]){
            cnt++;
        } else {
            maxCount = max(cnt,maxCount);
            cnt = 1;
        }
    }
    return maxCount;
}

// Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for(auto str : strs){
        string word = str;
        sort(word.begin(), word.end());
        mp[word].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto x: mp){
        ans.push_back(x.second);
    }
    return ans;
}

// Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) {
    int left = 0;
    int maxLength = 0;
    unordered_set<char> charSet;

    for (int right = 0; right < s.length(); right++) {
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }

        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength; 
}

// 151. Reverse Words in a String
string reverseWords(string s) {
    int n = s.size();
    string temp = "";
    vector<string> res;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            temp += s[i];
        } else {
            if (!temp.empty()) {
                res.push_back(temp);
                temp = "";
            }
        }
    }

    if (!temp.empty()) {
        res.push_back(temp);
    }
    
    reverse(res.begin(), res.end());
    string result = "";
    for (int i = 0; i < res.size(); i++) {
        result += res[i];
        if (i < res.size() - 1) result += ' ';
    }

    return result;
}

// Valid Palindrome Without extra space
bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right])) return false;

        left++;
        right--;
    }

    return true;
}


// 4Sum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            long long newTarget = (long long)target - (long long)(nums[i] + nums[j]);
            int l = j + 1;
            int r = n - 1;

            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];

                if (sum == newTarget) {
                    st.insert({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (sum < newTarget) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }

    for (auto &quad : st) {
        ans.push_back(quad);
    }

    return ans;
}

// CORPORATE BOOKINGS -- Array Manipulation IMP
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n,0);

    for(vector<int> ch: bookings){
        int s = ch[0];
        int e = ch[1];
        int seats = ch[2];

        ans[s - 1] += seats;
        if(e != n) ans[e] -= seats;
    }
    for(int i=1; i<n; i++){
        ans[i] += ans[i - 1];
    }
    return ans;
}

// Bulb Switcher Small but IMP
int bulbSwitch(int n) {
    long long i=1;
    int cnt=0;
    while((i*i)<=n){
        i++;
        cnt++;
    }
    return cnt;
}

// 560 Subarray Sum equals K
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int>mpp;
    mpp[0] = 1;
    int preSum = 0; int cnt = 0;
    for(int i=0; i<n; i++) {
        preSum += nums[i];
        int rem = preSum - k;
        cnt += mpp[rem];
        mpp[preSum] += 1;
    }
    return cnt;
}

// 523 Continuous subarray sum
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(mp.find(sum%k)!=mp.end()){
            if(i-mp[sum%k]>=2)
                return true;
        }
        else
            mp[sum%k]=i;
    }
    return false;
}

// 34. Find First and Last Position of Element in Sorted Array
vector<int> searchRange(vector<int>& nums, int target) {
    int start = -1, end = -1;
    int n = nums.size();
    int l=0, r=n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(nums[mid] == target){
            start = mid;
            r = mid -1;
        }
        else if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    if(start == -1) return {start, end};

    l=0, r=n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(nums[mid] == target){
            end = mid;
            l = mid + 1;
        }
        else if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return {start, end};
}

// Sqrt(x)
int mySqrt(int x) {
    if(x == 0 || x == 1){
        return x;
    }

    int start = 1, end = x, mid = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        long long square = static_cast<long long>(mid) * mid;
        if(square > x){
            end = mid - 1;
        } 
        else if(square == x) return mid;
        else start = mid + 1;
    }
    return static_cast<int>(std::round(end));
}

// Koko Eating Bananas
bool canEatAll(const vector<int>& piles, int h, int k) {
    int hours = 0;
    for (int bananas : piles) {
        hours += (bananas + k - 1) / k;
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, h, mid))
            right = mid;
        else
            left = mid + 1; 
    }
    return left;
}


