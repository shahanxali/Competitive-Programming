//Question: https://codeforces.com/contest/1867/problem/A
//Level: Div-4 A

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<int> arr;
        for(auto& i:arr){
            cin>>arr[i];
        }

        countn=1;
        map<int,int> dict;
        vector<int> ans;

        for(int i=0;i<n;i++){

            if(dict[arr[i]]!=1){
                while(dict[countn]!=1){
                    count++;
                }
                ans.push_back(arr[i]-countn);

            }
            else{
                ans.push_back()
            }
            

        }

    }
}