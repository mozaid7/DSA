#include<bits/stdc++.h>
using namespace std;

// start the iteration form the 1st element i.e. i=0 and consider it as minimum, then find other minimum in the array and swap it with the "i"th iteration.

void selection_sort(int arr[], int n) {
    for(int i=0; i<=n-2; i++) {
        int mini = i;
        for(int j=i; j<=n-1; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    selection_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}