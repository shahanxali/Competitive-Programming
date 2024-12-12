//Question: https://leetcode.com/problems/take-gifts-from-the-richest-pile/?envType=daily-question&envId=2024-12-12
//Level: Easy

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int> pq(gifts.begin(), gifts.end());

        long long ans = 0;
        while(k--){
            int temp = sqrt(pq.top());
            pq.pop();
            pq.push(temp);
        }

        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;

    }
};
