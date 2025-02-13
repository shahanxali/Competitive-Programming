//Question: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13
//Level: Medium

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        long long a = pq.top();
        int count = 0;

        while(a < k && pq.size() >= 2){

            pq.pop();
            long long b = pq.top();
            pq.pop();

            long long t = a;
            a = min(a, b);
            b = max(t, b);

            long long val = (long long)(a) * 2 + (long long)b;

            pq.push(val);
            count++;

            a = pq.top();

        }

        return count;

    }
};
