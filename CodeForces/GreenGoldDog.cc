//Question: https://codeforces.com/contest/1867/problem/A
//Level: 800

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector < pair < int, int > > v(n);
        vector < int > res(n);
        for(int i = 0 ; i < n; i++) {
            cin>>v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end(), greater < pair < int, int > >());
        for(int i = 0; i < n ; i++) {
            res[v[i].second] = i+1;
        }
        for(int i = 0 ; i < n ; i++) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }  
    return 0;
    
}