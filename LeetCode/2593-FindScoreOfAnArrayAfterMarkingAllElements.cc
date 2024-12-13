//Question: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/?envType=daily-question&envId=2024-12-13
//Level: Medium

class Solution {
public:

    struct compare{
        bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

    long long findScore(vector<int>& nums) {

        long long ans = 0;

        //val, index pair of priority queue;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }

        vector<bool> vis(nums.size(), false);

        while(!pq.empty()){
            int val = pq.top().first, ind = pq.top().second;
            pq.pop();

            if(vis[ind]){
                continue;
            }

            ans += val;
            vis[ind] = true;
            if(ind != 0) vis[ind - 1] = true;
            if(ind != nums.size()) vis[ind + 1] = true;

        }

        return ans;

    }
};
