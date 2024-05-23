//Question: https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04
//Level: Medium

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int first = 0, last = people.size() - 1;
        int count = 0;

        while (first < last) {
            if (people[first] + people[last] <= limit) {
                first++;
            }
            last--;
            count++;
        }

        if(first <= last){
            return count + 1;
        }
        
        return count;
    }
};
