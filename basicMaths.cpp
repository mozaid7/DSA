#include<bits/stdc++.h>
using namespace std;

// Count Digits
int count (int n) {
    int counter = 0;
    while (n>0) {
        counter = counter + 1;
        n = n / 10;
    }
    cout << counter;
    return counter;
}

// Reverse Number
int reverse (int n) {
    int revNum = 0;
    while (n>0) {
        int lastDig = n % 10;
        n = n / 10;
        revNum = revNum * 10 + lastDig;
    }
    cout << revNum;
    return revNum;
}

// Palindrome
int palindrome (int n) {
    int revNum = 0;
    int dup = n;
    while (n>0) {
        int lastDig = n % 10;
        n = n / 10;
        revNum = revNum * 10 + lastDig;
    }
    if (dup == revNum) cout << "True";
    else cout << "False";
}

// Armstrong Number
bool isArmstrong(int num) {
    int originalNum, remainder, sum = 0;
    int n = 0;
    originalNum = num;
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }
    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        sum += pow(remainder, n);
        originalNum /= 10;
    }
    return (sum == num);
}

// Print all divisors
int printDivi(int n) {
    int sum = 0;
    for(int i=1; i<=n; i++) {
        if(n % i == 0) {
            cout << i << " ";
            sum = sum + i;
        }
    }
    cout << endl << sum;
    return sum;
}

// Prime Number
int prime(int n){
    int cnt = 0;
    for (int i=1; i*i<=n; i++) {
        if(n%i==0) {
            cnt++;
            if((n/i) != i) cnt++;
        }
    }
    if(cnt == 2) cout << "true";
    else cout << "false";
}

// GCD with Euclidean Algo
int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) cout << b;
    else cout << a;
    return b;
    return a;
    
}

int main() {
    gcd(40,20);  
}