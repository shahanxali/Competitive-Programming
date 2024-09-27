//Question: https://leetcode.com/problems/my-calendar-ii/?envType=daily-question&envId=2024-09-27
//Level: Medium

class MyCalendarTwo {
public:

    vector<pair<int, int>> doubly;
    vector<pair<int, int>> singly;

    bool book(int start, int end) {

        for(auto pair : doubly){

            if(start < pair.second && end > pair.first){
                return false;
            }

        }

        for(auto pair : singly){

            if(start < pair.second && end > pair.first){
                doubly.push_back({max(start, pair.first), min(end, pair.second)});
            }

        }
        singly.push_back({start, end});

        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
