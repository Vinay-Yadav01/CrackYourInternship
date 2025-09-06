class Solution {
public:
    long long get(int x) { 
        int cur = 1;
        long long res = 0, mul = 1;
        while (cur <= x) {
            long long nxt = min(cur * 4, x + 1);
            long long cnt = nxt - cur;
            res += (cnt * mul);
            mul++;
            cur = nxt;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& q : queries) {
            long long cnt =
                (get(q[1]) -
                 get(q[0] - 1)); // cnt = 5 -> ans = 3 , cnt = 6 -> ans = 3;
            ans += (cnt + 1) / 2;
        }
        return ans;
    }
};