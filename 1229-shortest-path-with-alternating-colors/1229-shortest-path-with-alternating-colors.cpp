class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n), blueAdj(n);
        for (auto& e : redEdges)
            redAdj[e[0]].push_back(e[1]);
        for (auto& e : blueEdges)
            blueAdj[e[0]].push_back(e[1]);

        vector<vector<bool>> visited(n, vector<bool>(2, false)); // visited[node][color]
        vector<int> dist(n, -1);
        queue<pair<int, int>> q;

        q.push({0, 0}); // Start with red
        q.push({0, 1}); // Start with blue
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, color] = q.front(); q.pop();
                if (visited[node][color]) continue;
                visited[node][color] = true;

                if (dist[node] == -1) dist[node] = steps;

                if (color == 0) { // last edge was red, so now take blue
                    for (int nei : blueAdj[node])
                        if (!visited[nei][1])
                            q.push({nei, 1});
                } else { // last edge was blue, take red
                    for (int nei : redAdj[node])
                        if (!visited[nei][0])
                            q.push({nei, 0});
                }
            }
            steps++;
        }
        return dist;
    }
};
