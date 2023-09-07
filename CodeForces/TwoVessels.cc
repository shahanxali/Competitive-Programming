// Question: https://m1.codeforces.com/contest/1872/problem/A

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int a, b, c, d, e, check = 0;
        cin >> a >> b >> c;

        if (a > b)
        {
            d = a;
            e = b;
        }
        else if (a < b)
        {
            d = b;
            e = a;
        }
        else if (a == b)
        {
            check = 1;
        }

        if (check == 1)
        {
            cout << 0;
        }
        else
        {
            int tot = (d - e) / (2 * c);
            float rem1 = d - tot * c;
            float rem2 = e + tot * c;
            if (rem1 == rem2)
            {
                cout << tot;
            }
            else
            {
                cout << tot + 1;
            }
        }
        cout << "\n";
    }
    return 0;
}