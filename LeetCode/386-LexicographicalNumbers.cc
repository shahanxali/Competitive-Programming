//Question: https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21
//Level: Medium

class Solution {
public:

    void recur(int num, int orig, vector<int>& ans){

        //Base case
        if(num > orig) return;

        //Storing for the DF for answer
        if(num > 0){
            ans.push_back(num);
        }

        //The tree would go from adding 0 to 9
        for(int i = (num == 0) ? 1 : 0; i <= 9; i++){

            if((num * 10) + i > orig){
                break;
            }
            else{
                recur((num * 10) + i, orig, ans);
            }

        }

        return;

    }

    vector<int> lexicalOrder(int n) {

        vector<int> ans;
        int orig = n;

        recur(0, n, ans);

        return ans;

    }
};
