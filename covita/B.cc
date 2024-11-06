// #include <bits/stdc++.h>
// using namespace std;

// bool isBinaryString(const string &s) {
//     for (char c : s) {
//         if (c != '0' && c != '1') {
//             return false;
//         }
//     }
//     return true;
// }

// bool allze(const string &s) {
//     for (char c : s) {
//         if (c != '0') return false;
//     }
//     return true;
// }

// bool allon(const string &s) {
//     for (char c : s) {
//         if (c != '1') return false;
//     }
//     return true;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         string s;
//         int a, b;
//         cin >> s >> a >> b;

//         if (!isBinaryString(s)) {
//             cout << "INVALID";
//             continue;
//         }

//         if (allze(s) || allon(s)) {
//             cout << 0 ;
//         } else if (a < b) {
//             cout << a;
//         } else {
//             cout << b;
//         }

//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
int calculateHammingDistance(const string& binaryString, int A, int B) {
    int res = 0;
    for (int i = 0; i < binaryString.length() - 1; i++) {
        char ch = binaryString[i];
        if (ch != '1' && ch != '0') {
            return -1;
        }
        if (ch == '1') {
            if (A < B) {
                if (i - 1 >= 0 && binaryString[i - 1] == '0') {
                    res += A;
                } else if (i + 1 <= (binaryString.length() - 1) && binaryString[i + 1] == '0') {
                    res += B;
                    i++;
                }
            } else {
                if (i + 1 <= (binaryString.length() - 1) && binaryString[i + 1] == '0') {
                    res += B;
                    i++;
                } else if (i - 1 >= 0 && binaryString[i - 1] == '0') {
                    res += A;
                }
            }
        }
    }
    return res;
}
int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        string binaryString;
        int A, B;
        cin >> binaryString >> A >> B;
        int res = calculateHammingDistance(binaryString, A, B);
        if (res == -1) {
            cout << "INVALID";
        } else {
            cout << res;
        }
    }
    return 0;
}
