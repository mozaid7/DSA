#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
};

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

// Next Greater Element
vector<int> nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int>st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i]){ // while (!st.empty() && st.top() >= arr[i]) --> for next smaller element
            st.pop();
        }
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
    
}


// Largest Rectangle in Histogram 
vector<int> nextSmallerIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
}

vector<int> previousSmallerIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top(); 
        }

        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left = previousSmallerIndex(heights);
    vector<int> right = nextSmallerIndex(heights);

    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Maximal Rectangle 
vector<int> nextSmallerIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
}

vector<int> previousSmallerIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top(); 
        }

        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left = previousSmallerIndex(heights);
    vector<int> right = nextSmallerIndex(heights);

    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    int m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    int maxRectangle = 0;

    for (int i = 0; i < m; i++) {
        // Update heights: if '1' -> +1, if '0' -> reset to 0
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }
        maxRectangle = max(maxRectangle, largestRectangleArea(heights));
    }

    return maxRectangle;
}

// Number of Visible Person in a Queue
vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[i] > heights[st.top()]) {
            ans[i]++;
            st.pop();
        }

        if (!st.empty()) {
            ans[i]++;
        }

        st.push(i);
    }

    return ans;
}

// Palindrome Linked List
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    // Reverse first half while finding the middle
    while (fast && fast->next) {
        fast = fast->next->next;

        // Reverse logic
        ListNode* nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }

    // If odd-length list, skip the middle node
    if (fast) {
        slow = slow->next;
    }

    // Now, `prev` is the head of reversed first half,
    // and `slow` is the head of the second half
    while (prev && slow) {
        if (prev->val != slow->val) return false;
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

// Reorder List
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    // Step 1: Find the middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode* second = reverse(slow->next);
    slow->next = nullptr; // Break the first half

    // Step 3: Merge first and second halves
    ListNode* first = head;
    while (second) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}

// Delete Duplicate Elements
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;

    while (head != nullptr) {
        if (head->next != nullptr && head->val == head->next->val) {
            int duplicateVal = head->val;

            while (head != nullptr && head->val == duplicateVal) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }

            prev->next = head;
        } else {
            prev = prev->next;
            head = head->next;
        }
    }

    ListNode* result = dummy->next;
    delete dummy;
    return result;
}

// Game Of Life
int countLiveNeighbors(vector<vector<int>>& board, int row, int col, int m, int n) {
    int live = 0;
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (auto dir : directions) {
        int r = row + dir.first;
        int c = col + dir.second;

        if (r >= 0 && r < m && c >= 0 && c < n && abs(board[r][c]) == 1) {
            live++;
        }
    }

    return live;
}

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();

    // Apply rules with encoding
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int live = countLiveNeighbors(board, i, j, m, n);

            if (board[i][j] == 1) {
                if (live < 2 || live > 3) board[i][j] = -1; // live → dead
            } else {
                if (live == 3) board[i][j] = 2; // dead → live
            }
        }
    }

    // Finalize state
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = board[i][j] > 0 ? 1 : 0;
        }
    }
}

// Reverse Nodes in k-groups
ListNode* reverseLinkedList(ListNode *head){
    ListNode* temp = head;  
    ListNode* prev = NULL;  
    while(temp != NULL){  
        ListNode* current = temp->next;  
        temp->next = prev;  
        prev = temp;  
        temp = current; 
    }
    return prev;  
}

ListNode* getKthNode(ListNode* temp, int k){
    int cnt = 1; 
    while(temp != NULL && cnt < k){
        cnt++; 
        temp = temp -> next; 
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head; 
    ListNode* prevLast = NULL; 
    while(temp != NULL){
        ListNode* kThNode = getKthNode(temp, k); 
        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp; 
            }
            break; 
        }
        ListNode* nextNode = kThNode -> next; 
        kThNode -> next = NULL; 
        reverseLinkedList(temp); 
        if(temp == head){
            head = kThNode;
        }else{
            prevLast -> next = kThNode; 
        }
        prevLast = temp; 
        temp = nextNode; 
    }
    return head; 
}

// LRU Cache -- IMPORTANT
class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};

// Find Median in Data Stream with Priority Queue
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top();
        }
    }
};

// Recursion & Backtracking

// Combination Sum
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
    if (ind == arr.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }
    // pick up the element 
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    findCombination(ind + 1, target, arr, ans, ds);
}

vector<vector<int>>combinationSum(vector<int>&candidates,int target) {
    vector < vector < int >> ans;
    vector < int > ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}


// Combination Sum 2
void solve(vector<int> &candidates, int idx, int target, vector<int> &ds, set<vector<int>> &st){
    if(target == 0){
        st.insert(ds);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        if (candidates[i] > target) break;

        // Skip duplicates
        if (i > idx && candidates[i] == candidates[i - 1]) continue;

        ds.push_back(candidates[i]);
        solve(candidates, i + 1, target - candidates[i], ds, st); // i+1: use each number once
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    set<vector<int>> st;
    vector<vector<int>> ans;
    vector<int> ds;
    solve(candidates, 0, target, ds, st);
    for(auto& v : st) ans.push_back(v);
    return ans;
}

// Target Sum
void solve(vector<int> &nums, int idx, int target, int& count){
    if(idx == nums.size()){
        if(target == 0) count++;
        return;
    }
    solve(nums, idx+1, target+nums[idx],count);
    solve(nums, idx+1, target-nums[idx],count);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int count= 0;
    solve(nums,0,target, count);
    return count;
}

// Subsets
void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    
    for (int i = index; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}

// Permutations
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        current.push_back(nums[i]);

        backtrack(nums, used, current, result);

        current.pop_back();     // backtrack
        used[i] = false;
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);

    backtrack(nums, used, current, result);
    return result;
}

// Count Inversions using Merge Sort
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    long long inv_count = 0;
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return inv_count;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int inversionCount(int arr[], int n) {
    int* temp = new int[n];
    long long result = mergeSortAndCount(arr, temp, 0, n - 1);
    delete[] temp;
    return (int)result;
}

// 17. Letter Combinations of a Phone Number
void solve(string &digits, int idx, string str,vector<string> &dial, vector<string> &ans){
    if(idx == digits.size()){
        ans.push_back(str);
        return;
    }
    int n = dial[digits[idx] - '0'].size();
    for(int i=0; i<n; i++){
        solve(digits, idx+1, str+dial[digits[idx] - '0'][i],dial,ans);
    }
}
vector<string> letterCombinations(string digits) {
    if(digits.size() == 0) return {};
    vector<string> dial = {
        "0", "1", "abc", "def", 
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string>ans;
    string str = "";
    solve(digits,0,str,dial,ans);
    return ans;
}