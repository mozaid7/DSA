#include<bits/stdc++.h>
using namespace std;
// Array medium level problems.

// Two Sum Problem
vector<int> twoSum(vector<int> &permutation, int target) {
    map<int, int> mpp;
    int n = permutation.size();
    for(int i=0; i<n; i++) {
        int num = permutation[i];
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
vector<int> rearrangeArray(vector<int>& permutation) {
    int n = permutation.size();
    vector<int> ans(n,0);
    int posIndex = 0, negIndex = 1;
    for(int i=0; i<n; i++) {
        if(permutation[i] < 0) {
            ans[negIndex] = permutation[i];
            negIndex += 2;
        }
        else {
            ans[posIndex] = permutation[i];
            posIndex += 2;
        }
    }
    return ans;
}

// Rearrange Array elements by Sign where Positive & Negative elements are not the same.
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
vector<int> nextPermutation(vector<int> &permutation, int n) {
  next_permutation(permutation.begin(), permutation.end());
  return permutation;
}

vector<int> nextPermutation(vector<int> &permutation) {
    int ind = -1;
    int n = permutation.size();
    for(int i = n-2; i>=0; i--) {
        if(permutation[i] < permutation[i+1]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    for(int i=n-1; i>ind; i--) {
        if(permutation[i] > permutation[ind]) {
            swap(permutation[i], permutation[ind]);
            break;
        }
    }
    reverse(permutation.begin() + ind + 1, permutation.end());
    return permutation;
}
