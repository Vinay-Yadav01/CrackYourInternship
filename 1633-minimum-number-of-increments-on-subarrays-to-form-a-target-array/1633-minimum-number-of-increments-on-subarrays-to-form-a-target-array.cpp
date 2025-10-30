class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int sum = target[0], n = target.size();
        for (int i = 0; i + 1 < n; i++) {
            if (target[i + 1] > target[i])
                sum += (target[i + 1] - target[i]);
        }
        return sum;
    }
};