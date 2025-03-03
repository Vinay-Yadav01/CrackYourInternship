class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxElem = arr[0]; // The current winner
        int winStreak = 0;    // Consecutive wins
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxElem) {
                maxElem = arr[i];  // New winner
                winStreak = 1;     // Reset win streak
            } else {
                winStreak++;       // Current winner continues winning
            }
            
            if (winStreak == k) return maxElem;
        }
        
        // If k is too large, the overall max element is the final winner
        return maxElem;
    }
};
