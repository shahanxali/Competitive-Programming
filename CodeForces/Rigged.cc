//Question: https://codeforces.com/contest/1879/problem/A
//Level: Div-2 A

#include<iostream>
#include<vector>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int ans;

        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            vector<int> rows;
            for(int i=0;i<2;i++){
                int a;
                cin>>a;
                rows.push_back(a);
            }
            arr.push_back(rows);
        }

        vector<int> checklarge;
        for(int i=0;i<n-1;i++){
            if(arr[0][0]<=arr[i+1][0]){
                if(arr[0][1]<=arr[i+1][1]){
                    ans=-1;
                    break;
                }
                else{
                    checklarge.push_back(arr[i+1][0]);
                    checklarge.push_back(arr[i+1][1]);
                }

            }

        }

        if(ans!=-1){
            ans=arr[0][0];
        }
        cout<<ans<<endl;



    }

}