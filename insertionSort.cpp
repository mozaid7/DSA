#include<bits/stdc++.h>
using namespace std;

// picks up the element & places it in it's correct position. It picks an element checks if it is lesser than its previous element & swaps if true, it checks continue till the minimum element reaches it's correct position.

void insertion_sort(int arr[], int n) {
    for(int i=0; i<=n-1; i++) {
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

// Recursive Insertion Sort
void insertion_sort(int arr[], int i, int n) {
    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }
    insertion_sort(arr, i + 1, n);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    insertion_sort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}