#include<bits/stdc++.h>
using namespace std;

// the max. element is pushed to the end of the array with the completion of each iteration. (j) & (j+1) is compared & the greater number is swaped to the next index, this continues and the element reaches the end.

void bubble_sort(int arr[], int n) {
    for(int i=n-1; i>=1; i--) {
        for(int j=0; j<=i-1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Bubble Sort by Recursion
void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }
    //Range reduced after recursion:
    bubble_sort(arr, n - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    bubble_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}