//Question: https://www.codechef.com/START151D/problems/WEIGHTLIFT?tab=statement
//Level: Easy

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

	vector<pair<int, int>> store;


	for(int i = 0; i < 3; i++){
	    int a, b;
	    cin >> a >> b;
	   store.push_back({a, b});
	}

	int count = 0;

	for(int i = 0; i < 3; i++){
	    count += (max(store[i].first, store[i].second));
	}

	cout << count;

	return 0;

}
