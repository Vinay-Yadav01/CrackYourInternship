class MyCalendarThree {
    map<int, int> mp;

public:
    MyCalendarThree() { mp.clear(); }

    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int maxBooking = 0, currBooking = 0;
        for (auto& [time, val] : mp) {
            currBooking += val;
            maxBooking = max(maxBooking, currBooking);
        }
        return maxBooking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */