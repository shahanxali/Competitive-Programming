// Question: https://www.codechef.com/problems/APPENDOR
// Level: 1201

#include <iostream>
using namespace std;

int main(){

    //test cases
    int t;
    cin >> t;

    while (t--){

        int n, y;
        cin >> n >> y;
        
        //idk why I didnt use vector, I was a noobie lol
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        int f = a[0];

        //find or of all the elements in the array
        for (int i = 1; i < n; i++){
            f = f | a[i];
        }

        int q;

        for (int i = 0; i <= y; i++)
        {
            if (y == (f | i))
            {
                cout << i << endl;
                q = i;
                break;
            }
            else
            {
                continue;
            }
        }

        if (y != (f | q))
        {
            cout << -1 << endl;
        }
    }
    return 0;
}