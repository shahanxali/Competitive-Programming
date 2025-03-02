//Question: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02
//Level: Easy

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        vector<vector<int>> ans;

        int p1 = 0, p2 = 0;

        while(p1 < nums1.size() && p2 < nums2.size()){

            int a = nums1[p1][0], b = nums2[p2][0];
            if(a == b){
                ans.push_back({a, nums1[p1][1] + nums2[p2][1]});
                p1++;
                p2++;
            }
            else if(a < b){
                ans.push_back({a, nums1[p1][1]});
                p1++;
            }
            else{
                ans.push_back({b, nums2[p2][1]});
                p2++;
            }

        }

        while(p1 < nums1.size()) {
            ans.push_back({nums1[p1][0], nums1[p1][1]});
            p1++;
        }
        while(p2 < nums2.size()){
            ans.push_back({nums2[p2][0], nums2[p2][1]});
            p2++;
        }
        return ans;

    }
};
