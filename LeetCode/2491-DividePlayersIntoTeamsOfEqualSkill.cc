//Question: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/?envType=daily-question&envId=2024-10-04
//Level: Medium


class Solution {
public:
    long long dividePlayers(vector<int>& skills) {

        sort(skills.begin(), skills.end());

        long long mult = 0, check = skills[0] + skills[skills.size() - 1];

        for(int i = 0; i < skills.size() / 2; i++){
            if(skills[i] + skills[skills.size() - 1 - i] != check) return -1;
            mult += skills[i] * skills[skills.size() - 1 - i];
        }

        return mult;

    }
};
