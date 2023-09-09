// Question: https://codeforces.com/problemset/problem/1843/C
// Level: 800

#include <iostream>
using namespace std;

int ans(int n){
    
    unsigned long int a;

    a = (n / 2);


    if(n==1){
        return 1;
    }

    return n + ans(a);
}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        unsigned long int n;
        cin >> n;
        cout<<ans(n)<<endl;
    }
}