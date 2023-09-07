// Question: https://www.codechef.com/problems/FEVER
// Level: 348

#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    float f[a];
    for (int i = 0; i < a; i++)
    {
        cin >> f[i];
    }
    for (int i = 0; i < a; i++)
    {
        if (f[i] > 98.00)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}