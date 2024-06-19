//Question: https://leetcode.com/problems/most-profit-assigning-work/?envType=daily-question&envId=2024-06-18
//Level: Medium

//Not a good solution thought, should be more optimal using binary search but i dont know how

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<inint l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile[mid].second <= ability) {
                    jobProfit = max(jobProfit, jobProfile[mid].first);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }t, int>> pairr;

        for(int i = 0; i < profit.size(); i++){
            pairr.push_back({difficulty[i], profit[i]});
        }

        sort(pairr.begin(), pairr.end(), [](const pair<int, int> &a, pair<int, int> &b){
            return (a.first < b.first);
        });

        int ans = 0;
        for(int i = 0; i < worker.size(); i++){

            int maxi = 0;

            int l = 0, r = pairr.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (pairr[mid].first <= worker[i]) {
                    maxi = max(maxi, pairr[mid].second);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            

            ans += maxi;

            cout << ans << endl;

        }

        return ans;

    }
};
