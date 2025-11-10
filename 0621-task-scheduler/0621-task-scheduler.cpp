class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (char task : tasks) {
            mp[task]++;
        }
        priority_queue<int> maxHeap;
        for (auto [_, val] : mp) {
            maxHeap.push(val);
        }
        queue<pair<int, int>> q;
        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
