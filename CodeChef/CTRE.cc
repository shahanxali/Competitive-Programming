//Question: https://www.codechef.com/START153D/problems/CTRE
//Level:

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here


    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;

        vector<vector<int>> tree(n);

        for(int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;

            tree[a - 1].push_back(b - 1);
            tree[b - 1].push_back(a - 1);
        }

        int count = 0;

        for(int i = 0; i < n; i++){

            count += tree[i].size() >= 2 ? 2 : 3;

        }

        cout << count << endl;

    }

    return 0;

}
