//Question: https://leetcode.com/problems/integer-to-english-words/description/?envType=daily-question&envId=2024-08-07
//Level: Hard

class Solution {
public:
    void fillup(map<char, pair<string, string>>& store) {
        store['0'] = {"", ""};
        store['1'] = {"One", "Ten"};
        store['2'] = {"Two", "Twenty"};
        store['3'] = {"Three", "Thirty"};
        store['4'] = {"Four", "Forty"};
        store['5'] = {"Five", "Fifty"};
        store['6'] = {"Six", "Sixty"};
        store['7'] = {"Seven", "Seventy"};
        store['8'] = {"Eight", "Eighty"};
        store['9'] = {"Nine", "Ninety"};
    }

    string hundreds(map<char, pair<string, string>>& store, vector<string>& oneintens, const string& three) {
        string temp = "";
        if (three[0] != '0') {
            temp += store[three[0]].first + " Hundred";
        }
        if (three[1] == '1') {
            if (!temp.empty()) temp += " ";
            temp += oneintens[three[2] - '0'];
        } else {
            if (three[1] != '0') {
                if (!temp.empty()) temp += " ";
                temp += store[three[1]].second;
            }
            if (three[2] != '0') {
                if (!temp.empty()) temp += " ";
                temp += store[three[2]].first;
            }
        }
        return temp;
    }

    string tens(map<char, pair<string, string>>& store, vector<string>& oneintens, const string& two) {
        string temp = "";
        if (two[0] == '1') {
            temp += oneintens[two[1] - '0'];
        } else {
            if (two[0] != '0') {
                temp += store[two[0]].second;
            }
            if (two[1] != '0') {
                if (!temp.empty()) temp += " ";
                temp += store[two[1]].first;
            }
        }
        return temp;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string s = to_string(num);
        map<char, pair<string, string>> store;
        vector<string> oneintens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> placevalue = {"", "Thousand", "Million", "Billion"};

        fillup(store);

        string ans = "";
        int sizee = s.size();
        int countthree = 0;

        while (sizee > 0) {
            string t;
            if (sizee >= 3) {
                string three = s.substr(sizee - 3, 3);
                sizee -= 3;
                t = hundreds(store, oneintens, three);
            } else if (sizee == 1) {
                t = store[s[0]].first;
                sizee--;
            } else if (sizee == 2) {
                string two = s.substr(sizee - 2, 2);
                sizee -= 2;
                t = tens(store, oneintens, two);
            }
            if (!t.empty()) {
                if (!ans.empty()) {
                    ans = t + " " + placevalue[countthree] + " " + ans;
                } else {
                    ans = t + " " + placevalue[countthree];
                }
            }
            countthree++;
        }

        // Remove trailing spaces
        ans.erase(find_if(ans.rbegin(), ans.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), ans.end());

        return ans;
    }
};
