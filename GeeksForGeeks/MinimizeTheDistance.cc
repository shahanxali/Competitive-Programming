//Question: https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-154/problems
//Level: 

class Solution {
  public:
    int minimumDis(int N, vector<int> X) {
        
        sort(X.begin(), X.end());
        
        if(N % 2 == 0){
            return X[(N / 2) - 1];
        }
        
        return X[N / 2];
        
        
    }
};