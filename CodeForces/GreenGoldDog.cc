//Question: https://codeforces.com/contest/1867/problem/A
//Level: 800

#include<bits/stdc++.h>
using namespace std;

int main(){
    //test cases
    int t;
    cin>>t;

    while(t--){

        //all the input things
       int n;
       cin>>n;
       vector<int> arr;
       for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
       }

        //main idea is to store the elements and their positions of the vector, so I used map
       map<int,int> mapp;
       for(int i=0;i<n;i++){
        mapp[arr[i]]=i;
       }

        //then sorting, the index is stored in maps so no problem       
       sort(mapp.begin(),mapp.end());
       int c=1;

       //creating another vector why? because this will be the answer stupid
       vector<int> ans;

        //okay so, I analyzed the problem and found that highest number should be subtracted with 1
        //and till the lowest to 2, 3, 4 and so on, this is exactly what I tried to do, c will increase on every loop getting into answer vector
        //but not from start, I need to store those 1,2,3,4 in correct position of my question vector, and yeah I will use map I created 
        //and boom I got the answer
       for(int i=0;i<n;i++){
            ans[mapp[arr[i]]]=c;
            c++;
       }

       for(auto& i:arr){
        cout<<i;
       }

        cout<<"\n";
    }

    return 0;

}