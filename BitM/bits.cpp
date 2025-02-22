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
    
// if the no is power of two or not
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// swap two no. with the help of XOR
pair<int, int> get(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;
    return {a,b};
}

// count the no of set bits;
int countBits(int n){
    int cnt = 0;
    while(n > 1){
        if (n & 1) cnt += 1;
        n = n >> 1;
    }
    if (n == 1) cnt += 1;
    return cnt;
}

// Minimum flips to convert a no
int minBitFlips(int start, int goal) {
    int ans = start ^ goal;
    int cnt = 0;
    for(int i =0; i<31; i++){
        if(ans & (1 << i)){
            cnt = cnt + 1;
        }
    }
    return cnt;
}

// number that comes once in an array
// a^a = 0 ; arr={4,1,2,1,2}; 4^1^2^1^2 = 4; because 1 and 2 will get cancelled out by each others pair; 1^1 = 0; 2^2=0; 
// 4 ^ 0 ^ 0 = 4
int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for(int i=0; i<nums.size(); i++) {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

// insem break compiler construction First and Follow OPP LR(0), SLR(1)