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

// Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);

    for (const auto& q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long maxVal = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        maxVal = max(maxVal, current);
    }

    return maxVal;
}

// There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. Return an array of the results.
vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    vector<int> ans;
    int m = stringList.size();
    int n = queries.size();
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++){
            if(queries[i] == stringList[j]){
                cnt++;
            }
        }
        ans.push_back(cnt);
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

// Sherlock and Valid String
string isValid(string s) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    unordered_map<int, int> freqCount;
    for (auto pair : freq) {
        freqCount[pair.second]++;
    }

    if (freqCount.size() == 1) {
        return "YES";
    } else if (freqCount.size() == 2) {
        auto it = freqCount.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        if ((c1 == 1 && (f1 - 1 == f2 || f1 == 1)) ||
            (c2 == 1 && (f2 - 1 == f1 || f2 == 1))) {
            return "YES";
        }
    }

    return "NO";
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

// There is a string, , of lowercase English letters that is repeated infinitely many times. Given an integer, , find and print the number of letter a's in the first  letters of the infinite string.
long repeatedString(string s, long n) {
    long long cnt_a = 0;
    
    for(char ch: s){
        if(ch == 'a') cnt_a++;
    }
    
    long long full_repeats = n / s.length();
    long long remainder = n % s.length();
    
    long long cnt_rem = 0;
    for(int i=0; i<remainder; i++){
        if(s[i] == 'a') cnt_rem++;
    }
    
    return full_repeats * cnt_a + cnt_rem;
}


// Sean invented a game involving a 2n*2n matrix where each cell of the matrix contains an integer. He can reverse any of its rows or columns any number of times. The goal of the game is to maximize the sum of the elements in the n*n submatrix located in the upper-left quadrant of the matrix.
int flippingMatrix(vector<vector<int>> matrix) {
    int n = matrix.size() / 2;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a = matrix[i][j];
            int b = matrix[i][2*n - 1 - j];
            int c = matrix[2*n - 1 - i][j];
            int d = matrix[2*n - 1 - i][2*n - 1 - j];
            sum += max({a, b, c, d});
        }
    }

    return sum;
}

// Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> substrFreq;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        string substr = "";
        for (int j = i; j < n; ++j) {
            substr += s[j];
            string sorted_substr = substr;
            sort(sorted_substr.begin(), sorted_substr.end());
            substrFreq[sorted_substr]++;
        }
    }

    int count = 0;
    for (auto& p : substrFreq) {
        int freq = p.second;
        count += (freq * (freq - 1)) / 2;
    }

    return count;

}