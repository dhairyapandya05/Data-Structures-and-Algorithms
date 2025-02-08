class MyCalendar {
public:
    set<pair<int, int>> st;

    bool check(int start, int end, set<pair<int, int>> &st) {
        if (st.empty()) {
            return true;
        }
        for (auto it : st) {
            if (it.first < start and it.second <= start) {
                continue;
            } else if (it.second > end and it.first >= end) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    MyCalendar() {}

    bool book(int start, int end) {
        if (st.empty() or check(start, end, st)) {
            st.insert({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */