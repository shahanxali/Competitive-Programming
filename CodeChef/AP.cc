//Question: https://www.codechef.com/START153D/problems/AP
//Level:

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

	int t;
	cin >> t;

	while(t--){

	    int x, y, z;
	    cin >> x >> y >> z;

    	bool isorno = false;

	    if(y - x == z - y) isorno = true;

	    if(isorno) cout << 0;
	    else cout << 1;

	    cout << "\n";
    }

    return 0;
}
