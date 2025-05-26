class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        int low = 0, high = n - 1;
        int h = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int papers = n - mid;

            if (citations[mid] >= papers) {
                h = papers;
                high = mid - 1; // try to find a larger h (more to the left)
            } else {
                low = mid + 1; // go right
            }
        }

        return h;
    }
};
