//Question: https://codeforces.com/contest/2033/problem/0
//Level: Div - 3 (A)

#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){


        int n;
        cin >> n;

        cout << ((n % 2) == 0 ? "Sakurako" : "Kosuke") << endl;

    }
    return 0;


}
