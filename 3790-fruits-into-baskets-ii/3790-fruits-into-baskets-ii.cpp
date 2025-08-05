class Solution {
public:
    int numOfUnplacedFruits(const vector<int>& fruits,
                            const vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); // Track whether a basket has been used
        int unplaced = 0;
        for (int fruit : fruits) {
            bool placed = false;
            for (int i = 0; i < n; i++) {
                if (!used[i] && baskets[i] >= fruit) {
                    used[i] = true; 
                    placed = true;
                    break; 
                }
            }
            if (!placed) {
                unplaced++;
            }
        }

        return unplaced;
    }
};