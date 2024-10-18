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
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
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