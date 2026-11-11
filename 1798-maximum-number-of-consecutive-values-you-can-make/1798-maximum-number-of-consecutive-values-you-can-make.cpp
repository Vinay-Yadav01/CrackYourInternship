class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int current_max = 0;
        
        for (int coin : coins) {
            if (coin > current_max + 1) 
                break;
            current_max += coin;
        }
        
        return current_max + 1;
    }
};