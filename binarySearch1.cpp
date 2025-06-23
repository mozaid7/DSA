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

// Floor and Ceil || Floor --> largest no that is <= x, Ceil --> smallest no that is >= x.
int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the right
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the left
		}
	}
	return ans;
}

int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}
// both combined
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int floor = -1, ceil = -1;
    // Find floor
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= x) {
            floor = arr[mid];
            low = mid + 1; // move right to find larger value closer to x
        } else {
            high = mid - 1;
        }
    }

    // Reset low and high for ceil
    low = 0;
    high = n - 1;
    // Find ceil
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ceil = arr[mid];
            high = mid - 1; // move left to find smaller value closer to x
        } else {
            low = mid + 1;
        }
    }
    return {floor, ceil};
}

// First & Last occurence of x
int lowerBound(vector<int> arr, int x) {
        int n = arr.size();
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

int upperBound(vector<int> arr, int x) {
int n = arr.size();
int low = 0, high = n - 1;
int ans = n;

while (low <= high) {
    int mid = (low + high) / 2;
    // maybe an answer
    if (arr[mid] > x) {
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

vector<int> searchRange(vector<int>& arr, int k) {
    int n = arr.size();
    int lb = lowerBound(arr, k);
    if (lb == n || arr[lb] != k) return {-1, -1};
    return {lb, upperBound(arr, k)-1};
}

// Search in a Sorted Rotated array
int search(vector<int>& arr, int n, int k){
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) return mid;

        if(arr[low] <= arr[mid]) {
            if(arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if(arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// Search in a Sorted Rotated array with Duplicates
int search(vector<int>& arr, int n, int k){
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++, high--;
            continue;
        }

        if(arr[low] <= arr[mid]) {
            if(arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if(arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return false;
}

// Minimun from Rotated Sorted Array
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

// No of times the array is rotated
int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted.
        //then arr[low] will always be the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }
        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:
            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

// Book Allocation - Imp
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

// Koko Eating Bananas -- IMP
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

// Aggressive Cows
bool canWePlace(vector<int> &stalls, int dist, int cows){
    int cntCows = 1, last = stalls[0];
    for(int i = 1; i<stalls.size(); i++){
        if(stalls[i] - last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = (low + high)/2;
        if(canWePlace(stalls, mid, k) == true){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}