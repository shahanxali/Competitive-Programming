//Question: https://codeforces.com/problemset/problem/1857/D
//Level: 1300

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr1(n);
        vector<int> arr2(n);
        vector<int> ans;
        vector<vector<int>> graph(n); 

        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }

        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (i != j) {
                    if (arr1[i] - arr1[j] >= arr2[i] - arr2[j]) {
                        graph[i].push_back(j);
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == n - 1) {
                ans.push_back(i + 1); 
            }
        }

        sort(ans.begin(), ans.end());

        cout << ans.size() << endl;

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " "; 
        }
        cout << endl;
    }
    return 0; 
}
