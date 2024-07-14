//Question: https://leetcode.com/problems/number-of-atoms/description/?envType=daily-question&envId=2024-07-14
//Level: Hard

class Solution {
public:
    struct Row {
        string str;
        int num;
        bool flag;
    };

    string countOfAtoms(string formula) {
        vector<Row> store;
        int f = 0;

        while (f < formula.size()) {
            if (formula[f] == '(') {
                store.push_back({"", 0, true});
                f++;
            } else if (isupper(formula[f])) {
                string a(1, formula[f]);
                f++;
                while (f < formula.size() && islower(formula[f])) {
                    a += formula[f];
                    f++;
                }

                int k = 0;
                while (f < formula.size() && isdigit(formula[f])) {
                    k = k * 10 + (formula[f] - '0');
                    f++;
                }
                k = (k == 0) ? 1 : k;

                store.push_back({a, k, false});
            } else if (formula[f] == ')') {
                f++;
                int k = 0;
                while (f < formula.size() && isdigit(formula[f])) {
                    k = k * 10 + (formula[f] - '0');
                    f++;
                }
                k = (k == 0) ? 1 : k;

                vector<Row> temp;
                while (!store.empty() && !store.back().flag) {
                    Row top = store.back();
                    store.pop_back();
                    top.num *= k;
                    temp.push_back(top);
                }

                if (!store.empty() && store.back().flag) {
                    store.pop_back(); // Remove the flag marker '('
                }

                for (int i = temp.size() - 1; i >= 0; i--) {
                    store.push_back(temp[i]);
                }
            }
        }

        map<string, int> atomCounts;
        for (const auto& row : store) {
            atomCounts[row.str] += row.num;
        }

        string ans = "";
        for (const auto& pair : atomCounts) {
            ans += pair.first;
            if (pair.second > 1) {
                ans += to_string(pair.second);
            }
        }

        return ans;
    }
};
