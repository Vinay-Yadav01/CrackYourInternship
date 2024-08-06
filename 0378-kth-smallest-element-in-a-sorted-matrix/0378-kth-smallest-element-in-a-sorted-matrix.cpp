class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        vector<int> temp;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                temp.push_back(matrix[i][j]);
        }
        int size = temp.size();
        for (int i = 0; i < k; i++)
            pq.push(temp[i]);

        for (int i = k; i < size; i++) {
            if (pq.top() > temp[i]) {
                pq.pop();
                pq.push(temp[i]);
            }
        }
        return pq.top();
    }
};