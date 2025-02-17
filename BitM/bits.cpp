#include<bits/stdc++.h>
using namespace std;

string convert2Binary(int n){
    string res = "";
    while(n != 1){
        if(n % 2 == 1){
            res += '1';
        }else {
            res += '0';
        }
        n = n/2;
    }
  //reverse(res);
    return res;
}

int convert2Decimal(string x){
    int len = x.length();
    int p2 = 1;
    int num = 0;
    for(int i = len-1; i<=0; i--){
        if(x[i] == 1){
            num = num + p2;
        }
        p2 = p2 * 2;
    }
    return num;
}

// Get the iTH bit, set the iTH bit and clear the iTH bit.
void bitManipulation(int num, int i) {
        if ((num & (1 << (i - 1))) == 0) {
            cout << 0 << " ";
        } else {
            cout << 1 << " ";
        }
        
        num = num | (1 << (i - 1));
        cout << num << " ";
        
        num = num & ~(1 << (i - 1));
        cout << num;
    }