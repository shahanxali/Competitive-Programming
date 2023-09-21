//Question: https://codeforces.com/contest/1873/problem/C
//Level: Div-4 C

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){

        vector<string> shots;
        
        for (int i = 0; i < 10; i++) {
            string input;
            cin >> input;
            shots.push_back(input);
    }

        int sum=0,age=0;
        vector<vector<int>> heh={{1,1,1,1,1,1,1,1,1,1},
                                {1,2,2,2,2,2,2,2,2,1},
                                {1,2,3,3,3,3,3,3,2,1},
                                {1,2,3,4,4,4,4,3,2,1},
                                {1,2,3,4,5,5,4,3,2,1},
                                {1,2,3,4,5,5,4,3,2,1},
                                {1,2,3,4,4,4,4,3,2,1},
                                {1,2,3,3,3,3,3,3,2,1},
                                {1,2,2,2,2,2,2,2,2,1},
                                {1,1,1,1,1,1,1,1,1,1}};

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                
                if(shots[i][j]=='X'){
                    sum+=heh[i][j];
                }
            }
        }
        cout<<sum<<endl;

    }
    return 0;

}