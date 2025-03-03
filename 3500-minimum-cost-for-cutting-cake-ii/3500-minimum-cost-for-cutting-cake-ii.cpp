class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int i = 0, j = 0;
        int numOfVerticalSection = 1, numOfHorizontalSection = 1;
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        long long cost = 0;
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                cost += (horizontalCut[i] * numOfVerticalSection);
                numOfHorizontalSection++;
                i++;
            } else {
                cost += (verticalCut[j] * numOfHorizontalSection);
                numOfVerticalSection++;
                j++;
            }
        }
        while (i < horizontalCut.size()) {
            cost += (horizontalCut[i] * numOfVerticalSection);
            numOfHorizontalSection++;
            i++;
        }
        while (j < verticalCut.size()) {
            cost += (verticalCut[j] * numOfHorizontalSection);
            numOfVerticalSection++;
            j++;
        }
        return cost;
    }
};