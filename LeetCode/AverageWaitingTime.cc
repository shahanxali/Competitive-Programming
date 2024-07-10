//Question: https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09
//Level: Medium

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double check = customers[0][0] + customers[0][1];
        double ans = customers[0][1];

        for(int i = 1; i < customers.size(); i++){

            if(check > customers[i][0]){
                check += customers[i][1];
            }
            else{
                check = customers[i][0] + customers[i][1];
            }
            ans += check - customers[i][0];

        }

        return (ans / customers.size());

    }
};
