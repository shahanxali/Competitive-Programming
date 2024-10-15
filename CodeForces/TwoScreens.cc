//Question: https://codeforces.com/contest/2025/problem/A
//Level: Div 2 - A

#include<iostream>
#include<string>
using namespace std;

// Function to compute the length of the longest common prefix of two strings
int longest_common_prefix(const string& s, const string& t) {
    int len = 0;
    int minLength = min(s.size(), t.size());
    while (len < minLength && s[len] == t[len]) {
        len++;
    }
    return len;
}

int main() {
    int q;
    cin >> q;  // Number of test cases

    while (q--) {
        string s, t;
        cin >> s >> t;

        // Calculate the longest common prefix
        int lcp = longest_common_prefix(s, t);

        // Calculate the total number of operations:
        int result = (s.size() - lcp) + (t.size() - lcp);

        // If LCP is not empty, add 1 second for copying the prefix
        if (lcp > 0) {
            result += lcp + 1;
        } else {
            result += lcp;  // No extra second if no prefix to copy
        }

        cout << result << endl;
    }

    return 0;
}
