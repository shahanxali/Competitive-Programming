// Question: https://www.codechef.com/problems/MUFFINS3
// Level: 1023

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, ans;
        cin >> n;
        if (n % 2 == 0)
        {
            ans = n / 2 + 1;
        }
        else
        {
            ans = (n - 1) / 2 + 1;
        }
        cout << ans << endl;
    }
    return 0;
}