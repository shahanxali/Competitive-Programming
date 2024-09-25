//Question: https://www.codechef.com/START153D/problems/KARR
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
        vector<int> store(n);

        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            mini = min(mini, temp);
            store[i] = temp;
        }

        vector<int> sorted = store;
        sort(sorted.begin(), sorted.end());

        int checking = n - 1;

        while(store[checking] == sorted[checking]){
            checking--;
        }


        if(checking < 0){
            cout << 0 << endl;
        }
        else
            cout << sorted[checking] + mini << endl;

    }

    return 0;

}
