//Question: https://leetcode.com/problems/longest-happy-string/?envType=daily-question&envId=2024-10-16
//Level: Medium

class Solution {
public:

    void sortByCount(vector<pair<char, int>>& sor) {

        sort(sor.begin(), sor.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        });

        return;
    }

    string longestDiverseString(int a, int b, int c) {

        string ans = "";
        vector<pair<char, int>> sor(3);

        sor[0] = {'a', a};
        sor[1] = {'b', b};
        sor[2] = {'c', c};

        bool check = true;

        while(check) {

            sortByCount(sor);

            if (ans.size() >= 2 && ans[ans.size() - 1] == sor[2].first && ans[ans.size() - 2] == sor[2].first) {

                if (sor[1].second > 0) {
                    ans += sor[1].first;
                    sor[1].second--;
                }
                else {
                    check = false;
                }

            }
            else {

                if (sor[2].second > 0) {
                    ans += sor[2].first;
                    sor[2].second--;
                }
                else {
                    check = false;
                }

            }

        }

        return ans;
    }
};
