//Question: https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem?isFullScreen=true
//Level: Easy

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));
        
        //Writing solution here, last time use this template
        
        long fib1 = 1;
        long fib2 = 2;
        long sum = 0;

        while (fib2 <= n) {
            if (fib2 % 2 == 0) {
                sum += fib2;
            }

            long nextFib = fib1 + fib2;
            fib1 = fib2;
            fib2 = nextFib;
        }

        cout << sum << endl;
        
        
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
