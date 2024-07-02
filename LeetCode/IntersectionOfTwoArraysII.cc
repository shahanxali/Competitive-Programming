//Question: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02
//Level: Easy

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int first = 0, second = 0;
        vector<int> ans;

        while(first < nums1.size() && second < nums2.size()) {

            if(nums1[first] == nums2[second]) {
                ans.push_back(nums1[first]);
                first++;
                second++;
            }
            
            else if(nums1[first] < nums2[second]) {
                first++;
            }

            else {
                second++;
            }

        }

        return ans;
    }
};
