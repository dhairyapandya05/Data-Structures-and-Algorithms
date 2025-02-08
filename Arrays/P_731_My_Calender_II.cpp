class MyCalendarTwo {
public:
    // MyCalendarTwo* obj = new MyCalendarTwo();
    vector<pair<int, int>> booking;
    vector<pair<int, int>> double_booking;
    MyCalendarTwo() {}
    bool checkforoverlap(int s1, int e1, int start, int end) {
        return max(s1, start) < min(end, e1);
    }
    bool book(int start, int end) {
        for (auto it : double_booking) {
            if (checkforoverlap(it.first, it.second, start, end)) {
                return false;
            }
        }
        for (auto it : booking) {
            if (checkforoverlap(it.first, it.second, start, end)) {
                double_booking.push_back(
                    {max(it.first, start), min(it.second, end)});
            }
        }
        booking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */