//Question: https://leetcode.com/problems/my-calendar-i/description/
//Level: Medium

class MyCalendar {
public:

    vector<pair<int, int>> store;

    bool book(int start, int end) {

        for(auto pair : store){
            if(start < pair.second && end > pair.first){
                return false;
            }

        }

        store.push_back({start, end});
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
