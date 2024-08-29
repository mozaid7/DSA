#include<bits/stdc++.h>
using namespace std;


void print1(int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void print2(int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void print3(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print4(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print5(int n) {
    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=n-i+1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void print6(int n) {
    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=n-i+1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print7(int n) {
    for (int i = 0; i<n; i++) {
        
      for (int j=0; j<n-i-1; j++) {
        cout << " ";
      }
      for (int j=0; j<2*i+1; j++) {
        cout << "*";
      }
      for (int j=0; j<n-i-1; j++) {
        cout << " ";
      }
      cout << endl;
    }
}

void print8(int n) {
    for (int i = 0; i<n; i++) {
        
      for (int j=0; j<i; j++) {
        cout << " ";
      }
      for (int j=0; j<2*n-(2*i+1); j++) {
        cout << "*";
      }
      for (int j=0; j<i; j++) {
        cout << " ";
      }
      cout << endl;
    }
}

void print10(int n) {
    for (int i=1; i<=2*n-1; i++) {
        int stars = i;
        if(i>n) stars = 2*n -i;
        for(int j=1; j<=stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void print11(int n) {
    int start = 1;
    for (int i=0; i<n; i++) {
        if(i % 2 == 0) start = 1;
            else start = 0;
        for(int j = 0; j<=i; j++) {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

void print12(int n) {
    int space = 2*n-2;
    for (int i = 1; i<=n; i++) {
        
      for (int j=1; j<=i; j++) {
        cout << j ;
      }
      for (int j=1; j<=space; j++) {
        cout << " ";
      }
      for (int j=i; j>=1; j--) {
        cout << j ;
      }
      cout << endl;
      space -= 2;
    }
}

void print13(int n) {
    int num = 1;
    for(int i =1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout<< num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}

void print14(int n) {
    for(int i =0; i<n; i++) {
        for(char ch = 'A'; ch <= 'A'+ n-i-1; ch++) {
            cout<< ch << " ";
        }
        cout << endl;
    }
}
 
void print15(int n) {
    for(int i =0; i<n; i++) {
        char ch = 'A' + i;
        for(int j=0; j<=i; j++) {
            cout<< ch << " ";
        }
        cout << endl;
    }
}

void print16(int n) {
    for (int i = 0; i<n; i++) {
        
      for (int j=0; j<n-i-1; j++) {
        cout << " ";
      }
      
      char ch = 'A';
      int breakpoint = (2*i+1) / 2;
      for(int j=1; j<=2*i+1; j++) {
        cout << ch << " ";
        if(j <= breakpoint) ch++;
        else ch--;
      }

      for (int j=0; j<n-i-1; j++) {
        cout << " ";
      }
      cout << endl;
    }
}

void print17(int n) {
    for(int i=0; i<n; i++) {
        for(char ch ='E' - i; ch <= 'E'; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main() {
    int n =5;
    print17(n);
}