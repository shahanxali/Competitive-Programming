//Question: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06
//Level: Medium

class FindSumPairs {
public:

    vector<int> num1, num2;
    unordered_map<int, int> s1, s2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        for(int num : num1) s1[num]++;
        for(int num : num2) s2[num]++;
    }

    void add(int index, int val) {
        int c = s2[num2[index]];
        s2[num2[index]]--;
        num2[index] += val;
        s2[num2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for(auto pair : s1){
            if(pair.first <= tot){
                int diff = tot - pair.first;
                if(s2.find(diff) != s2.end()){
                    ans += (s2[diff] * pair.second);
                }
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
