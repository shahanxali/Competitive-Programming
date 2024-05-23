//Question: https://www.hackerrank.com/challenges/cloudy-day/problem?isFullScreen=true
//Level: Medium

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumPeople' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY p
 *  2. LONG_INTEGER_ARRAY x
 *  3. LONG_INTEGER_ARRAY y
 *  4. LONG_INTEGER_ARRAY r
 */
 long maximumPeople(vector<long> p, vector<long> x, vector<long> y, vector<long> r) {
    set<long> townInCloud;
    map<int, long> popInCloud;
    vector<pair<long, pair<int,int>>> pos;
    
    for (int i=0; i<x.size(); i++) {
        pos.push_back({x[i], {0, i}});
    }
    
    for (int i=0; i<y.size(); i++) {
        pos.push_back({y[i] - r[i], {-i-1, 0}}); // lower_bound
        pos.push_back({y[i] + r[i], {i+1,0}}); // upper_bound
    }
    sort(pos.begin(), pos.end());
    
    long res = 0;
    for (int i=0; i<pos.size(); i++) {
        
        if (pos[i].second.first < 0) { //add
            int ind = pos[i].second.first - 1;
            townInCloud.insert(ind);
        } 
        
        if (pos[i].second.first > 0) { // remove
            int ind = -pos[i].second.first - 1;
            townInCloud.erase(ind);
        } 
        
        if (pos[i].second.first == 0) { // town in cloud
        
            int ind = pos[i].second.second;
            if (townInCloud.size() == 0) {
                res += p[ind];
            } else if (townInCloud.size() == 1) {
                int posCloud = *(townInCloud.begin());
                popInCloud[posCloud] += p[ind];
            }
            
        }
        
    }
    long ans = 0;
    for (auto i : popInCloud) {
        ans = max(i.second, ans);
    }
    
    res += ans;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split(rtrim(p_temp_temp));

    vector<long> p(n);

    for (int i = 0; i < n; i++) {
        long p_item = stol(p_temp[i]);

        p[i] = p_item;
    }

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split(rtrim(x_temp_temp));

    vector<long> x(n);

    for (int i = 0; i < n; i++) {
        long x_item = stol(x_temp[i]);

        x[i] = x_item;
    }

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string y_temp_temp;
    getline(cin, y_temp_temp);

    vector<string> y_temp = split(rtrim(y_temp_temp));

    vector<long> y(m);

    for (int i = 0; i < m; i++) {
        long y_item = stol(y_temp[i]);

        y[i] = y_item;
    }

    string r_temp_temp;
    getline(cin, r_temp_temp);

    vector<string> r_temp = split(rtrim(r_temp_temp));

    vector<long> r(m);

    for (int i = 0; i < m; i++) {
        long r_item = stol(r_temp[i]);

        r[i] = r_item;
    }

    long result = maximumPeople(p, x, y, r);

    fout << result << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
