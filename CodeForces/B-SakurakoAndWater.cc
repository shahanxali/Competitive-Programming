//Question: https://codeforces.com/contest/2033/problem/B
//Level: Div - 3 (B)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(n));

        // Input the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int ans = 0;
        vector<vector<pair<int, bool>>> store(n, vector<pair<int, bool>>(n));

        // Store the elements with boolean indicating if they've been processed
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                store[i][j] = (arr[i][j] < 0) ? make_pair(arr[i][j], false) : make_pair(arr[i][j], true);
            }
        }

        // Traverse each element and check the diagonals
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // If the element is negative and hasn't been processed
                if(!store[i][j].second) {

                    // Variables to traverse the diagonal
                    int itemp = i, jtemp = j;
                    int maxi = INT_MIN;
                    bool foundNegative = false;

                    // Diagonal traversal (from [i,j] to bottom-right)
                    while(itemp < n && jtemp < n) {
                        if(!store[itemp][jtemp].second) {

                            store[itemp][jtemp].second = true;

                            maxi = max(maxi, abs(store[itemp][jtemp].first));
                            foundNegative = true;

                        }
                        itemp++;
                        jtemp++;
                    }

                    if(foundNegative) {
                        ans += maxi;
                    }

                }

            }

        }

        cout << ans << endl;
    }

    return 0;

}
