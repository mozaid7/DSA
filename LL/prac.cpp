#include<bits/stdc++.h>
using namespace std;

void prac(int pos){
    int temp =1;
    for(int i = 1; i<pos; i++){
        temp = temp + 1;
    }
    cout << temp;
}
int main(){
    prac(3);
}