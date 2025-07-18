class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<bool> vis(n, false);
        vis[start] = true;
        while (!q.empty()) {
            int ind = q.front();
            q.pop();
            if (arr[ind] == 0)
                return true;
            int newInd = ind + arr[ind];
            if (newInd < n && !vis[newInd]) {
                q.push(newInd);
                vis[newInd] = true;
            }
            newInd = ind - arr[ind];
            if (newInd >= 0 && !vis[newInd]) {
                q.push(newInd);
                vis[newInd] = true;
            }
        }
        return false;
    }
};