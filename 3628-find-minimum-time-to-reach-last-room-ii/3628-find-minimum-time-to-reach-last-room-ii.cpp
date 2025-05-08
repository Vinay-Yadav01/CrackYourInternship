class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        // dist[i][j][k]: min time to reach (i,j) with k=0 (next move costs 1),
        // k=1 (next move costs 2)
        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        dist[0][0][0] = 0;
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>, greater<>>
            pq; // min_Heap

        pq.push({0, 0, 0, 0}); // time, row, col, parity

        int delRow[] = {-1, 0, 1, 0}; // row
        int delCol[] = {0, 1, 0, -1}; // col

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int time = get<0>(it);
            int row = get<1>(it);
            int col = get<2>(it);
            int parity = get<3>(it);
            if (row == n - 1 && col == m - 1)
                return time; // destination

            if (dist[row][col][parity] < time)
                continue;

            // // 4 - direction
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow < 0 || nRow >= n || nCol < 0 || nCol >= m)
                    continue;

                int moveCost = (parity == 0) ? 1 : 2;

                int newTime = max(time, moveTime[nRow][nCol]) + moveCost;

                int newParity = 1 - parity;
                if (dist[nRow][nCol][newParity] > newTime) {
                    dist[nRow][nCol][newParity] = newTime;
                    pq.push({newTime, nRow, nCol, newParity});
                }
            }
        }
        return -1; // unreachable
    }
};