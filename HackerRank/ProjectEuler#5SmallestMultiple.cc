//Question: https://www.hackerrank.com/contests/projecteuler/challenges/euler005/problem?isFullScreen=true
//Level: Medium

#include <bits/stdc++.h>

using namespace std;

//GCD finding
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//Function to find LCM
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}


int SmallestMultiple(int n){
    
    int a = 1;
    for(int i = 2; i <= n; i++){
        
        a = lcm(a, i);
        
    }
    
    return a;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        cout << SmallestMultiple(n) << endl;
        
    }
    
    return 0;
    
}

