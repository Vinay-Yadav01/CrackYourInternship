class Solution {
    vector<int> dp;
    vector<int> next_job;
    int n;

    int solve(vector<vector<int>>& jobs, int i) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int skip = solve(jobs, i + 1);
        int take = jobs[i][2] + solve(jobs, next_job[i]);

        return dp[i] = max(skip, take);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        n = startTime.size();
        vector<vector<int>> jobs(n);

        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        // Sort by start time
        sort(jobs.begin(), jobs.end());

        dp.assign(n, -1);
        next_job.assign(n, n);

        // Precompute next non-overlapping job using binary search
        for (int i = 0; i < n; i++) {
            next_job[i] =
                lower_bound(jobs.begin() + i + 1, jobs.end(), jobs[i][1],
                            [](const vector<int>& job, int value) {
                                return job[0] < value;
                            }) -
                jobs.begin();
        }

        return solve(jobs, 0);
    }
};
