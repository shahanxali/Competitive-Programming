//Question: https://leetcode.com/contest/weekly-contest-420/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/
//Level: Medium

class Solution {
public:
    vector<string> stringSequence(string target) {

        vector<string> ans;
        string a = "";
        int point = 0;

        for (auto c : target) {

            a += "a";
            point++;
            ans.push_back(a);

            while (a[a.size() - 1] != c) {

                a[a.size() - 1]++;
                ans.push_back(a);

            }
        }

        return ans;
    }
};
