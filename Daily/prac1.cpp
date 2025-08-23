#include <bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum
int maxSubarray(vector<int>& arr){
    int n = arr.size();
    long long sum = 0, maxi = INT_MIN;
    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return sum;
}

// Container with Most Water
int maxArea(vector<int>& heights){
    int n = heights.size();
    int left = 0;
    int right = n - 1;
    int maxArea = 0;
    while(left < right){
        int currArea = min(heights[left], heights[right]) * (right - left);
        if(currArea > maxArea) maxArea = currArea;

        if(heights[left] < heights[right]){
            left++;
        } else {
            right --;
        }
    }
    return maxArea;
}

// Sort Colors or Sort 0s, 1s and 2s
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


int lengthOfLongestSubstring(string s){
    int n = s.length();
    int left = 0;
    int maxL = 0;
    unordered_set<char>charSet;

    for(int right=0; right<n; right++){
        while(charSet.find(s[right]) != charSet.end()){
            charSet.erase(s[left]);
            left++;
        }

        charSet.insert(s[right]);
        maxL = max(maxL, right - left + 1);
    }
    return maxL;
}

// Set Matrix Zeroes
void setZeroes(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    unordered_set<int> setRows;
    unordered_set<int> setCols;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                setRows.insert(i);
                setCols.insert(j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(setRows.count(i) > 0 || setCols.count()j > 0){
                matrix[i][j] = 0;
            }
        }
    }
}

// Word Search
int n,m;
vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

bool find(vector<vector<char>>& board, int i, int j, int idx, string word){

    if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[idx]) return false;
    if (idx == word.size() - 1) return true;

    char temp = board[i][j];
    board[i][j] = '$';
    
    for(auto &dir : directions){
        int newI = i + dir[0];
        int newJ = j + dir[1];

        if(find(board, newI, newJ, idx+1, word)){
            return true;
        }
    }

    board[i][j] = temp;
    return false;

}
bool exist(vector<vector<char>>& board, string word) {
    n = board.size();
    m = board[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0] && find(board, i, j, 0, word)){
                return true;
            }
        }
    }
    return false;
}

vector<int> rightSideView(TreeNode* root){
    if(root == NULL) return {};
    queue<TreeNode*>q;
    vector<int>ans;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=1; i<=size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            if(i == size) ans.push_back(node->val);
        }
    }
    return ans;

}

vector<int> topView(Node *root) {
    vector<int> ans;
    map<int, Node*>mp;
    queue<pair<Node*, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        Node* top = q.front().first;
        int v1 = q.front().second;
        q.pop();
        if(mp.find(v1) == mp.end()){
            mp[v1] = top;
        }
        if(top->left != NULL) q.push({top->left, v1-1});
        if(top->right != NULL) q.push({top->right, v1+1});
    }
    for(auto it : mp){
        ans.push_back(it.second->data);
    }
    return ans;
    
}

// Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    ListNode* dNode = new ListNode(-1);
    ListNode* temp = dNode;
    while(t1 != NULL && t2 != NULL){
        if(t1->val < t2->val){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dNode->next;
}