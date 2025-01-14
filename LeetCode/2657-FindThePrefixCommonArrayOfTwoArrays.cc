//Question: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2025-01-14
//Level: Medium

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();
        vector<bool> a(n, false), b(n, false);
        vector<int> ans;
        int c = 0;

        for(int i = 0; i < n; i++){
            int first = A[i] - 1, second = B[i] - 1;
            if(first == second){
                c++;
                ans.push_back(c);
                continue;
            }
            a[first] = true;
            b[second] = true;

            if(a[first] == b[first] && a[first]) c++;
            if(a[second] == b[second] && a[second]) c++;

            ans.push_back(c);
        }

        return ans;


    }
};
