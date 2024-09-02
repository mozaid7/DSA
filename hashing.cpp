#include<bits/stdc++.h>
using namespace std;

// Hashing
// int main () {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }

//     // arr[] = [1,3,1,4,3];
//     int hash[13] = {0};
//     for(int i=0; i<n; i++) {
//         hash[arr[i]] += 1;
//     }

//     int q;
//     cin >> q;
//     while(q--) {
//         int number;
//         cin >> number;
//         cout << hash[number] << endl;
//     }
//     return 0;
// }

// Hashing of characters
// int main() {
//     string s;
//     cin >> s;

//     int hash[256] = {0};
//     for(int i=0; i<s.size; i++) {
//         hash[s[i]]++;
//     }

//     int q;
//     cin >> q;
//     while(q--) {
//         char c;
//         cin >> c;
//         cout << hash[c] << endl;
//     }
//     return 0;
// }

// Map
int main () {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    map<int, int> mpp;
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }

    for(auto it : mpp) {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }
    return 0;
}