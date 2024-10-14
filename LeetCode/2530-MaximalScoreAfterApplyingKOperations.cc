//Question: https://leetcode.com/problems/maximal-score-after-applying-k-operations/?envType=daily-question&envId=2024-10-14
//Level: Medium

class Solution {
public:

    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq(nums.begin(), nums.end());

        long long score = 0;

        while(k--){

            int a = pq.top();
            pq.pop();

            score += a;
            a = (a + 2) / 3;
            pq.push(a);

        }

        return score;

    }
};
