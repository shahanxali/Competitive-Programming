//Question: https://codeforces.com/contest/1878/problem/B
//Level: Div-3 B

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        vector<int> vec;
        int mai=1;
        for(int i=0;i<n;i++){
            vec.push_back(mai);
            mai=mai+2;
        }
        for(auto& i: vec){
            cout<<i<<" ";
        }
        cout<<"\n";


    }
    return 0;


}