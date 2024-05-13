//Question: https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-154/problems
//Level:

class Solution
{
    public:
    string doesExists(string S)
    {
        
        if(S.length() == 1){
            return "NO";
        }
        
        map<char, int> mapp;
        
        for(int i = 0; i < S.length(); i++){
            
            mapp[S[i]]++;
            
        }
        
        if(mapp.size() == 1){
            return "NO";
        }
         
        return "YES";
        
        
  
    }
};