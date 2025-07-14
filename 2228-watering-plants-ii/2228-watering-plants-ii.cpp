class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int refill = 0;
        int currAliceWater = capacityA, currBobWater = capacityB;
        int i = 0, j = plants.size() - 1;

        while (i < j) {
            if (plants[i] <= currAliceWater) {
                currAliceWater -= plants[i];
            } else {
                currAliceWater = capacityA - plants[i];
                refill++;
            }
            i++;

            if (plants[j] <= currBobWater) {
                currBobWater -= plants[j];
            } else {
                currBobWater = capacityB - plants[j]; // ✅ fixed
                refill++;
            }
            j--;
        }

        if (i == j) {
            int maxWater = max(currAliceWater, currBobWater);
            if (maxWater < plants[i]) refill++;
        }

        return refill;
    }
};
