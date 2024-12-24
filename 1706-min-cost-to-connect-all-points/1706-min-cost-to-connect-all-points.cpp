class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        int u=0;
        for(auto it1: points){
            int v = 0;
            for(auto it2: points){
                if(it1==it2) {
                    v++;
                    continue;
                }
                int x1 = it1[0], y1 = it1[1];
                int x2 = it2[0], y2 = it2[1];
                int dist = abs(x2-x1) + abs(y2-y1);
                adj[u].push_back({v,dist});
                // cout<<u<<" "<<v<<endl;
                v++;
            }
            u++;
        }

        // cout<<endl<<endl;

        // for(int it=0;it<n;it++){
        //     for(auto i: adj[it]){
        //         cout<<it<<" "<<i.first<<" "<<i.second<<endl;
        //     }
        // }

        //Graph is ready now
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
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(!vis[adjNode]) pq.push({wt,adjNode});
            }
        }
        return sum;
    }
};