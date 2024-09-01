class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
               // Max-heap to store the k smallest distances
        priority_queue<int> maxHeap;
        vector<int> results;

        for (const auto& query : queries) {
            int x = query[0];
            int y = query[1];
            int dist = abs(x) + abs(y);

            // Add new distance to the heap
            maxHeap.push(dist);

            // Maintain only k smallest distances in the heap
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }

            // If the heap size is less than k, append -1
            if (maxHeap.size() < k) {
                results.push_back(-1);
            } else {
                // The top of the max-heap is the k-th smallest distance
                results.push_back(maxHeap.top());
            }
        }

        return results;
    }
};