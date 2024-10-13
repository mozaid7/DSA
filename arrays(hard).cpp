#include<bits/stdc++.h>
using namespace std;


// Pascal Triangle 
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1; col<row; col++) {
        ans = ans * (row-col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for(int i = 1; i<=N; i++) {
        ans.push_back(generateRow(i));
    }
    return ans;
}

// Majority element > n/3 of given array
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && v[i] != el2 ) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && v[i] != el1 ) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }
    vector<int> ls; // list of answers
    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }
    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);
    return ls;
}

// 3-Sum Problem i.e. nums[i] + nums[j] + nums[k] = 0;
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

// 4-Sum problem i.e. nums[i] + nums[j] + nums[k] + nums[l] = 0;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}

// Largest subarray with sum 0 (length of the largest sub-array with sum 0)
int maxLen(int A[], int n){
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }
    return maxi; 
}

// merge overlapping sub-intervals
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

// Count sub-arrays with XOR as K
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i into the map:
        mpp[xr]++;
    }
    return cnt;
}

// Merge two sorted arrays without any extra spaces
void merge(long long arr1[], long long arr2[], int n, int m) {
    int left = n-1;
    int right = 0;
    while(left >= 0 && right < 0) {
        if(arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// Option 2 - Leetcode accepted
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m - 1; // Start from the last valid element in nums1
    int right = n - 1; // Start from the last element in nums2
    int k = m + n - 1; // Start from the end of nums1 (combined size)

    // Merge from the back to the front
    while (left >= 0 && right >= 0) {
        if (nums1[left] > nums2[right]) {
            nums1[k--] = nums1[left--];
        } else {
            nums1[k--] = nums2[right--];
        }
    }

    // If there are remaining elements in nums2, copy them over
    while (right >= 0) {
        nums1[k--] = nums2[right--];
    }
}

// Count Inversions
int cnt = 0;
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int numberOfInversions(vector<int>&a, int n) {
    mergeSort(a, 0, n - 1);
    return cnt;
}