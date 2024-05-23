// Question: https://www.codechef.com/problems/PCJ18B
// Level: 1402

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0;
        cin >> n;
        for (int i = 1; i <= n; i = i + 2)
        {
            for (int j = i; j <= n; j++)
            {
                for (int k = i; k <= n; k++)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
        ;
    }

    return 0;
}