//Question: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11
//Level: Medium

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        int maxi = INT_MIN, mini = INT_MAX;
        sort(nums.begin(), nums.end());
        queue<int> a, b;

        for(auto num : nums){
            maxi = max(maxi, num + k);
            mini = min(mini, num - k);

            a.push(num - k);
            b.push(num + k + 1);

        }

        int ans = 1, count = 0;


        for(int i = mini; i <= maxi; i++){

            int temp1 = a.front(), temp2 = b.front();

            if(i == temp1){
                while(i == temp1){
                    count++;
                    if(!a.empty()){
                        a.pop();
                        temp1 = a.front();
                    }
                }
            }
            if(i == temp2){
                while(i == temp2){
                    count--;
                    if(!b.empty()){
                        b.pop();
                        temp2 = b.front();
                    }
                }
            }
            ans = max(ans, count);

        }

        return ans;


    }
};
