class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort all events by their start day
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap of end days
        int day = 1, i = 0, n = events.size(), count = 0;

        while (i < n || !pq.empty()) {
            // Add all events that start on this day
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // Remove all events that already ended before today
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that ends earliest
            if (!pq.empty()) {
                pq.pop();
                count++;
            }

            day++; // Move to next day
        }

        return count;
    }
};
