//Question: https://codeforces.com/contest/1878/problem/A
//Level: Div-3 A

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        int n,k;
        cin>>n>>k;
        vector<int> vec;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            vec.push_back(a);
        }

        bool chos=false;
        for(int i=0;i<n;i++){
            if(vec[i]==k){
                chos=true;
                break;
            }

        }
        if(chos){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;

}