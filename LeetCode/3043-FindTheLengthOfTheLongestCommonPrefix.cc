//Question: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2024-09-24
//Level: Medium

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_map <int, bool> store;

        for(int i = 0; i < arr1.size(); i++){

            int temp = arr1[i];
            while(temp != 0){
                store[temp] = true;
                temp /= 10;
            }

        }

        int ans = 0;

        for(int i = 0; i < arr2.size(); i++){

            int tempmax = 0, temp = arr2[i];

            while(temp != 0 && store.find(temp) == store.end()){
                temp /= 10;
            }
            while(temp != 0){
                tempmax++;
                temp /= 10;
            }

            ans = max(ans, tempmax);

        }

        return ans;

    }
};
