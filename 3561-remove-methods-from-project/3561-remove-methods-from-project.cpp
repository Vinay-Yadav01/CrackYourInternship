class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the graph using adjacency lists.
        vector<vector<int>> graph(n);
        for (auto& invocation : invocations) {
            graph[invocation[0]].push_back(invocation[1]);
        }
        
        // Step 2: Identify all suspicious methods using BFS starting from method 'k'.
        vector<bool> suspicious(n, false); // To track suspicious methods
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : graph[curr]) {
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Check if any method outside the suspicious group invokes a method within the group.
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) { // If i is not suspicious
                for (int neighbor : graph[i]) {
                    if (suspicious[neighbor]) {
                        // A non-suspicious method invokes a suspicious one, return all methods.
                        vector<int> all_methods(n);
                        iota(all_methods.begin(), all_methods.end(), 0); // Fill vector with {0, 1, ..., n-1}
                        return all_methods; 
                    }
                }
            }
        }
        
        // Step 4: Collect and return all non-suspicious methods.
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
