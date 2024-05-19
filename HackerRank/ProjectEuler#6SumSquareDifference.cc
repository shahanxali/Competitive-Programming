//Question: https://www.hackerrank.com/contests/projecteuler/challenges/euler006/problem?isFullScreen=true
//Level: Easy

#include <bits/stdc++.h>

using namespace std;

unsigned long long int SumSquareDifference(unsigned long long int n) {
    // Sum of the first n natural numbers
    unsigned long long int sumOfNumbers = (n * (n + 1)) / 2;
    // Square of the sum of the first n natural numbers
    unsigned long long int squareOfSum = pow(sumOfNumbers, 2);
    
    // Sum of the squares of the first n natural numbers
    unsigned long long int sumOfSquares = (n * (n + 1) * ((2 * n) + 1)) / 6;
    
    // Calculate and return the absolute difference
    unsigned long long int ans = squareOfSum - sumOfSquares;
    int mark = ans < 0 ? -1 : 1;
    return mark * ans;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        unsigned long long int n;
        cin >> n;
        
        cout << SumSquareDifference(n) << endl;
        
        
    }
    
    return 0;

    
}
