//Question: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10
//Level: Medium


// Approach 1: Brute force

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> fractions;

        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                fractions.push_back({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }

        sort(fractions.begin(), fractions.end());

        return {fractions[k - 1].second.first, fractions[k - 1].second.second};
    }
};
