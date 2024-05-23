//Question: https://codeforces.com/contest/1873/problem/B
//Level: Div-4 B

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int min=arr[0];
        int j=0;
        for(int i=0;i<n;i++){
            if(min>arr[i]){
                min=arr[i];
                j=i;
            }
            if(i==n-1){
                arr[j]++;
            }
        }

        int mul=1;
        for(int i=0;i<n;i++){

            mul=mul*arr[i];

        }
        cout<<mul<<endl;

    }

    return 0;

}