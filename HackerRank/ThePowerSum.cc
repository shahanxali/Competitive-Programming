//Question: https://www.hackerrank.com/challenges/the-power-sum/problem?isFullScreen=true
//Level: Medium


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int countWaysToSum(vector<int>& numbers, int target, int index) {
    if (target == 0) {
        // Found a combination that adds up to N
        return 1;
    }

    if (target < 0 || index >= numbers.size()) {
        // Overshot the target or reached the end of the vector
        return 0;
    }

    // Include the current number or exclude it
    int includeCurrent = countWaysToSum(numbers, target - numbers[index], index + 1);
    int excludeCurrent = countWaysToSum(numbers, target, index + 1);

    // Return the sum of combinations including and excluding the current number
    return includeCurrent + excludeCurrent;
}


int powerSum(int X, int N) {
    
    vector<int> numbers;
    int last = pow(X, 1.0 / N);
    
    for(int i=1; i<=last; i++){
        numbers.push_back(pow(i,N));
    }
    
    for(int i=0; i<numbers.size();i++){
        cout<<numbers[i];
    }

    return countWaysToSum(numbers,X,0);
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

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
