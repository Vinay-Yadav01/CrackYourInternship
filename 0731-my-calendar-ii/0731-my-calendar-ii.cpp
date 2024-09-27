class MyCalendarTwo {
public:
    vector<pair<int, int>> originalBooking;
    vector<pair<int, int>> doubleBooking;
    MyCalendarTwo() {}

    bool checkCommon(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> findCommon(int start1, int end1, int start2, int end2) {
        return { max(start1, start2), min(end1, end2) };
    }

    bool book(int start, int end) {
        // Check for triple booking
        for (auto booking : doubleBooking) {
            if (checkCommon(booking.first, booking.second, start, end))
                return false;
        }
        for (auto booking : originalBooking) {
            if (checkCommon(booking.first, booking.second, start, end))
                doubleBooking.push_back(
                    findCommon(booking.first, booking.second, start, end));
        }
        originalBooking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */