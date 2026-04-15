//Question: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/?envType=daily-question&envId=2026-04-15
//Level: Easy

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {

        int ans1 = 0, ans2 = 0, i = startIndex;

        while(words[i] != target){
            i = (i + 1) % words.size();
            ans1++;
            if(i == startIndex) return -1;
        }

        i = startIndex;
        while(words[i] != target){
            i = (i - 1 + words.size()) % words.size();
            ans2++;
            if(i == startIndex) return -1;
        }

        return min(ans1, ans2);

    }
};
