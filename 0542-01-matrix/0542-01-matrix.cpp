class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> deltaRow = {-1,0,1,0};
        vector<int> deltaCol = {0,1,0,-1};
        while(!q.empty()){
            auto node  = q.front();
            int row = node.first.first;
            int col = node.first.second;
            int dis = node.second;
            q.pop();
            dist[row][col] = dis;
            for(int i=0;i<4;i++){
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m &&
                    !vis[newRow][newCol] && mat[newRow][newCol]==1){
                        q.push({{newRow, newCol},dis+1});
                        vis[newRow][newCol] = 1;
                }
            }
        }
        return dist;
    }
};