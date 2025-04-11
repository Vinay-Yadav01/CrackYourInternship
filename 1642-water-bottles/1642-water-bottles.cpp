class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int waterBottles = numBottles, emptyBottles = numBottles;
        numBottles = 0; // Current water Bottles
        while (numBottles + emptyBottles >= numExchange) {
            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
            waterBottles += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
        }
        return waterBottles;
    }
};