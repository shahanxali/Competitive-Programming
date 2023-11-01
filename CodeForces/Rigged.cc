//Question: https://codeforces.com/contest/1879/problem/A
//Level: Div-2 A

#include<iostream>
#include<vector>

using namespace std;


int main()
{   

    int t;
    cin>>t;
    while(t--) {
        int n,polycarp_strength,polycarp_endurance,weight,strength,endurance;
        cin>>n;
 
        for(int i = 0; i < n ; i++) {
            cin>>strength>>endurance;
            if(i == 0) {
                polycarp_strength = strength;
                polycarp_endurance = endurance;
                weight = strength;
            }
            else {
                if(strength >= polycarp_strength and endurance >= polycarp_endurance) {
                    weight = -1;
                }
            }
        }
        cout<<weight<<endl;
    }
    return 0;     
 }