//Question: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem?isFullScreen=true
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

        int n = stoi(ltrim(rtrim(n_temp)));
        
        
        //Writing here the answer, took me a lot to figure out lol
        
        unsigned long long sum3, sum5, sum15;
        unsigned long long num3 = 3, num5 = 5, num15 = 15, i;
        
        unsigned long long vals[3] = {3, 5, 15};
        
        for(int i = 0; i < 3; i++)
        {
            long long x = (n - 1) / vals[i];
            vals[i] = ((vals[i] * x * (x + 1)) / 2);
        }
        cout << (vals[0] + vals[1] - vals[2]) << endl;
         
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
