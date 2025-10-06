#include <bits/stdc++.h>
using namespace std;

// 1. String Compression
string compressString(const string& input) {
    if(input.empty()) return "";

    string result = "";
    int count = 1;
    char current = input[0];
    
    for(int i=1; i<input.length(); i++){
        if(input[i] == current){
            count++;
        } else {
            result += current;
            if(count > 1){
                result += to_string(count);
            }
            current = input[i];
            count = 1;
        }
    }
    result += current;
    if(count > 1) {
        result += to_string(count);
    }
    return result;
}

// 2. Freqency Counter
string countFrequency(const vector<int>& arr) {
    vector<int> freq(10,0);
    string result = "";

    for (int num : arr){
        if(num >= 0 && num <= 9){
            freq[num]++;
        }
    }

    for(int i=0; i<10; i++){
        if(freq[i] > 0){
            result += to_string(i) + "occurs" + to_string(freq[i]) + "times\n";
        }
    }

    return result;
}