class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minCost=prices[0];
        for(int i=1;i<prices.size();i++){
            int currentProfit = prices[i]-minCost;
            profit = max(profit, currentProfit);
            minCost = min(minCost,prices[i]);
        }
        return profit;
    }
};