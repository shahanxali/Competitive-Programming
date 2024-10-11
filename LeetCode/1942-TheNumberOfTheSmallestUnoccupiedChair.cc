//Question: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/?envType=daily-question&envId=2024-10-11
//Level: Medium

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        vector<pair<int, int>> arrival;
        vector<pair<int, int>> departure;

        int a = 0, b = 0, c = 0;

        for(int i = 0; i < times.size(); i++){
            arrival.push_back({times[i][0], i});
            departure.push_back({times[i][1], i});
        }

        vector<int> seats(times.size(), -1);
        priority_queue<int, vector<int>, greater<int>> q;

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        while(a < times.size()){

            if(arrival[a].first < departure[b].first){

                if(q.empty()){
                    seats[arrival[a].second] = c;
                    c++;
                }
                else{
                    seats[arrival[a].second] = q.top();
                    q.pop();
                }

                //That's where the answer is found
                if(arrival[a].second == targetFriend) return seats[arrival[a].second];
                a++;

            }
            else{

                q.push(seats[departure[b].second]);
                b++;

            }

        }

        //If we cant find the target, should not reach here
        return -1;

    }
};
