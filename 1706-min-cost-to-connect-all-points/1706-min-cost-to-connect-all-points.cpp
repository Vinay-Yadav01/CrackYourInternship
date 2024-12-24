class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); //wt node
        int sum = 0;
        vector<int> vis(n,0);
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(int adjNode=0;adjNode<n;adjNode++){
                if(vis[adjNode]) continue;
                int wt = abs(points[node][0]-points[adjNode][0]) + abs(points[node][1]-points[adjNode][1]);
                pq.push({wt, adjNode});
            }
        }
        return sum;
    }
};