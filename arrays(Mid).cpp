#include<bits/stdc++.h>
using namespace std;
// Array medium level problems.

// Two Sum Problem
vector<int> twoSum(vector<int> &nums, int target) {
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

// Sort 0's, 1's & 2's
void sortArray(vector<int>& arr, int n) {
    int low = 0; int mid = 0; int high = n-1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Majority element > n/2 of arr given array
int majorityElement(vector<int> v) {
    int cnt = 0;
    int el;
    for(int i=0; i<v.size(); i++) {
        if(cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if(v[i] == el) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] == el) cnt1++;
    }
    if(cnt1 > (v.size() / 2)) {
        return el;
    }
    return -1;
}

// Maximum Sub-Array Sum
long long maxSubarray(int arr[], int n) {
    long long sum = 0, maxi = LONG_MIN;
    for(int i = 0; i<n; i++) {
        sum += arr[i];

        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    if(maxi < 0) {
        maxi = 0;
    }
    return maxi;
}

// Maximum Profit
int maximumProfit(vector<int> &prices) {
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

// Rearrange Array elements by Sign
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,0);
    int posIndex = 0, negIndex = 1;
    for(int i=0; i<n; i++) {
        if(nums[i] < 0) {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }
    return ans;
}

// Rearrange Array elements by Sign where Positive & Negative elements are not of the same number.
vector<int> alternateNumbers(vector<int>& arr) {
    vector<int> pos, neg;
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            pos.push_back(arr[i]);
        }
        else {
            neg.push_back(arr[i]);
        }
    }

    if(pos.size() > neg.size()) {
        for(int i=0; i<neg.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++) {
            arr[index] = pos[i];
            index++;
        }
    }
    else {
        for(int i=0; i<pos.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++) {
            arr[index] = neg[i];
            index++;
        }
    }
}

// Next Permutation using STL
vector<int> nextPermutation(vector<int> &nums, int n) {
  next_permutation(nums.begin(), nums.end());
  return nums;
}

// Next Permutation implementation
vector<int> nextPermutation(vector<int> &nums) {
    int ind = -1;
    int n = nums.size();
    for(int i = n-2; i>=0; i--) {
        if(nums[i] < nums[i+1]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        reverse(nums.begin(), nums.end());
        return nums;
    }
    for(int i=n-1; i>ind; i--) {
        if(nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());
    return nums;
}

// Leaders in an Array
vector<int> superiorElements(vector<int>&arr) {
    vector<int> ans;
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(arr[i] > maxi) {
            ans.push_back(arr[i]);
        }
        //keep track of right max.
        maxi = max(maxi, arr[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// Longest Consecutive Sequence
int longestSuccessiveElements(vector<int>&nums) {
    int n = nums.size();
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++) {
        st.insert(nums[i]);
    }

    for(auto it: st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                x = x+1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

// Set Matrix to zero where there is a zero in row or col.
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	int row[n] = {0}; //unordered_set<int> setRows;
	int col[m] = {0}; //unordered_set<int> setColumns;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j] == 0) {
				row[i] = 1; //setRows.insert(i);
				col[j] = 1; //setColumns.insert(j);
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(row[i] || col[j]) {
				matrix[i][j] = 0;
			}
            // if(setRows.count(i) > 0 || setColumns.count(j) > 0){
            //       matrix[i][j] = 0;
            //  }
		}
	}
	return matrix;
}

// Rotate a matrix by 90 degress.
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Spiral Matrix
vector<int> printSpiral(vector<vector<int>> matrix) {
  vector<int> ans;
  int n = matrix.size(); // no. of nows
  int m = matrix[0].size(); // no. of columns
  int top = 0, left = 0, bottom = n - 1, right = m - 1;
  
  // Loop until all elements are not traversed.
  while (top <= bottom && left <= right) {
    // For moving left to right
    for (int i = left; i <= right; i++) {
        ans.push_back(matrix[top][i]);
    }
    top++;

    // For moving top to bottom.
    for (int i = top; i <= bottom; i++) {
        ans.push_back(matrix[i][right]);
    }
    right--;
    
    // For moving right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(matrix[bottom][i]);
    }
    bottom--;
    
    // For moving bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(matrix[i][left]);
    }
    left++;
  }
  return ans;
}