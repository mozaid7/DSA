#include<bits/stdc++.h>
using namespace std;

// Largest Element
int largestElement(vector<int> &arr, int n) {
    int largest = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Second Largest & Second Smallest
int secondLargest(vector<int> &a, int n) {
    int largest = a[0];
    int slargest = -1;
    for(int i=0; i<n; i++) {
        if(a[i] > largest) {
            slargest = largest;
            largest = a[i];
        }
        else if(a[i] < largest && a[i] > slargest) {
            slargest = a[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> &a, int n) {
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i=0; i<n; i++) {
        if(a[i] < smallest) {
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] > smallest && a[i] < ssmallest) {
            ssmallest = a[i];
        }
    }
    return ssmallest;
}

// Array is sorted or not
int isSorted(int n, vector<int> a) {
   for(int i=1; i<n; i++) {
       if(a[i] >= a[i-1]) {

       }
       else {
           return false;
       }
   }
   return true;
}

// Remove Duplicates from an Array
int removeDuplicates(vector<int> &arr, int n) {
	int i = 0;
	for(int j =1; j<n; j++) {
		if(arr[i] != arr[j]) {
			arr[i+1] = arr[j];
			i++;
		}
	}
	return i+1;
}

// Rotate array by one
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i=1; i<n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}

// Rotating the array for "k" places
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// Moving zeros tho the end.
vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    for(int i=0; i<n; i++) {
        if(a[i] == 0) {
            j = i;
            break;
        }
    }
    // no non zero numbers
    if(j == -1) return a;

    for(int i = j+1; i<n; i++) {
        if(a[i] != 0) {
            swap(a[i],a[j]);
            j++;
        }
    }
    return a;
}

// Linear Search
int linearSearch(int arr[], int n, int k) {
    int check = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] == k) {
            check = 1;
            return i;
        }
    }
    return check;
}