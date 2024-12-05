//Question: https://leetcode.com/problems/move-pieces-to-obtain-a-string/?envType=daily-question&envId=2024-12-05
//Level: Medium


class Solution {
public:
    bool canChange(string start, string target) {

        int p1 = 0, p2 = 0, check = false;
        if(start.size() != target.size()) return false;

        while(p1 <= start.size()){

            check = false;
            char a = start[p1], b = target[p2];

            if(a == '_'){
                check = true;
                p1++;
            }
            if(b == '_'){
                check = true;
                p2++;
            }
            if(check) continue;

            if(a != b) return false;

            if((a == 'R' && p1 > p2) || (a == 'L' && p1 < p2)) return false;

            p1++;
            p2++;

        }

        return true;

    }
};
