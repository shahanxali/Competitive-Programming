// Question: https://www.codechef.com/problems/CUTPAPER
// Level: 800

#include <iostream>
using namespace std;

int main(){

    int t, a, b, k;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> a >> b;
        if ((a * a) % (b * b) == 0)
        {
            k = (a * a) / (b * b);
        }
        else
        {
            a = a - (a % b);
            k = (a * a) / (b * b);
        }
        cout << k << endl;
    }

    return 0;
}