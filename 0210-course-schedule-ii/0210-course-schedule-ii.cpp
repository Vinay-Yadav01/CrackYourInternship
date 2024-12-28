class Solution {
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> indegree(V,0);
	   for(int i=0;i<V;i++){
	       for(auto it: adj[i]){
	           indegree[it]++;
	       }
	   }
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0) q.push(i);
	   }
	   vector<int> topo;
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       topo.push_back(node);
	       for(auto it: adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0) q.push(it);
	       }
	   }
	   return topo;
	}
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
	    for(auto it: prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    vector<int> ans = topoSort(numCourses, adj);
	    if (ans.size()!=numCourses) return {};
	    return ans;
    }
};