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

// Majority element > n/2 of a given array
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