// Question: https://codeforces.com/problemset/problem/1843/C
// Level: 800

#include <iostream>
using namespace std;

long long int ans(long long int n) {
    long long int a;

    a = n / 2;

    if (n == 1) {
        return 1;
    }

    return n + ans(a);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;
        cout << ans(n) << endl;
    }
}
