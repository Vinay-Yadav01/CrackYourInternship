class MyCalendar {
public:
    vector<pair<int, int>> dates;
    MyCalendar() {}

    bool book(int start, int end) {
        for (auto date : dates) {
            if (date.first < end && start < date.second)
                return false;
        }
        dates.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */