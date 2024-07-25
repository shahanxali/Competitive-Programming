//Question: https://leetcode.com/problems/sort-an-array/description/?envType=daily-question&envId=2024-07-25
//Level: Medium



class Solution {
public:

    void mergeit(vector<int>& nums, vector<int>& left, vector<int>& right) {
        int a = 0, b = 0, orig = 0;
        int l = left.size();
        int r = right.size();

        while (a < l && b < r) {
            if (left[a] <= right[b]) {
                nums[orig++] = left[a++];
            } else {
                nums[orig++] = right[b++];
            }
        }

        while (a < l) {
            nums[orig++] = left[a++];
        }

        while (b < r) {
            nums[orig++] = right[b++];
        }
    }

    void breakarray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        breakarray(left);
        breakarray(right);

        mergeit(nums, left, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        breakarray(nums);
        return nums;
    }
};

