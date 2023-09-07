// Question: https://www.codechef.com/problems/TAXES
// Level: 276

#include <iostream>
using namespace std;

int main()
{
    int t, a;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        if (a > 100)
        {
            cout << a - 10 << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
    return 0;
}
