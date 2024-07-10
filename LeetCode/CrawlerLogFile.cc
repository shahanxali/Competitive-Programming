//Question: https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10
//Level: Easy

class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int count = 0;

        for(int i = 0; i < logs.size(); i++){

            if(logs[i][0] == '.' && logs[i][1] == '.' && logs[i][2] == '/'){
                if(count != 0)
                    count--;
            }
            else if(logs[i][0] == '.' && logs[i][1] == '/'){
                continue;
            }
            else{
                count++;
            }

        }
        return count;

    }
};
