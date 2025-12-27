class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            used; //{end_time, room_number}
        priority_queue<long long, vector<long long>, greater<long long>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        vector<long long> count(n, 0);

        for (auto meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            // Every starting of meeting, we have to saw all available rooms
            while (!used.empty() && start >= (used.top().first)) {
                auto temp = used.top();
                used.pop();
                long long room_number = temp.second;
                available.push(room_number);
            }
            // If their is no room available
            if (available.empty()) {
                auto temp = used.top();
                used.pop();
                long long end_time = temp.first;
                end = end_time + (end - start);
                long long room_number = temp.second;
                available.push(room_number);
            }
            long long room_number = available.top();
            available.pop();
            used.push({end, room_number});
            count[room_number]++;
        }

        int ind = -1, maxCount = -1;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                ind = i;
            }
        }
        return ind;
    }
};