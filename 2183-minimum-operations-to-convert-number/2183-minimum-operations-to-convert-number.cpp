class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int currVal = q.front();
                q.pop();

                if (currVal == goal)
                    return steps;

                for (int num : nums) {
                    for (int newVal :
                         {currVal + num, currVal - num, currVal ^ num}) {
                        if (newVal == goal)
                            return steps + 1;

                        // valid range check
                        if (newVal >= 0 && newVal <= 1000 &&
                            visited.count(newVal) == 0) {
                            q.push(newVal);
                            visited.insert(newVal);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
