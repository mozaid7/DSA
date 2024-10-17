#include<bits/stdc++.h>
using namespace std;

// Binary Search normal implementation
int search(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
// Recursive approach
int binarySearch(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1; //Base case.
    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}
int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
}

// Lower Bound
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}