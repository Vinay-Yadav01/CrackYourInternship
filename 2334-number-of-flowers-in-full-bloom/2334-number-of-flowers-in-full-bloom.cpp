class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        
        // Separate start and end times
        for (auto& f : flowers) {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }

        // Sort the start and end times
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans;
        for (int time : people) {
            // Count of flowers started on or before `time`
            int started = upper_bound(start.begin(), start.end(), time) - start.begin();

            // Count of flowers ended before `time`
            int ended = lower_bound(end.begin(), end.end(), time) - end.begin();
            ans.push_back(started - ended);
        }
        return ans;
    }
};
