// Question: https://www.codechef.com/problems/ZCOSCH
// Level: 1012

#include <iostream>
using namespace std;

int main()
{

    long long int r;
    cin >> r;
    if (r <= 50 && r >= 1)
    {
        cout << 100;
    }
    else if (r >= 51 && r <= 100)
    {
        cout << 50;
    }
    else
    {
        cout << 0;
    }

    return 0;
}