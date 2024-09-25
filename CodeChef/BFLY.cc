//Question: https://www.codechef.com/START153D/problems/BFLY
//Level:

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    int t;
    cin >> t;

    while(t--){

        int a, b, c;
        cin >> a >> b >> c;

        if(a > b + c || b > a + c || c > a + b) cout << "NO";
        else cout << "YES";

        cout << "\n";

    }

    return 0;

}
