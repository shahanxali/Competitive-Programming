//Question: https://leetcode.com/problems/my-calendar-i/description/
//Level: Medium

class MyCalendar {
private:
    std::vector<std::pair<int, int>> events;

public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        // Iterate through the existing events to check for double booking
        for (const auto& event : events) {
            if (start < event.second && end > event.first) {
                return false;
            }
        }

        // If no double booking found, add the new event and return true
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */