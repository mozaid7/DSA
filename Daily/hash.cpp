#include<bits/stdc++.h>
using namespace std;

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

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1;
    while( i>0 && nums[i-1] >= nums[i]){
        i--;
    }
    if(i == 0){
        reverse(nums.begin(), nums.end());
        return;
    }

    int j = nums.size() - 1;
    while(j >= i && nums[j] <= nums[i-1]){
        j--;
    }

    swap(nums[i-1], nums[j]);
    reverse(nums.begin()+i, nums.end());
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

private:
bool canEatAll(const vector<int>& piles, int h, int k) {
    int hours = 0;
    for (int bananas : piles) {
        hours += (bananas + k - 1) / k;
    }
    return hours <= h;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for(auto& str : strs){
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


void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    vector<pair<int, int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    while(!q.empty()){
        int r = grid.size();
        int c = grid[0].size();
        auto [x,y] = q.front();
        q.pop();

        for(auto [dx,dy] : dir){
            int nx = x+dx, ny = y+dy;
            if(nx >= 0 && ny >= 0 && nx < r && ny < c && grid[nx][ny] == '1' && !vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

bool canJump(vector<int>& nums) {
    int maxReachable = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > maxReachable) {
            return false;
        }
        maxReachable = max(maxReachable, i + nums[i]);
    }

    return true;
}


int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int l = 0, r = n - 1;
    int lMax = height[l], rMax = height[r]; 
    int total = 0;

    while (l < r) {
        if (height[l] <= height[r]) {
            if (height[l] < lMax) {
                total += lMax - height[l]; 
            } 
            lMax = max(lMax, height[l]);
            l++;  
        } else {
            if (height[r] < rMax) {
                total += rMax - height[r];  
            }
            rMax = max(rMax, height[r]);  
            r--;  
        }
    }
    return total;
}


int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int leftP = 1; //leftProduct
    int rightP = 1; //rightProduct
    int ans = nums[0];

    for(int i=0; i<n; i++){
        leftP = leftP == 0 ? 1 : leftP;
        rightP = rightP == 0 ? 1 : rightP;

        leftP *= nums[i];
        rightP *= nums[n-1-i];
        ans = max(ans, max(leftP, rightP));
    }
    return ans;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++) {
        if( i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            }
            else if (sum > 0){
                k--;
            }
            else {
                vector<int> temp = { nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while( j < k && nums[j] == nums[j-1]) j++;
                while( j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int buyPrice = prices[0];
    int profit = 0;

    for(int i=1; i<n; i++){
        if(prices[i] < buyPrice){
            buyPrice = prices[i];
        } else {
            int currProfit = prices[i] - buyPrice;
            profit = max(currProfit, profit);
        }
    }
    return profit;
}


int maxSubArray(vector<int>& nums) {
    int n =nums.size();
    long long sum = 0, maxi = LONG_MIN;
    for(int i = 0; i<n; i++) {
        sum += nums[i];

        if(sum > maxi) maxi = sum;
        if(sum < 0)sum = 0;
    }
    return maxi;
}


int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }
    return dp[m][n];
}


int jump(vector<int>& nums) {
    int jumps = 0;          
    int currentEnd = 0;     
    int farthest = 0;       

    for (int i = 0; i < nums.size() - 1; ++i) {
        farthest = max(farthest, i + nums[i]);  

        if (i == currentEnd) {
            jumps++;               
            currentEnd = farthest;
        }
    }

    return jumps;  
}


