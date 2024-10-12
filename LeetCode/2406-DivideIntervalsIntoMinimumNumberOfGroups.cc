//Question: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12
//Level: Medium

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        vector<int> arrival, departure;

        for(int i = 0; i < intervals.size(); i++){
            arrival.push_back(intervals[i][0]);
            departure.push_back(intervals[i][1]);
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int points1 = 0, points2 = 0;
        int temp = 0, maxx = INT_MIN;

        while(points1 < intervals.size() && points2 < intervals.size()){

            if(arrival[points1] <= departure[points2]){
                temp++;
                points1++;
            }
            else{
                temp--;
                points2++;
            }

            maxx = max(maxx, temp);

        }

        return maxx;

    }
};
