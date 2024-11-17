class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        vector<vector<int>> dist(rows, vector<int>(columns, 1e9));
        dist[0][0] = 0;
        
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == rows-1 && col == columns-1) {
                return wt;
            }
            for(int i=0;i<4;i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < columns) {
                    int newWeight = abs(heights[newRow][newCol] - heights[row][col]);
                    if (dist[newRow][newCol] > max(wt, newWeight)) {
                        dist[newRow][newCol] = max(wt, newWeight);
                        pq.push({dist[newRow][newCol], {newRow, newCol}});
                    }
                }
            }
        }
        return dist[rows-1][columns-1];
    }
};