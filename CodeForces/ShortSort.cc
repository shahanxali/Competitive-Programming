//Question: https://codeforces.com/contest/1873/problem/A
//Level: Div-4 A
#include <iostream>
using namespace std;

bool check(string s) {
    if (s == "abc") {
        return true;
    }
    return false;
}

void swap(char& a, char& b) {
    char d = a;
    a = b;
    b = d;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        
        cin >> s;

        if (check(s)) {
            cout << "YES" << endl;
        } else {
            swap(s[0], s[1]);
            if (check(s)) {
                cout << "YES" << endl;
            } else {
                swap(s[0], s[1]);
                swap(s[0], s[2]);
                if (check(s)) {
                    cout << "YES" << endl;
                } else {
                    swap(s[0], s[2]);
                    swap(s[1], s[2]);
                    if (check(s)) {
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }
    return 0; 
}
