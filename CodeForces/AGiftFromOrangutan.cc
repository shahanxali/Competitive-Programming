//Quesiton: https://codeforces.com/contest/2030/problem/A
//Level: DIV - 2 (B)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vector<int> store(n);

        for(int i = 0; i < n; i++){
            cin >> store[i];
        }

        int maxi = *max_element(store.begin(), store.end());
        int mini = *min_element(store.begin(), store.end());

        int ans = 0;

        if(maxi == mini) cout << 0 << endl;
        else{
            for(int i = 0; i < store.size() - 1; i++){
                ans += maxi - mini;
            }
            cout << ans << endl;
        }

    }
    return 0;


}
