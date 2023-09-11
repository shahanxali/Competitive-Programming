// Question: https://www.codechef.com/problems/SLAB
// Level: 1406

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, p;
        cin >> n;

        if (n <= 250000)
        {
            x = 1;
        }
        else if (n >= 250001 && n <= 500000)
        {
            x = 2;
        }
        else if (n >= 500001 && n <= 750000)
        {
            x = 3;
        }
        else if (n >= 750001 && n <= 1000000)
        {
            x = 4;
        }
        else if (n >= 1000001 && n <= 1250000)
        {
            x = 5;
        }
        else if (n >= 1250001 && n <= 1500000)
        {
            x = 6;
        }
        else if (n >= 1500001)
        {
            x = 7;
        }

        int t = 250000, total = 0, last = n;
        float l = 0;

        if (x == 1)
        {
            total = 0;
        }
        else
        {
            for (int i = 1; i < x; i++)
            {

                p = l * t;
                total = total + p;

                l = l + 0.05;
            }

            p = (n - ((x - 1) * 250000)) * ((x - 1) * 0.05);
            total += p;
        }

        n = n - total;

        cout << n << endl;
    }
    return 0;
}